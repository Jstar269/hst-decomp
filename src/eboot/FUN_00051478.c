/* HSTMATCH module=EBOOT.BIN start=0x00051478 end=0x00051490 symbol=FUN_00051478 lang=c99 */
/* Clone of src/sharing_main/FUN_00051e18.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00051478(int param_1,u32 param_2)
{
  **(u32 **)(param_1 + 0x28) = param_2;
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + 4;
}
