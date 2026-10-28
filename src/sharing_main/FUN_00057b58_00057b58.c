/* HSTMATCH module=hstp_trans_main.prx start=0x00057b58 end=0x00057bdc symbol=FUN_00057b58 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed the helper argument and preserved the zero-or-call result; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00010184();
extern u32 FUN_0002fe30(int param_1);
extern void FUN_00057bdc();
extern void FUN_00058514();
extern void FUN_000589c0();

void FUN_00057b58(int param_1)
{
  int iVar1;
  u32 uVar2;
  
  FUN_00057bdc();
  if (*(int *)(param_1 + 0x8c) != 0) {
    iVar1 = (*(int *)(*(int *)(param_1 + 0x8c) + 8) != 0)
               ? FUN_0002fe30(*(int *)(*(int *)(param_1 + 0x8c) + 8))
               : 0;
    uVar2 = FUN_00010184(0x10,iVar1 << 6);
    *(u32 *)(param_1 + 0x160) = uVar2;
    uVar2 = FUN_00010184(0x10,iVar1 << 6);
    *(u32 *)(param_1 + 0x164) = uVar2;
    FUN_000589c0(param_1);
  }
  FUN_00058514(param_1);
}
