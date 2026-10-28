/* HSTMATCH module=hstp_trans_main.prx start=0x001d5014 end=0x001d50d4 symbol=FUN_001d5014 lang=c99 */
/* Clone of src/eboot/dispatch_001c6bec.c (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: used a direct nonnegative signed guard; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001d08d8();
extern void FUN_001d0a3c();
extern void FUN_0023ba04();

void FUN_001d5014(int param_1,int param_2,u32 param_3,int param_4,u32 param_5, u32 param_6)
{
  if (param_2 < 0x11) {
    if (param_2 >= 0) {
      FUN_0023ba04(param_2,param_3);
    }
    if (param_4 < 0) {
      FUN_001d08d8(*(u32 *)(param_1 + 0x15c),param_2,param_3,param_5,param_6);
    }
    else {
      FUN_001d0a3c(*(u32 *)(param_1 + 0x15c),param_4,param_2,param_3,param_5,param_6);
    }
    *(u32 *)(param_1 + 0x154) = 0xffffffff;
  }
}
