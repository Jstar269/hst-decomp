/* HSTMATCH module=EBOOT.BIN start=0x002199c8 end=0x00219a50 symbol=FUN_002199c8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0391_002199c8_m15.c); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00051490();
extern void FUN_0005185c();
extern void FUN_0005a770();

void FUN_002199c8(u32 *param_1)
{
  int iVar2;
  int iVar1;
  
  FUN_00051490(*param_1,0,0,0x1e0,0x110,0,0);
  iVar2 = 0;
  iVar1 = 0;
  do {
    FUN_0005a770(param_1[1] + iVar1,*param_1,0,0);
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0xa0;
  } while (iVar2 < 200);
  FUN_0005185c(*param_1);
}
