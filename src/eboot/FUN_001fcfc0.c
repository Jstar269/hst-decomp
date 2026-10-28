/* HSTMATCH module=EBOOT.BIN start=0x001fcfc0 end=0x001fd060 symbol=FUN_001fcfc0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034a13c;
extern int FUN_00000bcc();
extern u32 * FUN_001fd180();
extern void FUN_001fd46c();
extern void FUN_001fd7e8();

void FUN_001fcfc0(u32 param_1,u32 param_2,u32 param_3,u32 param_4)
{
  int iVar1;
  
  if (DAT_0034a13c == 0) {
    iVar1 = FUN_00000bcc(0x1350);
    if (iVar1 != 0) {
      FUN_001fd180(iVar1,param_1);
    }
    FUN_001fd46c(DAT_0034a13c,1,0);
  }
  if (DAT_0034a13c != 0) {
    FUN_001fd7e8(DAT_0034a13c,param_2,param_3,param_4);
  }
}
