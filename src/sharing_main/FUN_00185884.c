/* HSTMATCH module=hstp_trans_main.prx start=0x00185884 end=0x0018589c symbol=FUN_00185884 lang=c99 */
/* Clone of src/eboot/FUN_001791f8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00185884(int param_1,int param_2)
{
  return **(u32 **)(*(int *)(param_1 + 0x1f0) + param_2 * 4);
}
