/* HSTMATCH module=hstp_trans_main.prx start=0x0011e940 end=0x0011e950 symbol=FUN_0011e940 lang=c99 */
/* Clone of src/eboot/FUN_00114168.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0011e968();

void FUN_0011e940(int param_1)
{
  *(u8 *)(*(int *)(param_1 + 0x54) + 0x90a) = 1;
  FUN_0011e968();
}
