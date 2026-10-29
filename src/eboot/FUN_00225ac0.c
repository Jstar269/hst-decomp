/* HSTMATCH module=EBOOT.BIN start=0x00225ac0 end=0x00225b00 symbol=FUN_00225ac0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_parts.h"

extern void FUN_000f6b0c();

/* Reset: clear the part at +0x30, then restore the +0x20 part's selection words. */
void FUN_00225ac0(ModeObj *self)
{
  ModeParts *parts;
  ModePart20 *part20;

  parts = self->parts;
  FUN_000f6b0c(parts->part30,0);
  part20 = parts->part20;
  part20->unk78 = -1;
  part20->unk7c = 0;
  part20->unk80 = 0;
}
