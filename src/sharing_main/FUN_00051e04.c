/* HSTMATCH module=hstp_trans_main.prx start=0x00051e04 end=0x00051e18 symbol=FUN_00051e04 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003ba4b0;
extern u32 FUN_00050920();

void FUN_00051e04(int param_1)
{
  FUN_00050920((int)&DAT_003ba4b0,*(u32 *)(param_1 + 4),0);
}
