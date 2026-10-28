/* HSTMATCH module=EBOOT.BIN start=0x00056d68 end=0x00056e58 symbol=FUN_00056d68 lang=c++ */
/* Clone of src/sharing_main/initialize_state_000579bc.cpp (hstclone.py tag u3r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: used a by-value empty tag for the third helper argument and a typed member address; exact match verified; names and types await human review. */
#include "hst/types.h"

struct EmptyTag_00056d68 {};
struct Obj_00056d68 { char pad[0x174]; u32 field174; };

extern "C" void * FUN_000114c0(void *,int,u32);
extern "C" void FUN_000595f8(void *,int);
extern "C" void FUN_000598b8(void *,u32,EmptyTag_00056d68);

extern "C" void FUN_00056d68(int param_1)
{
  u32 uVar2;
  int iVar1;
  
  *(u8 *)(param_1 + 0xec) = 1;
  uVar2 = 0;
  iVar1 = param_1;
  do {
    FUN_000114c0((void *)(iVar1 + 0xf0),0,0x34);
    *(u32 *)(iVar1 + 0xf0) = 0xffffffff;
    *(u32 *)(iVar1 + 0x100) = 0x3f800000;
    uVar2 = uVar2 + 1;
    *(u32 *)(iVar1 + 0x110) = 0xffffffff;
    iVar1 = iVar1 + 0x34;
  } while (uVar2 < 2);
  *(u32 *)(param_1 + 0x158) = 0;
  *(u32 *)(param_1 + 0x15c) = 0;
  *(u32 *)(param_1 + 0x160) = 0;
  *(u32 *)(param_1 + 0x164) = 0;
  *(u32 *)(param_1 + 0x168) = 0;
  *(u32 *)(param_1 + 0x16c) = 0;
  *(u8 *)(param_1 + 0x170) = 1;
  *(u8 *)(param_1 + 0x171) = 0;
  FUN_000598b8(&((Obj_00056d68 *)param_1)->field174,*(u32 *)(param_1 + 0x178),EmptyTag_00056d68());
  *(u32 *)(param_1 + 0x180) = 0;
  *(u32 *)(param_1 + 0x184) = 0x3f800000;
  *(u32 *)(param_1 + 400) = 0;
  *(u32 *)(param_1 + 0x194) = 0;
  *(u32 *)(param_1 + 0x198) = 0;
  *(u32 *)(param_1 + 0x1a0) = 0;
  *(u32 *)(param_1 + 0x1a4) = 0;
  *(u8 *)(param_1 + 0x1a8) = 1;
  if (*(u32 *)(param_1 + 0xe8) < 4) {
    FUN_000595f8((void *)(param_1 + 0xe0),4);
  }
}
