/* HSTMATCH module=EBOOT.BIN start=0x0028e02c end=0x0028e074 symbol=FUN_0028e02c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/titleinfo_menu.h"

extern u32 DAT_003415ac;
extern void FUN_00103628();
extern void FUN_00281090();

/* Clear the menu's two flags and pass the menu, the global object and the game state to their helpers. */
void FUN_0028e02c(TitleInfoHead *self)
{
  self->unk54 = 0;
  self->unk55 = 0;
  FUN_00103628(self,1);
  FUN_00103628(DAT_003415ac,1);
  FUN_00281090(self->game);
}
