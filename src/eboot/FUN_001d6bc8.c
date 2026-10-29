/* HSTMATCH module=EBOOT.BIN start=0x001d6bc8 end=0x001d6bf0 symbol=FUN_001d6bc8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309c94;
extern u8 DAT_00309ca0;

/* Polymorphic object with two zeroed words; two vtables are installed in turn, the second stays. */
typedef struct VtableWords { const void *vtable; u32 unk04; u32 unk08; } VtableWords;

VtableWords * FUN_001d6bc8(VtableWords *self)
{
  self->vtable = &DAT_00309ca0;
  self->unk04 = 0;
  self->unk08 = 0;
  self->vtable = &DAT_00309c94;
  return self;
}
