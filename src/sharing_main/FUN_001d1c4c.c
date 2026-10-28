/* HSTMATCH module=hstp_trans_main.prx start=0x001d1c4c end=0x001d1c6c symbol=FUN_001d1c4c lang=c99 */
/* Clone of src/eboot/FUN_001c38c0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001d1c4c(int param_1,u8 param_2)
{
  *(u8 *)(param_1 + 0x61) = param_2;
  if (*(u8 *)(param_1 + 0x61) != '\0') {
    *(u8 *)(param_1 + 0x62) = 1;
  }
}
