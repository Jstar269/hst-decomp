/* HSTMATCH module=EBOOT.BIN start=0x00166b7c end=0x00166ba0 symbol=FUN_00166b7c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_block.h"

/* Store a 4-float vector at +0x20. */
void FUN_00166b7c(VecBlock *blk,Float4 *v)
{
  blk->v20.x = v->x;
  blk->v20.y = v->y;
  blk->v20.z = v->z;
  blk->v20.w = v->w;
  return;
}
