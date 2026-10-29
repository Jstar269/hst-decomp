/* HSTMATCH module=hstp_trans_main.prx start=0x00277650 end=0x00277668 symbol=FUN_00277650 lang=c99 */
/* Clone of src/eboot/FUN_00266748.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mover.h"

/* Zeroes the body's +0xd0 float. */
void FUN_00277650(Mover *self)
{
  if (self->body != 0) {
    *(u32 *)&self->body->unkd0 = 0;
  }
}
