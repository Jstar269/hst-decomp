/* HSTMATCH module=hstp_trans_main.prx start=0x000bc6e0 end=0x000bc794 symbol=FUN_000bc6e0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: FUN_00048958 return type changed to int; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003751d4;
extern u8 * DAT_003e19f0;
extern u32 DAT_003e1f60;
extern u8 * DAT_003eb004;
extern int FUN_00048958();
extern void FUN_000bb408();
extern void FUN_000bc7fc();
extern u32 FUN_00100ef4();

void FUN_000bc6e0(int param_1)
{
  int iVar1;
  
  if ((((((int)*(char *)(DAT_003751d4 + 0x88) << 0x1e) >> 0x1e == 0) &&
       (iVar1 = FUN_00048958(), iVar1 == 0)) && (iVar1 = FUN_00100ef4(DAT_003e1f60), iVar1 == 0))
     && (*(int *)(DAT_003e19f0 + 0x3c) == 4)) {
    iVar1 = (*(int *)(param_1 + 0x68) + 1) % 3;
    *(int *)(param_1 + 0x68) = iVar1;
    *(char *)(DAT_003eb004 + 0x1052) = (char)iVar1;
    *(u32 *)(param_1 + 100) = *(u32 *)(param_1 + 0x68);
    FUN_000bb408(param_1);
  }
  FUN_000bc7fc(param_1);
}
