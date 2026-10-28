/* HSTMATCH module=hstp_trans_main.prx start=0x001bccd8 end=0x001bcdcc symbol=FUN_001bccd8 lang=c++ */
/* Clone of src/eboot/configure_menu_state_001af600.cpp (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" void FUN_00105470(...);
extern "C" void FUN_001118ac(...);
extern "C" u32 FUN_001aa91c();
extern "C" void FUN_001ba298(...);
extern "C" void FUN_001ba5cc(...);
extern "C" void FUN_001ba9b8(...);
extern "C" void FUN_001bac6c(...);
extern "C" void FUN_001baf04(...);

static inline int &EntryValue(int *p)
{
  return *(int *)((char *)p + 0x24);
}

extern "C" void FUN_001bccd8(int param_1)
{
  int iVar7;
  u32 uVar6;
  int iVar5;
  int iVar1;
  u32 *puVar2;
  u32 uVar3;
  u32 uVar4;
  
  iVar7 = *(int *)(param_1 + 0xc);
  FUN_001118ac(*(u32 *)(iVar7 + 0x914),0x1e,0x1f);
  iVar1 = FUN_001aa91c();
  uVar4 = *(u32 *)(iVar1 + 0x2dc);
  iVar1 = FUN_001aa91c() + 0x360;
  uVar6 = 0;
  if (*(int *)(iVar1 + 4) != 0) {
    iVar5 = 0;
    do {
      puVar2 = (u32 *)(iVar7 + (iVar5 + 0x7bc));
      int &item = EntryValue((int *)puVar2);
      if (uVar4 == uVar6) {
        FUN_00105470(item,0);
        uVar3 = *(u32 *)(iVar1 + 4);
      }
      else {
        FUN_00105470(item,1);
        uVar3 = *(u32 *)(iVar1 + 4);
      }
      uVar6 = uVar6 + 1;
      iVar5 = iVar5 + 0x14;
    } while (uVar6 < uVar3);
  }
  FUN_001ba298(iVar7,0);
  FUN_001ba5cc(iVar7,0);
  FUN_001ba9b8(iVar7,0);
  FUN_001bac6c(iVar7,0);
  FUN_001baf04(iVar7,1);
}
