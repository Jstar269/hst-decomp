/* HSTMATCH module=hstp_trans_main.prx start=0x0020ddc0 end=0x0020de38 symbol=FUN_0020ddc0 lang=c99 */
/* Clone of src/eboot/FUN_001ff5f0.c (hstclone.py tag u6cr4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: used a switch over the mode values to retain the retail reversed test order and branch delay stores; exact match verified; names and types await human review. */
#include "hst/types.h"
extern u32 DAT_003f3434;

void FUN_0020ddc0(u8 *param_1, int *param_2)
{
  *param_1 = 0;
  switch (DAT_003f3434) {
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
