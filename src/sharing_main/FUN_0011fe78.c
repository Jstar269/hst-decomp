/* HSTMATCH module=hstp_trans_main.prx start=0x0011fe78 end=0x0011fe84 symbol=FUN_0011fe78 lang=c99 */
/* Clone of src/eboot/FUN_00115088.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0011e968();

void FUN_0011fe78(int param_1)
{
  *(u8 *)(*(int *)(param_1 + 0x54) + 0x90a) = 0;
  FUN_0011e968();
}
