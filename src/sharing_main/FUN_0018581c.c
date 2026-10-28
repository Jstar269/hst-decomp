/* HSTMATCH module=hstp_trans_main.prx start=0x0018581c end=0x00185834 symbol=FUN_0018581c lang=c99 */
/* Clone of src/eboot/FUN_00179190.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_0018581c(int param_1,int param_2)
{
  return **(u32 **)(*(int *)(param_1 + 0x1d8) + param_2 * 4);
}
