/* HSTMATCH module=hstp_trans_main.prx start=0x00172dc8 end=0x00172dec symbol=FUN_00172dc8 lang=c99 */
/* Clone of src/eboot/FUN_00166c04.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/vec_block.h"

/* Set the first two +0x40 words to `b` and the first two +0x50 words to `c`. */
void FUN_00172dc8(VecBlock *blk,float *b,float *c)
{
  blk->unk40[0] = *b;
  blk->unk40[1] = *b;
  blk->unk50[0] = *c;
  blk->unk50[1] = *c;
  return;
}
