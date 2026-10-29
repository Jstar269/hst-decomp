/* HSTMATCH module=hstp_trans_main.prx start=0x0011fe30 end=0x0011fe78 symbol=FUN_0011fe30 lang=c99 */
/* Clone of src/eboot/FUN_00115040.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/state_host.h"

extern void FUN_0011eab8();

/* Sets the target's flag, then switches to state 5 keeping the value at 0x80. */
void FUN_0011fe30(StateHost *self,u32 value)
{
  self->target->unk90a = 1;
  self->unk80 = value;
  FUN_0011eab8(self,5);
  self->unk80 = value;
}
