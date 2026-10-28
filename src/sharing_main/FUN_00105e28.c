/* HSTMATCH module=hstp_trans_main.prx start=0x00105e28 end=0x00105e6c symbol=FUN_00105e28 lang=c99 */
/* Clone of src/eboot/FUN_001004f4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00051e18();

void FUN_00105e28(u32 param_1,int param_2)
{
  if ((*(u16 *)(param_2 + 0xe) & 0x600) != 0) {
    FUN_00051e18(param_1,0xd4000000);
    FUN_00051e18(param_1,0xd50441e0);
  }
}
