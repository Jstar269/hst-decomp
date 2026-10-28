/* HSTMATCH module=hstp_trans_main.prx start=0x00263794 end=0x002637c0 symbol=FUN_00263794 lang=c99 */
/* Clone of src/eboot/FUN_00253440.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_002637c0();

int FUN_00263794(int param_1)
{
  *(u8 *)(param_1 + 0x34) = 0;
  FUN_002637c0();
  return param_1;
}
