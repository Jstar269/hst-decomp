/* HSTMATCH module=EBOOT.BIN start=0x001cc7d0 end=0x001cc830 symbol=FUN_001cc7d0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/name_box_owner.h"

extern u32 * FUN_000149a8();
extern int FUN_00014a40();
extern void FUN_0018aa04();

/* Sets the second name buffer when `name` fits and tells the panel's widget. */
void FUN_001cc7d0(NameBoxOwner *self,u32 name)
{
  u32 length;
  PanelData *panel;
  
  length = FUN_00014a40(name);
  if (length < NAME_BOX_NAME_LIMIT) {
    FUN_000149a8(self->nameB,name);
    panel = self->panel;
    FUN_0018aa04(panel->unk20);
    panel->unk64 = 1;
  }
}
