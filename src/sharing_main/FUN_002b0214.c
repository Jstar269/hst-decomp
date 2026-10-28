/* HSTMATCH module=hstp_trans_main.prx start=0x002b0214 end=0x002b0240 symbol=FUN_002b0214 lang=c99 */
/* Clone of src/eboot/FUN_002a0e08.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00113a50();

void FUN_002b0214(int param_1,u8 param_2)
{
  *(u8 *)(param_1 + 0x14c) = param_2;
  if (*(u8 *)(param_1 + 0x14c) == '\0') {
    FUN_00113a50();
  }
}
