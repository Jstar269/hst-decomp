/* HSTMATCH module=EBOOT.BIN start=0x00250cc4 end=0x00250cec symbol=FUN_00250cc4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/scroll_list_obj.h"

/* Returns 1 when the list's kind is 4 or 6, else 0. */
u32 FUN_00250cc4(ScrollListObj *self)
{
  u32 result;
  
  result = 1;
  if ((self->kind != 4) && (self->kind != 6)) {
    result = 0;
  }
  return result;
}
