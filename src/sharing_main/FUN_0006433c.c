/* HSTMATCH module=hstp_trans_main.prx start=0x0006433c end=0x00064364 symbol=FUN_0006433c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003ba4b0;
extern u32 FUN_00050e10();
extern void FUN_00051d38();

void FUN_0006433c(int param_1)
{
  FUN_00051d38(*(u32 *)(param_1 + 4));
  FUN_00050e10((int)&DAT_003ba4b0);
}
