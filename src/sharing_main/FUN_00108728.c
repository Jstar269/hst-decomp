/* HSTMATCH module=hstp_trans_main.prx start=0x00108728 end=0x0010873c symbol=FUN_00108728 lang=c99 */
/* Clone of src/eboot/FUN_00102e24.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00108728(int param_1,int param_2)
{
  return *(u32 *)(*(int *)(param_1 + 0x10) + param_2 * 4);
}
