/* HSTMATCH module=hstp_trans_main.prx start=0x00097048 end=0x00097064 symbol=FUN_00097048 lang=c99 */
/* Clone of src/eboot/FUN_0009503c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/keyed_state.h"

/* Reset the keyed state record to its initial values. */
void FUN_00097048(KeyedState *self)
{
  self->mode = KEYED_MODE_INITIAL;
  self->key = KEYED_KEY_NONE;
  self->frame = 0;
  self->flag = 0;
}
