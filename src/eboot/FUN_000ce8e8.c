/* HSTMATCH module=EBOOT.BIN start=0x000ce8e8 end=0x000ce90c symbol=FUN_000ce8e8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030753c;
extern u8 DAT_00307550;

typedef struct FxBase {
  const void *vtable; /* 0x00 */
  int unk04;          /* 0x04 */
} FxBase;

/* Constructor: sets the base vtable, clears the field, then sets the derived vtable. */
FxBase * FUN_000ce8e8(FxBase *self)
{
  self->vtable = &DAT_0030753c;
  self->unk04 = 0;
  self->vtable = &DAT_00307550;
  return self;
}
