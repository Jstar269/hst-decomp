/* HSTMATCH module=hstp_trans_main.prx start=0x000db110 end=0x000db148 symbol=FUN_000db110 lang=c99 */
/* Clone of src/eboot/FUN_000d7420.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00();

void FUN_000db110(u32 param_1,u32 *param_2)
{
  if (((param_2 != (u32 *)0x0) && (param_2 != (u32 *)0x0)) && ((*param_2 & 1) != 0)) {
    FUN_00000a00(param_2[2]);
  }
}
