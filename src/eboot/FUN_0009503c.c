/* HSTMATCH module=EBOOT.BIN start=0x0009503c end=0x00095058 symbol=FUN_0009503c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/keyed_state.h"

/* Reset the keyed state record to its initial values. */
void FUN_0009503c(KeyedState *self)
{
  self->mode = KEYED_MODE_INITIAL;
  self->key = KEYED_KEY_NONE;
  self->frame = 0;
  self->flag = 0;
}
