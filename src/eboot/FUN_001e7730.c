/* HSTMATCH module=EBOOT.BIN start=0x001e7730 end=0x001e7770 symbol=FUN_001e7730 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_001ee200();

void FUN_001e7730(char *param_1)
{
  char *iVar1;
  
  iVar1 = (char *)(FUN_001ee200());
  *(int *)(param_1 + 0x2350) = *(int *)(iVar1 + 0x8178) + 4;
  *(u32 *)(param_1 + 0x2354) = 0xf;
}
