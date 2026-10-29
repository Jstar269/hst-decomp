/* HSTMATCH module=hstp_trans_main.prx start=0x001f8dbc end=0x001f8dd0 symbol=FUN_001f8dbc lang=c99 */
/* Clone of src/eboot/FUN_001eab18.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/two_quad_screen.h"

/* Marks the screen active and restarts its counter. */
void FUN_001f8dbc(TwoQuadRef *ref)
{
  TwoQuadScreen *screen;
  
  screen = ref->screen;
  screen->active = 1;
  screen->counter = 0;
}
