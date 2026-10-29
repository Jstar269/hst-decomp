/* HSTMATCH module=hstp_trans_main.prx start=0x002352c8 end=0x002352dc symbol=FUN_002352c8 lang=c99 */
/* Clone of src/eboot/FUN_00225d54.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_parts.h"

extern void FUN_0022fcdc();

void FUN_002352c8(ModeObj *self,u32 arg1,u32 arg2)
{
  FUN_0022fcdc(self->parts->part1c,arg1,1,arg2);
}
