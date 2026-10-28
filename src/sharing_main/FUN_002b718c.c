/* HSTMATCH module=hstp_trans_main.prx start=0x002b718c end=0x002b7198 symbol=FUN_002b718c lang=c99 */
/* Clone of src/eboot/FUN_002a79fc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00111aa4();

void FUN_002b718c(int param_1,u32 param_2)
{
  FUN_00111aa4(*(u32 *)(param_1 + 0x358),param_2,0);
}
