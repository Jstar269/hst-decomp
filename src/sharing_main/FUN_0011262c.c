/* HSTMATCH module=hstp_trans_main.prx start=0x0011262c end=0x00112638 symbol=FUN_0011262c lang=c99 */
/* Clone of src/eboot/FUN_0010c2b4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/stream_obj.h"

/* Clears two integer fields of the stream. */
void FUN_0011262c(StreamObj *self)
{
  self->unk08 = 0;
  self->unk68 = 0;
}
