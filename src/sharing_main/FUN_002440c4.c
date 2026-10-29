/* HSTMATCH module=hstp_trans_main.prx start=0x002440c4 end=0x0024414c symbol=FUN_002440c4 lang=c99 */
/* Clone of src/eboot/FUN_00233fc4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/challenge_lobby.h"

extern ChallengeLobby * DAT_003f3994;
extern u8 DAT_003f39a8;
extern void FUN_00243618();
extern void FUN_00244258();
extern void FUN_0024476c();

/* Forwards the call to the lobby, then starts the follow-up action for lobby states 6, 7 (action 2) and 9. */
void FUN_002440c4(u32 arg0,u32 arg1,u32 arg2,u32 arg3, u32 arg4,u32 arg5,u32 arg6,u32 arg7)
{
  bool is_6_or_7;
  int state;
  
  if (DAT_003f3994 != 0) {
    FUN_00243618(DAT_003f3994,arg1,arg2,arg3,arg4,arg5,arg6,arg7);
    state = DAT_003f3994->state;
    is_6_or_7 = true;
    if ((state != 6) && (state != 7)) {
      is_6_or_7 = false;
    }
    if (is_6_or_7) {
      FUN_00244258((int *)&DAT_003f39a8,2);
    }
    else if (state == 9) {
      FUN_0024476c((int *)&DAT_003f39a8);
    }
  }
}
