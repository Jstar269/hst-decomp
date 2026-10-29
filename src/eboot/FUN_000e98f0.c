/* HSTMATCH module=EBOOT.BIN start=0x000e98f0 end=0x000e9904 symbol=FUN_000e98f0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/elem_owner.h"

extern u8 DAT_002c0e30;

/* Constructor of an owner element: set the vtable pointer at +0x40. */
ElemSlot *FUN_000e98f0(ElemSlot *self)
{
  self->vtable = &DAT_002c0e30;
  return self;
}
