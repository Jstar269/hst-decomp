/* HSTMATCH module=hstp_trans_main.prx start=0x001c0e00 end=0x001c0eb8 symbol=FUN_001c0e00 lang=c99 */
/* Clone of src/eboot/select_mode_flags_001b2cd0.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: matched the status return type and branch polarity; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001be964();
extern int FUN_0023c5e0();

void FUN_001c0e00(int *param_1,u32 param_2)
{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  FUN_001be964(iVar2,1,0,param_2,0);
  if (FUN_0023c5e0(8) != 0) {
    FUN_001be964(iVar2,0xaf,0,0,0);
    *(u32 *)(iVar2 + 0x7cc) = 0xaf;
  }
  else {
    FUN_001be964(iVar2,0xae,0,0,0);
    *(u32 *)(iVar2 + 0x7cc) = 0xae;
  }
  FUN_001be964(iVar2,0x3e,0,0,0);
  FUN_001be964(iVar2,0x53,0,0,0);
}
