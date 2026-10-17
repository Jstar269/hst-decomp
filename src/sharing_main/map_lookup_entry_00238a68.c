/* HSTMATCH module=hstp_trans_main.prx start=0x00238a68 end=0x00238b68 symbol=FUN_00238a68 lang=c99 */
/* Clone of src/eboot/map_lookup_entry_002294f4.c (hstclone.py tag u6fr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: structured if/else ladder sharing common return variable, ternary map end check; exact match verified; names and types await human review. */
extern void *DAT_002d10cc;
extern void *DAT_002d10d0;
extern void *DAT_002d10d4;

extern void FUN_00238ddc(void *out, void *map, void *key);

struct Sub8 {
  char pad[8];
  int size;
};

struct Entry {
  void **array;
  int count;
  int pad;
};

struct Context {
  char pad[4];
  int f4;
  struct Sub8 *f8;
  struct Entry *entries;
};

void *FUN_00238a68(void *map, struct Context *ctx, int key_val, int index)
{
  int key = key_val;
  void *it[2];
  
  FUN_00238ddc(it, map, &key);
  int id = (it[0] != (char *)map + 4) ? *(int *)((char *)it[0] + 0x10) : -1;

  if (ctx != 0) {
    if (id >= 0) {
      void *res;
      if (ctx->f4 == 0) {
        res = &DAT_002d10d4;
      } else if (id < 0 || id >= ctx->f8->size) {
        res = &DAT_002d10d0;
      } else if (index < 0 || index >= ctx->entries[id].count) {
        res = &DAT_002d10cc;
      } else {
        res = ctx->entries[id].array[index];
      }
      return res;
    }
  }
  return 0;
}
