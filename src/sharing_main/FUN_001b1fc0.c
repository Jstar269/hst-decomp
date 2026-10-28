/* HSTMATCH module=hstp_trans_main.prx start=0x001b1fc0 end=0x001b1fd8 symbol=FUN_001b1fc0 lang=c99 */
/* Clone of src/eboot/FUN_001a49f4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_001b1fc0(int param_1,int param_2)
{
  return **(u32 **)(*(int *)(param_1 + 900) + param_2 * 4);
}
