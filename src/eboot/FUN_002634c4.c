/* HSTMATCH module=EBOOT.BIN start=0x002634c4 end=0x00263558 symbol=FUN_002634c4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/screen_obj.h"

extern u32 DAT_003415ac;
extern u8 DAT_0034a678;
extern void FUN_00103628();
extern void FUN_00234158();
extern void FUN_002815c4();

/* Copy the part value into the panel, refresh the panel, then pass 0x40 (panel mode 1 with value 2) or 0x3f to the helper. */
void FUN_002634c4(ScreenObj *self)
{
  FUN_00103628(DAT_003415ac,1);
  self->panel->unk61c = self->part->unkdc;
  FUN_002815c4(self->panel);
  if ((self->panel->unk80 == 1) &&
     (self->panel->unk61c == 2)) {
    FUN_00234158(&DAT_0034a678,0x40);
  }
  else {
    FUN_00234158(&DAT_0034a678,0x3f);
  }
}
