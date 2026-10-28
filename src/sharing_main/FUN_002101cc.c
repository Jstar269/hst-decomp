/* HSTMATCH module=hstp_trans_main.prx start=0x002101cc end=0x00210214 symbol=FUN_002101cc lang=c99 */
/* Clone of src/eboot/FUN_002019fc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/match_players.h"

/* Resets the setup object: clears the fields and sets the two float slots to 1.0f. */
MatchPlayers *FUN_002101cc(MatchPlayers *self)
{
  self->kind = 0;
  self->count = 0;
  self->unk00 = 0;
  self->p1 = 0;
  self->saved20[0] = 0;
  self->saved28[0] = 0;
  self->saved2c[0] = 1.0f;
  self->saved34[0] = 0.0f;
  self->saved3c[0] = 0;
  self->p2 = 0;
  self->saved20[1] = 0;
  self->saved28[1] = 0;
  self->saved2c[1] = 1.0f;
  self->saved34[1] = 0.0f;
  self->saved3c[1] = 0;
  return self;
}
