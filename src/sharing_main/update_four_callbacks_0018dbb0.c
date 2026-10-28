/* HSTMATCH module=hstp_trans_main.prx start=0x0018dbb0 end=0x0018dcb0 symbol=FUN_0018dbb0 lang=c99 */
/* Clone of src/eboot/update_four_callbacks_001814bc.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a/v3) corrected by hand: inverted outer and nested condition ordering; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00105470();
extern u32 FUN_00177e98();

void FUN_0018dbb0(int param_1)
{
  int iVar1;
  u32 *puVar2;
  u32 *puVar3;
  u32 *puVar4;
  u32 *puVar5;
  
  puVar5 = (u32 *)(param_1 + 0x80);
  puVar4 = (u32 *)(param_1 + 0x94);
  puVar3 = (u32 *)(param_1 + 0xa8);
  puVar2 = (u32 *)(param_1 + 0xbc);
  iVar1 = FUN_00177e98();
  if (*(u8 *)(iVar1 + 0x94) != '\0') {
    iVar1 = FUN_00177e98();
    if (*(u8 *)(iVar1 + 0x45) != '\0') {
      FUN_00105470(*puVar5,0);
      FUN_00105470(*puVar4,0);
      FUN_00105470(*puVar3,1);
      FUN_00105470(*puVar2,1);
    }
    else {
      FUN_00105470(*puVar5,1);
      FUN_00105470(*puVar4,1);
      FUN_00105470(*puVar3,0);
      FUN_00105470(*puVar2,0);
    }
  }
  else {
    FUN_00105470(*puVar5,1);
    FUN_00105470(*puVar4,1);
    FUN_00105470(*puVar3,1);
    FUN_00105470(*puVar2,1);
  }
}
