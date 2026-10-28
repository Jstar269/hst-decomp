/* HSTMATCH module=hstp_trans_main.prx start=0x002b4674 end=0x002b46a8 symbol=FUN_002b4674 lang=c99 */
/* Clone of src/eboot/FUN_002a4ee4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001109a8();

void FUN_002b4674(char *param_1)
{
  if (*(int *)(param_1 + 0x5d0) == 2) {
    FUN_001109a8(param_1 + 0x40,(u32 *)(param_1 + 0x5d4));
  }
}
