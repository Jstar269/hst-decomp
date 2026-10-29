/* HSTMATCH module=EBOOT.BIN start=0x00117cc4 end=0x00117d38 symbol=FUN_00117cc4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/wheel_state.h"

extern u32 DAT_003386b0;
extern void FUN_0001f558();
extern void FUN_00117d70();
extern void FUN_00117dd0();

void FUN_00117cc4(WheelState *state)
{
  FUN_00117d70(state,((state->unk5c + 10) - (state->unk68 + 1) % WHEEL_SLOTS) % WHEEL_SLOTS,
               -1,0);
  FUN_00117dd0(state);
  FUN_0001f558(DAT_003386b0,0x16,0,0);
}
