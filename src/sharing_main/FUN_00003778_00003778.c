/* HSTMATCH module=hstp_trans_main.prx start=0x00003778 end=0x000037f8 symbol=FUN_00003778 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: restored the dropped FUN_000030d0(param_1) argument and its int return; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_00003088();
extern int FUN_000030b0();
extern int FUN_000030d0(u32);
extern int FUN_00003148();
extern u8 FUN_00003168();

void FUN_00003778(u32 param_1,u32 *param_2,u32 *param_3)
{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  u32 *puVar4;
  
  iVar1 = FUN_000030d0(param_1);
  if (iVar1 == 0) {
    uVar3 = FUN_000030b0(param_1);
    *param_2 = uVar3;
    uVar2 = FUN_00003168(param_1);
    *param_3 = uVar2 & 0xff;
  }
  else {
    uVar3 = FUN_00003088(param_1);
    *param_2 = uVar3;
    puVar4 = (u32 *)FUN_00003148(param_1);
    *param_3 = *puVar4;
  }
}
