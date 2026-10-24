# g3-camera-court-lobby: loader analysis (private; column names / strides / enum names only, no cell values)

All addresses are EBOOT module-relative (retail selected.elf). "mgr" = the owning object. Getter kinds: I = FUN_00065104 (int), F = FUN_00065140 (float), S = FUN_0006517c (c-string, NULL for numeric cells), named variants FUN_00065554 (int by col name), FUN_000655f8 (float by col name), FUN_0006569c (string by col name), FUN_00065364 (col name -> col index or -1), FUN_00065480 (float by rowKey,colName), FUN_000657e4 (float by rowKey, col index).

## 0. Reader facts discovered on the way (add to the reader notes)
- Cells are typed when a line is split (FUN_00064820 builds one object per cell): text cell (vtable 0x307124) if the cell is empty or contains anything except digits, '.', '-'; float cell (vtable 0x307100) if it has a '.'; int cell (vtable 0x3070dc) otherwise. The string getter (vtable +0x14) therefore returns NULL for numeric cells. Cameradatabase cols 17/18 use exactly this: `if (getString(...) <= 0) int path else symbolic path`.
- FUN_00064bf4 drops empty lines (strtok-style), so row r = r-th NON-EMPTY line after the (optionally skipped) header. Cells are split on a single-char delimiter, consecutive delimiters give empty text cells.
- FUN_000650e8(reader,row) = number of cells in that row (row struct is {begin,count,cap}, 12 bytes). FUN_000650e0 = row count.
- Keyed variant FUN_000651b8(this, path, makeRowKeyMap, makeColKeyMap, delim): loads with skipHeader=0 (so row 0 = header line), then if makeRowKeyMap builds map(col0 text of each row -> row index) at this+0x10, if makeColKeyMap builds map(row-0 cell text -> col index) at this+0x20. Lookups: FUN_00065364(colName)->idx; FUN_00065554/6569c/655f8(this,row,colName); FUN_00065480(this,rowKey,colName); FUN_000657e4(this,rowKey,colIdx). Data rows therefore start at row 1 in every keyed table.
- strstr = FUN_00014d64 (returns pointer or NULL). ALL camera string->enum parsers are SUBSTRING matches in a fixed priority order (first listed wins). strcmp = FUN_00014934. strlen = FUN_00014a40, strcpy = FUN_000149a8, sprintf = FUN_000143b0, atoi = FUN_0000d62c.
- Shared "Stage" class (vtable 0x308244 base ctor FUN_0013fb58) is the common base of the court stage (sub-object at CourtMgr+0x40, vtable 0x308228) and the lobby stage (LobbyMgr+0, vtable 0x308108). Light/fog/areaclip/SE loaders operate on this Stage object. Offsets below marked "stage+" are relative to it. Court stage = CourtMgr+0x40, so stage+X = CourtMgr+0x40+X.

---------------------------------------------------------------------------------------------------

## 1. data/camera/cameradatabase.csv  (COMMA, skipHeader=1, 32 columns)
- Loader: FUN_0012f698(camMgr, ...) = LoadCameraDatabase (also loads camera_nearfar.txt, section 2). Caller: camera manager ctor FUN_0012f41c (call at 0x12f5e0). That ctor is called from the match-scene state machine FUN_00088a44 case 0 (call at 0x89190), i.e. every time a match scene starts (not at boot). Ctor sets global `_DAT_00340284` = camMgr (vtable 0x3081f0, alloc 0x140). Before the load the ctor zero-initialises all records (see +0x40 below). Also calls FUN_0001ca58 to open "game/500_ookubo/cameradata.xb" before and FUN_0001cb88 after (resource scope).
- Destination: global array at 0x33b584, stride 0x58, 0xe0 records (0x4d00 bytes; next global 0x340284 = the manager pointer). Record index is NOT the row number; it is a running counter:
  - Rows whose col0 contains "REPLAYCAMERA" set counter = 0x00; "GUTSCAMERA" -> 0x80; "SET" -> 0xc0 (strstr test on col0, in that order). The marker row is consumed (row skipped). Each following data row is stored at the counter, counter++.
  - Sections: REPLAYCAMERA 0x00-0x7f, GUTSCAMERA 0x80-0xbf, SET 0xc0-0xdf. The shipped file has all three markers (header line, REPLAYCAMERA row, 129 data rows [one more than 0x80 slots: record 0x80 is first written by replay row 129 then overwritten by the GUTS section], GUTSCAMERA row, 39 rows, "SET" row, 21 rows). No bounds check on the counter.
  - Col 0 (label) is used only for the marker test; it is not stored.
- Post pass (0x12f698 tail): for i in 0..0xdf: if rec[i].count(+0x40) < 1 -> 0; else count=1 and every later record j with the same group id (s16 +0x44) gets count(i)++ and rec[j].count = 0. So +0x40 = number of records in the group, stored on the FIRST record of each group, 0 on the others. Quirk: the ctor initialises +0x40 = 1 and group = 0 for all 0xe0 records, so never-loaded records also form a "group 0" with any real group-0 record.

Record layout `CameraDbEntry` (0x58 bytes):

| col | header (JP) | getter | dest off | width | meaning |
|---|---|---|---|---|---|
| 0 | label / section marker | S + strstr | - | - | marker test only |
| 1 | camera angle | F | +0x00 | f32 | angle |
| 2 | camera distance | F | +0x04 | f32 | distance |
| 3 | field of view | F | +0x08 | f32 | FOV |
| 4 | camera height | F | +0x0c | f32 | height |
| 5 | camera position ref point | S->FUN_0012fdb0 | +0x4a | u8 | RefPoint enum |
| 6 | gaze point height | F | +0x10 | f32 | |
| 7 | gaze X offset | F | +0x14 | f32 | |
| 8 | gaze Z offset | F | +0x18 | f32 | |
| 9 | gaze point ref point | S->FUN_0012fdb0 | +0x4b | u8 | RefPoint enum |
| 10 | damper ref point | S->FUN_0012fdb0 | +0x4c | u8 | RefPoint enum |
| 11 | camera vibration | S->FUN_00130074 | +0x4d | u8 | Trigger enum (shake trigger event) |
| 12 | how to move to next camera | S->FUN_0012ffac | +0x4e | u8 | Transition enum |
| 13 | switch-frame reference | S->FUN_00130074 | +0x4f | u8 | Trigger enum |
| 14 | diff from reference | F | +0x1c | f32 | frames/offset from the reference event |
| 15 | camera type | S->FUN_00130174 | +0x50 | u8 | CameraType enum |
| 16 | group ID | I | +0x44 | s16 | group id (see post pass) |
| 17 | next camera 1 (ID or type) | S->FUN_00130274 if text else I | +0x46 | s16 | next camera id, or 50/60/999 for TO_LONG/TO_FINISH/NOLOOP |
| 18 | next camera 2 | same | +0x48 | s16 | |
| 19 | lottery ratio | I | +0x34 | s32 | weight for random pick |
| 20 | condition 1 | S->FUN_00130304(str, &rec+0x38) | +0x51 (id) , +0x38 (s32 param) | u8 + s32 | Condition enum + numeric parameter/bitmask |
| 21 | condition 2 | S->FUN_00130304(str, &rec+0x3c) | +0x52 (id) , +0x3c (s32 param) | u8 + s32 | same |
| 22 | PC-down (knocked down) limit | I | +0x53 | u8 | |
| 23 | collision | I | +0x54 | u8 | |
| 24 | camera clipping | I | +0x55 | u8 | |
| 25 | 2-point fixed damper ref A | S->FUN_0012fdb0 | +0x56 | u8 | RefPoint enum |
| 26 | ref B | S->FUN_0012fdb0 | +0x57 | u8 | RefPoint enum |
| 27 | A fixed pos x | F | +0x20 | f32 | |
| 28 | A pos y | F | +0x24 | f32 | |
| 29 | B fixed pos x | F | +0x28 | f32 | |
| 30 | B pos y | F | +0x2c | f32 | |
| 31 | fixed camera height | F | +0x30 | f32 | |
| - | (runtime) | - | +0x40 | s32 | group member count (set by post pass; ctor init 1) |

(The type of the byte at +0x4d..+0x4f etc. is from stores `sb`. Ctor does not initialise +0x4d.) Unused/untouched in the loader: nothing else in 0x58.

### String->enum parsers (all substring matches; empty/NULL/no-match -> 0)
- FUN_0012fdb0 RefPoint (cols 5, 9, 10, 25, 26): 0 CENTERCOURT (also the default), 1 BALL_NOW, 2 BALLSHADOW_NOW, 3 SHOT_LAST, 4 BOUND_LAST, 5 PLAYER_NOW, 6 RIVAL_NOW, 7 SERVER_NOW, 8 RECIEVER_NOW (sic), 9 LASTSHOTPLAYER, 10 ONNET, 11 BASELINE, 12 BASECENTERLINE, 13 OPPOSITESIDE, 14 JUDGE, 15 HITGIMMICK. (Test order: CENTERCOURT, BALL_NOW, BALLSHADOW_NOW, SHOT_LAST, BOUND_LAST, PLAYER_NOW, RIVAL_NOW, SERVER_NOW, RECIEVER_NOW, LASTSHOTPLAYER, ONNET, BASELINE, BASECENTERLINE, OPPOSITESIDE, JUDGE, HITGIMMICK.) Note CENTERCOURT matched first gives 0.
- FUN_0012ffac Transition (col 12): 0 none, 1 NORMALLINEAR, 2 NORMALSECOND, 3 VALUELINEAR, 4 INSTANT, 5 CROSSFADE.
- FUN_00130074 Trigger/event (cols 11, 13): 0 none, 1 SERVICE, 2 REPLAYSTART, 3 SHOT_LAST, 4 BOUND_FIRST, 5 BOUND_LAST, 6 FINISHCAM, 7 HITGIMMICK.
- FUN_00130174 CameraType (col 15): 0 none, 1 SERVICEREPLAY, 2 LONGREPLAY, 3 SHORTREPLAY, 4 FINISHREPLAY, 5 GUTS, 6 CUTIN, 7 MATRIX. (Test order SERVICEREPLAY, LONGREPLAY, SHORTREPLAY, GUTS, FINISHREPLAY, CUTIN, MATRIX.)
- FUN_00130274 NextCamera symbolic (cols 17, 18 when the cell is text): TO_LONG -> 50 (0x32), TO_FINISH -> 60 (0x3c), NOLOOP -> 999, else 0. Numeric cells are taken as plain camera IDs.
- FUN_00130304 Condition (cols 20, 21), returns id; param3 pointer receives a numeric parameter (record +0x38 / +0x3c, preset 0 by ctor):
  1 SMASHACE, 2 SERVICEACE, 3 ONTHELINE, 4 COURTLIMIT (text "COURTLIMITnn/nn/..." : each 2-digit nn sets bit nn in the param, '/'-separated), 5 ITEM ("ITEMnn": 2-digit param at text[4..5]), 6 PCLOVE ("PCLOVEnn": 2-digit at [6..7]), 7 NOTIEBREAK, 8 NOADHOC, 9 FASTBALL, 10 HITGIMMICK ("HITGIMMICKnnn": 3-digit at [10..12]), (11 unused), 12 CUT_TOBITUKI, 13 CUT_SMASH, 14 CUT_GIMMICK ("CUT_GIMMICKnnn": 3-digit at [11..13]); no match -> 0. Test order: SMASHACE, SERVICEACE, ONTHELINE, COURTLIMIT, ITEM, PCLOVE, NOTIEBREAK, NOADHOC, FASTBALL, HITGIMMICK, CUT_TOBITUKI, CUT_SMASH, CUT_GIMMICK.
- All eight parsers are plain functions of (unused param_1, char* str[, u32* out]); param_1 passed is the camMgr.

---------------------------------------------------------------------------------------------------

## 2. data/camera/camera_nearfar.txt  (TAB, keyed table, 3 columns: Label / ENTRY / VALUE)
- Loader: same function FUN_0012f698, tail (0x12fc28-0x12fd..). Uses a local keyed reader (vtable 0x3070bc) via FUN_000651b8(reader, path, 1, 1, "\t") then FUN_00065480(reader, rowKey, "VALUE") for 11 row keys. Skipped if the file fails to load.
- Row keys (literal strings in the EBOOT, pointer array at 0x2daea0): "s_NearMin", "s_NearMax", "s_FOVMin", "s_FOVMax", "s_FOVRatioMin", "s_FOVRatioMax", "s_FarMin", "s_FarMax", "s_HeightMin", "s_HeightMax", "s_CointossNear". Column read: "VALUE" (the ENTRY column is not read).
- Destination: camMgr + 0x50 + 4*i, i = 0..10, f32 (11 floats, +0x50 .. +0x78), in the key order above.
- No further enum; nothing debug-gated.

---------------------------------------------------------------------------------------------------

## 3. data/script/script_bin/camera/cameradatabase%02d.csv  (COMMA, skipHeader=1, 29 columns, 30 files)
- Loader: FUN_0027d34c(scriptCamObj, lobbyNo, ...) = LoadScriptCameraDatabase. Path built with sprintf("data/script/script_bin/camera/cameradatabase%02d.csv", lobbyNo) where lobbyNo = (0-based lobby idx)+1. Only caller: FUN_001c772c (lobby-scene "enter lobby/room" function) at 0x1c78a0, inside the `if (param_5 != 0)` block, with obj = *(lobbyScene+0x170) (created by FUN_0027d17c, which sets `_DAT_0034a7e0` = obj and `_DAT_0034a7e4` = malloc'd record array). FUN_001c772c is called from FUN_001c725c (0x1c7338), which is called from the lobby scene init FUN_001c51dc (0x1c5700) and FUN_001c5f54 (0x1c5fa0).
- Destination: heap array `_DAT_0034a7e4`, 0x80 records x 0x40 bytes (cleared to 0, +0x3c=1 first). Same marker logic as section 1 but only "REPLAYCAMERA" (-> 0) and "GUTSCAMERA" (-> 0x40). Only REPLAYCAMERA appears in the shipped files.
- Per-column (the first 19 columns of the table are consumed, columns 19-28 [lottery, conditions, 2-point fixed...] are NOT read):

| col | header | getter | dest | width | notes |
|---|---|---|---|---|---|
| 1-4 | angle, dist, FOV, height | F | +0x00,+0x04,+0x08,+0x0c | f32 | |
| 5 | position ref point | S->FUN_0027d940 | +0x10 | s32 | 1 if text equals "NPC" (strcmp) and does not contain "CENTERLOBBY", else 0 |
| 6-8 | gaze height, X off, Z off | F | +0x14,+0x18,+0x1c | f32 | |
| 9 | gaze ref point | S->FUN_0027d940 | +0x20 | s32 | same 0/1 enum |
| 10 | damper ref | S->FUN_0027d940 | (discarded) | - | result not stored |
| 11 | vibration | S->FUN_0027da7c | (discarded) | - | FUN_0027da7c is a stub returning 0 |
| 12 | move method | S->FUN_0027d9b4 | +0x24 | s32 | 1 NORMALLINEAR, 2 NORMALSECOND, 3 VALUELINEAR, 4 INSTANT, 5 CROSSFADE (same names/order as FUN_0012ffac) |
| 13 | switch-frame ref | S->FUN_0027da7c | +0x28 | s32 | stub, always stores 0 |
| 14 | diff from ref | F | +0x2c | f32 | |
| 15 | camera type | S->FUN_0027da84 | (discarded) | - | stub returns 0 |
| 16 | group ID | I | +0x30 | s32 | |
| 17,18 | next cameras | I if numeric, else S->FUN_0027da8c | +0x34,+0x38 | s32 | text form is a stub (always 0), i.e. TO_LONG/TO_FINISH/NOLOOP are NOT parsed in this loader |
| - | group count | post pass | +0x3c | s32 | same count-per-group post pass as section 1 (over 0x80 records, key = +0x30) |

- Surprising: the parsers 0x27da7c, 0x27da84, 0x27da8c are 8-byte functions returning 0 (functions in this overlay-like region at 0x27d... were reduced to stubs). Columns 10, 11, 13 (as value), 15, and the text forms of 17/18 are therefore dead in the shipped binary. Consumers of the records: FUN_0027b8cc, 0027bad0, 0027be4c, 0027bf24, 0027c774, 0027c8a0, 0027c8d0, 0027c908 (read +0x24, +0x2c, +0x30, +0x34, +0x3c).

---------------------------------------------------------------------------------------------------

## 4. data/prize/commoncamera.csv  (COMMA, keyed table, rows keyed by col0 label)
- Loader: FUN_001ed27c(prizeCam) = LoadPrizeCommonCamera. Caller: FUN_001f2954 (prize/awards scene init; call at 0x1f2a44, arg *(scene+0x584)), itself called from FUN_001ef2ec (0x1ef39c) <- FUN_001eed9c (0x1eedec). Runs when the prize scene is built. First calls FUN_001ed460(prizeCam).
- Reader: heap-allocated keyed reader (0x30 bytes, vtable 0x3070bc) stored at prizeCam+0x90; FUN_000651b8(reader, "data/prize/commoncamera.csv", 1, 1, ","). Header row is row 0 ("label" + 3 more), data keyed by row-label in col 0; the file has 9 parameter rows read here (plus Result* rows that THIS loader does not read).
- Reads floats with FUN_000657e4(reader, rowKey, colIdx) for colIdx = 1 and 2 (two variants/slots; rows have values in col 1 and col 2; only RotSpeed has an extra value in col 3 which is not read).
- Destination: prizeCam + 0x9c, two records of 0x24 bytes (stride 0x24; slot k from column k+1):

| row key | dest off in slot | conversion | meaning |
|---|---|---|---|
| RotSpeed | +0x00 | deg * 0.017453292 * 0.033333335 (deg->rad, /30) | rotation speed per frame |
| Tilt | +0x04 | deg->rad | |
| TiltWin | +0x08 | deg->rad | |
| Distance | +0x0c | raw | |
| FovX | +0x10 | raw | |
| OffsetY | +0x14 | raw | |
| Near | +0x18 | raw | |
| Far | +0x1c | raw | |
| DefaultAngleY | +0x20 | deg->rad | |

- Row keys are literal EBOOT strings at 0x2ee454.. ("RotSpeed","Tilt","TiltWin","Distance","FovX","OffsetY","Near","Far","DefaultAngleY"). Absolute: slot0 = prizeCam+0x9c..0xbf, slot1 = prizeCam+0xc0..0xe3.

---------------------------------------------------------------------------------------------------

## 5. Court tables (all loaded from the court manager ctor path)
Entry: FUN_00132180 = CourtMgr ctor (alloc 0x14c0, vtable 0x30820c, sub-object "Stage" at +0x40, global `_DAT_003402a0` = this). Called from the match-scene state machine FUN_00088a44 case 0 (call at 0x88fe8), right before the camera manager. It reads court id from `DAT_003417cc` (forced to 1 if it is 0 or 10..12), stores it in mgr[0x4d9] and calls FUN_0013293c(mgr, courtNo) at 0x132370 (every match start). All court tables below are indexed by the court number (row index = courtNo) with the header skipped.

### 5.1 data/court/court.csv  (COMMA, skipHeader=1, 7 columns)
- Loader: FUN_0013293c = LoadCourt (761 lines; also drives all the per-court tables below). Row = courtNo (row 0 is the "c00" row, row 1 = c01 ...; so rows are 0-based by court number).

| col | header | getter | dest | meaning |
|---|---|---|---|---|
| 0 | court name (folder name) | S | strdup -> `_DAT_003402a4` (also strcpy -> mgr+0xd68 = stage+0xd28) | folder under data/court/ and name used in all later paths |
| 1 | surface type | S, strcmp | `_DAT_003402a8` (s32) | "CLAY" -> 2, "HARD" -> 1, anything else -> 0 (presumably grass). DAT_002d5a8c = (value+3)%3 |
| 2 | BGM | S | strdup -> `_DAT_003402ac` | BGM name |
| 3 | indoor (1) / outdoor (0) | I | mgr+0x141e (u8, !=0 -> 1) | |
| 4 | Side Width | F | mgr+0x1420 (f32) | |
| 5 | Base Width | F | mgr+0x1424 (f32) | |
| 6 | Camera Limit | F | mgr+0x1428 (f32) | |
- Also: mgr+0x1364 = courtNo; mgr+0xda8 (= stage+0xd68) = "data/court/" prefix string; mgr+0xd68 (= stage+0xd28) = court folder name.
- Adhoc/variant switch: the later sections (ground model load, gallery, gimmick) are done from "game/200_court/..." only when `DAT_003386b8 == 0 && mgr[0x141f] != 0` (0x141f set 1 in the ctor); otherwise a "game/201_court/ + data/adcourt/" variant is loaded and the gallery/escape/break/route data is NOT read (areaclip, light, fog, SE still are).

### 5.2 courtlight.csv / playerlight.csv / balllight.csv / fogsetting.csv  (COMMA, skipHeader=1)
- Loader: FUN_001428d4(stage, row, courtlightPath, playerlightPath, balllightPath, fogPath) = LoadStageLighting. Court call: FUN_0013293c at 0x132b4c with `data/court/courtlight.csv`, `playerlight.csv`, `balllight.csv`, `fogsetting.csv`, row = courtNo. Lobby call: FUN_0012cea0 at 0x12d094 with the lobby files (section 6.3), row = room index, balllight = NULL (skipped). Any NULL path is skipped.
- First it stores row into stage+0xd24 and initialises defaults through the light manager `_DAT_003313c4` (FUN_0005c76c ambient 0.4/0.4/0.4/1.0, FUN_0005c854 default light0 dir(-1,1,1) col(0.9,0.9,0.7), light1 col(0.2,0.2,0.2)), then snapshots into stage+0xdf0.. (FUN_0005cbf4 / FUN_0005cc18); fog defaults stage+0x12e0..0x12e8 = 0, 0x12ec..0x12f8 = 1.0. The source path string of each file is also copied into the stage (courtlight -> +0xee0, balllight -> +0xfe0, playerlight -> +0x10e0, fog -> +0x11e0).

courtlight.csv (15 cols, all F):

| cols | header | dest | width |
|---|---|---|---|
| 0,1,2 | Court Amb R,G,B | stage+0xdf0,0xdf4,0xdf8 | f32 |
| 3,4,5 | Court Light0 Col R,G,B | stage+0xe10,0xe14,0xe18 | f32 |
| 6,7,8 | Court Light0 Dir X,Y,Z | stage+0xe00,0xe04,0xe08 | f32 |
| 9,10,11 | Court Light1 Col R,G,B | stage+0xe30,0xe34,0xe38 | f32 |
| 12,13,14 | Court Light1 Dir X,Y,Z | stage+0xe20,0xe24,0xe28 | f32 |

balllight.csv (6 cols, F): cols 0-2 Ball Amb R,G,B -> stage+0xe40,0xe44,0xe48; cols 3-5 Ball Light Col R,G,B -> stage+0xe60,0xe64,0xe68. (The set's light dirs at 0xe50/0xe70 stay at their defaults.)
playerlight.csv (6 cols, F): cols 0-2 Chara Amb R,G,B -> stage+0xe90,0xe94,0xe98; cols 3-5 Chara Light Col R,G,B -> stage+0xeb0,0xeb4,0xeb8. (Dirs at 0xea0/0xec0 default.)
fogsetting.csv (7 cols, F): col0 Fog Near Vol -> stage+0x12e0; col1 Fog Far Vol -> +0x12e4; col2 Fog Near Z -> +0x12e8; col3 Fog Far Z -> +0x12ec; col4 Fog Col R -> +0x12f0; col5 (header says B, really G) -> +0x12f4; col6 B -> +0x12f8. (All f32. Guess: first three values 0-defaults / last four 1.0-defaults, so "Vol" cols are 0-based; exact use not traced.)
- Extra (not a CSV): the same function reads "%s%s/pointlight.dat" (binary: dword count N then N x 6 words) into a vector at stage+0xd10 (ptr), +0xd14 count, +0xd18 cap, element 0x20 bytes = {w0,w1,w2,1.0f, w3,w4,w5,1.0f} (two vec4s: position and colour, guess).

### 5.3 data/court/camera_time.csv  (COMMA, skipHeader=1, 4 columns)
- Loader: inline in FUN_0013293c (0x132b60..). Reuses the court.csv reader object. Skipped if the load fails. Reads ALL rows (not row = courtNo).
- Per row: cols 1,2,3 as I (col 0 = gimmick/name text is not read; headers: name, gimmick ID, frames, frames) -> element 12 bytes {s32 c1, s32 c2, s32 c3} appended to the vector at mgr+0x1450 (ptr), +0x1454 count, +0x1458 cap (grow helper FUN_0013cf68).

### 5.4 data/court/<name>/setting/cNN_areaclip.csv  (COMMA, skipHeader=1, 6 columns, 1 data row)
- Loader: FUN_001415e8(stage, row, path) = LoadAreaClip, shared with lobbies. Court wrapper FUN_00137840(mgr) builds "data/court/%s/setting/c%02d_areaclip.csv" with (`_DAT_003402a4`, mgr+0x1364) and calls FUN_001415e8(mgr+0x40, 0, path). Callers of the wrapper: FUN_0013293c at 0x132d94 and 0x133198 (the 200_court and 201_court branches).
- If the file fails to load or row >= row count, defaults: stage+0x1300 = -3.0, +0x1304 = 3.0, +0x1308 = -3.0, +0x130c = 3.0, +0x1314 = -1000.0, +0x1310 = 1000.0.
- Columns (all F): col0 MinusXAxisArea -> stage+0x1304 = -value; col1 PlusXaxisArea -> stage+0x1300 = -value; col2 MinusZaxisArea -> +0x1308 = value; col3 PlusZaxisArea -> +0x130c; col4 MinusClipZ -> +0x1314; col5 PlusClipZ -> +0x1310. (Note the crossed + negated mapping for X: +0x1300 is min X, +0x1304 is max X.) Consumer example: FUN_0012e028 (lobby, reads +0x1300/+0x1304).

### 5.5 data/court/<name>/setting/cNN_se.csv  (COMMA, skipHeader=1, 9 columns)
- Loader: FUN_001420a4(stage) = LoadStageSe. Called from FUN_0013293c at 0x132d8c and 0x133190 with stage = mgr+0x40. Path "%s%s/setting/c%02d_se.csv" with (stage+0xd68 = "data/court/", stage+0xd28 = court name, stage+0xd24 = court no / row). The virtual FUN_0014648c (Stage vtable 0x308228+0x14, slot 5) builds the same path for callers that ask the stage for it; it has no direct call site and for the court it appears redundant (the lobby path is the one that calls the virtual).
- Clears the two vectors, parses the CSV, then also reads "%s%s/sedata.dat" (binary) into stage+0x8d4.
- SE entry (0x28 bytes) vector at stage+0x8c8 (ptr) /+0x8cc count/+0x8d0 cap:

| col | header | getter | dest | width |
|---|---|---|---|---|
| 0 | EditorName | S -> FUN_00003268 (string assign) | +0x00 | 12-byte string object |
| 1 | from which frame | I | +0x0c | s32 |
| 2 | random range (frames) | I | +0x10 | s32 |
| 3 | repeat count | I | +0x14 | s32 |
| 4 | loop | I (!=0) | +0x18 | u8 |
| 5 | VolMin | F | +0x20 | f32 |
| 6 | VolMax | F | +0x24 | f32 |
| 7 | RequestName (numeric SE request id; the data is integers) | I | +0x1c | s32 (also the sort key) |
| 8 | comment | not read | - | - |
- Insertion order: if the vector is empty push_back; otherwise inserted after the last element whose +0x1c key is strictly less than the new key (ascending sort by col 7; decompile leaves the "smaller than all" case with an uninitialised iterator, worth a look at the asm if it matters).
- sedata.dat: dword N then N x 5 dwords {w0, w1, w2, w3, w4} -> stage+0x8d4 vector (ptr/+0x8d8 count/+0x8dc cap), element 0x30 bytes: +0x00..0x0b = w1,w2,w3 (probably x,y,z), +0x0c = 1.0f, +0x10 = w4, +0x14 = w0, +0x24 byte = 1; rest 0.

### 5.6 data/court/<name>/setting/cNN_gallery.csv  (COMMA, skipHeader=1, 4 columns)
- Loader: inline in FUN_0013293c (0x132e64..). Path "data/court/%s/setting/c%02d_gallery.csv" with (`_DAT_003402a4`, mgr+0x1364). Only if `DAT_003386b8 == 0 && mgr[0x141f] != 0` (200_court branch) AND `*(u8*)(_DAT_00338b44 + 0x45) != 0` (a settings byte, presumably "crowd on"). Before it, FUN_00141718 loads the binary "..._galleryarea.dat".
- All rows, cols 0..3 as I -> 16-byte element {area ID, count when no crowd, count normal, count many} appended to the vector at mgr+0x13e4 (ptr), +0x13e8 count, +0x13ec cap (grow FUN_0013ceac). Then one crowd object (0x68 bytes, ctor FUN_00266d24, init FUN_00268454(obj, elem[0], elem[1], isFirst, ...)) is created per element and registered in the vector at mgr+0x13bc/+0x13c0/+0x13c4; fields 0x17/0x18 of the object are set from mgr+0x1350/+0x1354. Only elem[0] and elem[1] are passed at creation; the other counts are stored for later (consumers not traced).

### 5.7 data/court/<name>/setting/cNN_escape_gimmick.csv  (COMMA, skipHeader=1, 10 columns)
- Loader: inline in FUN_0013293c (0x133284..). Path "data/court/%s/setting/c%02d_escape_gimmick.csv". Same gating as the gallery (200_court branch only, DAT_003386b8 == 0). Preceded by FUN_0014613c loading "..._route.dat" (binary).
- All rows; col 0 (name) not read. Element 0x24 bytes appended to vector mgr+0x13cc (ptr), +0x13d0 count, +0x13d4 cap (grow FUN_0013cd34):

| col | header | getter | dest off | width |
|---|---|---|---|---|
| 1 | gimmick type | I | +0x00 | s32 |
| 2 | action type | I | +0x04 | s32 |
| 3 | route ID | I | +0x08 | s32 |
| 4 | lifetime | I | +0x0c | s32 |
| 5 | speed | F | +0x10 | f32 |
| 6 | Y-axis direction angle | F | +0x14 | f32 |
| 7 | standard heading | I | +0x18 | s32 |
| 8 | random heading | I | +0x1c | s32 |
| 9 | debug flag | I | +0x20 | s32 |
- Not yet traced: the consumer of mgr+0x13cc (escape gimmick actors).

### 5.8 data/court/<name>/setting/cNN_break_gimmick.csv  (COMMA, skipHeader=1, 5 columns)
- Loader: inline in FUN_0013293c (0x13344c..), same gating. Element 0x10 bytes appended to vector mgr+0x13d8 (ptr), +0x13dc count, +0x13e0 cap (grow FUN_0013cdf0):

| col | header | getter | dest | meaning |
|---|---|---|---|---|
| 0 | gimmick name | not read | - | |
| 1 | gimmick number | I | +0x00 | passed to the gimmick ctor FUN_00246514(obj, gimmickNo) |
| 2 | route number | I | +0x04 | looked up with FUN_001463f8 (route.dat) for the position |
| 3 | default angle (deg) | I | +0x08 | base heading |
| 4 | random rotation (range) | I | +0x0c | heading += rand() % range (LCG 0x343fd/0x269ec3 in mgr+0x1360) when range != 0 |
- Then per element a 0x500-byte gimmick object (ctor FUN_00246514) is created, placed, and added to vectors at mgr+0x13b0.. and mgr+0x13f0..; deg->rad 0.017453292.

### 5.9 data/common/court/Court_Court.txt  (TAB, keyed by COLUMN NAME, 28 columns)
- Loader: FUN_0027e7d0(courtTable) = LoadCourtCatalog. Caller: FUN_00047054 (common boot init, call at 0x47330) <- FUN_000468c8 (0x46d04). Singleton object `_DAT_0034a7ec` (alloc 0x1c, ctor FUN_0027e71c). Boot-time, once.
- Reader: local keyed reader (vtable 0x3070bc), FUN_000651b8(reader, path, 0, 1, "\t") (column-name map only; row 0 = header; data rows from 1). Columns are located by name with FUN_00065364 (missing column -> value 0).
- Row key: the "Label" column text; index = atoi(last three characters of the label) (FUN_0000d62c(label+len-3)). Records stored in a vector at courtTable+4 (ptr)/+8 (count) of 0x28-byte records, resized to maxIndex+1 (initial reserve 0x15); default template has vtable ptr 0x309c88 at +0, Get = -1 (0xffff at +4), index = -1 (0xffff at +0x26).

| header | getter | dest | width |
|---|---|---|---|
| Label | text (index source) | +0x26 = index | s16 |
| Get | I (by name) | +0x04 | s16 |
| Price | I | +0x06 | s16 |
| No | I | +0x08 | s16 |
| Sf | I | +0x0a | s16 |
| Bound | I | +0x0c | s16 |
| Fast | I | +0x0e | s16 |
| Gallery | I | +0x10 | s16 |
| L1..L10 (10 consecutive columns starting at "L1") | I | +0x12..+0x1b | 10 x u8 |
| Gim1..Gim9 (9 consecutive columns starting at "Gim1") | I | +0x1c..+0x24 | 9 x u8 |
| Sharing | I | +0x25 | u8 |
- Post: builds an order vector at courtTable+0x10 (count +0x14) of s32 record indexes: records with Get < 0 sort key 0x7fff (last), others key = No (+0x08); sorted ascending with FUN_0001cfa4; only the Get >= 0 ones are kept in the vector (uVar7 count). Then FUN_0027ed88 x several (rebuild/finish) calls. This is the shop/unlock catalog of courts (Get/Price/No/Sharing like the other catalogs); L1-L10 are court-layout flags, Gim1-Gim9 gimmick enable flags, Sf = surface (guess).

---------------------------------------------------------------------------------------------------

## 6. Lobby tables
Entry: stage loader FUN_0012cea0(lobbyStage, lobbyNo, roomNo) = LoadLobbyRoom. It is a virtual (secondary-vtable thunk FUN_0012dc2c at 0x30813c, "this - 0x1320"), reached through FUN_00286f00 (virtual +0x18 dispatcher) from FUN_001c772c (the lobby/room enter function, inside it: `FUN_00286f00(lobbyMgr+0x1320, 0,0,0, lobbyIdx+1, roomIdx+1, 0, 0)` right after `FUN_0012cc4c` constructs the lobby manager, alloc 0x13d0, global `_DAT_0033b574`). Not at boot; every time a lobby room is entered. It stores lobbyIdx = lobbyNo-1 at stage[0x4e4] (+0x1390) and roomIdx = roomNo-1 at stage[0x4e5] (+0x1394), reader pointer for lobby.csv at stage[0x4e6] (+0x1398).

### 6.1 data/lobby/lobby.csv  (COMMA, skipHeader=1, 7 columns; one row per lobby; also a second resident copy in the lobby scene)
- Loader 1: FUN_0012cea0 (0x12cf20): heap reader (0x10 bytes) stored at stage[0x4e6]; row = clamp(lobbyIdx, DAT_002daa90 [=0], rows-1); room column = clamp(roomIdx, DAT_002daa94 [=0], colCount-2) +1 where colCount = FUN_000650e8(row). 
  - col 0 (folder name, header "lobby folder name") -> strcpy to stage+0xd28 (the "%s" in every data/lobby/%s/... path).
  - col roomIdx+1 (header "room name (suffix); collision name = room name + _col") -> used only inside the ground/haichi model paths ("data/lobby/%s/ground/%s%s.i3r", "...%s%s__haichi.i3m").
  - stage+0xd68 gets "data/lobby/". Rows therefore have up to 6 room columns.
- Loader 2: FUN_001c51dc (lobby scene init; call at 0x1c5660): `FUN_00064bf4(*(lobbyScene+0x178), "data/lobby/lobby.csv", 1, ",")`, resident for the lobby scene. Reader re-used by FUN_001c772c: `FUN_0006517c(*(scene+0x178), lobbyIdx, 0)` -> folder name for "data/lobby/%s" (script/text label paths). FUN_001c51dc is reached via FUN_001c4704's virtual (call at 0x1c4dac; no direct caller).

### 6.2 data/lobby/effect.csv  (COMMA, keyed by column NAME, header "(blank),Lobby,Object,Node,Effect,Frame,Scale")
- Loader: FUN_0028af58(lobbyChallengeTable, lobbyItemPath, pointPath, effectPath) = LoadLobbyChallengeAndEffects; called from FUN_001c51dc (0x1c568c) with obj = *(lobbyScene+0x17c), paths "data/menu/challenge/Challenge_LobbyItem.txt" (TAB), "data/menu/challenge/Challenge_PointXXX.txt" (TAB) and "data/lobby/effect.csv" (the first two belong to another group; they use keyed names Lobby/Room/Point/OBJ?/Re/ReType/Item/GetPer/SE1/SE2/Text_1..3, element 0x60 bytes in a vector at obj+0).
- effect.csv part: FUN_000651b8(reader, path, 0, 1, ","); rows 1..n; columns by name (FUN_00065554 = I, FUN_000655f8 = F, FUN_0006569c = S). Element 0x1c bytes appended to the vector at obj+0x18 (ptr), +0x1c count, +0x20 cap (grow FUN_0028c81c):

| header | getter | dest | width |
|---|---|---|---|
| Lobby | I | +0x00 | s16 |
| Object | I | +0x02 | s16 |
| Effect | I | +0x04 | s16 |
| Frame | I | +0x06 | s16 |
| (not in file) | const 0xffff | +0x08 | s16 (runtime/handle init) |
| Scale | F | +0x0c | f32 |
| Node | S (strncpy 9) | +0x10 | char[9], NUL at +0x18 |
| (blank first column) | not read | - | - |

### 6.3 data/lobby/<name>/setting/lNN_areaclip.csv / lNN_courtlight.csv / lNN_playerlight.csv / lNN_fogsetting.csv  (COMMA, skipHeader=1)
- Loader: all from FUN_0012cea0 with lobbyNo and row = roomIdx (a lobby file has one row per room, up to 6, plus header): path formats `data/lobby/%s/setting/l%02d_areaclip.csv` (0x12d00c), `..._courtlight.csv` (0x12d038), `..._playerlight.csv` (0x12d054), `..._fogsetting.csv` (0x12d070) with (folder name stage+0xd28, lobbyNo).
- areaclip -> FUN_001415e8(stage, roomIdx, path) (same 6 columns/dest as 5.4: MinusXAxisArea, PlusXaxisArea, MinusZaxisArea, PlusZaxisArea, MinusClipZ, PlusClipZ -> stage+0x1304/0x1300/0x1308/0x130c/0x1314/0x1310; defaults -3/3/-3/3/-1000/1000 when the row is missing).
- courtlight / playerlight / fogsetting -> FUN_001428d4(stage, roomIdx, courtlight, playerlight, NULL, fog): identical column layouts and destinations as 5.2 (courtlight cols 0-14 -> stage+0xdf0.., playerlight -> stage+0xe90/0xeb0, fog -> stage+0x12e0..0x12f8). No balllight in lobbies. It also loads "data/lobby/<folder>/pointlight.dat" via "%s%s" + "%s/pointlight.dat" (0x142e48) with stage+0xd68 = "data/lobby/".
- Important: in FUN_001428d4 `stage+0xd24 = row`, so for lobbies +0xd24 is the room index and for courts the court number.

### 6.4 data/lobby/<name>/setting/lNN_rNN_se.csv  (COMMA, skipHeader=1, 9 columns) and sedata.dat
- Path builders (virtuals of the lobby stage vtable 0x308108, slots +0x14 / +0x18): FUN_0012d7a8(stage, out) = "data/lobby/%s/setting/l%02d_r%02d_se.csv" and FUN_0012d808(stage, out) = "data/lobby/%s/setting/l%02d_r%02d_sedata.dat"; %s = col0 of lobby.csv (reader stage+0x1398, row lobbyIdx), then lobbyIdx+1, roomIdx+1. The court equivalents are FUN_0014648c / FUN_001464ac.
- Loader: FUN_001424c4(stage, sePath, sedataPath) = LoadLobbySe, called from FUN_0012cea0 at 0x12d330 after fetching the two paths through the virtuals. Parsing code is identical to 5.5 (same 9 columns -> same 0x28-byte SE entries in stage+0x8c8, sorted by col 7; sedata.dat -> stage+0x8d4 0x30-byte entries). If the CSV fails to load nothing is stored (the sedata read is inside the success branch, unlike the court version which reads sedata.dat regardless).
- Shipped files exist only for a few rooms (r01..r05 of a few lobbies); missing files are fine (load returns 0).

### 6.5 Neighbours
- FUN_0012dc4c (ctor, alloc 0x250, base FUN_00286790, vtable 0x308194): lobby "camera/avatar helper" object created by FUN_0012cde8 (call 0x12ce1c) when `_DAT_0033b580 == 0`; global `_DAT_0033b580` = this; contains a CSV reader at +0xd0 (initialised only: FUN_000649c0) and a child pointer at +0xe0. It does NOT load any table (no CSV path references it).
- FUN_0012ddd0 = its destructor (deletes +0xe0 child, clears `_DAT_0033b580`, frees reader).
- FUN_0012cde8 (vtable method) creates it and registers via FUN_001c68a8(`_DAT_0034a114`, obj).

---------------------------------------------------------------------------------------------------

## Proposed names
Functions
- 0x0012f41c CameraMgr_ctor (global 0x340284, vtable 0x3081f0)
- 0x0012f698 CameraMgr_LoadCameraDatabase (cameradatabase.csv + camera_nearfar.txt)
- 0x0012fdb0 ParseCameraRefPoint; 0x0012ffac ParseCameraTransition; 0x00130074 ParseCameraTrigger; 0x00130174 ParseCameraType; 0x00130274 ParseCameraNextSymbol; 0x00130304 ParseCameraCondition
- 0x0027d17c ScriptCamera_ctor (globals 0x34a7e0, 0x34a7e4); 0x0027d34c ScriptCamera_LoadDatabase; 0x0027d940 ParseScriptCamRefPoint; 0x0027d9b4 ParseScriptCamTransition; 0x0027da7c/0x0027da84/0x0027da8c ScriptCam_ParseStub0 (return 0)
- 0x001ed27c PrizeCamera_LoadCommonCamera
- 0x00132180 CourtMgr_ctor (global 0x3402a0, vtable 0x30820c); 0x0013293c CourtMgr_LoadCourt; 0x00137840 CourtMgr_LoadAreaClip (wrapper)
- 0x001415e8 Stage_LoadAreaClip; 0x001428d4 Stage_LoadLightingAndFog; 0x001420a4 Stage_LoadSeTable (court); 0x001424c4 Stage_LoadSeTableFromPaths (lobby); 0x0014648c Stage_GetSeCsvPath (court virtual); 0x001464ac Stage_GetSeDataPath (court virtual)
- 0x0012cc4c LobbyMgr_ctor (global 0x33b574, vtable 0x308108/0x308124); 0x0012cea0 LobbyStage_LoadRoom; 0x0012dc2c LobbyStage_LoadRoom_thunk; 0x0012d7a8 LobbyStage_GetSeCsvPath; 0x0012d808 LobbyStage_GetSeDataPath
- 0x001c51dc LobbyScene_Init (loads lobby.csv copy, effects); 0x001c772c LobbyScene_EnterRoom; 0x0028af58 LobbyChallenge_LoadTables (Challenge_LobbyItem / Challenge_PointXXX / effect.csv)
- 0x0027e7d0 CourtCatalog_Load (Court_Court.txt); 0x0027e71c CourtCatalog_ctor (global 0x34a7ec); 0x00047054 CommonBootInit (calls it)
- 0x0012dc4c LobbyHelper_ctor (global 0x33b580); 0x0012ddd0 LobbyHelper_dtor; 0x0012cde8 LobbyStage_CreateHelper
- Reader: 0x00065554 Csv_GetIntByName; 0x000655f8 Csv_GetFloatByName; 0x0006569c Csv_GetStrByName; 0x00065364 Csv_ColIndex; 0x00065480 Csv_GetFloatByRowKeyColName; 0x000657e4 Csv_GetFloatByRowKeyColIdx; 0x000651b8 Csv_LoadKeyed; 0x000650e8 Csv_RowCellCount

Structs / globals
- CameraDbEntry (0x58) @0x33b584[0xe0]: angle, distance, fov, height, gazeHeight, gazeOffX, gazeOffZ, frameDiff (+0x1c), fixAx, fixAy, fixBx, fixBy, fixHeight (+0x20..0x30), lottery (+0x34), condParam[2] (+0x38,+0x3c), groupCount (+0x40), groupId (+0x44), next[2] (+0x46,+0x48), posRef (+0x4a), gazeRef (+0x4b), damperRef (+0x4c), shakeTrigger (+0x4d), transition (+0x4e), switchTrigger (+0x4f), camType (+0x50), cond[2] (+0x51,+0x52), pcDownLimit (+0x53), collision (+0x54), clipping (+0x55), fixRefA (+0x56), fixRefB (+0x57)
- CameraNearFar floats at camMgr+0x50..0x78 (NearMin, NearMax, FOVMin, FOVMax, FOVRatioMin, FOVRatioMax, FarMin, FarMax, HeightMin, HeightMax, CointossNear)
- ScriptCameraEntry (0x40) @heap[0x34a7e4][0x80]
- PrizeCameraParams (0x24) x2 @prizeCam+0x9c
- StageSeEntry (0x28), StageSeDataEntry (0x30), StagePointLight (0x20), CourtCameraTime (0xc), CourtGalleryRow (0x10), CourtEscapeGimmick (0x24), CourtBreakGimmick (0x10), LobbyEffect (0x1c), CourtCatalogEntry (0x28)
- Enums: CameraRefPoint, CameraTransition, CameraTrigger, CameraType, CameraNextSymbol, CameraCondition (as listed above)
- Globals: 0x340284 g_CameraMgr, 0x3402a0 g_CourtMgr, 0x3402a4 g_CourtName, 0x3402a8 g_CourtSurface (0 other/1 HARD/2 CLAY), 0x3402ac g_CourtBgm, 0x33b574 g_LobbyMgr, 0x33b580 g_LobbyHelper, 0x34a7ec g_CourtCatalog, 0x3417cc g_SelectedCourtNo, 0x3386b8 g_AdhocFlag (guess)

## Unresolved / worth a second look
- Consumers of camera_nearfar floats (camMgr+0x50..0x78) and of many CameraDbEntry fields were not traced; semantic names (transition, trigger, ref point) are inferred from the enum strings and column headers only.
- cameradatabase.csv: 129 replay rows vs 0x80 slots (row 129 lands on record 0x80 and is overwritten by the GUTS section); confirm whether the first/last row is a dummy.
- Camera col 17/18 symbolic form: assumed from the cell-type rule (text -> parser). TO_LONG/TO_FINISH values 50/60 look like camera IDs, NOLOOP = 999 sentinel.
- Stage_LoadSeTable sorted-insert start case (decompile shows an uninitialised iterator when the new key is smaller than every existing key).
- sedata.dat / pointlight.dat / route.dat / galleryarea.dat record meanings are guesses (binary; only the loader shapes were read: FUN_0014613c route.dat, FUN_00141718 galleryarea.dat, 0x14189c/0x141c3c/0x141e70 lobby script_bin data are separate loaders outside this group).
- fogsetting column order beyond names (what "Vol" values mean) and the playerlight/balllight dir slots (left at default).
- Court_Court.txt semantic of Sf/L1..L10/Gim1..Gim9 and the final order vector consumers.
- Which game flag exactly is DAT_003386b8 (looks like ad-hoc/network match) and _DAT_00338b44+0x45 (crowd setting).
- Lobby effect.csv "Node" semantics and the 0xffff field at +0x08 (set at runtime).
