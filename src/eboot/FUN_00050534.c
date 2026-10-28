/* HSTMATCH module=EBOOT.BIN start=0x00050534 end=0x00050544 symbol=FUN_00050534 lang=c99 */
/* Clone of src/sharing_main/FUN_00050e10.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00050534(char *param_1)
{
  return *(u32 *)(param_1 + 0x1a0a4);
}
