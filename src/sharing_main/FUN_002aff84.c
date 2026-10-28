/* HSTMATCH module=hstp_trans_main.prx start=0x002aff84 end=0x002aff90 symbol=FUN_002aff84 lang=c99 */
/* Clone of src/eboot/FUN_002a0b78.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_002aff84(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 8) + 8);
}
