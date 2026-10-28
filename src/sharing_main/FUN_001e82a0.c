/* HSTMATCH module=hstp_trans_main.prx start=0x001e82a0 end=0x001e82ac symbol=FUN_001e82a0 lang=c99 */
/* Clone of src/eboot/FUN_001da1bc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_001e82a0(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 0x58) + 0xdc);
}
