/* HSTMATCH module=EBOOT.BIN start=0x00250f48 end=0x00250f58 symbol=FUN_00250f48 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/scroll_list_obj.h"

extern u32 DAT_002fbef4;

/* Store value in the list and in the shared global. */
void FUN_00250f48(ScrollListObj *self,u32 value)
{
  self->unk304 = value;
  DAT_002fbef4 = value;
}
