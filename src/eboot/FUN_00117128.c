/* HSTMATCH module=EBOOT.BIN start=0x00117128 end=0x00117154 symbol=FUN_00117128 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/wheel_state.h"

/* Resets the state's fields to their initial values (indices -1, counters 0). */
void FUN_00117128(WheelState *state)
{
  state->unk4c = 0;
  state->unk50 = 0;
  state->unk54 = 0;
  state->unk58 = 0;
  state->unk5c = -1;
  state->unk60 = -1;
  state->unk64 = -1;
  state->unk6c = -1;
  state->unk40 = 0;
}
