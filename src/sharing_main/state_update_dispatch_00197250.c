/* HSTMATCH module=hstp_trans_main.prx start=0x00197250 end=0x00197338 symbol=FUN_00197250 lang=c99 */
/* Clone of src/eboot/state_update_dispatch_0018ab04.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the if/else-if chain on the state rewritten as a switch with cases 0..4 in source order (empty case 4); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003751d4;
extern u8 FUN_0001e7a0();
extern void FUN_00105470();
extern void FUN_00108a2c();
extern void FUN_00108dac();
extern void FUN_00197338();
extern void FUN_00197458();
extern void FUN_0019791c();
extern void FUN_00197a08();

void FUN_00197250(int param_1)
{
  u8 bVar1;
  int iVar2;
  u32 uVar3;
  
  uVar3 = (u32)(*(int *)(param_1 + 0x54) != 2);
  if (uVar3 == 0) {
    uVar3 = (u32)(0 < *(int *)(param_1 + 0x60));
  }
  FUN_00105470(*(int *)(param_1 + 0x74),uVar3);
  bVar1 = FUN_0001e7a0(DAT_003751d4,(u32 *)(param_1 + 0x68),0x4000);
  *(u8 *)(param_1 + 0x70) = bVar1;
  iVar2 = *(int *)(param_1 + 0x54);
  switch (iVar2) {
  case 0:
    FUN_00197338(param_1);
    break;
  case 1:
    FUN_00197458(param_1);
    break;
  case 2:
    FUN_0019791c(param_1);
    break;
  case 3:
    FUN_00197a08(param_1);
    break;
  case 4:
    break;
  }
  FUN_00108dac(param_1);
  FUN_00108a2c(param_1);
}
