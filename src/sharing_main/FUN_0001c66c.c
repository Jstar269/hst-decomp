/* HSTMATCH module=hstp_trans_main.prx start=0x0001c66c end=0x0001c684 symbol=FUN_0001c66c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b3e6c;
extern bool FUN_0001bc2c();

void FUN_0001c66c(int param_1)
{
  *(u8 *)(param_1 + 0x1009) = 1;
  *(u8 *)(param_1 + 0x1008) = 1;
  FUN_0001bc2c((int)&DAT_003b3e6c);
}
