/* HSTMATCH module=hstp_trans_main.prx start=0x001dfd84 end=0x001dfd98 symbol=FUN_001dfd84 lang=c99 */
/* Clone of src/eboot/FUN_001d1f80.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_001dfd84(int param_1,int param_2)
{
  return *(u32 *)(*(int *)(param_1 + 4) + param_2 * 4);
}
