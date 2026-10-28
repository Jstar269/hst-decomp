/* HSTMATCH module=hstp_trans_main.prx start=0x00268ab8 end=0x00268ae0 symbol=FUN_00268ab8 lang=c99 */
/* Clone of src/eboot/FUN_00258608.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00268ab8(int param_1,int param_2,int param_3)
{
  return *(u32 *)(param_1 + param_2 * 0xa4 + param_3 * 4);
}
