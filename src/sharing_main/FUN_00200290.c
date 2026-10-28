/* HSTMATCH module=hstp_trans_main.prx start=0x00200290 end=0x002002ac symbol=FUN_00200290 lang=c99 */
/* Clone of src/eboot/FUN_001f1e8c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00200290(int param_1)
{
  if (*(int *)(param_1 + 0x44) == 0) {
    *(u8 *)(param_1 + 0x515) = 1;
  }
}
