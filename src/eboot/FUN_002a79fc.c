/* HSTMATCH module=EBOOT.BIN start=0x002a79fc end=0x002a7a08 symbol=FUN_002a79fc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_panel_obj.h"

extern void FUN_0010b8cc();

void FUN_002a79fc(ModePanel *self,u32 value)
{
  FUN_0010b8cc(self->gfx,value,0);
}
