/* HSTMATCH module=hstp_trans_main.prx start=0x00234f04 end=0x00234f10 symbol=FUN_00234f04 lang=c99 */
/* Clone of src/eboot/FUN_00225990.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0022a5fc();

void FUN_00234f04(int param_1)
{
  FUN_0022a5fc(**(u32 **)(param_1 + 0x3c));
}
