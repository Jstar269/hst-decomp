/* HSTMATCH module=hstp_trans_main.prx start=0x00277634 end=0x00277650 symbol=FUN_00277634 lang=c99 */
/* Clone of src/eboot/FUN_0026672c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mover.h"

/* Copies the body's +0xc4 float to +0xd0. */
void FUN_00277634(Mover *self)
{
  MoverBody *body;

  body = self->body;
  if (body != 0) {
    body->unkd0 = body->unkc4;
  }
}
