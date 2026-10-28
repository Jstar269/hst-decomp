/* HSTMATCH module=EBOOT.BIN start=0x00050bb8 end=0x00050bec symbol=FUN_00050bb8 lang=c99 */
/* Clone of src/sharing_main/FUN_000514cc.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00050bb8(char *param_1,u8 param_2,u8 param_3,u8 param_4, u8 param_5)
{
  *(u8 *)(param_1 + 0x1a0b4) = param_2;
  *(u8 *)(param_1 + 0x1a0b5) = param_3;
  *(u8 *)(param_1 + 0x1a0b6) = param_4;
  *(u8 *)(param_1 + 0x1a0b7) = param_5;
}
