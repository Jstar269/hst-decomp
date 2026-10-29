/* HSTMATCH module=EBOOT.BIN start=0x0021e4cc end=0x0021e520 symbol=FUN_0021e4cc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/digit_panel.h"

extern int FUN_002af920();

/* Store `flag` in unk1e4, set unk208, and clear unk208 again when `check` is set and unk200 >= the count FUN_002af920 reports for unk170. */
void FUN_0021e4cc(DigitPanel *self,u8 flag,int check)
{
  int limit;
  int index;
  
  self->unk1e4 = flag;
  self->unk208 = 1;
  if ((check != 0) &&
     (index = self->unk200, limit = FUN_002af920(self->unk170),
     index >= limit)) {
    self->unk208 = 0;
  }
}
