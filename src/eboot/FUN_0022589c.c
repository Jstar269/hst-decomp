/* HSTMATCH module=EBOOT.BIN start=0x0022589c end=0x002258f8 symbol=FUN_0022589c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: merged allocation and constructor store pattern for sub-object; readability pass; exact match verified; names and types await human review. */
#include "hst/mode_parts.h"

extern void *DAT_00309608;
extern void *DAT_0034a2e0;
extern void *FUN_00000bcc(unsigned int);
extern void *FUN_0001f06c(void *);
extern ModeParts *FUN_00225090(ModeParts *);

/* Constructor: base constructor, vtable, global instance pointer, then build the part set. */
ModeObj *FUN_0022589c(ModeObj *self)
{
  ModeParts *parts;

  FUN_0001f06c(self);
  self->vtbl = &DAT_00309608;
  self->parts = 0;
  DAT_0034a2e0 = self;
  parts = FUN_00000bcc(sizeof(ModeParts));
  if (parts != 0) parts = FUN_00225090(parts);
  self->parts = parts;
  return self;
}
