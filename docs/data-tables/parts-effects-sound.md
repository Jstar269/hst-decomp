# g2-parts-misc: loader analysis (private; no cell values recorded)

All addresses are module-relative vaddrs in the retail EBOOT (selected.elf). Pseudocode: ghidra EBOOT_BIN-p2.

## 0. Reader-class variants found (extends HOWTO)

The CSV/TXT reader (ctor FUN_000649c0, vtable 0x3070cc) has a second flavour used by most of this group:

- Header-aware reader = same object with vtable `0x3070bc` (object size 0x30: `piVar[0]=0x3070bc`, `FUN_0008c230(this+0x10)`, `FUN_0008c230(this+0x20)` init two std::map-like trees; this+0x10 = rowName map, this+0x20 = columnName map). Dtor/free is the same FUN_00064a08 (vfunc slot 2, `(**(vtbl+8))(this,1)`).
- Loader wrapper `FUN_000651b8(this, path, buildRowNameMap, buildColNameMap, delimiterStr)`:
  calls FUN_00064bf4(this, path, skipHeader=**0**, delim) (header line is KEPT as row 0; data row r is index r, 1-based),
  then if arg3 != 0 fills the map at this+0x10 with {cell(row,0) string -> row index} for all rows,
  if arg4 != 0 fills the map at this+0x20 with {cell(0,c) string -> column index} from the header row.
- Name-keyed getters (all `(reader, row, name)` unless noted; missing name/row yields 0):
  - FUN_00065364(reader, colName) -> column index or -1
  - FUN_00065554(reader, row, colName) -> int (cell vfunc +0xc)
  - FUN_000655f8(reader, row, colName) -> float (cell vfunc +0x10)
  - FUN_0006569c(reader, row, colName) -> c-string (cell vfunc +0x14)
  - FUN_00065740(reader, rowName, col) -> int; FUN_000657e4(reader, rowName, col) -> float (row looked up via the this+0x10 map, col by index)
  - Parts wrappers: FUN_000d8b3c(reader,row,colName) = int (col idx via FUN_00065364, then FUN_00065104; 0 when column absent), FUN_000d8b9c = float variant (FUN_00065140).
- Index getters unchanged: FUN_00065104 int, FUN_00065140 float, FUN_0006517c string; FUN_000650e0 = row count (including header row when skipHeader=0); FUN_000650e8(reader,row) = column count of that row.

Status summary: 20 table files, **all 20 resolved** (Parts_Face/Head/Body/Acce/Racket share one parser; Particle texlist/motlist x3 share one loader), 0 unresolved. No debug-only gating found for any of them.

---

## 1. Parts_Face / Parts_Head / Parts_Body / Parts_Acce / Racket_Racket_param (data/chara/parameter/*.txt)

| item | value |
|---|---|
| Loader | **FUN_000d84e0(partsDb)** (1584 bytes), 5 iterations of one parse body, one per table |
| Caller | FUN_00047054 (boot/game init, itself called from startup FUN_000468c8): `partsDb = FUN_000d83b8(alloc(0x4c))`, `DAT_00338b08 = partsDb`, then `FUN_000d84e0(partsDb)` |
| When | boot, once |
| Path/kind table | 5 x {int kind, char* path} (8-byte stride) at **0x2c066c**: kind 0 -> Face (ptr 0x2d68dc), 1 -> Head (0x2d6900), 2 -> Body (0x2d6924), 3 -> Acce (0x2d6948), **5** -> Racket_Racket_param (0x2d696c). (Kind 4 has no file; see lookup below.) The array is read as `local_94 = &DAT_002c066c; kind=*p; path=p[1]; p+=2` (lui 0x2c + 0x66c at 0xd850c) |
| Reader | header-aware reader (vtbl 0x3070bc) on stack; `FUN_000651b8(rdr, path, 0, 1, "\t"=0x2d69d8)`; columns fetched by header NAME. Tab separated, UTF-8 BOM handled by the reader. Header is row 0, data rows 1..n |
| Destination | `DAT_00338b08` = PartsDb object (size 0x4c). Layout: +0 vtbl 0x3075e0; +4 .. +0x4c = **6 vectors** of 12 bytes {data*, size, cap} (array ctor FUN_000007f4(this+4, FUN_000d8460 ctor, FUN_000d8408 dtor, elemsize 0xc, count 6)). Vector for kind k is at `partsDb + 4 + k*0xc` (data at +4+k*0xc, size at +8+k*0xc). Element = pointer to a row record (calloc 0x6c via FUN_00000bcc, vtbl 0x3075ec at +0, zero-filled by FUN_000114c0). |
| Row index | `atoi(last 3 chars of "Label")` (FUN_0000d62c = strtol base 10 on `label + strlen - 3`); labels look like `Face_000`, `Head_001` ... i.e. `<Kind>_<NNN>`. Gaps are allowed (null pointers). Vector is pre-sized to 0x280 (640) null entries (FUN_000d8d4c) and later trimmed to `maxIndex+1` (FUN_000d8c98 grows / size field decremented). There is NO bounds check against 640 in the loader (max seen index is 602) |
| Lookup | `FUN_000d8c24(partsDb, kind, idx)`: kind 4 is remapped to 3 (second accessory slot shares the Acce table), returns NULL if idx<0, idx>=size, entry null, or `rec[0x60]==0xFF` (Get column = 0xFF means empty/unused). 40 functions call it |

### Row record (stride 0x6c, "PartsRow")

| CSV column | getter | dest offset | width / bits | note |
|---|---|---|---|---|
| Label | string (FUN_0006569c) | (row index only) | - | `atoi(label[-3:])` |
| EXP | int | +0x5e | s16 | |
| Get | int | +0x60 | s8 | default 0xFF set before parse; 0xFF = row disabled in lookup |
| Price | int | +0x58 | s16 | |
| No | int | +0x5a | s16 | |
| Type | int | +0x62 | bits 0-3 (lo nibble) | consumers test `(s8)rec[0x62] << 28 >> 28` == 0 for "type 0" |
| Face | int | +0x62 | bits 4-7 (hi nibble) | |
| Site | int | +0x63 | bits 0-5 of byte | |
| Lim | int | +0x64 | bits 0-3 | |
| Motion | int | +0x64 | bits 4-7 | |
| GetLobby | int | +0x5c | s16 | |
| GetPer | int | +0x61 | s8 | |
| Sharing | int | +0x65 | bits 0-1 | |
| ShopFlag | int | +0x65 | bits 2-3 | |
| RX | int | +0x54 (u32) | bits 0-8 | 9-bit |
| RY | int | +0x54 (u32) | bits 9-17 | 9-bit |
| RZ | int | +0x54 (u32) | bits 18-26 | 9-bit (written through u16 at +0x56, bits 2-10) |
| POW_n,TEC_n,SPE_n,STA_n,IMP_n (n=0..3) | **float** (FUN_000d8b9c), name built with `"%s_%d"` format strings `POW_%d` `TEC_%d` `SPE_%d` `STA_%d` `IMP_%d` (name table 0x2d69c4: 0x2d699c,0x2d69a4,0x2d69ac,0x2d69b4,0x2d69bc) | +0x04 + (n*5 + k)*4, k = POW0,TEC1,SPE2,STA3,IMP4 | f32 x 20 (+0x04..+0x53) | stat boost per P-level n; consumer FUN_000d7eb8 sums them |
| PC_SEX | int | +0x65 | bits 4-7 | |
| PC_TYPE | int | +0x66 | bits 0-3 | |
| PC_ONLY_1/2/3 | int (`PC_ONLY_%d`, 0x2d6a64) | +0x67,+0x68,+0x69 | u8 each | character ids the part is restricted to (consumer compares to char id) |

Columns present in the file header but **never read by this loader**: SE, GLNo, P_Max, Forte, SUM_0..SUM_3 (no EBOOT string "SE"/"GLNo"/"P_Max" exists; "Forte" only inside unrelated strings). Untouched record bytes +0x6a..0x6b are padding.
Face (10 cols) and Racket (7 cols: Label, Get, Price, No, GetLobby, GetPer, Sharing) simply lack the other names, which resolve to 0 (FUN_000d8b3c returns 0 for a missing column), so e.g. Racket rows keep all stats 0.
Header-string addresses: Label 0x2d69e0, EXP 0x2d69e8, Get 0x2d69ec, Price 0x2d69f0, No 0x2d69f8, Type 0x2d69fc, Face 0x2d6a04, Site 0x2d6a0c, Lim 0x2d6a14, Motion 0x2d6a18, GetLobby 0x2d6a20, GetPer 0x2d6a2c, Sharing 0x2d6a34, ShopFlag 0x2d6a3c, RX 0x2d6a48, RY 0x2d6a4c, RZ 0x2d6a50, PC_SEX 0x2d6a54, PC_TYPE 0x2d6a5c.

Other notes: FUN_000d9220 / FUN_000d92bc / FUN_000d8d4c / FUN_000d8c98 / FUN_000d9064 / FUN_000d9148 are std::vector<T*> helpers (alloc `n<<2`, fill, resize); FUN_000d8b10 is an empty exception-path stub. FUN_00082f14, FUN_000cb5dc, FUN_0018f238 (listed in the brief) are NOT loaders: they are consumers touching neighbouring constants (DAT_002c065c..0x2c0668 = list {1,2,3,4} of part kinds iterated by FUN_000d7eb8 and others).

---

## 2. data/common/parts/Parts_P_Set.txt (loader FUN_00195b08)

| item | value |
|---|---|
| Loader | **FUN_00195b08()** (idempotent: runs only if `DAT_0034174c == 0`) |
| Caller / when | FUN_00047054, boot, once |
| Reader | alloc 0x30, header-aware reader vtbl 0x3070bc, `FUN_000651b8(rdr, path, 0, 0, "\t"(0x2e15d4))`: no name maps; header kept as row 0 |
| Destination | **`DAT_0034174c`** = the reader object itself, kept resident; rows are read lazily as raw strings |
| Columns | 5: Set (col 0, row label, unused by code), Item_1..Item_4 (cols 1..4) = strings of form `Head_NNN` / `Body_NNN` / `Acce_NNN` |
| Consumers | FUN_001bfa44(save, setIdx, value): for each of the 4 item columns (`FUN_0006517c(rdr, setIdx+1, c+1)`), matches prefix "Head"(0x2e9fec)/"Body"(0x2e9ff4)/"Acce"(0x2e9ffc), `atoi(str+5)`, and writes byte `value` into per-save arrays `save+0x84c+idx` (Head), `save+0xacc+idx` (Body), `save+0xd4c+idx` (Acce), idx < 0x280. FUN_001bfbe8(save, setIdx) returns 1 only if all 4 items have state 4 or 5 (`uVar5-4 < 2`) = "set complete"; also referenced by FUN_001bfdd0, FUN_001f6bec, FUN_0022bfcc |
| Row index | set number s (0-based) = data row s+1; bound by FUN_000650e0 |

---

## 3. data/common/parts/Parts_P_Param.txt (loader FUN_002af6ec)

| item | value |
|---|---|
| Loader | **FUN_002af6ec(tbl)**; wrapper FUN_002af8f4 (`if (DAT_0034b5d4) FUN_002af6ec(DAT_0034b5d4)`) |
| Caller / when | FUN_00047054 boot: allocs `DAT_0034b5d4 = malloc(0x348)` and zero-inits, then FUN_002af8f4 |
| Reader | transient (alloc 0x30, vtbl 0x3070bc), `FUN_000651b8(rdr, path, 0, 1, "\t"=0x302e08)`; freed with vfunc 2 after parsing. Column-name map is built |
| Fixed rows | 30 (0x1e), loop i=0..29 reads data row i+1 (the `Lv` column is not read: level = row order) |
| Destination `DAT_0034b5d4` (0x348 bytes) | +0x00 .. +0xEF: 30 entries x 8 bytes; +0xF0 .. +0x347: 30 x 5 floats (0x14 stride) cumulative sums |

| col | getter | dest | meaning |
|---|---|---|---|
| Param | int (FUN_00065554) | entry[i] u32 bits 0-3 (only values 0..3 are stored, anything else leaves 0) | which stat slot (0..3) the level bonus goes to (guess: POW/TEC/SPE/STA order; array of sums has 5 slots) |
| Value | float (FUN_000655f8) stored raw bits | entry[i]+4, f32 | bonus amount |
| EXP | float getter converted to int (`(int)f << 4`) | entry[i] u32 bits 4-31 | exp needed for level i+1 (guess) |
| Lv, PER | not read | - | |

Cumulative table: FUN_002afaf8(out[5], level) sums `Value` into `out[Param]` for entries 0..level; FUN_002af6ec stores the result for level 0..29 at `tbl + 0xF0 + level*0x14` (words 0x3c..0x40 of each). Header strings: Param 0x302e0c, Value 0x302e14, EXP 0x302e1c.

---

## 4. data/sound/resvol.csv and movievol.csv (loader FUN_001b1810)

| item | value |
|---|---|
| Loader | **FUN_001b1810()** |
| Caller / when | FUN_001b2380(soundSys=0x34179c): first `FUN_001b0ef8(*soundSys, 0x58, ...)` then FUN_001b1810; FUN_001b2380 called from FUN_00047054 at boot |
| Reader | header-aware reader on stack, delimiter "," (0x2e983c), `FUN_000651b8(rdr, path, 0, 1, ",")` for each file (resvol path 0x2e9824, movievol 0x2e98bc) |
| resvol destination | **float volume[0x1da (474)] at 0x2e515c** (data segment, preset to 1.0f = 0x3f800000) ; end 0x2e58c4 |
| resvol match | for each data row, `filename` (FUN_0006569c by name "filename" 0x2e9840) is strcmp'ed (FUN_00014934) against the 474-entry sound-resource name pointer array `PTR_s_BGM_bgm_title_sgh_002c5a34` (name[0] = BGM/bgm_title.sgh ... name[473]); on match `volume[i] = FUN_000655f8(rdr,row,"volume" 0x2e984c)` (float, stored raw). Every matching entry is updated (duplicates allowed). Rows whose name matches nothing are ignored |
| movievol destination | **float movieVolume[4] at 0x2e58c4** (preset 1.0f). Row order is positional: data row r (1..4) -> `movieVolume[r-1]`; the filename is read but ignored; a 5th row terminates parse (`iVar8-1 > 3` break) |
| Columns | both: filename (string, name-keyed), volume (float, name-keyed) |
| Consumers | resvol array read by FUN_001b150c, 1b2af0 (reads name list index), 1b3ce8, 1b3f24, 1b42b8, 1b4530, 1b46bc; movie volume getter FUN_001b2ad8(obj, idx) = `0x2e58c4[idx]` |
| Notes | FUN_00020f5c(vol) after each assignment is a no-op debug/format stub; FUN_001b1b20 is an empty stub (leftover debug print) |

---

## 5. data/menu/scene.csv (loader = menu scene ctor FUN_0008be64)

| item | value |
|---|---|
| Loader | inside **FUN_0008be64(this)** (menu scene object, size 0x9e0; ctor): `FUN_000651b8(this+0x990, "data/menu/scene.csv" (0x2d2658), buildRowNameMap=1, buildColNameMap=0, ","=0x2d266c)` |
| Caller / when | FUN_0008cb68 (menu manager ctor, vtbl 0x3071f4; allocs 0x9e0 and stores `this[0xf]`, sets global `_DAT_003386c8 = this`) called from FUN_00047698 (boot-time menu startup) |
| Destination | reader object embedded at `menuScene + 0x990` (vtbl 0x3070bc, this+0x10 = rowName map). Accessor FUN_0008d9a0(menuMgr) = `menuMgr[0xf] + 0x990`; FUN_001ff670() = `_DAT_003386c8 ? FUN_0008d9a0(_DAT_003386c8) : 0` |
| Layout | 3 columns, no header line at all: the first line (key Kaku_FOV) is row 0 and is a normal data row (loaded with skipHeader=0; the row-name map is built from ALL rows including row 0); col 0 = key string (row name), col 1 / col 2 = value-or-comment |
| Lookup | `FUN_000657e4(reader, rowName, col)` float; `FUN_00065740(reader, rowName, col)` int |
| Value column | **`Kaku_*` keys: value in col 1** (col 2 is the comment); **`MenuLady_*`, `AdhocSingles_*`, `AdhocDoubles_*` keys: value in col 2** (col 1 is a non-numeric note) |
| Key families and consumers | Kaku_ (37 keys: FOV, CameraZ/Y, Angle{1P,2P}_S, Angle{1..4}P_D, Pos{..}, Light0/1 Dir XYZ + Color RGB, Ambient RGB, PointLight_Enable, PointLight0/1 Color RGB): FUN_001a9140 (lights/camera setup), FUN_001a9248.. , FUN_001a96b0 (PointLight_Enable via int getter), FUN_001ba05c (player pos/angle). MenuLady_ (27): FUN_001d630c (camera, lights, ambient), FUN_002a03c0 (WIN_POS_X/Y, WIN_WIDTH, WIN_HEIGHT, LEAD_POS_Y of the speech window). AdhocSingles_ / AdhocDoubles_ (22 each): FUN_00254e18 (camera pos/target/fov, 2 lights, ambient) |
| Count | file is 108 lines; the same file exists in 3 archives (a1645/a1646/a1647 dumps) |

---

## 6. data/menu/game_eff/gutseffect.csv (loader inside FUN_000c5118)

| item | value |
|---|---|
| Loader | block at ~line 488 of **FUN_000c5118(this)** (in-game effect manager ctor, size 0x300 object, vtbl set in ctor): `FUN_000649c0(rdr); FUN_00064bf4(rdr, "data/menu/game_eff/gutseffect.csv" (0x2d5c24), skipHeader=1, ","=0x2d5c48)`; plain index-based reader (no name map) |
| Caller / when | FUN_00088a44 (in-game scene ctor, "game_100" common load) allocs 0x300 and calls FUN_000c5118; stored at `scene[0x24]` (when entering a match/court scene); loader freed with FUN_00064a08(rdr,-1) |
| Rows | data rows 0..n-1 (header skipped) |
| Destination | 16 containers of 12 bytes ({data,size,cap} std::vector of entries) inside the effect manager: container for PC number `pc` at `mgr + 0x220 + pc*12` (dwords `0x88 + pc*3`); `pc == 999` (NPC) goes to `mgr + 0x2d4` (dword 0xb5). Pc is NOT bounds checked (0..14 fits). Entry pushed with FUN_000c7644 (vector push_back) |
| Entry | 0x18 bytes (guess): {std::string motionFileName (ctor FUN_00002f90, assigned by FUN_00003268), std::vector<int> motionNumbers (ctor FUN_000c777c, 3 zero words)} |

| col | getter | use |
|---|---|---|
| 0 | int (FUN_00065104) | PC number, 999 = NPC |
| 1 | string (FUN_0006517c) | motion file name -> entry name |
| 2 | int | first motion number; **-1 means range mode** |
| 3, 4 | int | range mode only: push every integer from col3 up to and including col4 |
| 2..n | int | list mode: push col2, col3, ... until a value of -1 or end of row (row width via FUN_000650e8) |

Header gives the same semantics (comment text in header says -1 at col 2 -> range from 2nd to 3rd number, and -1 terminates the data).

---

## 7. data/menu/game_eff/chakudan/ballmark.csv (loader inside FUN_000cede4)

| item | value |
|---|---|
| Loader | tail of **FUN_000cede4(this, ...)** (ball-landing-mark "chakudan" effect ctor, vtbl 0x3074dc, object has slots up to dword 0x2e): `FUN_00064bf4(rdr, "data/menu/game_eff/chakudan/ballmark.csv" (0x2d6460), skipHeader=1, ",")` |
| Callers | FUN_000c801c (called from FUN_000c5118, the effect manager ctor) and FUN_000cabe0 |
| Row | `row = *(_DAT_003402a0 + 0x1364)` = current court id (e.g. used also in the large court-id switch earlier in the ctor); data row index = court id (header skipped) |
| Cols | col 0 court name: ignored. col 1 blend (string via FUN_0006517c): compared with "SUB" (0x2d648c) -> `this[0x2d] = 2` (dword offset 0xb4) else 0 (i.e. MUL). col 2 alpha (float via FUN_00065140) -> `this[0x2e]` (offset 0xb8) |
| Defaults | if the file fails to load: `this[0x2d]=0`, `this[0x2e]=0x42800000 (64.0f)` |
| Other | the ctor also builds 5+ ballmark sprites from `data/menu/game_eff/chakudan/chakudan%02d` ("%s.i3r" / "%s.i3m", 0x2d6384/0x2d6374/0x2d637c) |

---

## 8. Particle lists: texlist.csv + motlist.csv (shared loader FUN_00067e54)

Shared loader: **FUN_00067e54(texlistPath, motlistPath, instanceCount, motionFlag(byte), appendMode)** (base class FUN_00067498, vtbl 0x30716c, singleton manager `_DAT_00331c28`, size 0x2c). Three thin wrappers:

| wrapper | paths | args (count, flag, append) | how it is reached |
|---|---|---|---|
| **FUN_000ce70c** | data/menu/game_eff/particle/texlist.csv (0x2d62bc), motlist.csv (0x2d62e4) | 0x10, 0, **0 (fresh)** | virtual slot +0x1c (ptr 0x307594 in vtbl 0x307578), called explicitly from the ctor FUN_000ce65c (class created in FUN_000c8178 inside effect manager ctor FUN_000c5118: `mgr[0x44]`) |
| **FUN_000ce72c** | data/court/particle/texlist.csv (0x2d630c), motlist.csv (0x2d632c) | 0x10, 0, **1 (append)** | FUN_000c81c0 (`if (mgr[0x44]) FUN_000ce72c()`), called from FUN_000c5118 right after the above, so the menu list is loaded first and the court list is appended to the same manager |
| **FUN_0026377c** | data/court/particle/texlist.csv (0x2fde6c), motlist.csv (0x2fde8c) | 0x20, 0, **0 (fresh)** | virtual slot +0x1c (ptr 0x309aa4 in vtbl 0x309a88, subclass ctor FUN_002636d8); invoked as `(**(vtbl(obj[0x164 bytes])+0x1c))()` in FUN_001c51dc; object created in court-scene ctor FUN_001c3bac (`this[0x59]`). Its own destructor FUN_0026370c calls slot +0x20 |

Behaviour of FUN_00067e54 (reader = plain index reader, `FUN_00064bf4(rdr, path, skipHeader=1, ","=0x2d122c)`):

- append==0: tears down old manager (FUN_00068cb0), creates a new 0x2c-byte one (FUN_00068c98, FUN_00068c84(+0x10), FUN_00068c6c(+0x1c)), clears the texture map at +0x1c. append==1 re-uses the existing manager.
- **texlist.csv** (header `no,texname`, cols 0..1): for each row r: col 1 = texture file name; full path = directory part of the texlist path + name (`"%s%s"` 0x2d1230); texture object alloc 0x48 (FUN_00050ff4(this, path, 0)), FUN_000513fc(obj,1), FUN_00051398(3000.0f(0x453b8000), obj); col 0 (int, FUN_00065104) = texture id key; inserted into the map at manager+0x1c (key -> texture*). If key already present, the new texture is deleted (existing wins). Finalised by FUN_0006b9e8 (fresh mode only).
- **motlist.csv** (header `no,motname,comment`, cols 0..2): for each row: col 0 (int) = motion number key, col 1 (string) = motion base name, col 2 comment unused. Loads `"<dir><name>.i3r"` (`"%s%s.i3r"` 0x2d1238; resource object alloc 0x30 via FUN_00053670) and `"<dir><name>.i3m"` (`"%s%s.i3m"` 0x2d1244; motion object alloc 0x10 via FUN_00055df8(this, path, motionFlag)). If the .i3r has no node list the load aborts for the whole remaining table (`break`, ends the loop early). Then every node name in the .i3r is scanned: nodes containing the substring `effect_` (0x2d1250) are parsed:
  - name contains `loop` (0x2d1258) -> loop flag byte = 1
  - name contains `size` (0x2d1260) -> scale float = decimal number after it * 0.01
  - else an emitter record of 20 s16 (0x28 bytes) is built with {node index at [0]} and a small letter/number mini-language after `effect_`: letters I, B, T select fields (`I`->rec[3] (clamped >=1), `B`->rec[2] (clamped 0..5), `T`->rec[1]); a `P` prefix switches to second set (D,G,E,C,T,S,s,V,v,U,u,R,L,...); digits accumulate decimal (`x` moves to next s16, `m` negates, `_` ends the field); several fields clamped to 0..3 / 0..5. (Gist only; guess, not fully decoded.)
  - Each motion is inserted into the manager's motion map (manager+0x00) keyed by col 0; entry = {i3r*, i3m*, vector<EmitterRec 0x28 bytes>, loop(u8), size(f32)}.
- After the lists: fresh mode calls FUN_0006ab24(manager+0x10, instanceCount) (pool/vector reserve; 0x10 for the menu/game-effect set, 0x20 for the court set) and sets `_DAT_00331c20 = FUN_0001342c()` (timestamp/tick).
- Row counts in the dumps: game_eff texlist 83 lines / motlist 51; court texlist 20 / motlist 47.

---

## 9. data/script/motion_list/common.csv and special.csv (loader FUN_00127308)

| item | value |
|---|---|
| Loader | **FUN_00127308(scriptBuf, sceneIdx)** |
| Caller / when | FUN_001c7cb4(…) -> FUN_00127308(buf, param_3-1) after reading `data/script/script_bin/lobby%02d/motlist.mld` (0x2ea9e4) via FUN_0004cad0; FUN_001c7cb4 is called from the lobby scene loader FUN_001c772c (every lobby room load) |
| Readers | two header-aware readers, delimiter "," (0x2da874): common (path 0x2da850) and special (0x2da878); both `FUN_000651b8(rdr, path, 0, 1, ",")` (header kept as row 0, column names map). If either fails to load, nothing is loaded |
| Selection | `scriptBuf` is the `motlist.mld` file: a byte per motion row; bit `1<<sceneIdx` (sceneIdx = lobby room - 1) says "this motion is needed in this scene". Common row r (1-based) uses byte `scriptBuf[r-1]`; special entries use `scriptBuf[200 + no]`. Common rows are also forced in when `autoload > 0` |
| Destination 1 | `_DAT_0033b4a8` : array of **800 motion objects, 0x10 bytes each** (alloc FUN_000008d8(…, FUN_00055dd0 ctor, FUN_00055e48 dtor, 0x10, 800)). Slot = row-1 for common (0..199 used), slot = `200 + no` for special. Loaded with `FUN_00055eac(&slot, "data/lobby/motion/%s.i3m" (0x2da8b4) % filename, 0)` |
| Destination 2 | `_DAT_0033b4ac` : array of **800 x 3 bytes** (alloc with elem ctor FUN_00127770 = {0,0,10}): byte0 = facial, byte1 = half, byte2 = blend (default 10) |
| Destination 3 | `DAT_0033b4b0`: **49 ints (0x31), preset -1**: for common rows, the filename is strcmp'ed against the 49-entry name pointer array `PTR_s_l99_npc_wa_sta_00_f_002c13a8` (l99/npc_wa_sta_00_f ... l99/npc_ge_oth_29_m, the lobby-NPC standard motions); on match `DAT_0033b4b0[k] = row-1` (slot of that named motion) |
| Frees old | FUN_00127788 releases the previous `_DAT_0033b4ac` and `_DAT_0033b4a8` first |

common.csv columns (name-keyed): `filename` (string, 0x2da8a8), `facial` (int -> byte0), `half` (int, 0x2da8d8 -> byte1), `autoload` (int, 0x2da89c; >0 forces load), `blend` (int, 0x2da8e0 -> byte2).
special.csv columns: `no` (int, 0x2da8e8 -> slot = no+200), `filename` (string), `facial` (-> byte0), `half` (-> byte1); the `blend` column is NOT read (byte2 keeps default 10). The special table is only loaded for entries whose scene bit is set.

---

## Proposed names

| address | proposed name |
|---|---|
| FUN_000d84e0 | LoadPartsTables (Face/Head/Body/Acce/Racket) |
| FUN_000d83b8 | PartsDb_ctor (size 0x4c, vtbl 0x3075e0) |
| FUN_000d8c24 | PartsDb_GetRow(kind, idx) |
| FUN_000d8b3c / FUN_000d8b9c | PartsReader_GetIntByName / GetFloatByName |
| DAT_00338b08 | g_partsDb |
| 0x2c066c | s_partsTableFiles (struct {int kind; const char* path;}[5]) |
| struct (0x6c) | PartsRow {vtbl; f32 stat[4][5]; u32 rxryrz; s16 price,no,getLobby,exp; s8 get,getPer; u8 typeFace; u8 site; u8 limMotion; u8 sharingShopSex; u8 pcType; u8 pcOnly[3];} |
| FUN_00195b08 / DAT_0034174c | LoadPartsSetTable / g_partsSetReader |
| FUN_001bfa44 / FUN_001bfbe8 | SetPartsSetOwnedState(save,set,val) / IsPartsSetComplete(save,set) |
| FUN_002af6ec / FUN_002af8f4 | LoadPartsLevelParamTable / LoadPartsLevelParamTableOnce; DAT_0034b5d4 g_partsLevelParams (0x348); FUN_002afaf8 SumPartsLevelBonus(out[5],level) |
| FUN_001b1810 | LoadSoundVolumeTables (resvol + movievol); 0x2e515c g_resVolume[474]; 0x2e58c4 g_movieVolume[4]; 0x2c5a34 g_soundResNames[474] |
| FUN_001b2380 | SoundSys_InitAndLoadVolumes; FUN_001b2ad8 GetMovieVolume |
| FUN_000651b8 | CsvReader_LoadNamed (path, buildRowMap, buildColMap, delim) |
| FUN_00065364 / 65554 / 655f8 / 6569c | CsvReader_FindCol / GetIntByName / GetFloatByName / GetStringByName |
| FUN_00065740 / 657e4 | CsvReader_GetIntByRowName / GetFloatByRowName |
| FUN_0008be64 | MenuScene_ctor (loads scene.csv into this+0x990); FUN_0008d9a0 MenuMgr_GetSceneCsv; FUN_001ff670 GetSceneCsv |
| FUN_000c5118 | GameEffectMgr_ctor (loads gutseffect.csv); +0x220 g_gutsEffectByPc[15] + NPC at +0x2d4 |
| FUN_000cede4 | ChakudanEffect_ctor (loads ballmark.csv row = court id) |
| FUN_00067e54 | ParticleMgr_LoadLists(texPath, motPath, count, motFlag, append); FUN_000ce70c LoadMenuParticleLists; FUN_000ce72c AppendCourtParticleLists; FUN_0026377c LoadCourtParticleLists |
| FUN_00127308 | LoadLobbyMotionLists(motlistMld, sceneIdx); 0x33b4a8 g_lobbyMotions[800]; 0x33b4ac g_lobbyMotionFlags[800][3]; 0x33b4b0 g_lobbyNamedMotionSlot[49]; 0x2c13a8 g_lobbyNpcMotionNames[49] |

## Unresolved / uncertain

- Parts_*: the semantic meaning of `Type`, `Face`, `Site`, `Lim`, `Motion`, `Sharing`, `ShopFlag`, `RX/RY/RZ` fields and of kind 5 = Racket is inferred from names only; columns SE, GLNo, P_Max, Forte, SUM_n are never read by the EBOOT loader (maybe tool-only). Racket accessor id 5: consumers not traced.
- Parts_P_Param: the Param value range beyond 0..3 and exact meaning of EXP/Value; destination slot is 5 floats but only types 0..3 can be stored (note).
- Gutseffect entry struct (0x18) and container count are inferred from stack layout (guess).
- Particle node-name mini-language only partially decoded; the exact field meanings of the 20-s16 emitter record are not derived.
- scene.csv: "row 0" quirk: the row-name map includes row 0 (the first data line is row 0 because skipHeader=0 and the file has no real header); Kaku_FOV consumer FUN_001a92a8 etc. not exhaustively listed.
- FUN_00127308 `scriptBuf` layout (`motlist.mld`) assumed as plain byte array (bytes 0..199 common, 200+ special); not verified against the file.
