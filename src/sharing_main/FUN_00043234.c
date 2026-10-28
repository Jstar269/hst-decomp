/* HSTMATCH module=hstp_trans_main.prx start=0x00043234 end=0x00043240 symbol=FUN_00043234 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00043234(int param_1,u32 *param_2)
{
  *(u32 *)(param_1 + 0x68) = *param_2;
}
