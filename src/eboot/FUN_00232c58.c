/* HSTMATCH module=EBOOT.BIN start=0x00232c58 end=0x00232cc4 symbol=FUN_00232c58 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/challenge_lobby.h"

extern ChallengeLobby * DAT_0034a664;
extern void FUN_00000a00();
extern void FUN_00232e2c();
extern void FUN_00233384();
extern void FUN_002afd2c();

/* Lobby destructor: unregisters the singleton, releases the owned objects; frees the object when delete_flag > 0. */
ChallengeLobby * FUN_00232c58(ChallengeLobby *self,short delete_flag)
{
  if (self != 0) {
    DAT_0034a664 = 0;
    FUN_002afd2c();
    FUN_00232e2c(self);
    FUN_00233384(self,0xf0,0x88);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
