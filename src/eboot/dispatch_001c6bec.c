/* HSTMATCH module=EBOOT.BIN start=0x001c6bec end=0x001c6cac symbol=FUN_001c6bec lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: used a direct nonnegative signed guard; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001c25b0();
extern void FUN_001c2714();
extern void FUN_0022bf94();

void FUN_001c6bec(int param_1,int param_2,u32 param_3,int param_4,u32 param_5, u32 param_6)
{
  if (param_2 < 0x11) {
    if (param_2 >= 0) {
      FUN_0022bf94(param_2,param_3);
    }
    if (param_4 < 0) {
      FUN_001c25b0(*(u32 *)(param_1 + 0x15c),param_2,param_3,param_5,param_6);
    }
    else {
      FUN_001c2714(*(u32 *)(param_1 + 0x15c),param_4,param_2,param_3,param_5,param_6);
    }
    *(u32 *)(param_1 + 0x154) = 0xffffffff;
  }
}
