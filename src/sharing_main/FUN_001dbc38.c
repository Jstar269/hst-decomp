/* HSTMATCH module=hstp_trans_main.prx start=0x001dbc38 end=0x001dbc60 symbol=FUN_001dbc38 lang=c99 */
/* Clone of src/eboot/FUN_001cd55c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0028d264();

void FUN_001dbc38(int param_1)
{
  if (*(int *)(param_1 + 0x170) != 0) {
    FUN_0028d264(*(u32 *)(*(int *)(param_1 + 0x170) + 0x3c));
  }
}
