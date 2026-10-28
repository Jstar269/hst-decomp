/* HSTMATCH module=EBOOT.BIN start=0x000ba504 end=0x000ba57c symbol=FUN_000ba504 lang=c99 data=0x002d4c5c */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128b); exact match verified; names and types await human review. Data: its string literals (4 strings, 0x002d4c5c-0x002d4d62) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern void FUN_000ba3ac();
extern int FUN_002b7cc0();

u32 FUN_000ba504(void)
{
  int iVar1;
  u32 uVar2;
  
  iVar1 = FUN_002b7cc0(0x100);
  if (iVar1 < 0) {
    FUN_000ba3ac("sceUtilityUnloadModule(SCE_UTILITY_MODULE_NET_COMMON) failed(0x%X)\n",iVar1);
    uVar2 = 0;
  }
  else {
    FUN_000ba3ac("sceUtilityUnloadModule(SCE_UTILITY_MODULE_NET_COMMON) success\n");
    iVar1 = FUN_002b7cc0(0x101);
    if (iVar1 < 0) {
      FUN_000ba3ac("sceUtilityUnloadModule(SCE_UTILITY_MODULE_NET_ADHOC) failed(0x%X)\n",iVar1);
      uVar2 = 0;
    }
    else {
      FUN_000ba3ac("sceUtilityUnloadModule(SCE_UTILITY_MODULE_NET_ADHOC) success\n");
      uVar2 = 1;
    }
  }
  return uVar2;
}
