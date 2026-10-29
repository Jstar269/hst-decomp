/* HSTMATCH module=hstp_trans_main.prx start=0x00277604 end=0x0027761c symbol=FUN_00277604 lang=c99 */
/* Clone of src/eboot/FUN_002666fc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mover.h"

/* Stores a byte into the body at +0xc0. */
void FUN_00277604(Mover *self,u8 value)
{
  if (self->body != 0) {
    self->body->unkc0 = value;
  }
}
