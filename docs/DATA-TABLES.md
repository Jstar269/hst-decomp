# Data tables: loaders and struct fields (private)

Private analysis (2026-10-24). Nothing here is game data: only file names, column header names, offsets, strides and
function addresses. The table contents were never copied. Addresses are module-relative EBOOT.BIN (`hstdis.py` /
`ghidra/out/EBOOT_BIN-p2/pseudocode`). The tables were identified from the PGD-removed `GAMEDATA.BDL` (whose outer index is
described in [BDL-INDEX-FORMAT.md](BDL-INDEX-FORMAT.md)) and checked against the EBOOT's path strings.

Detailed per-table column maps (column index -> destination offset/type -> header name) are in `docs/data-tables/`:

| Group file | Tables |
|---|---|
| [characters-ai.md](data-tables/characters-ai.md) | character/NPC/racket params, grade, common, etc_offset, npc_voicepack, aityaku, AI (7 files), PCGut (2), Rule_Iromono |
| [parts-effects-sound.md](data-tables/parts-effects-sound.md) | Parts_Face/Head/Body/Acce, Racket_Racket_param, Parts_P_Set/P_Param, resvol/movievol, scene.csv, gutseffect, ballmark, particle lists, motion lists |
| [camera-court-lobby.md](data-tables/camera-court-lobby.md) | cameradatabase (+script variants), camera_nearfar, commoncamera, court/light/fog/areaclip/SE/gallery/gimmick tables, Court_Court, lobby tables |
| [menus-prize-shop.md](data-tables/menus-prize-shop.md) | chrselect, status, regulation, lastconfirm, result_status, shop Item, prize tables, challenge tables, toplady |

Coverage: the BDL holds 91 distinct table paths (the per-court and per-lobby `setting/` files count once per file name,
and the `cameradatabase%02d` family once). 90 have a located loader. The exception is
`data/menu/inpane/Point_BonusPoint.txt` (7 lines, `Label/ENTRY/VALUE`): no EBOOT string or path format reaches it, so
it is an orphan (the matching prize table `Point_ShopPoint.txt` is read). `toplady.csv` has its loader and layout but two
columns are unexplained. Some field meanings are inferred from header names only; each group file ends with an
"unresolved / uncertain" list.

## The table readers

All CSV/TXT tables go through one family of reader classes:

| Address | Role |
|---|---|
| `0x000649c0` | table object constructor (vtable `0x3070cc`; row vector at +4, row count at +8) |
| `0x00064bf4` | `Load(path, skipHeader, delimiter)`: whole-file read (`0x0004cad0`), `\r` to `\n`, UTF-8 BOM stripped, line split, cell objects built |
| `0x000651b8` | `LoadNamed(path, buildRowKeyMap, buildColKeyMap, delimiter)`: the same, keeping the header as row 0 and building name to index maps (vtable `0x3070bc`) |
| `0x00065104` / `0x00065140` / `0x0006517c` | cell getters `(row, col)`: int / float / string (cells are typed; a numeric cell's string getter returns NULL) |
| `0x00065554` / `0x000655f8` / `0x0006569c` | cell getters `(row, headerName)`: int / float / string; a missing column reads as 0 |
| `0x00065740` / `0x000657e4` | cell getters `(rowLabel, col)`: int / float |
| `0x000650e0` | row count |

Tab-separated `.txt` tables and comma-separated `.csv` tables use the same classes; only the delimiter string differs.
Named loaders ignore column order. Positional loaders (camera, court, sound) depend on it.

## Table to loader index

Loader = function that opens and parses the table (it is often a larger constructor or scene-init function).

### Characters, AI, parameters ([characters-ai.md](data-tables/characters-ai.md))
| Table | Loader | Destination |
|---|---|---|
| `common/parameter/character.csv`, `NPC_Param.csv`, `Racket_param.csv` | `0x00162338` (called from boot init `0x00047054`) | `CharacterParam` stride 0x22c; PC/NPC tables `0x341508`, racket table `0x34150c` |
| `common/parameter/grade.csv` | `0x001607a4` (from `0x00162338`) | `GradeRow` {Power, Technique, Speed, Stamina, Impact} f32; `0x341510` |
| `common/parameter/common.csv` | `0x00160998` | `CommonParam` size 0x3e8 at `0x341120` (about 300 named tuning values) |
| `chara/model/etc/etc_offset.csv` | `0x000d9358` (map-based, 0.1 fixed point; no table object) | `0x338b18` part-name to column, `0x338b34` offsets per chara |
| `chara/parameter/npc_voicepack.csv` | `0x000b3cf4` (from gameplay scene init `0x00088a44`) | `0x338ab0` |
| `common/aityaku/aityaku.csv` | `0x0024d808` (ctor) | `AityakuTable` at `0x34a77c` |
| `common/parameter/AI_Param_1..3.csv`, `AI_param_PC.csv`, `AI_param_NPC.csv` | `0x00234898` | `AiParam` stride 0x230; rank tables `0x34a6a8`, chara tables `0x34a6ac` |
| `common/parameter/AI_Shot.csv` | `0x00235da4` | `AiShotRow`, `0x34a6b0` |
| `common/parameter/AI_Param_Doubles.csv` | `0x00235ff4` | `AiParamDoublesRow` 0x48, `0x34a6b4` |
| `common/parameter/AI_Shot_Doubles.csv` | `0x0023650c` | `AiShotDoublesRow` 0x1c, `0x34a6b8` |
| `chara/parameter/PCGut_PcGut.txt`, `PCGut_NpcGut.txt` | `0x0027dcec` (stored transposed) | `GutRecord` 0x68, `0x34a7e8` |
| `common/rule/Rule_Iromono.txt` | `0x00253630` (ad hoc rooms) and `0x001a0148` (last-confirm menu) | two independent readers |

### Parts, effects, sound ([parts-effects-sound.md](data-tables/parts-effects-sound.md))
| Table | Loader | Destination |
|---|---|---|
| `chara/parameter/Parts_Face/Head/Body/Acce.txt`, `Racket_Racket_param.txt` | `0x000d84e0` (path array at `0x2c066c`, five {kind, path} pairs) | `PartsRow` 0x6c bytes in six vectors under `0x338b08` |
| `common/parts/Parts_P_Set.txt` | `0x00195b08` | resident reader `0x34174c` |
| `common/parts/Parts_P_Param.txt` | `0x002af6ec` | 0x348-byte table `0x34b5d4` |
| `sound/resvol.csv`, `movievol.csv` | `0x001b1810` | `0x2e515c` volumes[474], `0x2e58c4` movie[4] |
| `menu/scene.csv` | menu scene ctor `0x0008be64` | scene object +0x990 |
| `menu/game_eff/gutseffect.csv` | `0x000c5118` | effect manager +0x220 / +0x2d4 |
| `menu/game_eff/chakudan/ballmark.csv` | `0x000cede4` | ball-mark effect object |
| `menu/game_eff/particle/texlist.csv`, `motlist.csv`; `court/particle/texlist.csv`, `motlist.csv` | shared `0x00067e54` via `0x000ce70c`, `0x000ce72c`, `0x0026377c` | particle manager |
| `script/motion_list/common.csv`, `special.csv` | `0x00127308` | `0x33b4a8..0x33b4b0` lobby motion tables |

### Camera, court, lobby ([camera-court-lobby.md](data-tables/camera-court-lobby.md))
| Table | Loader | Destination |
|---|---|---|
| `camera/cameradatabase.csv`, `camera_nearfar.txt` | `0x0012f698` | `CameraDbEntry` 0x58 records at `0x33b584` (section markers pick base 0x00 / 0x80 / 0xc0); near/far floats at camera manager +0x50..0x78 |
| `script/script_bin/camera/cameradatabase%02d.csv` | `0x0027d34c` | `ScriptCameraEntry` 0x40 (columns 10, 11, 15 discarded) |
| `prize/commoncamera.csv` | `0x001ed27c` | `PrizeCameraParams` 0x24 |
| `court/court.csv`, `courtlight.csv`, `playerlight.csv`, `balllight.csv`, `fogsetting.csv`, `camera_time.csv`, `<court>/setting/cNN_gallery.csv`, `cNN_escape_gimmick.csv`, `cNN_break_gimmick.csv` | court manager load `0x0013293c` (helpers `0x001415e8`, `0x001428d4`) | court manager structs |
| `court/<court>/setting/cNN_areaclip.csv` | `0x00137840` -> `0x001415e8` | |
| `court/<court>/setting/cNN_se.csv` (+ `sedata.dat`) | `0x001420a4` (court), `0x001424c4` (lobby) | `StageSeEntry` 0x28 |
| `common/court/Court_Court.txt` | `0x0027e7d0` (from boot init) | `CourtCatalogEntry` 0x28 at `0x34a7ec` |
| `lobby/lobby.csv`, `lobby/effect.csv` | `0x0012cea0`, `0x001c51dc` | lobby manager `0x33b574` |
| `lobby/<name>/setting/lNN_areaclip/courtlight/playerlight/fogsetting.csv` | `0x0012cea0` | |
| `lobby/<name>/setting/lNN_rNN_se.csv` | `0x0012d7a8` | |

### Menus, prize, shop ([menus-prize-shop.md](data-tables/menus-prize-shop.md))
| Table | Loader | Destination |
|---|---|---|
| `menu/chrselect/chrsel_param.csv`, `chrsel_param_color.csv`, `chrsel_param_scroll.csv` | `0x0016f45c` (via `0x0017ae48` / `0x0017b260`) | scene object +0x2a4 (30 words) etc. |
| `menu/chrselect/chrsel_unitlist.txt`, `menu/dressup/dressup_unitlist.txt` | `0x0017fff4`, `0x001802b4` (via `0x002172f4`) | `0x34151c`, `0x341520` |
| `menu/chrselect/chrsel_param_chara.csv` | `0x002042c8` (transposed per character) | |
| `menu/chrselect/chrsel_param_scroll.csv` (shop copy) | `0x0026d224` (shop scene init, reads by row position) | |
| `menu/status/status_param.csv`, `status_param_color.csv`, `status_param_scroll.csv`, `sort.csv` | `0x002392dc` | |
| `menu/status/status_unitlist.txt` | `0x0023c040` | `0x34a6c0` |
| `menu/regulation/reg_param.csv`, `reg_tall_param.csv` | `0x001fd50c` | `RegParams` (21 floats) |
| `menu/regulation/regulation_unitlist.txt` | `0x001ffdbc` | `0x34a144` |
| `menu/lastconfirm/lastconfirm_param.csv`, `lastconfirm_param_color.csv` | `0x001a0148` | `LastConfirmParams`, `LastConfirmColors` |
| `menu/result/result_status/result_status_unitlist.txt` | `0x001e1c40` | `0x34a130` |
| `menu/shop/Item.csv` | `0x00293bd4`, `0x00293c6c` | `ShopItemRec` vectors per category |
| `prize/Point_ShopPoint.txt`, `rank_param.csv`, `Rank_PlayersRanked.txt` | `0x001ee248` | prize scene |
| `prize/score.csv` | `0x002ada5c` | csv object `0x34b5a0` |
| `menu/challenge/Challenge_LobbyItem.txt`, `Challenge_PointXXX.txt` | `0x0028af58` (from `0x001c51dc`) | `ChallengeLobbyItemRec` 0x60, `ChallengePointRec` 8 |
| `menu/challenge/Challenge_AdhocTable.txt` | `0x002800ac` (ctor; accessor `0x00280188`) | |
| `menu/mainmenu/toplady.csv` | `0x002a03c0` | `TopLadyMotionTable` (partly understood) |

## Notable findings

- **Positional packing hazards.** `0x0017ae48` / `0x0017b260` store a menu parameter only when it is inside its min/max
  range; an out-of-range value is dropped and every later parameter shifts down by one slot.
- **Dead columns.** `SliceSpin`, `LobSpin`, `DropSpin` (character tables), `Rank`/`Playstyle` (AI tables), the SE, GLNo,
  P_Max, Forte, SUM columns of the Parts tables, three columns of the script camera tables, the `blend` column of
  `special.csv` and several prize/challenge columns are never read by the EBOOT.
- **Unreachable data.** The second data row of `common.csv` cannot be selected (the only caller passes -1).
- **String to enum parsers by substring.** The camera enum parsers use `strstr`, so test order decides the winner.
- **Hard-coded row counts.** The `*_unitlist.txt` loaders read a fixed row count (214/107/203/78/123/40/15); replacement
  files must keep the same count.
- **Gated court data.** Gallery and gimmick tables load only when `DAT_003386b8 == 0` and the court manager's +0x141f byte
  is set; the ad hoc court branch skips them.

## Names

Proposed names for loaders, structs and globals are listed at the end of each group file ("Proposed names").
Functions in `src/eboot` keep their address-based `symbol=` names (the build links by address); the names are
recorded as comments only, so compiled bytes are unchanged.
