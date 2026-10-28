/* HSTMATCH module=hstp_trans_main.prx start=0x001dbc70 end=0x001dbc7c symbol=FUN_001dbc70 lang=c99 */
/* Clone of src/eboot/FUN_001cd594.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_001dbc70(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 0x170) + 0x3c);
}
