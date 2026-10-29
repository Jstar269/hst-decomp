/* HSTMATCH module=hstp_trans_main.prx start=0x00242d08 end=0x00242d58 symbol=FUN_00242d08 lang=c99 */
/* Clone of src/eboot/FUN_00232c08.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/challenge_lobby.h"

extern ChallengeLobby * DAT_003f3994;
extern void FUN_00242dc4();
extern void FUN_0024312c();

/* Lobby constructor: clears the owned pointers and flags, registers the singleton, builds the menu and enters the initial state. */
ChallengeLobby * FUN_00242d08(ChallengeLobby *self)
{
  self->menu = 0;
  self->unk4 = 0;
  DAT_003f3994 = self;
  self->unk10 = 0;
  self->unk11 = 0;
  self->unk12 = 0;
  FUN_00242dc4();
  FUN_0024312c(self,LOBBY_STATE_INITIAL);
  return self;
}
