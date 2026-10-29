/* HSTMATCH module=EBOOT.BIN start=0x00166c04 end=0x00166c28 symbol=FUN_00166c04 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_block.h"

/* Set the first two +0x40 words to `b` and the first two +0x50 words to `c`. */
void FUN_00166c04(VecBlock *blk,float *b,float *c)
{
  blk->unk40[0] = *b;
  blk->unk40[1] = *b;
  blk->unk50[0] = *c;
  blk->unk50[1] = *c;
  return;
}
