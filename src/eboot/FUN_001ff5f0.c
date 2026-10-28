/* HSTMATCH module=EBOOT.BIN start=0x001ff5f0 end=0x001ff668 symbol=FUN_001ff5f0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: used a switch over the mode values to retain the retail reversed test order and branch delay stores; exact match verified; names and types await human review. */
#include "hst/types.h"
extern u32 DAT_0034a0fc;

void FUN_001ff5f0(u8 *param_1, int *param_2)
{
  *param_1 = 0;
  switch (DAT_0034a0fc) {
  case 1:
    *param_1 = 1;
    *param_2 = 2;
    break;
  case 2:
    *param_1 = 1;
    *param_2 = 1;
    break;
  case 3:
    *param_1 = 1;
    *param_2 = 0;
    break;
  case 4:
    *param_1 = 1;
    *param_2 = 3;
    break;
  default:
    break;
  }
}
