/* HSTMATCH module=hstp_trans_main.prx start=0x00100fb0 end=0x00100fbc symbol=FUN_00100fb0 lang=c99 */
/* Clone of src/eboot/FUN_000fb874.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00100fb0(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 0x3c) + 0x98);
}
