/* HSTMATCH module=EBOOT.BIN start=0x00117c24 end=0x00117c74 symbol=FUN_00117c24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/wheel_state.h"

extern WheelHost * DAT_00340284;
extern void FUN_00117d70();
extern void FUN_00117dd0();

void FUN_00117c24(WheelState *state)
{
  FUN_00117d70(state,1,-20,1);
  FUN_00117dd0(state);
  state->unk4c = 1;
  DAT_00340284->unk80->unk79 = 0;
}
