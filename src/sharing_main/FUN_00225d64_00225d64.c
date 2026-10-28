/* HSTMATCH module=hstp_trans_main.prx start=0x00225d64 end=0x00225de4 symbol=FUN_00225d64 lang=c99 */
/* Clone of src/eboot/FUN_00216d60_00216d60.c (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: placed the nonzero dispatch arm first to match the target branch layout; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002d9e00;
extern u32 DAT_002d9e04;
extern u32 DAT_002d9e08;
extern u32 DAT_002d9e0c;
extern void FUN_00051d40();

void FUN_00225d64(u8 *param_1,int param_2)
{
  if (param_2 != 0) {
    FUN_00051d40(*(u32 *)(param_1 + 4),1);
    *(u32 *)(param_1 + 0x108) = DAT_002d9e04;
    *(u32 *)(param_1 + 0x10c) = DAT_002d9e00;
    *param_1 = 1;
  }
  else {
    FUN_00051d40(*(u32 *)(param_1 + 4),2);
    *(u32 *)(param_1 + 0x108) = DAT_002d9e0c;
    *(u32 *)(param_1 + 0x10c) = DAT_002d9e08;
    *param_1 = 1;
  }
}

