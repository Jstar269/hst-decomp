/* HSTMATCH module=hstp_trans_main.prx start=0x00111474 end=0x001114d8 symbol=FUN_00111474 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0399_00111474_m09.c); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00111474(int param_1,int param_2)
{
  u32 uVar2;
  int iVar1;
  
  *(u32 *)(param_1 + 0xd0) = 0;
  if (param_2 == 0) {
    *(u32 *)(param_1 + 0xdc) = *(u32 *)(param_1 + 0x110);
    *(u32 *)(param_1 + 0xe0) = 0;
    *(int *)(param_1 + 0xe4) = *(int *)(param_1 + 0x124) + -1;
  }
  *(u8 *)(param_1 + 0xe8) = 0;
  *(u8 *)(param_1 + 0xe9) = 0;
  *(u8 *)(param_1 + 0xea) = 0;
  *(u16 *)(param_1 + 0xec) = 0;
  *(u16 *)(param_1 + 0xee) = 0;
  *(u16 *)(param_1 + 0x11c) = 0;
  *(u16 *)(param_1 + 0x11e) = 0;
  uVar2 = 0;
  iVar1 = param_1;
  do {
    uVar2 = uVar2 + 1;
    *(u32 *)(iVar1 + 0xf0) = 0;
    iVar1 = iVar1 + 4;
  } while (uVar2 < 8);
  *(u8 *)(param_1 + 300) = 1;
}
