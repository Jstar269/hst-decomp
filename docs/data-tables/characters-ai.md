# g1-chara-ai: loaders for character / NPC / AI / grade / common / aityaku / voicepack / PCGut / Iromono tables

Private analysis. Column names, offsets, strides and EBOOT string names only; no cell values.
All addresses are module-relative (EBOOT.BIN). Sources: Ghidra pseudocode + `hstdis` + jal/lui xref scans.
Summary: every table in the group has a located loader (18 files incl. AI_Param_1..3, plus Racket_param.csv found as a shared-reader user); 0 loaders unresolved, some field meanings are guesses (see end).

## 0. Reader class actually used here (differs slightly from the HOWTO description)

Almost every table below uses a second, **named-column CSV reader** (vtable `0x3070bc`; same row/cell storage as the
`0x3070cc` class in the HOWTO). Loader entry = `FUN_000651b8(this, path, buildRowLabelMap, buildHeaderMap, delimStr)` which calls `FUN_00064bf4` (read +
split) and then optionally builds two `std::map`s:

| fn | meaning |
|---|---|
| `FUN_000651b8(this,path,a,b,delim)` | load; `a!=0` -> map "row label (col 0) -> row index" at this+0x10; `b!=0` -> map "header name (row 0) -> col index" at this+0x20. Row 0 (header) is **kept as row 0**; callers loop rows 1..n-1 |
| `FUN_00065364(this,name)` | column index by header name, -1 if absent |
| `FUN_000655f8(this,row,name)` | float cell by (row, header name); 0 if column absent |
| `FUN_00065554(this,row,name)` | int cell by (row, header name); 0 if column absent |
| `FUN_0006569c(this,row,name)` | string cell by (row, header name) |
| `FUN_000657e4(this,rowLabel,col)` | float cell by (row label, col index) (needs the row-label map) |
| `FUN_001639ec / FUN_00163a4c(this,row,name)` | int / float by header name; wrappers over 00065364 + 00065104/00065140 (return 0 if absent) |
| `FUN_00065104 / 00065140 / 0006517c(this,row,col)` | int / float / string by (row,col) |
| `FUN_000650e0(this)` / `FUN_000650e8(this,row)` | row count (incl. header row) / column count of one row |

Consequence: for the by-name loaders the CSV **column order does not matter**; a missing column silently reads as 0.
Delimiters: `0x2de8b4` = "," (also `0x2f4a64`, `0x2d47a8`, `0x2fbdbc`); `0x2fcc70` / `0x2fe780` / `0x2e1cb8` = TAB.
The tables come from already-extracted archives (`FUN_0001ca58(0x30ebf4,"common/common_10.xb")` etc. precede the loads).

### Call tree / timing
```
FUN_000468c8  (boot / main init)  --jal 0x46d04-->  FUN_00047054  (boot-time "load common parameter tables")
    FUN_00047054:
        FUN_00160998(&0x341120, -1)                      common.csv           -> global struct @0x341120 (size 0x3e8)   [0x470f4]
        _DAT_00341508 = array_new(ctor 0x1621e0, dtor 0x162200, elemsize 0x18, count 2)
        FUN_00162338(_DAT_00341508,        "data/common/parameter/character.csv")   [0x47134]
              \-> (path contains "character.csv") FUN_00162338(_DAT_0034150c = array_new(count 1), Racket_param.csv)   [0x163398]
              \-> and FUN_001607a4(_DAT_00341510 = array_new(ctor 0x160790, dtor 0x1622d8, elemsize 0xc, 1))   grade.csv   [0x1633d0]
        FUN_00162338(_DAT_00341508 + 0x18, "data/common/parameter/NPC_Param.csv")   [0x4714c]
        FUN_000d9358("data/chara/model/etc/etc_offset.csv")                         [0x47158]
        _DAT_0034a77c = new(0x54) ; FUN_0024d808(this)   aityaku.csv (ctor loads it)   [0x47300]

FUN_00088a44 (gameplay-scene state machine, state 0 = scene init; objects freed again by the scene dtor FUN_00088388)
        _DAT_0034a6b0 = array_new(count 1, elem 0x24); FUN_00235da4(it)           AI_Shot.csv                 [0x88cd8]
        _DAT_0034a6a8 = array_new(count 3, elem 0x20); FUN_00234898(elem[i], sprintf("data/common/parameter/AI_Param_%d.csv", i+1))  [0x88d38]
        _DAT_0034a6ac = array_new(count 2, elem 0x20); FUN_00234898(elem[0], ".../AI_param_PC.csv") [0x88d88]; FUN_00234898(elem[1], ".../AI_param_NPC.csv") [0x88da0]
        _DAT_0034a6b4 = array_new(count 1, elem 0xc);  FUN_00235ff4(it)           AI_Param_Doubles.csv        [0x88dd8]
        _DAT_0034a6b8 = array_new(count 1, elem 0xc);  FUN_0023650c(it)           AI_Shot_Doubles.csv         [0x88e10]
        _DAT_0034a7e8 = array_new(count 2, elem 0xc);  FUN_0027dcec(elem[0], PCGut_PcGut.txt) [0x88e5c]; FUN_0027dcec(elem[1], PCGut_NpcGut.txt) [0x88e6c]
        _DAT_00338ab0 = new(0x18) via FUN_000b3ca0 ; FUN_000b3cf4(it)             npc_voicepack.csv           [0x88e98]
Rule_Iromono.txt: two different consumers (menu "lastconfirm" scene FUN_001a0148 and ad-hoc room scene ctor FUN_00253630), see section 10.
```
(`array_new` = `FUN_000008d8(mem, ctor, dtor, elemSize, count)`; the 3-word containers are simple `{ptr,count,capacity}` vectors.)

---

## 1. data/common/parameter/character.csv, NPC_Param.csv (and Racket_param.csv)  -- loader `FUN_00162338(container, path)`

- Loader: `0x162338`. Callers: `FUN_00047054` at 0x47134 (character.csv) and 0x4714c (NPC_Param.csv); self-call at 0x163398 for Racket_param.csv.
- When: boot (inside the one-time init `FUN_00047054`). Not reached from anywhere else.
- Reader: named-column CSV, `FUN_000651b8(this,path,0,1,",")`; rows 1..n-1; ID column = header "ID" (`0x2de908`), falling back to header "Label" (`0x2dfb04`; Racket_param.csv uses "Label").
- Destination container (0x18 bytes, `FUN_00162338` arg 1, call it `p`): `p[0]` element array base, `p[1]` count, `p[2]` capacity,
  `p[3]` `short[]` index map (element index by ID; unfilled entries 0xffff), `p[4]` map size (= max ID + 1).
  Element stride **0x22c**. Three containers: `_DAT_00341508` (offset +0) = character.csv (PC, 15 rows), `_DAT_00341508 + 0x18` = NPC_Param.csv (206 rows),
  `_DAT_0034150c` = Racket_param.csv. Row index = row order; lookup by ID goes through the short index map
  (e.g. rackets: `FUN_00163aac` uses `p[3][racketId]*0x22c`); lookup by name = `FUN_00165004(container,name)` (linear scan comparing the name at +2; error string
  "CharacterParameter '%s' not found." at `0x2e03c4`, referenced at 0x16507c). Callers of `FUN_00165004`: 0x97674 (inside `FUN_00097520`, match chara setup, `_DAT_00341508 + isNpc*0x18`), 0x16bb98, 0x1eb000, 0x2180a8, 0x2181a4, 0x2182a0, 0x254bd0.
- Element header: +0x00 s16 ID = atoi starting at the first digit of the ID/Label cell text (`FUN_0000fe64` isdigit scan + `FUN_0000d62c` atoi); +0x02 char[16] = full ID/Label cell text (strcpy `FUN_000149a8`).
- Everything else is read by header name (`FUN_001639ec` int, `FUN_00163a4c` float); u8/s16 fields are narrowed ints. Field list (offset, width, header name, column index in `character.csv`; "[not in this csv header]" = loader asks for the name but character.csv/NPC_Param.csv have no such column so it stays 0; these 5 `*Shop` columns exist in Racket_param.csv):

```
+0x000 s16 ID                       (digits of ID/Label cell, see above)
+0x002 char[16] name                (ID/Label cell text)
+0x012 u8  SwingFore (col 1)
+0x013 u8  SwingBack (col 2)
+0x014 u8  Playstyle (col 3)
+0x018 f32 ManualTargetUnitX (col 4)
+0x01c f32 VolleyManualTargetUnitX (col 5)
+0x020 f32 SmashManualTargetUnitX (col 6)
+0x024 f32 Height (col 11)
+0x028 f32 Leach (col 12)
+0x02c f32 DistLimitStroke (col 13)
+0x030 f32 StrongshotArea (col 14)
+0x034 f32 StrongshotAreaMax (col 15)
+0x038 f32 BallhitArea (col 16)
+0x03c f32 HeightLimitServe (col 18)
+0x040 f32 Toss (col 19)
+0x044 f32 Power (col 20)
+0x048 f32 Spin (col 21)
+0x04c f32 Technique (col 22)
+0x050 f32 Speed (col 23)
+0x054 f32 Stamina (col 24)
+0x058 f32 Impact (col 25)
+0x05c f32 PowerShop [not in this csv header]
+0x060 f32 TechniqueShop [not in this csv header]
+0x064 f32 SpeedShop [not in this csv header]
+0x068 f32 StaminaShop [not in this csv header]
+0x06c f32 ImpactShop [not in this csv header]
+0x070 f32 UsaPower (col 28)
+0x074 f32 UsaSpin (col 29)
+0x078 f32 KamePower (col 30)
+0x07c f32 KameSpin (col 31)
+0x080 f32 BackPower (col 32)
+0x084 f32 BackSpin (col 33)
+0x088 f32 BackTechnique (col 34)
+0x08c f32 BackVolleyPower (col 35)
+0x090 f32 BackVolleySpin (col 36)
+0x094 f32 BackVolleyTechnique (col 37)
+0x098 f32 BodyArea (col 38)
+0x09c f32 BodyPower (col 39)
+0x0a0 f32 BodySpin (col 40)
+0x0a4 f32 BodyTechnique (col 41)
+0x0a8 s32 BodyRigor (col 42)
+0x0ac f32 SnatchPowerLower (col 43)
+0x0b0 f32 SnatchPowerUpper (col 44)
+0x0b4 f32 SnatchSpinLower (col 45)
+0x0b8 f32 SnatchSpinUpper (col 46)
+0x0bc f32 SnatchTechnique (col 47)
+0x0c0 s16 SnatchRigor (col 48)
+0x0c2 s16 SnatchMissRigor (col 49)
+0x0c4 f32 SpeedForward (col 51)
+0x0c8 f32 SpeedBackward (col 52)
+0x0cc f32 SpeedSide (col 53)
+0x0d0 f32 TopPower (col 54)
+0x0d4 f32 TopSpin (col 55)
+0x0d8 f32 TopSidespin (col 56)
+0x0dc f32 TopTechnique (col 57)
+0x0e0 s32 TopRigor (col 58)
+0x0e4 f32 SlicePower (col 61)
+0x0e8 f32 SliceSidespin (col 63)
+0x0ec f32 SliceTechnique (col 64)
+0x0f0 s32 SliceRigor (col 65)
+0x0f4 f32 LobPower (col 68)
+0x0f8 f32 LobSidespin (col 70)
+0x0fc f32 LobTechnique (col 71)
+0x100 s32 LobRigor (col 72)
+0x104 f32 VolleyPower (col 75)
+0x108 f32 VolleySpin (col 76)
+0x10c f32 VolleySidespin (col 77)
+0x110 f32 VolleyTechnique (col 78)
+0x114 f32 VolleyArea (col 79)
+0x118 s32 VolleyRigor (col 80)
+0x11c f32 VolleyWeakPower (col 83)
+0x120 f32 VolleyWeakSpin (col 84)
+0x124 f32 VolleyWeakSidespin (col 85)
+0x128 f32 VolleyWeakTechnique (col 86)
+0x12c s32 VolleyWeakRigor (col 87)
+0x130 f32 LowvolleyPower (col 90)
+0x134 f32 LowvolleySpin (col 91)
+0x138 f32 LowvolleySidespin (col 92)
+0x13c f32 LowvolleyTechnique (col 93)
+0x140 f32 LowvolleyArea (col 94)
+0x144 f32 LowvolleyAreaNear (col 95)
+0x148 s32 LowvolleyRigor (col 96)
+0x14c f32 LowvolleyWeakPower (col 99)
+0x150 f32 LowvolleyWeakSpin (col 100)
+0x154 f32 LowvolleyWeakSidespin (col 101)
+0x158 f32 LowvolleyWeakTechnique (col 102)
+0x15c s32 LowvolleyWeakRigor (col 103)
+0x160 f32 HighvolleyPower (col 106)
+0x164 f32 HighvolleySpin (col 107)
+0x168 f32 HighvolleySidespin (col 108)
+0x16c f32 HighvolleyTechnique (col 109)
+0x170 s32 HighvolleyRigor (col 110)
+0x174 f32 FlatPower (col 113)
+0x178 f32 FlatSpin (col 114)
+0x17c f32 FlatSidespin (col 115)
+0x180 f32 FlatTechnique (col 116)
+0x184 f32 FlatArea (col 117)
+0x188 s32 FlatRigor (col 118)
+0x18c f32 DropPower (col 121)
+0x190 f32 DropSidespin (col 123)
+0x194 f32 DropTechnique (col 124)
+0x198 s32 DropRigor (col 125)
+0x19c f32 AirshotPower (col 128)
+0x1a0 f32 AirshotSpin (col 129)
+0x1a4 f32 AirshotSidespin (col 130)
+0x1a8 f32 AirshotTechnique (col 131)
+0x1ac f32 AirshotArea (col 132)
+0x1b0 s32 AirshotRigor (col 133)
+0x1b4 f32 RisingPower (col 136)
+0x1b8 f32 RisingSpin (col 137)
+0x1bc f32 RisingSidespin (col 138)
+0x1c0 f32 RisingTechnique (col 139)
+0x1c4 f32 RisingArea (col 140)
+0x1c8 s32 RisingRigor (col 141)
+0x1cc f32 SmashPower (col 144)
+0x1d0 f32 SmashSpin (col 145)
+0x1d4 f32 SmashSidespin (col 146)
+0x1d8 f32 SmashTechnique (col 147)
+0x1dc s32 SmashRigor (col 148)
+0x1e0 f32 SpinservePower (col 151)
+0x1e4 f32 SpinserveSpin (col 152)
+0x1e8 f32 SpinserveSidespin (col 153)
+0x1ec f32 SpinserveTechnique (col 154)
+0x1f0 s32 SpinserveRigor (col 155)
+0x1f4 f32 SliceservePower (col 158)
+0x1f8 f32 SliceserveSpin (col 159)
+0x1fc f32 SliceserveSidespin (col 160)
+0x200 f32 SliceserveTechnique (col 161)
+0x204 s32 SliceserveRigor (col 162)
+0x208 f32 FlatservePower (col 165)
+0x20c f32 FlatserveSpin (col 166)
+0x210 f32 FlatserveSidespin (col 167)
+0x214 f32 FlatserveTechnique (col 168)
+0x218 s32 FlatserveRigor (col 169)
+0x21c u8  TopForte (col 60)
+0x21d u8  SliceForte (col 67)
+0x21e u8  LobForte (col 74)
+0x21f u8  VolleyForte (col 82)
+0x220 u8  VolleyWeakForte (col 89)
+0x221 u8  LowvolleyForte (col 98)
+0x222 u8  LowvolleyWeakForte (col 105)
+0x223 u8  HighvolleyForte (col 112)
+0x224 u8  FlatForte (col 120)
+0x225 u8  DropForte (col 127)
+0x226 u8  AirshotForte (col 135)
+0x227 u8  RisingForte (col 143)
+0x228 u8  SmashForte (col 150)
+0x229 u8  SpinserveForte (col 157)
+0x22a u8  SliceserveForte (col 164)
+0x22b u8  FlatserveForte (col 171)
```
- The struct tiles gap-free from +0x012 to +0x22c. Header columns of character.csv/NPC_Param.csv (172 cols) that the loader never reads: `TimingBureUnitUsakameX`, `TimingBureUnitVolleyX`, `TimingBureUnitSmashX`, `TimingBureRatio`, `DistLimitSnatch`, `GIPower`, `GISpin`, `Acceleration`, every `*SpinVelocity`, and `SliceSpin`, `LobSpin`, `DropSpin` (so the struct has Power/Sidespin/Technique for Slice/Lob/Drop but no plain Spin). `Toss` and `Spin` are referenced by the loader through unnamed `&DAT_002dfb94` / `&DAT_002dfb9c`; resolved from the string table.
- Racket_param.csv through the *same* reader: header columns present = Label, Power, Technique, Speed, Stamina, Impact, PowerShop, TechniqueShop, SpeedShop, StaminaShop, ImpactShop, Leach, DistLimitStroke, StrongshotArea, DistLimitSnatch (unread), HeightLimitServe, Toss, UsaPower, UsaSpin, KamePower, KameSpin, BackPower, BackSpin, BackTechnique, BackVolleyPower, BackVolleySpin, BackVolleyTechnique, SnatchPowerLower/Upper, SnatchSpinLower/Upper, SnatchTechnique, SnatchRigor; all other struct fields stay 0 for rackets. (The Racket group should reference this same loader.)
- NPC_Param.csv and character.csv have identical 172-column headers.

## 2. data/common/parameter/grade.csv  -- loader `FUN_001607a4(vec)`

- Loader `0x1607a4`; sole caller `0x1633d0` inside `FUN_00162338` (reached only when the path being loaded contained "character.csv", i.e. once at boot).
- Reader: `FUN_000651b8(this,path,0,1,",")`; rows 1..n-1 (7 data rows); first header cell is blank (row-name column ignored).
- Destination: `_DAT_00341510` = `{ptr,count,cap}` (0xc bytes); element stride **0x14** = 5 x f32 (`FUN_000655f8` by header name):
  `+0x00 Power, +0x04 Technique, +0x08 Speed, +0x0c Stamina, +0x10 Impact`.
- Use: e.g. `FUN_00163aac` clamps a rating between `grade[0].Power` and `grade[count-1].Power`; ~20 accessors (0x163bec..0x164f64) use the other columns.

## 3. data/common/parameter/common.csv  -- loader `FUN_00160998(dest, id)`

- Loader `0x160998`; sole caller `FUN_00047054` at 0x470f4 with `dest=0x341120`, `id=-1`. Boot.
- Reader: `FUN_000651b8(this,path,0,1,",")`. Row selection: `want = (id>=0) ? id : _DAT_00341514`; scan rows 1..n-1 comparing int column "ID" (`0x2de908`) with `want`; if found use that row and store `_DAT_00341514 = want`;
  if not found use row 1 and leave `_DAT_00341514` (initially 0).
- **Surprise:** `_DAT_00341514` is written only here and read only in `FUN_000a4220` (`if (_DAT_00341514 == 0)`), and the only caller passes -1, so the second data row of common.csv (lines=3 => 2 data rows) can never be selected at runtime.
- Destination: global struct at **0x341120**, size **0x3e8** (immediately followed by the container pointer at 0x341508). 246 named reads: `FUN_000655f8` (f32) except 4 s32 (`TimingAdjustLimitEarly`, `TimingAdjustLimitLate`, `WeekshotAjustArea`, `DoublesPartnerRank`) and 2 bools (`Param_1` at +0x1e4, `Param_2` at +0x1e5, `!= 0`). Fields (offset, type, header name, csv column index):

```
+0x000 f32 Air (col 1)
+0x004 f32 ShotDistBase (col 2)
+0x008 f32 ShotDistBaseB (col 3)
+0x00c f32 ShotDistBaseC (col 4)
+0x010 f32 ShotDistBaseD (col 5)
+0x014 f32 ShotDistBaseE (col 6)
+0x018 f32 ShotDistBaseF (col 7)
+0x01c f32 ShotDistRatioPower (col 8)
+0x020 f32 ShotDistRatioSpin (col 9)
+0x024 f32 ShotDistRatioPowerSlice (col 10)
+0x028 f32 ShotDistRatioSpinSlice (col 11)
+0x02c f32 ShotDistRatioPowerLob (col 12)
+0x030 f32 ShotDistRatioSpinLob (col 13)
+0x034 f32 ShotDistRatioPowerDrop (col 14)
+0x038 f32 ShotDistRatioSpinDrop (col 15)
+0x03c f32 ShotDistRatioPowerVolley (col 16)
+0x040 f32 ShotDistRatioSpinVolley (col 17)
+0x044 f32 ShotDistRatioPowerHighvolley (col 18)
+0x048 f32 ShotDistRatioSpinHighvolley (col 19)
+0x04c f32 ShotDistRatioPowerSmash (col 20)
+0x050 f32 ShotDistRatioSpinSmash (col 21)
+0x054 f32 ManualTargetDefaultZ (col 22)
+0x058 f32 ManualTargetUnitX (col 23)
+0x05c f32 ManualTargetUnitZ (col 24)
+0x060 f32 SmashManualTargetUnitX (col 25)
+0x064 f32 VolleyManualTargetUnitX (col 26)
+0x068 f32 DoublesTarget (col 148)
+0x06c f32 ManualTargetLimitX (col 27)
+0x070 f32 TimingBureUnitUsakameX (col 28)
+0x074 f32 TimingBureRatio (col 29)
+0x078 f32 TimingBureRatioNear (col 149)
+0x07c f32 RandomBureWait (col 150)
+0x080 f32 RandomBureDash (col 151)
+0x084 f32 RandomBureDashTime (col 235)
+0x088 f32 RandomBureSnatch (col 152)
+0x08c f32 TimingBureRatioVolley (col 153)
+0x090 f32 RandomBureRatioVolley (col 154)
+0x094 f32 StraightRatio (col 30)
+0x098 f32 ForwardRatio (col 31)
+0x09c f32 BackwardRatio (col 32)
+0x0a0 f32 TimingBureUnitVolleyX (col 33)
+0x0a4 f32 TimingBureUnitSmashX (col 34)
+0x0a8 f32 SpeedRun (col 36)
+0x0ac f32 SpeedStep (col 37)
+0x0b0 f32 SpeedTiredA (col 38)
+0x0b4 f32 SpeedTiredB (col 39)
+0x0b8 f32 ShotAngleLimitRun (col 40)
+0x0bc f32 ShotAngleLimitDash (col 41)
+0x0c0 f32 StaminaMax (col 42)
+0x0c4 f32 StaminaMin (col 43)
+0x0c8 f32 TiredTimeA (col 44)
+0x0cc f32 TiredTimeB (col 45)
+0x0d0 f32 TiredTimeC (col 132)
+0x0d4 f32 PowerSpinTiredA (col 46)
+0x0d8 f32 PowerSpinTiredB (col 47)
+0x0dc f32 BureLow (col 48)
+0x0e0 f32 BureHigh (col 49)
+0x0e4 f32 DepthMinus (col 50)
+0x0e8 f32 DepthPlus (col 51)
+0x0ec f32 SnatchDepthAdd (col 53)
+0x0f0 f32 StrongshotPower (col 54)
+0x0f4 f32 StrongshotSpin (col 55)
+0x0f8 f32 StrongshotPowerMax (col 56)
+0x0fc f32 StrongshotSpinMax (col 57)
+0x100 f32 PowerMinCircle (col 58)
+0x104 f32 PowerMin (col 59)
+0x108 f32 PowerMinSmash (col 60)
+0x10c f32 PowerMinSnatch (col 61)
+0x110 f32 SliceSpinMax (col 63)
+0x114 f32 SliceSpinMin (col 65)
+0x118 f32 LobSpinMax (col 66)
+0x11c f32 LobSpinMin (col 67)
+0x120 f32 DropSpinMax (col 70)
+0x124 f32 DropSpinMin (col 71)
+0x128 f32 DropDistMinusMax (col 72)
+0x12c f32 DropDistMinusMin (col 73)
+0x130 f32 DropDistMinusForte (col 74)
+0x134 f32 WeaksmashPower (col 75)
+0x138 f32 WeaksmashSpin (col 76)
+0x13c f32 ServeWalkSpeed (col 77)
+0x140 f32 DepthBureSpinserve (col 78)
+0x144 f32 DepthBureSliceserve (col 79)
+0x148 f32 DepthBureFlatserve (col 80)
+0x14c f32 ImpactBaseSpinserve (col 81)
+0x150 f32 ImpactBaseSliceserve (col 82)
+0x154 f32 ImpactBaseFlatserve (col 83)
+0x158 f32 ImpactRatioSpinserve (col 84)
+0x15c f32 ImpactRatioSliceserve (col 85)
+0x160 f32 ImpactRatioFlatserve (col 86)
+0x164 s32 TimingAdjustLimitEarly (col 87)
+0x168 s32 TimingAdjustLimitLate (col 88)
+0x16c f32 ShotRangeJustDMax (col 89)
+0x170 f32 ShotRangeJustDMin (col 90)
+0x174 f32 ShotRangeDMax (col 91)
+0x178 f32 ShotRangeDMin (col 92)
+0x17c f32 ShotRangeBaseD (col 35)
+0x180 f32 ShotTargetOffsetRatioX (col 93)
+0x184 f32 ShotTargetOffsetRatioNearX (col 94)
+0x188 f32 ShotTargetOffsetRatioFarX (col 95)
+0x18c f32 ShotTargetOffsetRatioZ (col 96)
+0x190 f32 ShotTargetBaseZ (col 99)
+0x194 f32 Bound_1 (col 100)
+0x198 f32 Bound_2 (col 101)
+0x19c f32 Bound_3 (col 102)
+0x1a0 f32 Bound_4 (col 103)
+0x1a4 f32 Bound_5 (col 104)
+0x1a8 f32 Fast_1 (col 105)
+0x1ac f32 Fast_2 (col 106)
+0x1b0 f32 Fast_3 (col 107)
+0x1b4 f32 Fast_4 (col 108)
+0x1b8 f32 Fast_5 (col 109)
+0x1bc f32 FastDropA (col 249)
+0x1c0 f32 FastDropB (col 250)
+0x1dc f32 SpinRatio (col 110)
+0x1e0 f32 SpinVelocity (col 111)
+0x1e4 bool Param_1 (col 112)
+0x1e5 bool Param_2 (col 113)
+0x1e8 f32 ChargePower (col 114)
+0x1ec f32 ChargeSpin (col 115)
+0x1f0 f32 ChargeTechnique (col 116)
+0x1f4 f32 ChargeTime (col 117)
+0x1f8 f32 ChargeSpeed (col 118)
+0x1fc f32 SuperDashSpeed (col 119)
+0x200 f32 TiredTimeRatio (col 120)
+0x204 f32 StaminaPoint (col 121)
+0x208 f32 StaminaPointRatio (col 122)
+0x20c f32 StaminaGame (col 123)
+0x210 f32 StaminaGameRatio (col 124)
+0x214 f32 StaminaSet (col 125)
+0x218 f32 StaminaSetRatio (col 126)
+0x21c f32 StaminaCircleSwingRatio (col 127)
+0x220 f32 StaminaCrossSwingRatio (col 128)
+0x224 f32 StaminaTriangleSwingRatio (col 129)
+0x228 f32 StaminaSuperDashRatio (col 130)
+0x22c f32 StaminaSnatchRatio (col 131)
+0x230 f32 StaminaSmash (col 251)
+0x234 f32 NoboundPowerRatio (col 133)
+0x238 f32 NoboundSpinRatio (col 134)
+0x23c f32 NoboundTechniqueRatio (col 135)
+0x240 f32 OneboundPowerRatio (col 136)
+0x244 f32 OneboundSpinRatio (col 137)
+0x248 f32 OneboundTechniqueRatio (col 138)
+0x24c s32 WeekshotAjustArea (col 139)
+0x250 f32 DropShotspeedMax (col 140)
+0x254 f32 DropShotspeedRatio (col 141)
+0x258 f32 ServePowerHigh (col 142)
+0x25c f32 ServeSpinHigh (col 143)
+0x260 f32 ServeTechniqueHigh (col 144)
+0x264 f32 ServePowerLow (col 145)
+0x268 f32 ServeSpinLow (col 146)
+0x26c f32 ServeTechniqueLow (col 147)
+0x270 f32 CounterPowerCross (col 155)
+0x274 f32 CounterSpinCross (col 156)
+0x278 f32 CounterPowerTriangle (col 157)
+0x27c f32 CounterSpinTriangle (col 158)
+0x280 f32 CounterPowerCircle (col 159)
+0x284 f32 CounterSpinCircle (col 160)
+0x288 f32 CounterPowerStrongshot (col 161)
+0x28c f32 CounterSpinStrongshot (col 162)
+0x290 f32 DepthMinusDefault (col 163)
+0x294 f32 DepthMinusLow (col 164)
+0x298 f32 DepthMinusBound (col 165)
+0x29c f32 DepthMinusSnatch (col 166)
+0x2a0 f32 DepthMinusBody (col 167)
+0x2a4 f32 DepthPlusNobound (col 168)
+0x2a8 f32 DepthPlusDash (col 169)
+0x2ac f32 DepthPlusSuperDash (col 170)
+0x2b0 f32 DepthPlusSnatch (col 171)
+0x2b4 f32 DepthPlusBody (col 172)
+0x2b8 f32 DashTechnique (col 173)
+0x2bc f32 SuperDashTechnique (col 174)
+0x2c0 f32 RandomBureRatioLow (col 175)
+0x2c4 f32 RandomBureRatioBack (col 176)
+0x2c8 f32 RandomBureRatioWeak (col 177)
+0x2cc f32 RandomBureRatioNobound (col 178)
+0x2d0 f32 RandomBureRatioWeakshot (col 179)
+0x2d4 f32 RandomBureRatioCross (col 180)
+0x2d8 f32 RandomBureRatioTiredA (col 181)
+0x2dc f32 RandomBureRatioTiredB (col 182)
+0x2e0 f32 RandomBureRatioStrongshot (col 252)
+0x2e4 f32 RandomBureChargeMax (col 183)
+0x2e8 f32 RandomBureChargeHalf (col 184)
+0x2ec f32 RandomBureSuperDash (col 185)
+0x2f0 f32 PowerLowest (col 186)
+0x2f4 f32 SpinLowest (col 187)
+0x2f8 f32 PowerLow (col 188)
+0x2fc f32 SpinLow (col 189)
+0x300 f32 PowerHighest (col 190)
+0x304 f32 SpinHighest (col 191)
+0x308 f32 PowerLowestCross (col 192)
+0x30c f32 SpinLowestCross (col 193)
+0x310 f32 PowerLowCross (col 194)
+0x314 f32 SpinLowCross (col 195)
+0x318 f32 PowerHighestCross (col 196)
+0x31c f32 SpinHighestCross (col 197)
+0x320 f32 PowerLowestTriangle (col 198)
+0x324 f32 SpinLowestTriangle (col 199)
+0x328 f32 PowerLowTriangle (col 200)
+0x32c f32 SpinLowTriangle (col 201)
+0x330 f32 PowerHighestTriangle (col 202)
+0x334 f32 SpinHighestTriangle (col 203)
+0x338 f32 PowerLowestVolley (col 204)
+0x33c f32 SpinLowestVolley (col 205)
+0x340 f32 PowerLowVolley (col 206)
+0x344 f32 SpinLowVolley (col 207)
+0x348 f32 PowerHighestVolley (col 208)
+0x34c f32 SpinHighestVolley (col 209)
+0x350 f32 DepthMinusRatioSlice (col 210)
+0x354 f32 DepthPlusRatioSlice (col 211)
+0x358 f32 DepthMinusRatioDrop (col 212)
+0x35c f32 DepthPlusRatioVolleyWeak (col 213)
+0x360 f32 DepthMinusRatioLob (col 214)
+0x364 f32 DepthPlusRatioLob (col 215)
+0x368 f32 DepthMinusRatioFlat (col 216)
+0x36c f32 StrongshotSlicePower (col 217)
+0x370 f32 StrongshotSlicePowerMax (col 218)
+0x374 f32 StrongshotSliceSpin (col 219)
+0x378 f32 StrongshotSliceSpinMax (col 220)
+0x37c f32 StrongshotSliceSidespinAdd (col 221)
+0x380 f32 StrongshotSliceSidespinAddMax (col 222)
+0x384 f32 StrongshotDropPower (col 223)
+0x388 f32 StrongshotDropPowerMax (col 224)
+0x38c f32 StrongshotDropSpin (col 225)
+0x390 f32 StrongshotDropSpinMax (col 226)
+0x394 f32 StrongshotDropSidespinAdd (col 227)
+0x398 f32 StrongshotDropSidespinAddMax (col 228)
+0x39c f32 StrongshotDropTechnique (col 229)
+0x3a0 f32 StrongshotDropTechniqueMax (col 230)
+0x3a4 f32 StrongshotLobPower (col 231)
+0x3a8 f32 StrongshotLobPowerMax (col 232)
+0x3ac f32 StrongshotLobSpin (col 233)
+0x3b0 f32 StrongshotLobSpinMax (col 234)
+0x3b4 f32 StrongshotAreaRatioTiredA (col 236)
+0x3b8 f32 StrongshotAreaRatioTiredB (col 237)
+0x3bc f32 DistLimitSnatchRatioTiredA (col 238)
+0x3c0 f32 DistLimitSnatchRatioTiredB (col 239)
+0x3c4 f32 ShotRangeAddCross (col 240)
+0x3c8 f32 DepthBureMaxSpinserve (col 241)
+0x3cc f32 DepthBureMaxSliceserve (col 242)
+0x3d0 f32 DepthBureMaxFlatserve (col 243)
+0x3d4 f32 TiredTimeAse (col 244)
+0x3d8 f32 SnatchBureMax (col 245)
+0x3dc f32 PowerRatioMin (col 246)
+0x3e0 f32 PowerRatioMax (col 247)
+0x3e4 s32 DoublesPartnerRank (col 248)
```
- Header columns never read: `DepthPlusLob`, `SlicePowerMax`, `SlicePowerMin`, `LobDistPlusMax`, `LobDistPlusForte`, `ShotTargetOffsetRatioNearZ`, `ShotTargetOffsetRatioFarZ`;
  struct words +0x1c4, +0x1c8, +0x1cc, +0x1d0, +0x1d4, +0x1d8 are never written by the loader (BSS zero unless other code sets them).
- Readers of the struct: functions referencing 0x341120: 0x9a78c, 0xa73e0, 0xa82b8, 0xa8608, 0xa8880, 0xa8de8, 0xa902c, 0xa938c, 0xa975c, 0xa9f90, 0xaa358, 0xaaae4, 0xab044, 0xc24f0, 0xc2aa0, 0x2b5780 (ball/shot physics).

## 4. data/chara/model/etc/etc_offset.csv  -- loader `FUN_000d9358(path)`

- Loader `0xd9358`; sole caller `FUN_00047054` at 0x47158 (boot). Does NOT use the CSV class: raw file read `FUN_0004cad0`, NUL-terminate, split lines with strtok on `"\n"` (`0x2c06b0`), drop lines starting with `//`, then split each line with `FUN_000d9a2c` on ",".
- Header line (first non-comment line): columns 0 and 1 (ID, Partname) skipped; from column 2 up to the first empty cell or a cell equal to "," each header cell is a **part name**, inserted into global `std::map<std::string,short>` at **0x338b18** with value = (col-2). Duplicate names call `FUN_000d9a00` (fatal) and hang.
- Data rows (lines 1..): col 0 = `atoi` -> key `short ID` (character model id); col 1 (Partname) ignored; every part column cell is a triple split with strtok on the character set at `0x2c06b4` (`5f 81 51` = "_" and SJIS full-width "_"): up to 3 numbers, each stored as `(s16)(atof(tok) * 10.0)` (0.1-unit fixed point). Missing/empty cell = `{0x7fff,0x7fff,0x7fff}` ("no offset" sentinel). If any value in the row is non-zero, the x and y components of every cell are **negated** (z unchanged) and the row is inserted into global `std::map<short, std::vector<short[3]>>` at **0x338b34**: key = ID, value = one {x,y,z} s16 triple per part column (index = part col - 2). Rows with all-zero cells are not stored.
- Query `FUN_000d9b1c(float out[3], short id, std::string partName)` (sole caller `FUN_000931ec`): looks up id in 0x338b34 and partName in 0x338b18; returns false if either is missing or the triple is the all-0x7fff sentinel; else `out[i] = triple[i] * 0.1f`. The caller builds the part key with `"head%02d"`, `"body%02d"`, `"face%02d"` (`0x2d2a7c / 0x2d2a70 / 0x2d2a88`) from part ids at +0x1b4 of the equipment/part records (tries head/body, falls back to face).
- Columns: `ID` (col 0, int key), `Partname` (col 1, label only, ignored), cols 2..72 = part names (face00..face210, body02..body198, head04..head407; 71 names, listed in table-catalog-headers.md).

## 5. data/chara/parameter/npc_voicepack.csv  -- loader `FUN_000b3cf4(obj)`

- Loader `0xb3cf4`; sole caller `FUN_00088a44` at 0x88e98 (gameplay scene init) after `FUN_000b3ca0` constructs the 0x18-byte object `_DAT_00338ab0` (two `{ptr,count,cap}` vectors at +0x00 and +0x0c, element stride **0x12**; freed in `FUN_00088388`).
- Reader: `FUN_000651b8(this,path,0,0,",")` (no header map, no label map, first line is NOT skipped: it is the first record label). Path string at `0x2d4780`.
- Format: repeating blocks of 7 rows: one label row (col 0 text, read with `FUN_0006517c(row,0)`; first label is "NPC_w00") then **6 rows x 3 int columns** (`FUN_00065104(row, col 0..2)`), stored as 18 bytes: `byte[group*3 + sub] = cell(row = label+1+group, col = sub)`, group 0..5, sub 0..2.
  Record is appended to vector #0 if the label contains substring "NPC_w" (`0x2d47ac`), else vector #1 (NPC_m). Records stay in file order (161 lines = 23 records).
- Query `FUN_000b3f20(obj, npcIdString, group, sub)`: picks vector by `strstr` "NPC_w" / "NPC_m" (`0x2d47b4`), record number = atoi of the first digit run in the string, returns `byte[number*0x12 + group*3 + sub] - 1`. Caller `FUN_000a0738` (npc id string at `*(chara+0x154)+0x2d`, sub = `*(chara+0x164)`), result used as voice-sample index (`*2 + 0xae / 0xb4 / 0xba / 0xc0`). Not an enum parser.

## 6. data/common/aityaku/aityaku.csv  -- ctor/loader `FUN_0024d808(this)`

- Loader/ctor `0x24d808` (object size **0x54**, `FUN_00000bcc(0x54)`); sole caller `FUN_00047054` at 0x47300 -> global `_DAT_0034a77c` (also stored inside the ctor). Boot. ~80 functions reference 0x34a77c.
- Reader: `FUN_000651b8(this,path,1,0,",")` (row-label map on, header map off). Rows keyed by col 0 `Label`, value in col 1 `Value` (col 2 `Help` unread). Row labels: NeedX, NeedY, GetWin0/1/2, GetLose0/1/2, GetSet1/3/5, GetSetMin1/3/5, GetB, GetK, Bonus_Boss, Bonus_Appeal (strings at 0x2fbdf8..0x2fbee4).
- After loading, `FUN_0024d908(this)` precomputes a **cumulative threshold table of 9 f32 at this+0x30 .. this+0x50** (levels 1..9): `step[i] = f(i+1+NeedX) ... + NeedY` where the helper `FUN_0000c07c(x, 2.0)` is a double pow (or mul), i.e. probably `(i+1+NeedX)^2 + NeedY` (see unresolved); `cum[0]=step[0]`, `cum[i]=cum[i-1]+step[i]`. The two debug printfs ("need point", "LV%d : %4.0f") were compiled out (`FUN_0024d8dc` is an empty stub).
- Accessors: `FUN_0024da48(this, setCount{1,3,5}, score, outcome{0..5})` = `GetWin/Lose{2,1,0}[outcome] * GetB * GetSet{n} * (GetK + score * GetSetMin{n})` (labels read per call with `FUN_000657e4(this,label,1)`); `FUN_0024dd40(float pts,this)` -> level 0..9 (scans cum[8]..cum[0]); `FUN_0024dd8c` / `FUN_0024de20` -> fractional progress inside a level (remapped to 0.1..0.9); `FUN_0024df74` / `FUN_0024df84` -> Bonus_Boss / Bonus_Appeal value.
- "aityaku" = attachment/affinity-style meter (guess).

## 7. AI parameter tables: AI_Param_%d.csv (1..3), AI_param_PC.csv, AI_param_NPC.csv  -- loader `FUN_00234898(obj, path)`

- Loader `0x234898` (container ctor `FUN_002347c4`, dtor `FUN_00234800`, 0x20-byte container). Called only from `FUN_00088a44` (gameplay-scene init): 0x88d38 (loop i=0..2, AI_Param_(i+1) -> `_DAT_0034a6a8 + i*0x20`), 0x88d88 (AI_param_PC -> `_DAT_0034a6ac`), 0x88da0 (AI_param_NPC -> `_DAT_0034a6ac + 0x20`).
- Container (0x20 bytes): element vector at +0x14 ptr / +0x18 count / +0x1c cap; element stride **0x230**, appended in row order (rows 1..n-1). Reader: `FUN_000651b8(this,path,0,1,",")`.
- Row selection at runtime:
  * AI_Param_N (difficulty tier N = byte at +0x14 of `FUN_000b3c68(chara)`, 1..3): `FUN_00215a58(chara)` = `table[N-1].elems + FUN_0020b62c(chara) * 0x230` (index = AI rank; 17 data rows; header column "Rank" is NOT read, rank = row order).
  * AI_param_PC/NPC (named characters): `FUN_00235ca4(table, name)` finds the element whose name (+4) equals the chara name; error string "AIParameter '%s' not found." at `0x2f517c`; caller 0x97694 inside `FUN_00097520`; result index stored at chara+0x160; accessor `FUN_00215a20(chara)` = `_DAT_0034a6ac[isNpc].elems + idx*0x230`.
- Per row, named reads (`FUN_000655f8` f32 / `FUN_00065554` int / `FUN_0006569c` string for list columns). ID: header "ID" (`0x2f4a68`) if present: string cell -> name copy + atoi of digits, otherwise int; no "ID" column (AI_Param_N) -> ID 0 and the name field is left as uninitialised stack bytes. Element layout (offset, width, header name, column index in AI_param_PC.csv (168 cols); AI_Param_N has the same names, found by name):

```
+0x000 s32 ID (digits of ID/Label cell; 0 if no ID column)
+0x004 char[16] name = full ID cell text
+0x014 f32 MoveForecast (PC col 3)
+0x018 f32 MoveForecastSkill (PC col 4)
+0x01c f32 MoveTimeCurve (PC col 5)
+0x020 s16 MoveTimeFast (PC col 6)
+0x022 s16 MoveTimeLate (PC col 7)
+0x024 f32 MoveTimeCurveLob (PC col 11)
+0x028 s16 MoveTimeFastLob (PC col 12)
+0x02a s16 MoveTimeLateLob (PC col 13)
+0x02c f32 MoveTimeCurveDrop (PC col 17)
+0x030 s16 MoveTimeFastDrop (PC col 18)
+0x032 s16 MoveTimeLateDrop (PC col 19)
+0x034 f32 MoveTimeCurveNet (PC col 8)
+0x038 s16 MoveTimeFastNet (PC col 9)
+0x03a s16 MoveTimeLateNet (PC col 10)
+0x03c f32 MoveTimeCurveLobNet (PC col 14)
+0x040 s16 MoveTimeFastLobNet (PC col 15)
+0x042 s16 MoveTimeLateLobNet (PC col 16)
+0x044 f32 MoveTimeCurveDropNet (PC col 20)
+0x048 s16 MoveTimeFastDropNet (PC col 21)
+0x04a s16 MoveTimeLateDropNet (PC col 22)
+0x04c s16 MoveGood (PC col 23)
+0x04e s16 MoveBad (PC col 24)
+0x050 f32 MoveSmash (PC col 25)
+0x054 s32 MoveForeAdjust (PC col 26)
+0x058 f32 MoveError (PC col 27)
+0x05c f32 MoveErrorSmash (PC col 28)
+0x060 s16 MoveAdvance (PC col 29)
+0x062 s16 MoveKeep (PC col 30)
+0x064 s16 MoveServiceline (PC col 31)
+0x066 s16 MoveBaseline (PC col 32)
+0x068 s16 MoveShort (PC col 33)
+0x06a s16 MoveFore (PC col 34)
+0x06c s16 MoveGoodHeight (PC col 35)
+0x06e s16 MoveHigh (PC col 36)
+0x070 s16 MoveStrongshot (PC col 37)
+0x074 f32 MoveCertainshotId1 (PC col 38)
+0x078 f32 MoveCertainshotFrequency1 (PC col 39)
+0x07c f32 MoveCertainshotId2 (PC col 40)
+0x080 f32 MoveCertainshotFrequency2 (PC col 41)
+0x084 f32 MoveOutshot (PC col 42)
+0x088 s32 MoveOutshotReaction (PC col 43)
+0x08c f32 MoveSidespinForecast (PC col 44)
+0x090 f32 MoveSidespinReaction (PC col 45)
+0x094 s32 MovePursuePattern (PC col 46)
+0x098 f32 ShotSituation (PC col 47)
+0x09c f32 ShotAimTimingMin (PC col 48)
+0x0a0 f32 ShotAimTimingMax (PC col 49)
+0x0a4 f32 ShotAccuracy (PC col 50)
+0x0a8 s16 ShotWidth (PC col 51)
+0x0aa s16 ShotWidthNet (PC col 52)
+0x0ac s16 ShotTimingError (PC col 53)
+0x0ae s16 ShotTimingErrorNet (PC col 54)
+0x0b0 f32 ShotSwingmissMin (PC col 55)
+0x0b4 f32 ShotSwingmissMax (PC col 56)
+0x0b8 f32 ShotSwingmissMaxP (PC col 57)
+0x0bc u8  ShotMissA (PC col 58)
+0x0bd u8  ShotMissB (PC col 59)
+0x0be u8  ShotMissC (PC col 60)
+0x0bf u8  ShotMissD (PC col 61)
+0x0c0 u8  ShotMissE (PC col 62)
+0x0c1 u8  ShotMissF (PC col 63)
+0x0c2 u8  ShotMissG (PC col 64)
+0x0c3 u8  ShotMissH (PC col 65)
+0x0c4 vec<s16>{ptr,count,cap} ShotVariationAdd (PC col 81)
+0x0d0 vec<s16>{ptr,count,cap} ShotVariationDel (PC col 82)
+0x0dc vec<s16>{ptr,count,cap} ShotDepthAdd (PC col 83)
+0x0e8 vec<s16>{ptr,count,cap} ShotDepthDel (PC col 84)
+0x0f4 vec<s16>{ptr,count,cap} ShotWidthAdd (PC col 85)
+0x100 vec<s16>{ptr,count,cap} ShotWidthDel (PC col 86)
+0x10c u8  ShotPattern1 (PC col 66)
+0x10d u8  ShotPattern2 (PC col 67)
+0x10e u8  ShotPattern3 (PC col 68)
+0x10f u8  ShotPattern4 (PC col 69)
+0x110 u8  ShotPattern5 (PC col 70)
+0x111 u8  ShotPattern6 (PC col 71)
+0x112 u8  ShotPattern7 (PC col 72)
+0x113 u8  ShotPattern8 (PC col 73)
+0x114 u8  ShotPattern9 (PC col 74)
+0x115 u8  ShotPattern10 (PC col 75)
+0x116 u8  ShotPattern11 (PC col 76)
+0x117 u8  ShotPattern12 (PC col 77)
+0x118 u8  ShotPattern13 (PC col 78)
+0x119 u8  ShotPattern14 (PC col 79)
+0x11a u8  ShotPattern15 (PC col 80)
+0x11c f32 ReturnTiming (PC col 87)
+0x120 f32 ReturnTimingNet (PC col 88)
+0x124 f32 ReturnError (PC col 89)
+0x128 f32 ReturnStop (PC col 90)
+0x12c f32 ReturnWait (PC col 91)
+0x130 f32 ReturnFront (PC col 92)
+0x134 f32 ReturnCenter (PC col 93)
+0x138 f32 ReturnBest (PC col 94)
+0x13c f32 ReturnBackward (PC col 95)
+0x140 f32 ReturnNetdashAll (PC col 96)
+0x144 f32 ReturnNetdashSlice (PC col 97)
+0x148 f32 ReturnNetdashSnatch (PC col 98)
+0x14c f32 ReturnNetdashTime (PC col 99)
+0x150 f32 ReturnNetdashServe (PC col 100)
+0x154 f32 ReturnNetdashReceive (PC col 101)
+0x158 u8  ReturnBias (PC col 102)
+0x159 u8  ReturnLimitedshot (PC col 103)
+0x15c f32 ServeCare (PC col 105)
+0x160 f32 ServeFirstCircle (PC col 106)
+0x164 f32 ServeFirstCross (PC col 107)
+0x168 f32 ServeFirstTriangle (PC col 108)
+0x16c f32 ServeFirstCenter (PC col 109)
+0x170 f32 ServeFirstMiddle (PC col 110)
+0x174 f32 ServeFirstSide (PC col 111)
+0x178 f32 ServeFirstCenterAim (PC col 112)
+0x17c f32 ServeFirstMiddleAim (PC col 113)
+0x180 f32 ServeFirstSideAim (PC col 114)
+0x184 f32 ServeFirstLevel (PC col 115)
+0x188 f32 ServeFirstAccuracy (PC col 116)
+0x18c f32 ServeFirstQuick (PC col 117)
+0x190 f32 ServeSecondCircle (PC col 119)
+0x194 f32 ServeSecondCross (PC col 120)
+0x198 f32 ServeSecondTriangle (PC col 121)
+0x19c f32 ServeSecondCenter (PC col 122)
+0x1a0 f32 ServeSecondMiddle (PC col 123)
+0x1a4 f32 ServeSecondSide (PC col 124)
+0x1a8 f32 ServeSecondCenterAim (PC col 125)
+0x1ac f32 ServeSecondMiddleAim (PC col 126)
+0x1b0 f32 ServeSecondSideAim (PC col 127)
+0x1b4 f32 ServeSecondLevel (PC col 128)
+0x1b8 f32 ServeSecondAccuracy (PC col 129)
+0x1bc f32 ServeSecondQuick (PC col 130)
+0x1c0 f32 ServeReceiveForecast (PC col 132)
+0x1c4 f32 ServeReceiveForecastSkill (PC col 133)
+0x1c8 f32 ServeReceiveTimeCurve (PC col 134)
+0x1cc f32 ServeReceiveTimeFast (PC col 135)
+0x1d0 f32 ServeReceiveTimeLate (PC col 136)
+0x1d4 f32 ServeReceiveError (PC col 137)
+0x1d8 f32 ServeReceivePositionFirst (PC col 138)
+0x1dc f32 ServeReceiveAdjustFirst (PC col 139)
+0x1e0 f32 ServeReceivePositionSecond (PC col 140)
+0x1e4 f32 ServeReceiveAdjustSecond (PC col 141)
+0x1e8 u8  ServeReceiveDash (PC col 142)
+0x1ec f32 DoublesJudgmentA (PC col 143)
+0x1f0 f32 DoublesJudgmentB (PC col 144)
+0x1f4 f32 DoublesJudgmentC (PC col 145)
+0x1f8 f32 DoublesMoveTimeCurve (PC col 146)
+0x1fc f32 DoublesMoveTimeFast (PC col 147)
+0x200 f32 DoublesMoveTimeLate (PC col 148)
+0x204 f32 DoublesMoveError (PC col 149)
+0x208 f32 DoublesTheoryRate (PC col 150)
+0x20c f32 DoublesFreeShot (PC col 151)
+0x210 f32 DoublesReturnTiming (PC col 152)
+0x214 f32 DoublesReturnTimingNet (PC col 153)
+0x218 f32 DoublesReturnError (PC col 154)
+0x21c f32 DoublesSnatch (PC col 155)
+0x220 f32 DoublesFrameshot (PC col 156)
+0x224 u8  DoublesCircle (PC col 159)
+0x225 u8  DoublesCross (PC col 160)
+0x226 u8  DoublesTriangle (PC col 161)
+0x227 u8  DoublesFront (PC col 162)
+0x228 u8  DoublesHalf (PC col 163)
+0x229 u8  DoublesBackward (PC col 164)
+0x22a u8  DoublesLeft (PC col 165)
+0x22b u8  DoublesCenter (PC col 166)
+0x22c u8  DoublesRight (PC col 167)
```
- Generated names: `MoveTime{Curve,Fast,Late}` + suffix from the pointer table at `0x2f4994` = "", "Lob", "Drop", "Net", "LobNet", "DropNet" (format `MoveTimeCurve%s` etc. at `0x2f4a90`); `Serve{First,Second}{Circle,Cross,Triangle,Center,Middle,Side,CenterAim,MiddleAim,SideAim,Level,Accuracy,Quick}` (format `Serve%s%s` at `0x2f4ea4`; tables at `0x2f49bc` / `0x2f4a34`); `ShotPattern%d` (`0x2f4d70`), d=1..15 (u8 each).
- The six `Shot{Variation,Depth,Width}{Add,Del}` columns are text lists split with strtok on "_" (`0x2c9ee4`) into `vector<s16>` ({ptr,count,cap}, 12 bytes each, tokens via atoi); order of the six vectors from the pointer table `0x2f4958`; consumed by `FUN_0020ea40` (+0xc4+0x18k = Add, +0xd0+0x18k = Del for k = Variation, Depth, Width).
- The Doubles block (+0x1ec..+0x22c) is read **only if the path contains "AI_param_PC" or "AI_param_NPC"** (case-sensitive `strstr`; the `AI_Param_%d` files skip it, leaving those element bytes uninitialised).
- Header columns never read: `Rank`, `Playstyle`, `ReturnSnatchCancel`, `ServeFirstTec`, `ServeSecondTec`, `DoublesDefensive`, `DoublesIformation` (that last name is a typo in the csv header too). (`ID` is read as the id/name.) AI_Param_N also has one empty-named trailing header cell.

## 8. AI_Shot.csv, AI_Param_Doubles.csv, AI_Shot_Doubles.csv

All three from `FUN_00088a44` (gameplay-scene init); named-column reader `FUN_000651b8(this,path,0,1,",")`, rows 1..n-1.

### 8a. data/common/parameter/AI_Shot.csv -- `FUN_00235da4(obj)` (0x235da4; call at 0x88cd8)
- `_DAT_0034a6b0` object = 3 vectors `{ptr,count,cap}` (0x24 bytes, cleared by `FUN_0008b198` at loader start). Element stride **0xc** = 6 x s16. Each row goes to vector `[ShotAINo / 100]` (ShotAINo 0xx/1xx/2xx -> vectors 0..2; 300 data rows).

| off | type | header name |
|---|---|---|
| +0x00 | s16 | ShotAINo |
| +0x02 | s16 | ShotSituationLimit |
| +0x04 | s16 | ShotAllRank |
| +0x06 | s16 | ShotBaseRank |
| +0x08 | s16 | ShotNetRank |
| +0x0a | s16 | ShotFrequency |

(csv order is ShotAINo, ShotSituationLimit, ShotNetRank, ShotAllRank, ShotBaseRank, ShotFrequency; irrelevant since read by name.) Consumer `FUN_0020ea40` (iterates the 3 vectors through `FUN_0020ebb0`).

### 8b. data/common/parameter/AI_Param_Doubles.csv -- `FUN_00235ff4(vec)` (0x235ff4; call at 0x88dd8)
- `_DAT_0034a6b4` = one vector `{ptr,count,cap}`, element stride **0x48**, row order = rank (accessor `FUN_00215ab8(chara)` = `vec.ptr + FUN_0020b62c(chara)*0x48`).

```
+0x00 s32 Rank                  (int; header "Rank", string at 0x2f5240)
+0x04 f32 DoublesJudgmentA      +0x08 f32 DoublesJudgmentB       +0x0c f32 DoublesJudgmentC
+0x10 f32 DoublesMoveTimeCurve  +0x14 f32 DoublesMoveTimeFast    +0x18 f32 DoublesMoveTimeLate
+0x1c f32 DoublesMoveError      +0x20 f32 DoublesTheoryRate      +0x24 f32 DoublesFreeShot
+0x28 f32 DoublesReturnTiming   +0x2c f32 DoublesReturnTimingNet +0x30 f32 DoublesReturnError
+0x34 f32 DoublesSnatch         +0x38 f32 DoublesFrameshot
+0x3c u8 DoublesCircle  +0x3d u8 DoublesCross  +0x3e u8 DoublesTriangle  +0x3f u8 DoublesFront
+0x40 u8 DoublesHalf    +0x41 u8 DoublesBackward  +0x42 u8 DoublesLeft  +0x43 u8 DoublesCenter  +0x44 u8 DoublesRight
(+0x45..0x47 zero padding; element is memset to 0 before filling)
```
Header columns never read: `DoublesDefensive`, `DoublesIformation`. Same field names/semantics as the Doubles block at +0x1ec of the AI param element.

### 8c. data/common/parameter/AI_Shot_Doubles.csv -- `FUN_0023650c(vec)` (0x23650c; call at 0x88e10)
- `_DAT_0034a6b8` = one vector, element stride **0x1c** = 7 x s32, row order, 163 data rows.
`+0x00 DoublesShotAINo, +0x04 DoublesFormationA, +0x08 DoublesFormationB, +0x0c DoublesShotCharacter, +0x10 DoublesShotAim, +0x14 DoublesShotButton, +0x18 DoublesShotFrequency` (all `FUN_00065554` int by header name; csv has exactly these 7 columns in this order). Consumer: `FUN_00211270`.

## 9. data/chara/parameter/PCGut_PcGut.txt, PCGut_NpcGut.txt  -- loader `FUN_0027dcec(vec, path)`

- Loader `0x27dcec` (vector ctor `FUN_0027dcd8`, dtor `FUN_00088774`); called from `FUN_00088a44` at 0x88e5c / 0x88e6c (gameplay-scene init): `_DAT_0034a7e8` = array of 2 `{ptr,count,cap}` vectors; [0] = PcGut, [1] = NpcGut (+0xc).
- Reader: the CSV class used purely positionally: `FUN_000651b8(this,path,0,0,TAB 0x2fe780)`; **no header line** (line 0 is data). The table is stored **transposed**: R = `FUN_000650e0` rows (24 for PcGut, 20 for NpcGut), C = `FUN_000650e8(this,0)` columns (75 / 115). Record count = C/5 (15 PC, 23 NPC). Each record consumes 5 consecutive columns; element stride **0x68**:
  * `byte[g*20 + r] = int cell(row=r, col = rec*5 + g)` for g = 0..4, r = 0..19 -> bytes +0x00..+0x63
  * if R == 0x18 (PcGut only): `byte[0x64 + k] = int cell(row = 0x14+k, col = rec*5 + 4)` for k = 0..3 -> +0x64..+0x67. In NpcGut those 4 bytes stay 0.
- Query `FUN_000b2f0c(chara)` (caller 0xa0738) = `vec[isNpc].ptr + idx*0x68`, `idx` = chara id (s16 at `*(chara+0x154)`) for PCs, or the short at `0x34180e + *(chara+0x148)*0x120` for NPCs (isNpc = signed nibble at +0x62 of the record from `FUN_000d8c24`). `FUN_000b2fc0(chara, shotId)` (caller 0xb270c) maps ids 0x9e..0xdf-ish (long if-chain; 24 classes 0..0x17) to a class and returns `byte[0x50 + class]` of the record, i.e. group g=4 (20 bytes) followed by the 4 extra bytes: one byte per shot class (24 classes = the 24 PcGut rows). Groups g=0..3 (+0x00..+0x4f) are read elsewhere (not traced).
- "Gut" meaning unknown (guess: per-character, per-shot-class "guts"/gut-string modifiers). No column names (no header).

## 10. data/common/rule/Rule_Iromono.txt  -- two independent users

(13 per-archive copies; TAB separated, 20 data lines, 4 columns, no header.)

### 10a. Ad-hoc room scenes: `FUN_00253630(obj)` (0x253630)
- Callers: `FUN_0025c474` at 0x25c4f4 (ctor of the "ad_hoc_02" menu scene; obj = scene+0x18c) and `FUN_0025de54` at 0x25deb4 (second ad-hoc scene; callers 0x2638d8, 0x26bc68). Menu time.
- Plain reader `FUN_00064bf4(this, path, 0 /*no header skip*/, TAB 0x2fcc70)`; for every row r: if `int cell(r,3) != 0` then `obj[7 + obj[6]++] = r`. Result: `obj[0]` = selected-rule bitset (init 0), `obj[6]` = count, `obj[7..]` = list of enabled row indices (col 3 = "enabled in ad-hoc" flag, GUESS). Consumed by `FUN_002536f0` (popcount/bitset UI of up to 32 chosen rules).

### 10b. "lastconfirm" menu scene: `FUN_001a0148(scene)` (0x1a0148; sole caller `FUN_001a1828` <- `FUN_001a4c1c`)
- `FUN_000651b8(scene+0x450, path, 1, 0, TAB 0x2e1cb8)` (row-label map on, no header map), then `FUN_001a13a0` (0x1a13a0): for rows 0..19 (`iVar8-1`, iVar8 = 1..0x14) `if (int cell(row,2) > 0)` the rule is listed; entries are grouped 3 per page (`idx/3`, `idx%3`) into the page list at scene+0x390.
- So col 3 (ad-hoc) and col 2 (lastconfirm) act as boolean availability flags in two menus; cols 0 and 1 are not read by the code I saw.

---

## Proposed names

| address | proposed name |
|---|---|
| `FUN_00047054` | `LoadCommonParameterTables` (boot init) |
| `FUN_000468c8` | `BootInit` / `AppInitMain` |
| `FUN_00160998` | `LoadCommonParam` (common.csv -> global `g_CommonParam` @0x341120, struct `CommonParam`, size 0x3e8) |
| `_DAT_00341514` | `g_CommonParamId` |
| `FUN_00162338` | `LoadCharacterParamCsv` (struct `CharacterParam`, stride 0x22c; used for character.csv, NPC_Param.csv, Racket_param.csv) |
| `_DAT_00341508` | `g_CharacterParamTables[2]` ([0]=PC, [1]=NPC), `_DAT_0034150c` = `g_RacketParamTable` |
| `FUN_00165004` | `FindCharacterParamIndexByName` |
| `FUN_001607a4` | `LoadGradeParam` (`_DAT_00341510` = `g_GradeTable`, struct `GradeRow` {Power,Technique,Speed,Stamina,Impact} f32) |
| `FUN_000d9358` | `LoadEtcOffsetTable`; `FUN_000d9b1c` = `GetEtcPartOffset(out xyz, charaModelId, partName)`; maps `0x338b18` `g_EtcPartNameToCol`, `0x338b34` `g_EtcOffsetsByChara` |
| `FUN_000b3cf4` | `LoadNpcVoicePack`; `FUN_000b3f20` = `GetNpcVoicePackIndex`; `_DAT_00338ab0` = `g_NpcVoicePack` |
| `FUN_0024d808` | `AityakuTable::AityakuTable` (ctor loads aityaku.csv); `FUN_0024d908` = `BuildNeedPointTable`; `FUN_0024da48` = `CalcAityakuGain`; `FUN_0024dd40` = `GetAityakuLevel`; `_DAT_0034a77c` = `g_Aityaku` |
| `FUN_00088a44` | `GameScene_StateMachine` (state 0 = load AI tables) |
| `FUN_00234898` | `LoadAiParamCsv` (struct `AiParam`, stride 0x230); `FUN_00235ca4` = `FindAiParamIndexByName`; `FUN_00215a58` = `GetAiParamByRank`; `FUN_00215a20` = `GetAiParamForChara` |
| `_DAT_0034a6a8` / `_DAT_0034a6ac` | `g_AiParamRankTables[3]` / `g_AiParamCharaTables[2]` ([0]=PC,[1]=NPC) |
| `FUN_00235da4` | `LoadAiShotTable` (`_DAT_0034a6b0`; `AiShotRow` {ShotAINo,ShotSituationLimit,ShotAllRank,ShotBaseRank,ShotNetRank,ShotFrequency}, 3 vectors by ShotAINo/100) |
| `FUN_00235ff4` | `LoadAiParamDoubles` (`_DAT_0034a6b4`; `AiParamDoublesRow` 0x48) |
| `FUN_0023650c` | `LoadAiShotDoubles` (`_DAT_0034a6b8`; `AiShotDoublesRow` 0x1c) |
| `FUN_0027dcec` | `LoadGutTable` (`_DAT_0034a7e8`; `GutRecord` 0x68 bytes); `FUN_000b2f0c` = `GetGutRecord`; `FUN_000b2fc0` = `GetGutByteForShot` |
| `FUN_00253630` | `IromonoRuleList::IromonoRuleList` (ad-hoc); `FUN_001a0148` = `LastConfirmScene_Init`; `FUN_001a13a0` = `LastConfirm_BuildIromonoPages` |
| `FUN_000651b8` | `NamedCsv::Load`; `FUN_00065364` `FindColumn`; `FUN_000655f8` `GetFloatByName`; `FUN_00065554` `GetIntByName`; `FUN_0006569c` `GetStringByName`; `FUN_000657e4` `GetFloatByRowLabel` |

Field names: use the CSV header names verbatim (see listings), e.g. `CharacterParam::ManualTargetUnitX`, `CommonParam::ShotDistBase`, `AiParam::MoveTimeCurveLob`.

## Unresolved / guesses

1. `FUN_0024d908` step formula: pseudocode shows a double op (`FUN_0000c07c` with arg 2.0) then an add; I believe `(i+1+NeedX)^2 + NeedY` accumulated into this+0x30.., but did not verify the helper (pow vs mul).
2. PCGut/NpcGut: gameplay meaning of the 5 x 20 (+4) bytes; only indexing (character x shot class) and accessor `FUN_000b2fc0` known; consumers of groups 0..3 not found.
3. `Rule_Iromono.txt` column meanings (cols 0,1 not seen read); which per-archive copy each scene gets is not mapped.
4. AI_Param_1..3: `name` (+4) and the Doubles block are uninitialised stack data in the element; harmless only if never read.
5. common.csv struct words +0x1c4..+0x1d8 are never written by the loader; other code may set them (not searched).
6. etc_offset: the 71 part-column names and consumers other than `FUN_000931ec` not traced.
7. Counts "15 PC / 206 NPC rows" etc. come from file line counts in the catalog (header excluded), not from code.
