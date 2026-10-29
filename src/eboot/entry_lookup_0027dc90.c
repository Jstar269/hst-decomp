/* HSTMATCH module=EBOOT.BIN start=0x0027dc90 end=0x0027dcd8 symbol=FUN_0027dc90 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/entry_pool.h"

extern PoolEntry *DAT_0034a7e4;

/* Find the pool entry whose key matches; store its index in *out_index when given, return 0 if none. */
PoolEntry *FUN_0027dc90(int key,int *out_index)
{
  PoolEntry *result;
  PoolEntry *base;
  int i;
  PoolEntry *entry;

  result = 0;
  base = DAT_0034a7e4;
  entry = base;
  for (i = 0; i < ENTRY_POOL_SLOTS; i++) {
    if (key == entry->key) {
      result = base + i;
      if (out_index != 0) {
        *out_index = i;
      }
      break;
    }
    entry = entry + 1;
  }
  return result;
}
// near miss from lane od3 (unreviewed)
