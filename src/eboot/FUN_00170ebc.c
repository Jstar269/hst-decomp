/* HSTMATCH module=EBOOT.BIN start=0x00170ebc end=0x00170f08 symbol=FUN_00170ebc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int DAT_003415ac;

void FUN_00170ebc(void)
{
  int iVar1;
  
  iVar1 = DAT_003415ac;
  if (DAT_003415ac != 0) {
    *(u32 *)(DAT_003415ac + 0x74) = 0x3f800000;
    *(u32 *)(iVar1 + 0x78) = 0x3f800000;
    iVar1 = DAT_003415ac;
    *(u32 *)(**(int **)(DAT_003415ac + 4) + 0x60) = 0x43700000;
    *(u32 *)(**(int **)(iVar1 + 4) + 100) = 0x43080000;
  }
}
