/* HSTMATCH module=hstp_trans_main.prx start=0x00097edc end=0x00097f14 symbol=FUN_00097edc lang=c99 */
/* Clone of src/eboot/FUN_00095dd8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_000114c0();

int FUN_00097edc(int param_1)
{
  *(u32 *)(param_1 + 0x2c) = 1;
  FUN_000114c0(param_1,0,0x40);
  return param_1;
}
