/* HSTMATCH module=EBOOT.BIN start=0x00166af4 end=0x00166b38 symbol=FUN_00166af4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_block.h"

/* Store a 4-float vector at +0x00 and a copy at +0x70. */
void FUN_00166af4(VecBlock *blk,Float4 *v)
{
  blk->v00.x = v->x;
  blk->v00.y = v->y;
  blk->v00.z = v->z;
  blk->v00.w = v->w;
  blk->v70.x = v->x;
  blk->v70.y = v->y;
  blk->v70.z = v->z;
  blk->v70.w = v->w;
  return;
}
