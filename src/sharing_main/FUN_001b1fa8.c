/* HSTMATCH module=hstp_trans_main.prx start=0x001b1fa8 end=0x001b1fc0 symbol=FUN_001b1fa8 lang=c99 */
/* Clone of src/eboot/FUN_001a49dc.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_001b1fa8(int param_1,int param_2)
{
  return **(u32 **)(*(int *)(param_1 + 0x378) + param_2 * 4);
}
