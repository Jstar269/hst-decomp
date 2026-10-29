/* HSTMATCH module=EBOOT.BIN start=0x00289ba8 end=0x00289c3c symbol=FUN_00289ba8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: typed the copied record fields as floats; readability pass; exact match verified; names and types await human review. */
#include "hst/vec.h"

/* Record pool: the number of records in use and the start of the record array. */
typedef struct RecPool {
  int unk00;          /* 0x00 */
  int count;          /* 0x04 records in use */
  Float4 *base;       /* 0x08 */
} RecPool;

/* Insert cursor: the slot to write and the pool it belongs to. */
typedef struct RecCursor {
  Float4 *slot;       /* 0x00 */
  RecPool *pool;      /* 0x04 */
} RecCursor;

/* Store `src` at the cursor's slot; a slot past the records in use also grows the pool's count. Returns the slot. */
int FUN_00289ba8(RecCursor *cursor,Float4 *src)
{
  int diff;
  Float4 *slot;
  
  slot = cursor->slot;
  diff = (int)slot - (int)cursor->pool->base;
  if (diff / 16 < cursor->pool->count) {
    slot->x = src->x;
    slot->y = src->y;
    slot->z = src->z;
    slot->w = src->w;
  }
  else {
    if (slot != (Float4 *)0x0) {
      slot->x = src->x;
      slot->y = src->y;
      slot->z = src->z;
      slot->w = src->w;
    }
    cursor->pool->count = cursor->pool->count + 1;
  }
  return (int)cursor->slot;
}
