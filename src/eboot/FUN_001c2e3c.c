/* HSTMATCH module=EBOOT.BIN start=0x001c2e3c end=0x001c2ea8 symbol=FUN_001c2e3c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: use the raw integer helper result and explicit early return; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/menu_state.h"
extern u32 DAT_003415ac;
extern void FUN_00103628();
extern int FUN_001155c0();
extern u32 FUN_001156d4();
extern void FUN_001cd88c();

/* State handler: once the dialog at DAT_003415ac has an answer, records whether it was 0 and returns to state 0. */
void FUN_001c2e3c(MenuState *self)
{
  int answered;
  answered = FUN_001155c0(DAT_003415ac);
  if (answered == 0) return;
  FUN_00103628(DAT_003415ac, 1);
  answered = FUN_001156d4(DAT_003415ac);
  self->unkb0 = answered == 0;
  FUN_001cd88c(self, 0, 1);
}
