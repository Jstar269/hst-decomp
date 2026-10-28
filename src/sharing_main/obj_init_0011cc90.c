/* HSTMATCH module=hstp_trans_main.prx start=0x0011cc90 end=0x0011cde0 symbol=FUN_0011cc90 lang=c99 */
/* Clone of src/eboot/obj_init_00112cc0.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: member offsets written off a piVar1 = param_1 + 0x20 base, the address expressions rewritten, #pragma opt_strength_reduction off (retail recomputes param_1 + iVar2 per store); exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
#include "hst/types.h"
extern u8 DAT_002cc260;
extern u8 DAT_0037ffe4;
extern u8 DAT_003b0a68;
extern u8 DAT_003b0fbc;
extern u8 DAT_003b0fc8;
extern u32 FUN_00056cac();
extern u32 * FUN_001016c0();
extern u32 * FUN_00101748();
extern u32 * FUN_001017dc();

int * FUN_0011cc90(int *param_1,short param_2)
{
  int *piVar1;
  int iVar2;

  if (param_2 != 0) {
    piVar1 = param_1 + 0x20;
    *param_1 = (int)piVar1;
    FUN_001017dc(piVar1);
    FUN_00056cac(piVar1 + 0xc);
    *piVar1 = (int)&DAT_003b0a68;
    piVar1[0x1c] = 0;
    piVar1[0x1d] = -1;
    piVar1[0x1e] = 0x3f800000;
    piVar1[0x1f] = 0x3f800000;
    FUN_00056cac(piVar1 + 0x20);
    piVar1[0x30] = (int)&DAT_0037ffe4;
    FUN_00101748(piVar1,&DAT_002cc260);
    FUN_001016c0(piVar1 + 0x20,&DAT_002cc260);
  }
  param_1[0x1f] = (int)&DAT_003b0fbc;
  *(u8 **)*param_1 = &DAT_003b0fc8;
  iVar2 = 0;
  *(int *)(*param_1 + 0xd0) = (int)(param_1 + 0x20) - *param_1;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  piVar1 = param_1;
  do {
    piVar1[4] = -999;
    *(u8 *)((int)param_1 + iVar2 + 0x4c) = 1;
    *(u8 *)((int)param_1 + iVar2 + 0x5b) = 0;
    *(u8 *)((int)param_1 + iVar2 + 0x6a) = 0;
    piVar1[5] = -999;
    *(u8 *)((int)param_1 + iVar2 + 0x4d) = 1;
    *(u8 *)((int)param_1 + iVar2 + 0x5c) = 0;
    *(u8 *)((int)param_1 + iVar2 + 0x6b) = 0;
    piVar1[6] = -999;
    *(u8 *)((int)param_1 + iVar2 + 0x4e) = 1;
    *(u8 *)((int)param_1 + iVar2 + 0x5d) = 0;
    *(u8 *)((int)param_1 + iVar2 + 0x6c) = 0;
    piVar1[7] = -999;
    *(u8 *)((int)param_1 + iVar2 + 0x4f) = 1;
    *(u8 *)((int)param_1 + iVar2 + 0x5e) = 0;
    *(u8 *)((int)param_1 + iVar2 + 0x6d) = 0;
    piVar1[8] = -999;
    *(u8 *)((int)param_1 + iVar2 + 0x50) = 1;
    *(u8 *)((int)param_1 + iVar2 + 0x5f) = 0;
    *(u8 *)((int)param_1 + iVar2 + 0x6e) = 0;
    iVar2 = iVar2 + 5;
    piVar1 = piVar1 + 5;
  } while (iVar2 < 0xf);
  return param_1;
}
