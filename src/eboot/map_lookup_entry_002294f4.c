/* HSTMATCH module=EBOOT.BIN start=0x002294f4 end=0x002295f4 symbol=FUN_002294f4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: structured if/else ladder sharing common return variable, ternary map end check; exact match verified; names and types await human review. */
extern void *DAT_002c0e18;
extern void *DAT_002c0e1c;
extern void *DAT_002c0e20;

extern void FUN_00229868(void *out, void *map, void *key);

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

void *FUN_002294f4(void *map, struct Context *ctx, int key_val, int index)
{
  int key = key_val;
  void *it[2];
  
  FUN_00229868(it, map, &key);
  int id = (it[0] != (char *)map + 4) ? *(int *)((char *)it[0] + 0x10) : -1;

  if (ctx != 0) {
    if (id >= 0) {
      void *res;
      if (ctx->f4 == 0) {
        res = &DAT_002c0e20;
      } else if (id < 0 || id >= ctx->f8->size) {
        res = &DAT_002c0e1c;
      } else if (index < 0 || index >= ctx->entries[id].count) {
        res = &DAT_002c0e18;
      } else {
        res = ctx->entries[id].array[index];
      }
      return res;
    }
  }
  return 0;
}
