/* HSTMATCH module=hstp_trans_main.prx start=0x002c0154 end=0x002c0214 symbol=FUN_002c0154 lang=c99 */
/* Clone of src/eboot/FUN_002b0704.c (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Near-miss wip (lane u5cr1-2, unreviewed) corrected by hand: Ghidra dropped FUN_001118ac's third argument, which is the already computed iVar5 - 1 held in a2; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001118ac(int, int, int);
extern void FUN_00111aa4();

void FUN_002c0154(int param_1,u32 param_2)
{
  int iVar1;
  int iVar4;
  int iVar2;
  u32 uVar3;
  int iVar5;
  int current;
  int expected;
  
  iVar1 = param_1 + *(int *)(param_1 + 0x94) * 4;
  iVar5 = 0;
  iVar4 = 0;
  iVar2 = *(int *)(iVar1 + 0x3d0) << 1;
  do {
    if (iVar2 < *(int *)(iVar1 + 0x110)) {
      iVar5 = iVar5 + 1;
    }
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar4 < 6);
  current = *(int *)(param_1 + 0x3f8);
  expected = iVar5 - 1;
  if (current != expected) {
    FUN_001118ac(*(int *)(param_1 + 900),0,expected);
    *(int *)(param_1 + 0x3f8) = iVar5 + -1;
  }
  uVar3 = *(u32 *)(param_1 + 900);
  FUN_00111aa4(uVar3,param_2,0);
  ((u32 *)((char *)param_1 + 0x3a8))[*(int *)(param_1 + 0x94)] =
       *(u32 *)(*(int *)(param_1 + 900) + 0xdc);
}
