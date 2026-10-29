/* HSTMATCH module=hstp_trans_main.prx start=0x00172d40 end=0x00172d64 symbol=FUN_00172d40 lang=c99 */
/* Clone of src/eboot/FUN_00166b7c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/vec_block.h"

/* Store a 4-float vector at +0x20. */
void FUN_00172d40(VecBlock *blk,Float4 *v)
{
  blk->v20.x = v->x;
  blk->v20.y = v->y;
  blk->v20.z = v->z;
  blk->v20.w = v->w;
  return;
}
