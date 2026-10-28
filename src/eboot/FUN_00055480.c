/* HSTMATCH module=EBOOT.BIN start=0x00055480 end=0x0005548c symbol=FUN_00055480 lang=c99 */
/* Clone of src/sharing_main/FUN_00055fd0.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00055480(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 0x8c) + 0xc);
}
