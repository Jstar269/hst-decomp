# g4-menu: loaders for menu / prize / challenge / shop data tables (private; no cell values recorded)

All addresses are module-relative EBOOT vaddrs. "csv" = instance of the CSV table class (vtable 0x3070cc, size 0x10 + two std::map-like members at +0x10 (row-key map) and +0x20 (column-key map)).
Delimiters were read from EBOOT strings (all `,` except where noted `\t`).

## 0. Shared helpers discovered (used by almost every table below)

| addr | what | notes |
|---|---|---|
| 0x000651b8 | `LoadCsv(csv, path, buildRowKeyMap, buildColKeyMap, delim)` | wrapper around FUN_00064bf4(csv, path, **skipHeader=0**, delim). So with this wrapper the header line is **row 0** and data starts at row 1. If buildRowKeyMap!=0 the map at csv+0x10 is filled with key = cell(row,0) string -> row index (all rows incl. row 0). If buildColKeyMap!=0 the map at csv+0x20 is filled with key = cell(0,col) string -> col index. Returns bool. |
| 0x00064bf4 | raw load(this,path,skipHeader,delim) | called directly (skipHeader=1) by Item.csv, AdhocTable, lobby.csv; (skipHeader=0) by toplady.csv, the shop's chrsel_param_scroll read. UTF-8 BOM is stripped (Point_ShopPoint, Rank_PlayersRanked, Challenge_* start with a BOM). |
| 0x00065104 / 65140 / 6517c | getter (csv,row,col): int (cell vtbl+0xc) / float (+0x10) / c-string (+0x14) | |
| 0x00065740 | `GetIntByRowKey(csv, rowKey, col)` (+0xc); 0x000657e4 = same but float (+0x10) | returns 0 if key missing |
| 0x0006531c | `FindRowByKey(csv, key)` -> row index or -1 | |
| 0x000653ac / 65480 | (csv, rowKey, colKey) int / float | needs both maps |
| 0x00065554 / 655f8 / 6569c | (csv, rowIdx, colKey) int(+0xc) / float(+0x10) / string(+0x14) | needs column-key map |
| 0x000650e0 | RowCount; 0x000650e8(csv,row) = ColCount of that row | |
| 0x0017ae48 | `LoadMenuParamCsv(dest, csv, path)` (existing name unpack_record_0017ae48) | generic "name,type,min,max,value,..." parameter file -> packed array, see 0.1 |
| 0x0017b260 | `LoadMenuColorCsv(dest, csv, path)` (existing name collect_valid_ids_0017b260) | "name,R,G,B,..." file -> packed int array, see 0.2 |
| 0x0017b030 | `LoadMenuParamCsvTransposed(base, csv, path, elemStride, count)` | see chrsel_param_chara |
| 0x002172f4 | `LoadUnitList(int **outBuf, path)` | see 0.3 |

### 0.1 LoadMenuParamCsv (0x0017ae48): generic param file
Load (skipHeader=0, delim ","), then for data rows r = 1 .. rowCount-1:
- col 1 = type string, first char selects: `f` -> float(col 4) ; `i` -> int(col 4) ; `s` -> strncpy(dest+off, cell(col4), 0x20) and off += 8 (pointer-size slot; buffer written is 0x20 max at dest+off - no file in this group uses `s`).
- For f/i: min = col 2, max = col 3. The value is stored (and the write offset advances by 4) **only if min <= value <= max**. A value outside its range is silently dropped and every following parameter shifts down by 4 bytes. So dest layout = "row order, 4 bytes each" provided all values are in range.
- col 0 (name) and cols >=5 (comments / proposal columns) are not read.
### 0.2 LoadMenuColorCsv (0x0017b260)
For data rows r >= 1: col 0 name (read, unused), cols 1,2,3 = int R,G,B. Each component is stored as int (4 bytes, sequential, running offset) only if 0 <= v < 0x100 (else dropped and the rest shifts). So dest = int[3*rows], row-major (R,G,B). Cols >=4 unread.
### 0.3 LoadUnitList (0x002172f4) and the *_unitlist.txt family
Used for: chrsel_unitlist.txt, dressup_unitlist.txt, status_unitlist.txt, regulation_unitlist.txt, result_status_unitlist.txt.
- Local csv, `LoadCsv(path, 0, 0, ",")` (delim at 0x2efb1c = `,`), **no header line** (row 0 is data). Allocates buffer (rowCount*0x21 bytes via 0x00000a90, hidden size arg) stored into `*outBuf`.
- For each row i: `buf[i*0x21] = (u8)int(col0)` = index into the screen's group-name table (see per-screen lists); `strcpy(buf+i*0x21+1, string(col1))` = unit (layer-object) name (32 chars + NUL max). Returns 1 on success, 0 if load failed.
- Consumer: `0x00216f14 FillUnitRecords(out20, groupArray, listBuf, count)` (existing name fill_result_records): for i<count: `unit = FindChildByName(groupArray[buf[i*0x21]], name)` (FUN_001026b8) and, if found, writes out[i*0x14+0]=unit, +4=unit[9], +0x10=*unit. The element count is a **hard-coded constant at each call site** and equals the file's line count in the shipped files (see per table). `0x00216e90 LookupNameList(outGroups, layout, nameTable, n)` builds the groupArray from a table of n C-string pointers (FUN_001039d8 find by name).
- Output globals (each a malloc'd pointer, never freed in these loaders): chrsel DAT_0034151c, dressup DAT_00341520, status DAT_0034a6c0, regulation DAT_0034a144, result_status DAT_0034a130.

---

## 1. Character select (menu/chrsel_010_param.xb scene)

Loader / owner: **FUN_0016f45c** (screen resource-load / init state; mark "menu/chrsel_010_param.xb" at 0x2e0540 first). Caller: 0x001717c0 in FUN_00171714 (chrsel scene state function, itself called from 0x179724). Runs on entering the character-select screen. `this` = param_1 (screen object).

### chrsel_param.csv (`data/menu/chrselect/chrsel_param.csv`, string 0x2e055c)
- `FUN_0017ae48(this+0x2a4, csvobj=this+0x214, path)`; delim `,`; 30 data rows -> 30 x 4 bytes at this+0x2a4 .. 0x31c (0x78 bytes). Row i (0-based among data rows) -> `this+0x2a4+4*i`.
| idx | offset | type | header/row name (JP, translated) |
|---|---|---|---|
| 0 | +0x2a4 | f | base character size |
| 1 | +0x2a8 | f | camera Y offset (char select) |
| 2 | +0x2ac | f | camera Y offset (dress-up) |
| 3 | +0x2b0 | f | rotation speed (auto) |
| 4 | +0x2b4 | f | rotation speed (manual) |
| 5 | +0x2b8 | i | auto-rotate wait |
| 6 | +0x2bc | f | scale speed |
| 7 | +0x2c0 | f | scale min |
| 8 | +0x2c4 | f | scale max |
| 9,10,11 | +0x2c8..0x2d0 | f | light0 direction X,Y,Z |
| 12,13,14 | +0x2d4..0x2dc | f | light0 color R,G,B |
| 15,16,17 | +0x2e0..0x2e8 | f | light1 direction X,Y,Z |
| 18,19,20 | +0x2ec..0x2f4 | f | light1 color R,G,B |
| 21,22,23 | +0x2f8..0x300 | f | ambient color R,G,B |
| 24 | +0x304 | i | cross-fade time |
| 25 | +0x308 | i | slide time |
| 26 | +0x30c | i | decide-pose ("kime pose") time |
| 27 | +0x310 | f | NOW LOADING scale |
| 28 | +0x314 | f | racket alpha speed |
| 29 | +0x318 | f | parameter-gauge speed |
- Header columns of the file: name, type, min, max, value, free-text note (only 0..4 read).

### chrsel_param_color.csv (string 0x2e0584)
- `FUN_0017b260(this+0x31c, csvobj=this+0x244, path)`; 17 rows x 3 ints = 0xcc bytes at this+0x31c..0x3e8 (row k -> this+0x31c+12k, comps R,G,B). Row names (header col 0): 0 head(part), 1 body(part), 2 accessory1(part), 3 accessory2(part), 4 head(partin), 5 body(partin), 6 acc1(partin), 7 acc2(partin), 8 selected(partin), 9 head(icon), 10 body(icon), 11 acc1(icon), 12 acc2(icon), 13 OK(icon), 14 selected(icon), 15 playstyle base, 16 playstyle net.

### chrsel_param_scroll.csv (string 0x2e05b0)
- `LoadCsv(this+0x274, path, buildRowKeyMap=1, 0, ",")`; **no header row** (row 0 is data). Keyed by col 0; value read as int col 1 with `FUN_00065740(this+0x274, key, 1)`. Keys (EBOOT strings): `ScrollDankaiTime` (0x2e0650), `ScrollTimeFast` (0x2e0664), `ScrollTime` (0x2e0674). Consumer: FUN_001755b8 (chrsel per-frame update, 6 call sites 0x178f84..0x179088): `if (held-count > ScrollDankaiTime) scrollSpeed = ScrollTimeFast else ScrollTime`, passed to FUN_00186d7c.
- **Also loaded by the shop** (see 7) and the layout is the same file name (`data/menu/chrselect/chrsel_param_scroll.csv`, string 0x2fe1dc). Header col 2 = comment ("scroll time"), unread.

### chrsel_unitlist.txt (string 0x2e0858)
- Loader call: `FUN_002172f4(&DAT_0034151c, path)` inside **FUN_0017fff4** (chrsel layout loader; called 0x16f8fc from FUN_0016f45c; first loads "menu/chrsel_030_chrsel.xb", then layout `data/menu/chrselect/chrselect_layout...`).
- Count constant: 0xd6 = 214 records (`FillUnitRecords(this+0x44, this+0x14, DAT_0034151c, 0xd6)`). Group table `PTR_s_title_002e0798` (12 names): title, keyassign, second, chrsel, kigae, gearin, gear, profile, parameter, good_bad, pc_model, bg (col0 = index into this).
### dressup_unitlist.txt (string 0x2e08c0)
- **FUN_001802b4** (dress-up/"kigae" screen setup; lazily once, guarded by byte this+0x1f44; caller 0x173110 in FUN_00171714; loads "menu/chrsel_050_kigae.xb"): `FUN_002172f4(&DAT_00341520, path)`, count 0x6b = 107 (`FillUnitRecords(this+0x1f74, this+0x1f4c, DAT_00341520, 0x6b)`). Group table `PTR_s_title_002e07f8` (10): title, part_ok, part_in, part, pc_model, keyassign, box1, box2, box3, bg.

### chrsel_param_chara.csv (string 0x2ef5b0) -- TRANSPOSED per-character table
- Loader **FUN_002042c8** (existing name global_alloc_init_002042c8): `if (_DAT_0034a148==0)`: array-new (FUN_000008d8) of 15 (0xf) elements of 0x10 bytes (element ctor FUN_0020437c zero-fills 4 words) -> `_DAT_0034a148` (points at element 0), allocate csv `_DAT_0034a14c`, then `FUN_0017b030(_DAT_0034a148, csv, path, 0x10, 0xf)`. Called once-only (guard) by FUN_0016f45c (0x16f490), FUN_001a0148 lastconfirm (0x1a01c8) and FUN_001fd50c regulation (0x1fd538). Free: FUN_00204394 (callers 0x16ee88, 0x19fda8, 0x1fd304). Accessor: **FUN_00204400(charId)** -> `_DAT_0034a148 + charId*0x10` for 0<=charId<=14 else 0 (callers 0x17cc78 (in FUN_0017c968), 0x17db00 (FUN_0017dab8), 0x17de8c (FUN_0017de58); FUN_00205bc0, called from FUN_001badb0 at 0x1bade4, reads the array `_DAT_0034a148` directly (index<15, rec[0]); there is also a data pointer to FUN_00204400 at 0x39fa20).
- Layout of the file: **rows = header/meta, columns = fields**: row 0 = field names, row 1 = type char (f/i/s), row 2 = min, row 3 = max, rows 4..18 = one row per character (col 0 = label "<name><height>"; characters 0..14). `FUN_0017b030`: ncols = ColCount(row 0); for character c (0..count-1) and col k=1..ncols-1: type = cell(1,k)[0]; value = cell(c+4,k); min = cell(2,k); max = cell(3,k); stored at `base + c*stride + running_off` (4 bytes per f/i, 8 per s) only when min<=v<=max.
| col | element offset | type | name |
|---|---|---|---|
| 1 | +0x00 | f | scale (multiplies the model base scale: FUN_00205bc0 `scale = param[0x10] * rec[0]`, FUN_0017dab8 `rec[0]*x*y`) |
| 2 | +0x04 | f | capture X offset (pre-render capture; FUN_0017de58 passes rec[4], rec[8], rec[0xc] to FUN_0018ba64) |
| 3 | +0x08 | f | capture Y offset |
| 4 | +0x0c | f | capture Z offset |
- Row (character) index is the game character id (0..14, 15 characters); 5 copies of the file exist in different archives.

## 2. Status screen (menu/status_01.xb)

Owner **FUN_002392dc** (existing/likely status-menu init; marks "menu/status_01.xb" at 0x2f5324). Caller 0x00239648 in FUN_002395f8 (called from 0x23a854 in 0x23a848). Entered when the status menu opens. `this` = param_1.
| table | call | dest | notes |
|---|---|---|---|
| status_param.csv (0x2f5338) | FUN_0017ae48(this+0x18b8, csv this+0x1858) | this+0x18b8 (1 param, 4 bytes) | idx0 = blink time (点滅時間), type i |
| status_param_color.csv (0x2f535c) | FUN_0017b260(this+0x18bc, csv this+0x1888) | this+0x18bc..0x18d4: 2 rows x 3 ints | row0 = graph line-segment color RGB (+0x18bc), row1 = graph fill color RGB (+0x18c8) |
| status_param_scroll.csv (0x2f5384) | LoadCsv(this+0x18d4, path, rowKeyMap=1, 0, ",") | csv at this+0x18d4 | no header row; keys ScrollDankaiTime (0x2f53d0), ScrollTimeFast (0x2f53e4), ScrollTime (0x2f53f4), int col 1. Consumer FUN_00239a7c (4 groups of call sites 0x23a414..0x23a7a8): same select-by-held-count logic as chrsel. |
| sort.csv (0x2f53b4) | LoadCsv(this+0x1904, path, 0, 0, ",") | csv at this+0x1904 | header line = row 0 (cols: list-by-ID, 50-on order, ID, comment). **Only col 0 of rows 1..0x28 (40 rows) is read**: `FUN_00065104(this+0x1904, i+1, 0)` -> two std::vector<int> of 0x28 at this+0x1838 and this+0x1844 (both filled from col 0; the second is then sorted with FUN_0023a928 (introsort, comparator FUN_00238cc0 on the character name strings at record+4) = alphabetical/gojuon order; the first stays in ID order). **Cols 1 and 2 (gojuon order, ID) are never read** by the loader. The row count 40 is a hard-coded constant (0x28). |
| status_unitlist.txt (0x2f54a0) | FUN_0023c040(this+0x50): FUN_002172f4(&DAT_0034a6c0, path) | glob DAT_0034a6c0 | count 0xcb = 203 (`FillUnitRecords(this+0x50+0x2c, this+0x58, DAT_0034a6c0, 0xcb)`); group table PTR_s_title_002f5468 (9): title, page1_l1, page1_l2, page1, page2, page3, page4_in, page4, bg. FUN_0023c040 is called from FUN_002392dc at 0x2395a8 (after resources load) and loads "menu/status_02.xb" first. |

## 3. Regulation (rules) screen

Owner **FUN_001fd50c** (existing name init_regulation_lights_001fd50c), guarded one-shot by byte this+0x1291; callers: 0x1fd488 in FUN_001fd46c (called with `this`, flag) and 0x1fdabc in FUN_001fd7e8 (load_record_and_init). `this` = regulation object (the global at _DAT_0034a13c; accessor FUN_001fd170).
| table | call | dest | notes |
|---|---|---|---|
| reg_param.csv (0x2ef050) | FUN_0017ae48(this+0x12f4, csv this+0x1294) | 21 floats at this+0x12f4..0x1348 | idx0 +0x12f4 camera Z offset; idx1 +0x12f8 camera Y offset; idx2 +0x12fc NPC1 pos X (doubles); idx3 +0x1300 NPC2 pos X (doubles); idx4 +0x1304 facing direction; idx5-7 +0x1308..0x1310 light0 dir XYZ; idx8-10 +0x1314..0x131c light0 color RGB; idx11-13 +0x1320..0x1328 light1 dir XYZ; idx14-16 +0x132c..0x1334 light1 color RGB; idx17-19 +0x1338..0x1340 ambient RGB; idx20 +0x1344 rotation speed. All type f. Extra columns in the file (cols 5-8: notes, two proposals "案1/案2") are not read. Copied into two 0x2c0-byte camera/light blocks at this+0xcd0 (loop of 2). |
| reg_tall_param.csv (0x2ef074) | LoadCsv(this+0x12c4, path, rowKeyMap=1, 0, ",") (delim 0x2ef09c) | csv at this+0x12c4 | no header row; keys `BaseTall` (0x2ef19c), `Rating` (0x2ef1a8); `FUN_000657e4(csv, key, 1)` = float col 1. Consumer FUN_00201a84 (existing name init_match_players): `scale = FUN_00195a18(BaseTall, Rating, tall)` (header comment in file: Scale = 1 + (Tall - BaseTall) * Rating) applied per player (two players at csv `_DAT_0034a13c + 0x12c4`), passed to FUN_00093484 (set model scale). Col 2 is a note. |
| regulation_unitlist.txt (0x2ef130) | **FUN_001ffdbc**(this+200): FUN_002172f4(&DAT_0034a144, path) | glob DAT_0034a144 | FUN_001ffdbc (existing ctor_menu_regulation) called from FUN_001fd50c at 0x1fd7b8; count 0x4e = 78; group table PTR_s_title_002ef108 (10): title, keyassign, chara1, chara2, parameter1, parameter2, basic, vs, under, bg. Layout `data/menu/regulation/regulation_layout...` (0x2ef160). |

## 4. Last confirm screen (menu/lastconfirm_10.xb)

Owner **FUN_001a0148** (existing name lastconfirm_init_001a0148). Caller: 0x1a194c in FUN_001a1828 (flow_state_update; called from 0x1a4c38 in 0x1a4c1c). There is **no unitlist** in this screen's loader. It also calls FUN_002ada80 (score->grade, see 9) at 0x1a0484 and FUN_002042c8 (chara table).
| table | call | dest | notes |
|---|---|---|---|
| lastconfirm_param.csv (0x2e1c34) | FUN_0017ae48(this+0x424, csv this+0x3c4) | this+0x424, 2 x 4 bytes (to 0x42c) | idx0 = decide-pose time (決めポーズ時間, i); idx1 = flame animation speed (炎 アニメーション速度, i) |
| lastconfirm_param_color.csv (0x2e1c60) | FUN_0017b260(this+0x42c, csv this+0x3f4) | this+0x42c..0x450, 3 rows x 3 ints | row0 = top-menu unselected (layer m_info), row1 = top-menu selected (m_info), row2 = "iromono" selected (layer ir_menubg0) |
- Same function also loads (not in my list) `data/common/rule/Rule_Iromono.txt` (0x2e1c94): `LoadCsv(this+0x450, path, rowKeyMap=1, 0, "\t")`.

## 5. Result screen status unit list

### result_status_unitlist.txt (0x2ebd78)
- **FUN_001e1c40(this)** (existing init_result_status_001e1c40): `FUN_002172f4(&DAT_0034a130, path)`; caller 0x1e0728 in FUN_001e05d4 (ctor_subobjects, itself called from 0x1f2a68 in FUN_001f2954). Layout (this+0x9b4) = `data/menu/result/result_status/result_status_layout...` (0x2ebdb4). Count 0x7b = 123 (`FillUnitRecords(this+0x9cc, this+0x9b8, DAT_0034a130, 0x7b)`). Group table PTR_s_game_set_mode_002ebbb8 (5): game_set_mode, mainfinfo, subinfo, etcinfo, bg.

## 6. Prize / result-points scene (game/700_prize_005_param.xb)

Constructor **FUN_001ee248(this)** (object size 0x81d0, vtable 0x3094e0; allocated in scene_set_state_00088a44 at 0x891b8 into param_1[0x28]). Loads at construction after `FUN_0001ca58("game/700_prize_005_param.xb")`.
| table | call | dest (csv obj inside prize object) | delim | notes |
|---|---|---|---|---|
| Point_ShopPoint.txt (0x2ee76c) | LoadCsv(this+0x10cc [=param_1+0x433 words], path, **rowKeyMap=1, colKeyMap=1**, "\t" 0x2ee78c) | this+0x10cc | TAB | header: Label, VALUE1, VALUE2, ENTRY. Keyed row = Label, col key `VALUE1` (0x2ee988). Consumers: FUN_001f64d4 (sets this+0x1090 = float(VALUE1) of row `Rank_0`+rank via FUN_000655f8(csv, rowIdx, "VALUE1"), and reads int VALUE1 via FUN_000653ac(csv, key, "VALUE1") for keys Line, S_Ace, R_Ace, Sm_Ace, Keep, Break, Love, Doble (0x2eea84..), and win_0/1/2, Lose_0/1/2, d_win_0/1/2, d_Lose_0/1/2 (0x2eeac4..0x2eeb28) depending on result); caller 0x1f928c in FUN_001f898c. Accessor `FUN_001ee234()` returns `*(_DAT_003386b0+0xa0)+0x10cc` (used by FUN_00119040 at 0x119210 and via data ptr 0x398848) - external code reads the same table by key (Line, S_Ace, R_Ace, Sm_Ace, Keep, Break, Love, Doble, ...). **VALUE2 and ENTRY (display label) are never read** (no "VALUE2" string in EBOOT). Row keys in file (identifiers): Line, S_Ace, R_Ace, Sm_Ace, Keep, Break, Love, Doble, Hard, AirShot, Rising, Rank_0..Rank_16, win_0..2, Lose_0..2, d_win_0..2, d_Lose_0..2. |
| rank_param.csv (0x2ee790) | LoadCsv(this+0x5f8 [=param_1+0x17e words], path, rowKeyMap=1, 0, "," 0x2ee450) | this+0x5f8 | COMMA | header: label,値. Two rows keyed `A` (0x2ee8f4) and `B` (0x2ee8f8); float col 1 via FUN_000657e4. Consumer **FUN_001f4f80** (existing set_scaled_floats; called 0x1f911c in FUN_001f898c): rating-point delta = A*0.01 + B*(otherRating - myRating) clamped to constant bounds -> this+0x5e8, new rating -> this+0x5ec. |
| Rank_PlayersRanked.txt (0x2ee7ac) | LoadCsv(this+0x1054 [=param_1+0x415 words], path, rowKeyMap=1, 0, "\t") | this+0x1054 | TAB | header: RANK, UP, DOWN. Keys Rank_000..Rank_016 (17 rows). Consumer **FUN_001f6108** (called 0x1f926c in FUN_001f898c): `row = FindRowByKey("Rank_000") + curRank` (0x2ee944), ints col 1 (UP) and col 2 (DOWN) = points thresholds for promotion / demotion (results used by the rank-up logic at the end of that function). |
- All three csvs are members of the prize object; destruct at FUN_001ee998 (0x1ee998 frees this+0x10cc). Related (not mine): score.csv (see 9) is used by the same score-calc function FUN_001f7f64.

## 7. Shop

### Item.csv (`data/menu/shop/Item.csv`, string 0x2ffbcc)
- **FUN_00293bd4** (existing initialize_object_if_absent): allocates global csv `_DAT_0034a84c` (0x10 bytes, ctor FUN_000649c0) and `load(csv, path, skipHeader=1, ",")` (delim 0x2ffbe4). On failure deletes it and nulls the pointer. Called once at boot from FUN_00047054 (0x475e4) after "common/common_50.xb".
- **FUN_00293c6c(list)** (existing shop_item_table_00293c6c): same lazy-load of the csv (if null), then: `list` = 8-element array (array-new ctor FUN_00293acc, 0xc stride; FUN_00293a34 constructs it) of `std::vector<Rec>` {begin,size,cap} at list+cat*0xc where `Rec` = 5 x s16 (10 bytes). First pushes 4 default Recs {0xffff,0,0,0,0} into vector 6 (Judge_), then for each csv row r=0..N-1 (rows start at 0 because skipHeader=1): category chosen by `strstr(cell(r,0), prefix)` in this order: 0 `Item_Cam` (0x2ffbe8), 1 `Item_CD` (0x2ffbf4), 2 `Item_Voice` (0x2ffbfc), 3 `Item_JudgeVoice` (0x2ffc08), 4 `Item_Wallpaper` (0x2ffc18), 5 `Item_Tickets` (0x2ffc28), 6 `Judge_` (0x2ffc38). **If no prefix matches the category register keeps its previous value (initially uninitialised/stale)** - possible latent bug, harmless for shipped data.
| col | Rec offset | width | header name | meaning |
|---|---|---|---|---|
| 0 | - | string | Label | item id string, used only to choose the category vector (strstr) |
| 1 | +0 | s16 | Get | |
| 2 | +2 | s16 | Price | |
| 3 | +4 | s16 | No | item number |
| 4 | +6 | s16 | GetLobby | |
| 5 | +8 | s16 | GetPer | |
- Callers of FUN_00293c6c: FUN_0026d224 shop scene init (0x26d46c, list = shop_obj+0x920), FUN_0026ef04 (0x26f188, local list auStack_60, followed by count FUN_00293b7c(list,cat) = `*(list+cat*0xc+4)` and FUN_00293ae0), FUN_00279b7c (0x279f38), FUN_001c0c0c (0x1c0cb4; lobby, local list). The csv object is only referenced by those two functions.

### chrsel_param_scroll.csv read by the shop (0x2fe1dc) in **FUN_0026d224** (existing shop_scene_init_0026d224; caller 0x26cdf8 in FUN_0026cc00)
- raw `load(local csv, path, skipHeader=0, ",")` (delim 0x2fe208); rows 0,1,2 col 1 as ints: `shop+0x98c` = row0, `shop+0x990` = row1, `shop+0x994` = row2, i.e. ScrollTime, ScrollTimeFast, ScrollDankaiTime in file order (file order differs from the keyed chrsel/status usage but matches: consumer FUN_002708ac: `if (held > [0x994]) [0x998] = [0x990] else [0x998] = [0x98c]`). The csv is destructed at the end (0x26d..: FUN_00064a08).

## 8. Challenge (lobby)

Owner **FUN_001c51dc** (lobby scene first-state, runs when `this+200 < 2`; caller 0x1c4dac in FUN_001c4704). Loads xbs lobby_010 common_010/015/020/030/040, `data/lobby/lobby.csv` (0x2ea57c, raw load skipHeader=1 into `*(this+0x178)`, delim `,` 0x2ea594; not mine), then the call **FUN_0028af58(this->0x17c object, "data/menu/challenge/Challenge_LobbyItem.txt" (0x2ea598), "data/menu/challenge/Challenge_PointXXX.txt" (0x2ea5c4), "data/lobby/effect.csv" (0x2ea5f0))** at 0x1c5688. FUN_0028af58 is a "ChallengeLobbyItemTable::Load" (clears the object via FUN_0028b5f4 first). Object (param_1) layout: `+0x00` vector<LobbyItemRec> (begin,size,cap, elem 0x60); `+0x0c` vector<PointRec> (elem 8); `+0x18` vector<EffectRec> (elem 0x1c); `+0x24` int sum of PointRec.per.
Local csvs use `LoadCsv(local, path, rowKeyMap=0, colKeyMap=1, "\t")` for the .txt files (delim 0x2fed4c = TAB) and `","` (0x2fedac) for effect.csv; header row 0 provides the column names; data rows 1..N-1. Cells are read by column **name** (FUN_00065554 int, FUN_000655f8 float, FUN_0006569c string).

### Challenge_LobbyItem.txt -> LobbyItemRec (0x60 bytes)
| col name (string addr) | getter | rec offset | width | notes |
|---|---|---|---|---|
| Lobby (0x2fed50) | int | +0x00 | s32 | lobby id |
| Room (0x2fed58) | int | +0x04 | s32 | |
| Point (0x2fed60) | int | +0x08 | s32 | |
| OBJ (0x2fed68) | int | +0x0c | s32 | |
| Re (0x2fed6c) | int | +0x10 | s32 | |
| Item (0x2fed98) | string -> `FUN_0028b654(obj, str, &type, &id)` | +0x14 type, +0x18 id | s32,s32 | see parser below |
| GetPer (0x2fed78) | float * 0.01 | +0x1c | f32 | stored as fraction |
| Text_1 / Text_2 / Text_3 (0x2fed80/88/90) | int | +0x20 / +0x24 / +0x28 | s32 | |
| ReType (0x2fed70) | int | +0x2c | u8 | stored as `(ReType == 0)` |
| SE1 (0x2feda0) | string, strncpy 0x18 + NUL | +0x2e..+0x46 | char[0x19] | empty -> zero-filled |
| SE2 (0x2feda4) | same | +0x47..+0x5f | char[0x19] | |
- Item-string parser **FUN_0028b654(self, str, int *outType, int *outId)**: copies str, `strrchr(copy,'_')` (FUN_00014cfc = strrchr), cuts there, skips to first digit, `outId = atoi(rest)`; `outType` from the prefix by strcmp (FUN_00014934): `Head`=1, `Body`=2, `Acce`=3, `Racket`=4, `Court`=5, `Judge`=6, `Item_Cam`=7, `Item_CD`=8, `Item_Voice`=9, `Item_JudgeVoice`=10, `Item_Wallpaper`=11, `Item_Tickets`=12, `Item_Stamp`=13, `Point`=14, `Kunsyo`=15, `P_Set`=16; empty/NULL/no-match -> type=-1, id=-1 (strings at 0x2fedd8..0x2fee6c).

### Challenge_PointXXX.txt -> PointRec (8 bytes)
- header: Point, Per. For each row: `FUN_0028b654(string(row,"Point"))` -> (type,id); **only rows whose type == 14 (`Point`)** are kept: PointRec{ +0 s32 id (the number parsed from e.g. "Point_PTnnn"), +4 s32 Per (int col "Per" 0x2feda8) } pushed to the vector at obj+0x0c; obj+0x24 += Per. (Weighted-random table for the point-prize items; Per sum is the total weight.)

### data/lobby/effect.csv (not in my list, same function)
- header-named columns: Lobby, Object, Effect, Frame (each stored as s16), Scale (float), Node (string, 9 chars): EffectRec (0x1c): +0 s16 Lobby, +2 s16 Object, +4 s16 Effect, +6 s16 Frame, +8 s16 = 0xffff (runtime), +0xc f32 Scale, +0x10 char[9] Node.

### Challenge_AdhocTable.txt (`data/menu/challenge/Challenge_AdhocTable.txt`, path string 0x2fe898, delim `\t` 0x2fe8c8)
- **FUN_002800ac(obj)** (existing FUN_002800ac_002800ac; constructor of the "AdhocTable" holder; global `_DAT_0034a7f0 = obj`; obj+0 = csv (alloc 0x10, ctor FUN_000649c0); `load(csv, path, skipHeader=1, "\t")`). Created once at boot: allocated (4 bytes) and constructed in the game-manager constructor **FUN_0008be64 (call at 0x8c06c)**, itself called from the global game-object ctor FUN_0008cb68 (0x8cd60), called from the boot routine FUN_00047698 (0x47714). Destroy: FUN_00280114 (deletes csv, nulls global) called from FUN_0008c248 (0x8c2d4).
- Accessor **FUN_00280188(obj, u8 *outRank, int level, int npcSlot)** (existing pair_pick_00280188): for every row (rows start at 0): `if int(col0 "LEVEL") == level` collect `string(col 2+npcSlot)` (NPC1 for slot 0, NPC2 for slot 1) and `string(col1 "RANK")` into two vectors; then picks a random matching index (`FUN_0001342c % count`) and returns the NPC string; `*outRank = atoi(RANKstring + 5)` (string is of the form `Rank_NNN`); returns 0 if no match. Cols FRAG (4), NAME (5), FORMAT (6) are **not read by this code**. Consumer FUN_002817e0 (0x281840, 0x28192c; called from 0x263c98/0x263cb4 in FUN_00263a40 and 0x28df50 in FUN_0028df14) for `level = *(this+0x84)` of the ad-hoc challenge session: picks 2 NPC names (slots 0 and 1), builds two player records at this+0x648.. and this+0x768...
- **FUN_00280830, FUN_0029bf68, FUN_0029e160 are NOT loaders**: they only reference the string block `"MTP1A000\0MTP1A001\0data/menu/challenge/Challenge_AdhocTable.txt"` at 0x2fe888 (the xref hit is the neighbouring ad-hoc product-ID strings MTP1A000/MTP1A001, selected by session mode), they are ad-hoc/game-sharing session setup functions (FUN_00280830 creates the 0x288-byte network object FUN_000ba2a8 and sets product id; FUN_0029e160 references "menu/game_sharing_recv.xb").

## 9. Prize score table

### score.csv (`data/prize/score.csv`, string 0x302c54)
- **FUN_002ada5c** = `LoadCsv(0x34b5a0, path, rowKeyMap=1, 0, ",")` (delim 0x302c6c) into the global csv object at **0x34b5a0** (no explicit constructor found; zero-initialised BSS). Called once at boot from FUN_00047054 (call 0x475bc), right after FUN_002af8f4.
- No header row (row 0 is data). Keys (col 0) and use: `Kansyo`, `Syori`, `Sinsyo`, `Sekihai`, `Haiboku` (0x302c5c..0x302c90) - read as int col 1 by **FUN_002ada80(score)** (score -> grade 0..5: >=Kansyo ->5, >=Syori ->4, >=Sinsyo ->3, >=Sekihai ->2, >=Haiboku ->1, else 0; callers 0x1a0484 (lastconfirm), 0x1fab10, 0x250e1c/e90/f04, 0x2acec0/f30); `perKansyo`, `perSyori` (0x2eec10/0x2eec1c) - int col 1, thresholds on win-percentage (FUN_001f7f64 at 0x1f8214..); `score50`, `score65`, `score80`, `score100` (0x2eecd0/c8/c0/b4) - used as row anchors with FUN_0006531c(row) and then `int(row,1)`, `int(row+1,1)` (this row's and the next row's value) to interpolate the score; `scoreMax`, `Kanpai` are present in the file but not referenced by name by the EBOOT code I saw. Col 2 (trailing) is never read. Consumer function: **FUN_001f7f64** (prize/result score calculation, in the 0x81d0 prize object; 14 references).

## 10. Main menu

### toplady.csv (`data/menu/mainmenu/toplady.csv`, path string 0x2cc1a4; delim 0x3006f4 = `,`)
- **FUN_002a03c0(this)** = constructor of the main-menu "top lady" (guide girl) model object (vtable 0x309e9c, base ctor FUN_00056b98). Called once with `puVar3+0xa4` words (= main menu object + 0x290) from **FUN_001cf798** (main-menu scene object ctor; called 0x8c560/0x8c630/0x8c794 in FUN_0008c434, i.e. at game-manager init). Loads 43 (0x2b) motion files (`toplady_wait_NN.i3m` etc. via PTR table 0x3005ac) then builds the motion table:
- raw `load(local csv, path, skipHeader=0, ",")`, **no header** (141 rows, 4 columns). Allocates `TopLadyMotionTable` (0x10c bytes) = this+0x1cc (param_1[0x73]):
  - `+0x00` int total row count = RowCount(csv); `+0x04` ptr to zeroed array of `rows*0x10`; `+0x08` int group count = `FUN_002a0b78(motionDb)` where motionDb = `FUN_0018c9f4(0x14)` (entry 0x14 of the global model/motion database at `_DAT_003415b0`, stride 0x10); `+0x0c..` int[groups+1] cumulative first-row index of each group (group size = `FUN_002a0b5c(motionDb, g)`).
  - Rows are consumed strictly in file order, group by group: row k of the csv is the k-th motion entry (groups in order, entries in order, pointer = `FUN_0018f1ac(motionDb, group, idx)`).
  - Element (0x10 bytes): `+0x00` ptr = motion entry (from motionDb); `+0x04` int = **col 2**; `+0x08` int = **col 1**; `+0x0c` int from **col 3** string first char: NULL/empty -> 0, `I` -> 1, `S` -> 2, `E` -> 3 (looks like Idle/Start/End motion kind; guess). Col 0 is never read (a comment/name).
- The same constructor also reads the menu-lady window placement from the shared menu parameter csv returned by `FUN_0008d9a0(_DAT_003386c8)`: keys `MenuLady_WIN_POS_X` (0x2cc298, float, col 2), `MenuLady_WIN_POS_Y` (0x2cc284, float), `MenuLady_WIN_WIDTH` (0x2cc270, int), `MenuLady_WIN_HEIGHT` (0x2cc25c, int), `MenuLady_LEAD_POS_Y` (0x2cc248, int) with `FUN_000657e4/65740(csv, key, 2)` -- that csv is probably `data/menu/scene.csv` (not in my list; unresolved which one).

---
## Proposed names (loader -> descriptive name)
- 0x000651b8 `LoadCsvTable` (csv, path, buildRowKeyMap, buildColKeyMap, delim); 0x00064bf4 `CsvLoad`; 0x00065740 `CsvGetIntByRowKey`; 0x000657e4 `CsvGetFloatByRowKey`; 0x0006531c `CsvFindRowByKey`; 0x000653ac/00065480 `CsvGetInt/FloatByRowColKey`; 0x00065554/000655f8/0006569c `CsvGetInt/Float/StringByColKey`.
- 0x0017ae48 `LoadMenuParamCsv` (packed f/i/s array); 0x0017b260 `LoadMenuColorCsv` (packed RGB ints); 0x0017b030 `LoadTransposedPerCharaCsv`; 0x002172f4 `LoadUnitList`; 0x00216f14 `FillUnitRecordsFromList`; 0x00216e90 `LookupLayoutGroups`.
- 0x0016f45c `ChrSelect_LoadParamsAndLayout`; 0x0017fff4 `ChrSelect_LoadLayoutAndUnitList`; 0x001802b4 `DressUp_LoadLayoutAndUnitList`; 0x002042c8 `LoadChrSelParamChara`; 0x00204400 `GetChrSelParamChara(charId)`; 0x00204394 `FreeChrSelParamChara`. Structs: `ChrSelParams` (0x78 B, 30 fields, names above), `ChrSelColors` (17 x RGB int), `ChrSelParamChara { f32 scale; f32 captureOffsetX, captureOffsetY, captureOffsetZ; }` (0x10 B x 15), `UnitListRec { u8 groupIdx; char name[0x20]; }` (0x21 B), `UnitRef { void *unit; int u9; int pad[2]; void *vtbl; }` (0x14 B).
- 0x002392dc `StatusMenu_LoadParamsAndSort`; 0x0023c040 `StatusMenu_LoadLayoutAndUnitList`; struct `StatusParams { i32 blinkTime; }`, `StatusColors { i32 graphLine[3]; i32 graphFill[3]; }`, scroll csv keys ScrollTime/ScrollTimeFast/ScrollDankaiTime.
- 0x001fd50c `Regulation_InitOnce`; `RegParams` (21 floats: camZ, camY, npc1PosXDoubles, npc2PosXDoubles, facing, light0Dir[3], light0Color[3], light1Dir[3], light1Color[3], ambient[3], rotSpeed); 0x001ffdbc `Regulation_LoadLayoutAndUnitList`.
- 0x001a0148 `LastConfirm_Init`; `LastConfirmParams { i32 decidePoseTime; i32 flameAnimSpeed; }`, `LastConfirmColors { i32 menuUnselected[3]; i32 menuSelected[3]; i32 iromonoSelected[3]; }`.
- 0x001e1c40 `ResultStatus_LoadUnitList`.
- 0x00293bd4 `ShopItem_PreloadCsv`; 0x00293c6c `ShopItemTable_Build`; struct `ShopItemRec { s16 get, price, no, getLobby, getPer; }` in `std::vector<ShopItemRec> byCategory[8]` (categories: Cam, CD, Voice, JudgeVoice, Wallpaper, Tickets, Judge).
- 0x001ee248 `PrizeScene_ctor` (loads Point_ShopPoint, rank_param, Rank_PlayersRanked); 0x001ee234 `GetPrizeShopPointCsv`; 0x001f4f80 `Prize_ComputeRatingDelta` (A,B from rank_param.csv); 0x001f6108 `Prize_ComputeRankUpDown` (Rank_PlayersRanked); 0x001f64d4 `Prize_ComputeShopPoints` (Point_ShopPoint); 0x001f7f64 `Prize_ComputeScore` (score.csv); 0x002ada5c `LoadScoreCsv`; 0x002ada80 `ScoreToGrade`.
- 0x001c51dc `ChallengeLobby_Init`; 0x0028af58 `ChallengeLobbyItems_Load`; 0x0028b654 `ParseChallengeItemString`; structs `ChallengeLobbyItemRec` (0x60), `ChallengePointRec { s32 id; s32 per; }`, `LobbyEffectRec` (0x1c). 0x002800ac `AdhocTable_ctor`; 0x00280188 `AdhocTable_PickNpc(level, slot, &rank)`; 0x00280114 `AdhocTable_dtor`; 0x002817e0 `AdhocChallenge_SetupOpponents`.
- 0x002a03c0 `TopLady_ctor` (loads toplady.csv); struct `TopLadyMotionTable`, `TopLadyMotionEntry { void *motion; i32 col2; i32 col1; i32 kind; }`.

## Unresolved / not verified
- Actual meaning (semantic role, not just name) of every consumer field (e.g. which UI element uses chrsel_param idx 27 "NOW LOADING scale") - names are taken from the file headers; I verified the packed-offset mapping only for reg_param (against the code that reads +0x1308..+0x1340) and chrsel_param_chara.
- toplady.csv: column semantics (col 1, col 2) and the I/S/E code meaning are unknown; row <-> motion group mapping is inferred from loop structure (motionDb group sizes). Which game-database entry 0x14 is (motion list "toplady") was not traced.
- The CSV object for `score.csv` (0x34b5a0) has no explicit constructor call that I could find; assumed BSS zero state is acceptable to the loader. Same for `_DAT_0034a84c` Item csv (allocated with ctor, fine).
- `FUN_002172f4` allocation size is passed in a hidden register at the call to 0x00000a90; I assumed rowCount*0x21 from the 0x21 stride used by FillUnitRecords.
- Shop (`FUN_0026d224`) reads `chrsel_param_scroll.csv` by row position (0,1,2) whereas chrsel/status read it by key; relies on file order (ScrollTime, ScrollTimeFast, ScrollDankaiTime in the shipped file).
- 0x00186378 (listed under chrsel_param_color) is **not** a loader: it sets visibility of five 3-star stat gauges (FUN_000ffb3c on unit-array elements at this+0x1f74/0x2500) from a character's stat levels read at FUN_0016bc70()+0x588; the only link is address proximity to the 0x2e0988 data. Chrsel color is loaded only by FUN_0017b260 in FUN_0016f45c.
- Who consumes each chrsel_param_color row and each status/lastconfirm color row (UI code) was not traced.
- The five per-language copies of unitlist/chara files can have different row counts; callers use fixed counts (214/107/203/78/123/40/15), so shipped alternative files must keep the same count.

## Surprises
- Challenge_AdhocTable.txt: only cols LEVEL, RANK, NPC1, NPC2 are used (FRAG, NAME, FORMAT unread); RANK is parsed as `atoi(str+5)` from "Rank_NNN".
- sort.csv: only col 0 is read (both arrays); gojuon order is done at runtime by sorting names, not from the file.
- Point_ShopPoint VALUE2/ENTRY unread; score.csv col 2 unread; `scoreMax`/`Kanpai` rows not referenced by name.
- The three "challenge adhoc" functions (0x280830, 0x29bf68, 0x29e160) in the task list are false leads (they share the string block with MTP1A000/MTP1A001).
- Item.csv category selection falls through to a stale value if the label matches no prefix (uninitialised register s1).
- LoadMenuParamCsv / LoadMenuColorCsv drop out-of-range values and shift all later parameters (positional packing hazard when editing files).
