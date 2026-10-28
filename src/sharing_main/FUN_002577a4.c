/* HSTMATCH module=hstp_trans_main.prx start=0x002577a4 end=0x002577c4 symbol=FUN_002577a4 lang=c99 */
/* Clone of src/eboot/FUN_0024759c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_002577a4(char *param_1,int param_2)
{
  if (*(int *)(param_1 + 0x3c) != param_2) {
    *(int *)(param_1 + 0x3c) = param_2;
    *(u8 *)(param_1 + 0x464) = 1;
  }
}
