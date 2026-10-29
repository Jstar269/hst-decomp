/* HSTMATCH module=EBOOT.BIN start=0x00166bac end=0x00166bb8 symbol=FUN_00166bac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_block.h"

void FUN_00166bac(VecBlock *blk,float *value)
{
  blk->unk3c = *value;
  return;
}
