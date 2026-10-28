/* HSTMATCH module=hstp_trans_main.prx start=0x00051d40 end=0x00051d84 symbol=FUN_00051d40 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: expressed the three stores as ascending switch cases; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00051d40(int param_1,int param_2)
{
  switch (param_2) {
    case 0: *(u32 *)(param_1 + 0x1c) = 0x10; break;
    case 1: *(u32 *)(param_1 + 0x1c) = 0x11; break;
    case 2: *(u32 *)(param_1 + 0x1c) = 0x12; break;
  }
}
