/* HSTMATCH module=hstp_trans_main.prx start=0x000bd848 end=0x000bd8c0 symbol=FUN_000bd848 lang=c99 data=0x0037b524 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. Data: its string literals (4 strings, 0x0037b524-0x0037b62a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern void FUN_000bd6f0();
extern int FUN_002c7a60();

u32 FUN_000bd848(void)
{
  int iVar1;
  u32 uVar2;
  
  iVar1 = FUN_002c7a60(0x100);
  if (iVar1 < 0) {
    FUN_000bd6f0("sceUtilityUnloadModule(SCE_UTILITY_MODULE_NET_COMMON) failed(0x%X)\n",iVar1);
    uVar2 = 0;
  }
  else {
    FUN_000bd6f0("sceUtilityUnloadModule(SCE_UTILITY_MODULE_NET_COMMON) success\n");
    iVar1 = FUN_002c7a60(0x101);
    if (iVar1 < 0) {
      FUN_000bd6f0("sceUtilityUnloadModule(SCE_UTILITY_MODULE_NET_ADHOC) failed(0x%X)\n",iVar1);
      uVar2 = 0;
    }
    else {
      FUN_000bd6f0("sceUtilityUnloadModule(SCE_UTILITY_MODULE_NET_ADHOC) success\n");
      uVar2 = 1;
    }
  }
  return uVar2;
}
