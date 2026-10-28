/* HSTMATCH module=EBOOT.BIN start=0x00155c40 end=0x00155cac symbol=FUN_00155c40 lang=c99 data=0x002dcb90 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag q3); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dcb90-0x002dcba3) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_003402f0;
extern u32 DAT_0034a114;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern int FUN_001c70c0();
extern void FUN_00293764();

u32 FUN_00155c40(int param_1,u32 param_2)
{
  int iVar1;
  
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94("UnlinkKomono [%d]\n",*(u32 *)(param_1 + 8));
  }
  iVar1 = FUN_001c70c0(DAT_0034a114,*(u32 *)(param_1 + 8));
  if (iVar1 != 0) {
    FUN_00293764(iVar1,0);
  }
  return 0;
}
