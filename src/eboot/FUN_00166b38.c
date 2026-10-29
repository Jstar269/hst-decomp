/* HSTMATCH module=EBOOT.BIN start=0x00166b38 end=0x00166b7c symbol=FUN_00166b38 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_block.h"

/* Store a 4-float vector at +0x10 and mirror it to +0x80. */
void FUN_00166b38(VecBlock *blk,Float4 *v)
{
  blk->v10.x = v->x;
  blk->v10.y = v->y;
  blk->v10.z = v->z;
  blk->v10.w = v->w;
  blk->v80.x = blk->v10.x;
  blk->v80.y = blk->v10.y;
  blk->v80.z = blk->v10.z;
  blk->v80.w = blk->v10.w;
  return;
}
