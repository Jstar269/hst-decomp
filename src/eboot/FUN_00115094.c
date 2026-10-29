/* HSTMATCH module=EBOOT.BIN start=0x00115094 end=0x001150d8 symbol=FUN_00115094 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/state_host.h"

extern void FUN_001142b0();

/* Clears the target's flag, then switches to state 5 keeping the value at 0x80. */
void FUN_00115094(StateHost *self,u32 value)
{
  self->target->unk90a = 0;
  self->unk80 = value;
  FUN_001142b0(self,5);
  self->unk80 = value;
}
