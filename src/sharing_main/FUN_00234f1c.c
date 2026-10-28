/* HSTMATCH module=hstp_trans_main.prx start=0x00234f1c end=0x00234f28 symbol=FUN_00234f1c lang=c99 */
/* Clone of src/eboot/FUN_002259a8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00234f1c(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 0x3c) + 0x2c);
}
