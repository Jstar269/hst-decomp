/* HSTMATCH module=hstp_trans_main.prx start=0x001e1e80 end=0x001e1e8c symbol=FUN_001e1e80 lang=c99 */
/* Clone of src/eboot/FUN_001d407c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001e1e80(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0x24) = param_2;
  *(u32 *)(param_1 + 0x28) = param_2;
}
