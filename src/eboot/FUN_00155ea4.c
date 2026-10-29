/* HSTMATCH module=EBOOT.BIN start=0x00155ea4 end=0x00155ed8 symbol=FUN_00155ea4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/cmd_base.h"

extern u8 DAT_00308508;
extern u32 * FUN_0014c3f8();

/* Constructor: base constructor, then this class's vtable. */
CmdBase * FUN_00155ea4(CmdBase *self)
{
  FUN_0014c3f8();
  self->vtable = &DAT_00308508;
  return self;
}
