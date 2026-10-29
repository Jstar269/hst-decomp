/* HSTMATCH module=EBOOT.BIN start=0x00232c08 end=0x00232c58 symbol=FUN_00232c08 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/challenge_lobby.h"

extern ChallengeLobby * DAT_0034a664;
extern void FUN_00232cc4();
extern void FUN_0023302c();

/* Lobby constructor: clears the owned pointers and flags, registers the singleton, builds the menu and enters the initial state. */
ChallengeLobby * FUN_00232c08(ChallengeLobby *self)
{
  self->menu = 0;
  self->unk4 = 0;
  DAT_0034a664 = self;
  self->unk10 = 0;
  self->unk11 = 0;
  self->unk12 = 0;
  FUN_00232cc4();
  FUN_0023302c(self,LOBBY_STATE_INITIAL);
  return self;
}
