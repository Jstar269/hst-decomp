/* HSTMATCH module=hstp_trans_main.prx start=0x002a5b70 end=0x002a5b84 symbol=FUN_002a5b70 lang=c99 */
/* Clone of src/eboot/FUN_002955b4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00111aa4();

void FUN_002a5b70(int param_1)
{
  FUN_00111aa4(**(u32 **)(param_1 + 0x58),0,0);
}
