/* HSTMATCH module=hstp_trans_main.prx start=0x001220cc end=0x001220f8 symbol=FUN_001220cc lang=c99 */
/* Clone of src/eboot/FUN_00117128.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/wheel_state.h"

/* Resets the state's fields to their initial values (indices -1, counters 0). */
void FUN_001220cc(WheelState *state)
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
