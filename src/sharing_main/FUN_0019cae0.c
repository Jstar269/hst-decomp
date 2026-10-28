/* HSTMATCH module=hstp_trans_main.prx start=0x0019cae0 end=0x0019cb14 symbol=FUN_0019cae0 lang=c99 */
/* Clone of src/eboot/FUN_001902d0.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_000031f0();

int FUN_0019cae0(int param_1)
{
  FUN_000031f0();
  *(u32 *)(param_1 + 0xc) = 0;
  *(u32 *)(param_1 + 0x10) = 0;
  *(u32 *)(param_1 + 0x14) = 0;
  return param_1;
}
