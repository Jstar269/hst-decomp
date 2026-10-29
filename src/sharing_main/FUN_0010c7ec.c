/* HSTMATCH module=hstp_trans_main.prx start=0x0010c7ec end=0x0010c7fc symbol=FUN_0010c7ec lang=c99 */
/* Clone of src/eboot/FUN_00106c08.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d13b0;
extern void FUN_00105fe4();

/* Forward to the two-path loader with a fixed second name. */
void FUN_0010c7ec(int self,u32 *path,u32 arg)
{
  FUN_00105fe4(self,path,(u32 *)&DAT_002d13b0,arg);
}
