/* HSTMATCH module=EBOOT.BIN start=0x001e7b08 end=0x001e7b48 symbol=FUN_001e7b08 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_001ee200();

void FUN_001e7b08(char *param_1)
{
  char *iVar1;
  
  iVar1 = (char *)(FUN_001ee200());
  *(int *)(param_1 + 0x2350) = *(int *)(iVar1 + 0x8178) + 3;
  *(u32 *)(param_1 + 0x2354) = 0xf;
}
