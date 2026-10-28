/* HSTMATCH module=hstp_trans_main.prx start=0x001c8c6c end=0x001c8c88 symbol=FUN_001c8c6c lang=c99 */
/* Clone of src/eboot/FUN_001baf24.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u8 FUN_001c8c6c(int param_1,int param_2)
{
  return *(u8 *)(**(int **)(*(int *)(param_1 + 4) + param_2 * 4) + 0x75);
}
