/* HSTMATCH module=EBOOT.BIN start=0x00233fc4 end=0x0023404c symbol=FUN_00233fc4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/challenge_lobby.h"

extern ChallengeLobby * DAT_0034a664;
extern u8 DAT_0034a678;
extern void FUN_00233518();
extern void FUN_00234158();
extern void FUN_0023466c();

/* Forwards the call to the lobby, then starts the follow-up action for lobby states 6, 7 (action 2) and 9. */
void FUN_00233fc4(u32 arg0,u32 arg1,u32 arg2,u32 arg3, u32 arg4,u32 arg5,u32 arg6,u32 arg7)
{
  bool is_6_or_7;
  int state;
  
  if (DAT_0034a664 != 0) {
    FUN_00233518(DAT_0034a664,arg1,arg2,arg3,arg4,arg5,arg6,arg7);
    state = DAT_0034a664->state;
    is_6_or_7 = true;
    if ((state != 6) && (state != 7)) {
      is_6_or_7 = false;
    }
    if (is_6_or_7) {
      FUN_00234158((int *)&DAT_0034a678,2);
    }
    else if (state == 9) {
      FUN_0023466c((int *)&DAT_0034a678);
    }
  }
}
