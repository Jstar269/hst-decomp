/* HSTMATCH module=EBOOT.BIN start=0x001fb404 end=0x001fb44c symbol=FUN_001fb404 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern int FUN_001b1c44();

void FUN_001fb404(int param_1)
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x12d0) == -1) {
    iVar1 = FUN_001b1c44((int *)&DAT_0034179c,0x10);
    *(int *)(param_1 + 0x12d0) = iVar1;
    *(u32 *)(param_1 + 0x12d4) = 0;
  }
}
