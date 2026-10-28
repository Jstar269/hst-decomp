/* HSTMATCH module=hstp_trans_main.prx start=0x0015bbd4 end=0x0015bc00 symbol=FUN_0015bbd4 lang=c99 */
/* Clone of src/eboot/FUN_0014fba8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00299db0();

u32 FUN_0015bbd4(int param_1)
{
  FUN_00299db0(*(u32 *)(param_1 + 8),*(u32 *)(param_1 + 0xc),
               *(u32 *)(param_1 + 0x10));
  return 0;
}
