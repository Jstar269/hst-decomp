/* HSTMATCH module=hstp_trans_main.prx start=0x0010c7ec end=0x0010c7fc symbol=FUN_0010c7ec lang=c99 */
/* Clone of src/eboot/FUN_00106c08.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d13b0;
extern void FUN_00105fe4();

void FUN_0010c7ec(int param_1,u32 *param_2,u32 param_3)
{
  FUN_00105fe4(param_1,param_2,(u32 *)&DAT_002d13b0,param_3);
}
