/* HSTMATCH module=EBOOT.BIN start=0x001c35ec end=0x001c364c symbol=FUN_001c35ec lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed FUN_00226128 as int instead of a byte result; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/menu_state.h"

extern u32 DAT_0034a2e0;
extern void FUN_001cd88c();
extern void FUN_002260e0();
extern u32 FUN_00226118();
extern int FUN_00226128();

void FUN_001c35ec(MenuState *self)
{
  int ready;
  u32 value;
  
  ready = FUN_00226128(DAT_0034a2e0);
  if (ready != 0) {
    value = FUN_00226118(DAT_0034a2e0);
    self->unkf4 = value;
    FUN_002260e0(DAT_0034a2e0);
    FUN_001cd88c(self,0,1);
  }
}
