/* HSTMATCH module=hstp_trans_main.prx start=0x001dbee0 end=0x001dbeec symbol=FUN_001dbee0 lang=c99 */
/* Clone of src/eboot/FUN_001cd804.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_001dbee0(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 0x15c) + 0x2c);
}
