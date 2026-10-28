/* HSTMATCH module=hstp_trans_main.prx start=0x001e9da4 end=0x001e9de0 symbol=FUN_001e9da4 lang=c99 */
/* Clone of src/eboot/FUN_001dbc04.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e1a54;
extern void FUN_0005ffd8();

void FUN_001e9da4(int param_1)
{
  if ((*(int *)(param_1 + 0x3c) != 0) && (*(u8 *)(param_1 + 0xcc) != '\0')) {
    FUN_0005ffd8(*(int *)(param_1 + 0x3c),DAT_003e1a54);
  }
}
