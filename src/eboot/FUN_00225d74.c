/* HSTMATCH module=EBOOT.BIN start=0x00225d74 end=0x00225d98 symbol=FUN_00225d74 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_parts.h"

/* Reset the +0x20 part's words; the last two only when `full` is nonzero. */
void FUN_00225d74(ModeObj *self,int full)
{
  ModePart20 *part20;

  part20 = self->parts->part20;
  part20->unk78 = -1;
  if (full != 0) {
    part20->unk7c = 0;
    part20->unk80 = 0;
  }
}
