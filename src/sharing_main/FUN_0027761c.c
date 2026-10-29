/* HSTMATCH module=hstp_trans_main.prx start=0x0027761c end=0x00277634 symbol=FUN_0027761c lang=c99 */
/* Clone of src/eboot/FUN_00266714.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mover.h"

/* Stores a float into the body at +0xc4. */
void FUN_0027761c(float value,Mover *self)
{
  if (self->body != 0) {
    self->body->unkc4 = value;
  }
}
