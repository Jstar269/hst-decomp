/* HSTMATCH module=hstp_trans_main.prx start=0x002c1e5c end=0x002c20ac symbol=FUN_002c1e5c lang=c99 */
/* Clone of src/eboot/FUN_002b23d8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_003ac0a4[];
extern char DAT_003ac21c[];
extern char DAT_003ac230[];
extern char DAT_003ac23c[];
extern char DAT_003ac24c[];
extern char DAT_003ac25c[];
extern char DAT_003ac268[];
extern char DAT_003ac274[];
extern char DAT_003ac288[];
extern void FUN_000143b0();
extern void FUN_00105470();
extern int FUN_00108124();
extern int FUN_00109304();

void FUN_002c1e5c(int param_1,u32 param_2,u32 param_3)
{
  u32 uVar1;
  u8 auStack_40 [64];
  
  FUN_000143b0(auStack_40,DAT_003ac21c);
  uVar1 = FUN_00109304(param_1 + 0x3c,param_2,0);
  uVar1 = FUN_00108124(uVar1,auStack_40);
  FUN_00105470(uVar1,1);
  FUN_000143b0(auStack_40,DAT_003ac230,param_3);
  uVar1 = FUN_00109304(param_1 + 0x3c,param_2,0);
  uVar1 = FUN_00108124(uVar1,auStack_40);
  FUN_00105470(uVar1,1);
  FUN_000143b0(auStack_40,DAT_003ac23c,param_3);
  uVar1 = FUN_00109304(param_1 + 0x3c,param_2,0);
  uVar1 = FUN_00108124(uVar1,auStack_40);
  FUN_00105470(uVar1,1);
  FUN_000143b0(auStack_40,DAT_003ac24c,param_3);
  uVar1 = FUN_00109304(param_1 + 0x3c,param_2,0);
  uVar1 = FUN_00108124(uVar1,auStack_40);
  FUN_00105470(uVar1,1);
  FUN_000143b0(auStack_40,DAT_003ac25c,param_3);
  uVar1 = FUN_00109304(param_1 + 0x3c,param_2,0);
  uVar1 = FUN_00108124(uVar1,auStack_40);
  FUN_00105470(uVar1,1);
  FUN_000143b0(auStack_40,DAT_003ac268,param_3);
  uVar1 = FUN_00109304(param_1 + 0x3c,param_2,0);
  uVar1 = FUN_00108124(uVar1,auStack_40);
  FUN_00105470(uVar1,1);
  FUN_000143b0(auStack_40,DAT_003ac274,param_3);
  uVar1 = FUN_00109304(param_1 + 0x3c,param_2,0);
  uVar1 = FUN_00108124(uVar1,auStack_40);
  FUN_00105470(uVar1,1);
  FUN_000143b0(auStack_40,DAT_003ac288,param_3);
  uVar1 = FUN_00109304(param_1 + 0x3c,param_2,0);
  uVar1 = FUN_00108124(uVar1,auStack_40);
  FUN_00105470(uVar1,1);
  FUN_000143b0(auStack_40,DAT_003ac0a4,param_3);
  uVar1 = FUN_00109304(param_1 + 0x3c,param_2,0);
  uVar1 = FUN_00108124(uVar1,auStack_40);
  FUN_00105470(uVar1,1);
}
