/* HSTMATCH module=hstp_trans_main.prx start=0x00122c74 end=0x00122cc4 symbol=FUN_00122c74 lang=c99 */
/* Clone of src/eboot/FUN_00117c24.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/wheel_state.h"

extern WheelHost * DAT_003e95c4;
extern void FUN_00122dc0();
extern void FUN_00122e94();

void FUN_00122c74(WheelState *state)
{
  FUN_00122dc0(state,1,-20,1);
  FUN_00122e94(state);
  state->unk4c = 1;
  DAT_003e95c4->unk80->unk79 = 0;
}
