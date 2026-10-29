/* HSTMATCH module=hstp_trans_main.prx start=0x00172d7c end=0x00172dc8 symbol=FUN_00172d7c lang=c99 */
/* Clone of src/eboot/FUN_00166bb8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/vec_block.h"

/* Set +0x60 from `a`, fill the +0x40 words with `b` and the +0x50 words with `c`. */
void FUN_00172d7c(VecBlock *blk,float *a,float *b,float *c)
{
  blk->unk60 = *a;
  blk->unk40[0] = *b;
  blk->unk40[1] = *b;
  blk->unk40[2] = *b;
  blk->unk40[3] = *b;
  blk->unk50[0] = *c;
  blk->unk50[1] = *c;
  blk->unk50[2] = *c;
  blk->unk50[3] = *c;
  return;
}
