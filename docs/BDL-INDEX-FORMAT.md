# GAMEDATA.BDL outer index ("FB" file table)

Private. Describes the format only (no game bytes). Read from the game's own reader in the retail EBOOT
(module addresses, base 0, as used by hst-decomp) and reproduced by `decode_bdl_index.py` in this folder.
`python -I decode_bdl_index.py` prints `RESULT: PASS` against the extracted tree: all 2,355 slot
offsets match `bdl_xb_offsets.csv`, the last slot ends exactly at the 427,069,696-byte plaintext size, and
every one of the 2,354 loose `xbdata` files hashes to a record whose slot holds identical bytes.
`--csv` writes slot, offset, size, padded size, name hash and name for all 2,355 slots.

## Reader functions (EBOOT.BIN)

| Address | Role |
|---|---|
| `0x000fcbe4` | `GameData::CreateFileTable(count)` - allocates `count*0x14+0x18` bytes (index buffer, `DAT_0033a664`) and `count*4` bytes (slot offset table, `DAT_0033a66c`); default `count` is `0xa8c`. |
| `0x000fcc78` | `GameData::Initialize(path, mode)` - opens `ms0:/PSP/SAVEDATA/UCUS98701GAMEDATA/GAMEDATA.BDL` (the installed copy, also tried as `ms0:/PSP/GAME/NPUG70099/FILE.BDL`), reads the index, checks `'F','B'`, un-XORs the header and records, builds the offset table. |
| `0x000fd850` | `GameData::Open(name, buf, maxsize, err)` - lowercases the name, hashes it, binary-searches the records, lseeks to the slot offset, reads the slot, optionally decrypts and CRC-checks it. |
| `0x000ff414` | lower_bound over 20-byte records keyed on the first word; ties are broken by `strcmp` of the record's name pointer against the lookup name (the pointers are all empty in this file). |
| `0x00016938` | ASCII `tolower` (table at `0x002ba7b0`). |
| `0x000fcc4c` | debug-log printer used by all `GameData::` messages (strings at `0x002d8480..0x002d8898`). |
| `0x00295298`, `0x002a0140` | the two install threads (`InstallGameDataThread`) that copy `FILE.BDL` to the memory stick; they do not parse the index. |

Globals: `0x0033a660` initialised flag, `0x0033a664` index buffer, `0x0033a668` record table pointer,
`0x0033a66c` slot offset table, `0x0033a670` mode, `0x00339c40` CRC-32 table, `0x002c0d94` 32-byte stream key.

## Layout (all words little-endian; the table is the plaintext after PGD removal)

```
0x00  'F' 'B'  flag2  flag3        flag2 == 0x1f : slot payload is NOT run through the stream decrypt
                                   flag3 == 0x2a : slot CRC-32 is NOT checked      (this file: 0x1f, 0x2a)
0x04  u32  count ^ 0x19740819 , then + 0x83b9ec81   -> N = 2355
0x08  u32  not read by the game (0x2d226e33)
0x0c  u32  not read by the game (0x8729382e)
0x10  u32  extra ^ 0x76540321                        -> extra = 4 bytes between header and records
0x14  extra bytes (unused name area; every record's name offset is 0)
0x18  N records of 20 bytes, sorted ascending by word 0
data_start = ((N + 1) * 20 + extra) rounded up to 64        = 47168
```

Record (20 bytes at `0x18 + 20*k`):

| Off | Field | Decode |
|---|---|---|
| +0x00 | name hash | plain; `h = 0; for c in lowercase(name)[:255]: h = h*31 + c` (32-bit) |
| +0x04 | name offset | `^ 0x6fae3293`, relative to file offset 0x14; Initialize turns it into a pointer. Always 0 here. |
| +0x08 | slot index | `^ 0x7232aabb` - the slot this hash resolves to (a permutation of 0..N-1) |
| +0x0c | slot size | `^ 0x22330033` - bytes of slot `k` (the record's own position, not the slot index of +8) |
| +0x10 | CRC-32 | of slot `k`'s bytes (`~crc`, polynomial table `0x339c40`); 0 and unchecked in this file |

So a record plays two roles: its position `k` addresses slot `k` (size, CRC), while its hash/slot-index pair is
the sorted lookup structure. Slot offsets are a running sum: `offset[0] = data_start`,
`offset[k+1] = offset[k] + roundup64(size[k])`. The last slot ends at the file size exactly.

Names are the path below `xbdata/` as the game requests it (`common/common_10.xb`, `game/200_court/court01.xb`,
`menu/...`), ASCII-lowercased, no leading slash. Identical loose files are stored once per name (separate slots with
identical bytes), which is why `bdl_xb_offsets.csv` showed several loose paths per content hash.

If flag2 were not `0x1f`, `Open` would run a byte stream transform with the 32-byte key at `0x002c0d94`:
`out[i] = (key[j] ^ in[i]) - prev; prev = out[i]; j = (j + 1) & 31`. Not used by this file.

## Slot 5

One slot has no loose file: slot 5 (offset 404,288, 2,512 bytes, between `common_50.xb` and `common_22.xb0`). Its
name hash `0x4ed1abc4` equals the hash of `common/dbgfont.xb`; it contains `data/dbgfont/font10c.gim`. The EBOOT has no
`dbgfont` string and no reference to that hash (see HST-DISCOVERIES-20261024.md).
