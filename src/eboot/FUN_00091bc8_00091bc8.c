/* HSTMATCH module=EBOOT.BIN start=0x00091bc8 end=0x00091c48 symbol=FUN_00091bc8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: loop form and local declaration order; readability pass; exact match verified; names and types await human review. */
#include "hst/model_set_full.h"

extern u8 DAT_002beb30;
extern void FUN_000006e8();
extern void FUN_00091af4();
extern void FUN_00092c38();
extern void FUN_00092dc8();
extern void FUN_0006e024();

/* Release the object's resources and return it to its initial state. */
void FUN_00091bc8(ModelSetFull *self)
{
  int i;
  u32 *id;
  
  FUN_00092dc8();
  i = 5;
  id = (unsigned int *)(&DAT_002beb30);
  for (; i >= 0; i--, id--) {
    FUN_00092c38(self,*id);
  }
  if (self->entries != 0) {
    FUN_000006e8(self->entries,FUN_0006e024);
    self->entries = 0;
  }
  FUN_00091af4(self);
}
