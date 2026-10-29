/* HSTMATCH module=EBOOT.BIN start=0x0016fbf4 end=0x0016fc48 symbol=FUN_0016fbf4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/table_page.h"

extern void FUN_0016b6c8();
extern void FUN_00170c24();
extern void FUN_00170d9c();

/* Calls the page hook and two helpers on the page's handles. */
void FUN_0016fbf4(TablePage *self)
{
  self->hook(self->unkb8);
  FUN_0016b6c8(self->unkbc);
  FUN_00170c24(self,0);
  if (self->unk3e != '\0') {
    FUN_00170d9c(self);
  }
}
