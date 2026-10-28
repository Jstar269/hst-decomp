/* HSTMATCH module=hstp_trans_main.prx start=0x00094cb0 end=0x00094ccc symbol=FUN_00094cb0 lang=c99 */
/* Clone of src/eboot/FUN_00092e1c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00094cb0(int param_1)
{
  if (*(int *)(param_1 + 0x58) != 0) {
    *(u8 *)(*(int *)(param_1 + 0x58) + 0x170) = 1;
  }
}
