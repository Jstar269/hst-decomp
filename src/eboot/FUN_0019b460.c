/* HSTMATCH module=EBOOT.BIN start=0x0019b460 end=0x0019b490 symbol=FUN_0019b460 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0010b5a4();

void FUN_0019b460(int param_1)
{
  FUN_0010b5a4();
  *(u32 *)(param_1 + 0x138) = 0;
  *(u32 *)(param_1 + 0x130) = 0;
  *(u32 *)(param_1 + 0x134) = 0;
}
