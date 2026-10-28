/* HSTMATCH module=EBOOT.BIN start=0x0025ccb4 end=0x0025ccfc symbol=FUN_0025ccb4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/adhoc_menu.h"

extern u32 DAT_003415ac;
extern void FUN_00103628();
extern void FUN_00281090();

/* Clears the two menu flags, resets the menu and the object at DAT_003415ac, and restarts the menu helper. */
void FUN_0025ccb4(AdhocMenu *self)
{
  self->unk54 = 0;
  self->unk55 = 0;
  FUN_00103628(self,1);
  FUN_00103628(DAT_003415ac,1);
  FUN_00281090(self->unk5c);
}
