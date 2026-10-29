/* HSTMATCH module=EBOOT.BIN start=0x00166bb8 end=0x00166c04 symbol=FUN_00166bb8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_block.h"

/* Set +0x60 from `a`, fill the +0x40 words with `b` and the +0x50 words with `c`. */
void FUN_00166bb8(VecBlock *blk,float *a,float *b,float *c)
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
