/* HSTMATCH module=EBOOT.BIN start=0x00216d60 end=0x00216de0 symbol=FUN_00216d60 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: placed the nonzero dispatch arm first to match the target branch layout; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002c983c;
extern u32 DAT_002c9840;
extern u32 DAT_002c9844;
extern u32 DAT_002c9848;
extern void FUN_000513a0();

void FUN_00216d60(u8 *param_1,int param_2)
{
  if (param_2 != 0) {
    FUN_000513a0(*(u32 *)(param_1 + 4),1);
    *(u32 *)(param_1 + 0x108) = DAT_002c9840;
    *(u32 *)(param_1 + 0x10c) = DAT_002c983c;
    *param_1 = 1;
  }
  else {
    FUN_000513a0(*(u32 *)(param_1 + 4),2);
    *(u32 *)(param_1 + 0x108) = DAT_002c9848;
    *(u32 *)(param_1 + 0x10c) = DAT_002c9844;
    *param_1 = 1;
  }
}

