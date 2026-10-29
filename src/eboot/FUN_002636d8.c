/* HSTMATCH module=EBOOT.BIN start=0x002636d8 end=0x0026370c symbol=FUN_002636d8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern u8 DAT_00309a88;
extern u32 * FUN_00067498();

/* Constructor: run the base constructor, then install this class's vtable. */
VtableObj * FUN_002636d8(VtableObj *self)
{
  FUN_00067498();
  self->vtable = &DAT_00309a88;
  return self;
}
