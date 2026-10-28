/* HSTMATCH module=EBOOT.BIN start=0x001b2c70 end=0x001b2cd0 symbol=FUN_001b2c70 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a1), refined by hstperm.py tag p4 random mutation from try/gen-a1/v0/FUN_001b2c70.c; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00062418();

void FUN_001b2c70(u32 *param_1)
{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  iVar1 = piVar2[0xb2];
  if (iVar1 == 0) {
    iVar1 = *piVar2;
  }
  else {
    if (iVar1 != 0) {
      FUN_00062418(iVar1,1);
      piVar2[0xb2] = 0;
    }
  }
  if (((*piVar2) != 0) && ((*piVar2) != 0)) {
    FUN_00062418((*piVar2),1);
    *piVar2 = 0;
  }
}
