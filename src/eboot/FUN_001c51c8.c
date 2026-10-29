/* HSTMATCH module=EBOOT.BIN start=0x001c51c8 end=0x001c51d4 symbol=FUN_001c51c8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/phase_obj.h"

/* Switches to the given phase and restarts the timer. */
void FUN_001c51c8(PhaseObj *obj,u32 state)
{
  obj->state = state;
  obj->timer = 0;
}
