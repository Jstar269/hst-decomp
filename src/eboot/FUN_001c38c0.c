/* HSTMATCH module=EBOOT.BIN start=0x001c38c0 end=0x001c38e0 symbol=FUN_001c38c0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/menu_state.h"

/* Set the flag at 0x61; turning it on also sets the flag at 0x62. */
void FUN_001c38c0(MenuState *self,u8 flag)
{
  self->unk61 = flag;
  if (self->unk61 != '\0') {
    self->unk62 = 1;
  }
}
