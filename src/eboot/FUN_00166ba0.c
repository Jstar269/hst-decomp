/* HSTMATCH module=EBOOT.BIN start=0x00166ba0 end=0x00166bac symbol=FUN_00166ba0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_block.h"

void FUN_00166ba0(VecBlock *blk,float *value)
{
  blk->unk30 = *value;
  return;
}
