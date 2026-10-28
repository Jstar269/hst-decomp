/* HSTMATCH module=hstp_trans_main.prx start=0x002a4454 end=0x002a446c symbol=FUN_002a4454 lang=c99 */
/* Clone of src/eboot/FUN_00292e48.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_002a4454(int param_1)
{
  *(u8 *)(param_1 + 0x40) = 0;
  *(u32 *)(param_1 + 4) = 0x41f00000;
  *(u32 *)(param_1 + 8) = 0x41f00000;
  *(u32 *)(param_1 + 0x38) = 0;
}
