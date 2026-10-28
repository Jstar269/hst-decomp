/* HSTMATCH module=hstp_trans_main.prx start=0x000514cc end=0x00051500 symbol=FUN_000514cc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1gs); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000514cc(char *param_1,u8 param_2,u8 param_3,u8 param_4, u8 param_5)
{
  *(u8 *)(param_1 + 0x1a0b4) = param_2;
  *(u8 *)(param_1 + 0x1a0b5) = param_3;
  *(u8 *)(param_1 + 0x1a0b6) = param_4;
  *(u8 *)(param_1 + 0x1a0b7) = param_5;
}
