/* HSTMATCH module=EBOOT.BIN start=0x001c364c end=0x001c36d8 symbol=FUN_001c364c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/menu_state.h"

extern u32 DAT_003415d4;
extern void FUN_0015d46c();
extern void FUN_001905b8();
extern void FUN_001ca8f0();
extern void FUN_001cd3d8();
extern void FUN_001cd88c();

void FUN_001c364c(MenuState *self)
{
  if (self->time == 0x1e) {
    if (self->unkf8 == 1) {
      FUN_0015d46c();
    }
    else {
      FUN_001ca8f0(self->parent);
      self->unke8 = 1;
      self->unkf0 = 0;
      FUN_001905b8(DAT_003415d4,3);
      FUN_001cd88c(self,8,1);
      FUN_001cd3d8(self->parent);
    }
  }
}
