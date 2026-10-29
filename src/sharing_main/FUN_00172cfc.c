/* HSTMATCH module=hstp_trans_main.prx start=0x00172cfc end=0x00172d40 symbol=FUN_00172cfc lang=c99 */
/* Clone of src/eboot/FUN_00166b38.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/vec_block.h"

/* Store a 4-float vector at +0x10 and mirror it to +0x80. */
void FUN_00172cfc(VecBlock *blk,Float4 *v)
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
