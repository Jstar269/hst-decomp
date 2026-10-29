/* HSTMATCH module=hstp_trans_main.prx start=0x00242d58 end=0x00242dc4 symbol=FUN_00242d58 lang=c99 */
/* Clone of src/eboot/FUN_00232c58.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/challenge_lobby.h"

extern ChallengeLobby * DAT_003f3994;
extern void FUN_00000a00();
extern void FUN_00242f2c();
extern void FUN_00243484();
extern void FUN_002bf77c();

/* Lobby destructor: unregisters the singleton, releases the owned objects; frees the object when delete_flag > 0. */
ChallengeLobby * FUN_00242d58(ChallengeLobby *self,short delete_flag)
{
  if (self != 0) {
    DAT_003f3994 = 0;
    FUN_002bf77c();
    FUN_00242f2c(self);
    FUN_00243484(self,0xf0,0x88);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
