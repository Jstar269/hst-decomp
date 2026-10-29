/* HSTMATCH module=EBOOT.BIN start=0x0027929c end=0x002792a8 symbol=FUN_0027929c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_menu.h"

extern void FUN_0010b8cc();

/* Forwards a key to the sub object. */
void FUN_0027929c(ModeMenu *self,u32 key)
{
  FUN_0010b8cc(self->sub,key,0);
}
