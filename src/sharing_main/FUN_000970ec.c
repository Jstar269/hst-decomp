/* HSTMATCH module=hstp_trans_main.prx start=0x000970ec end=0x00097110 symbol=FUN_000970ec lang=c99 */
/* Clone of src/eboot/FUN_000950e0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/keyed_state.h"

/* True when the frame matches, or when the mode is 3 or above (frame not compared). */
bool FUN_000970ec(KeyedState *self,int frame)
{
  bool same;
  
  if (self->mode < 3) {
    same = self->frame == frame;
  }
  else {
    same = true;
  }
  return same;
}
