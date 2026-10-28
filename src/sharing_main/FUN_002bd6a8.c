/* HSTMATCH module=hstp_trans_main.prx start=0x002bd6a8 end=0x002bd6ec symbol=FUN_002bd6a8 lang=c99 */
/* Clone of src/eboot/FUN_002161c4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003f4910;
extern void FUN_00000a00();

int FUN_002bd6a8(int param_1,short param_2)
{
  if ((param_1 != 0) && (DAT_003f4910 = 0, 0 < param_2)) {
    FUN_00000a00();
  }
  return param_1;
}
