/* HSTMATCH module=hstp_trans_main.prx start=0x00172cb8 end=0x00172cfc symbol=FUN_00172cb8 lang=c99 */
/* Clone of src/eboot/FUN_00166af4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/vec_block.h"

/* Store a 4-float vector at +0x00 and a copy at +0x70. */
void FUN_00172cb8(VecBlock *blk,Float4 *v)
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
