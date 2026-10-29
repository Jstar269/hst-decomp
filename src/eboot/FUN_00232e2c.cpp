/* HSTMATCH module=EBOOT.BIN start=0x00232e2c end=0x00232ec4 symbol=FUN_00232e2c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/challenge_lobby.h"

/* Owned objects, each deleted through its virtual destructor. */
struct LobbyMenu { virtual ~LobbyMenu(); };
struct LobbyHelper4 { virtual ~LobbyHelper4(); };
struct LobbyHelper8 { virtual ~LobbyHelper8(); };

/* Deletes the lobby's three owned objects (menu and the two helpers) and clears the pointers. */
extern "C" void FUN_00232e2c(ChallengeLobby *self)
{
  LobbyMenu *menu;
  LobbyHelper4 *helper4;
  LobbyHelper8 *helper8;
  
  menu = self->menu;
  if (menu != 0) {
    delete menu;
    self->menu = 0;
  }
  helper4 = self->unk4;
  if (helper4 != 0) {
    delete helper4;
    self->unk4 = 0;
  }
  helper8 = self->unk8;
  if (helper8 != 0) {
    delete helper8;
    self->unk8 = 0;
  }
}
