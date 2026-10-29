/* HSTMATCH module=EBOOT.BIN start=0x00126c2c end=0x00126d1c symbol=FUN_00126c2c lang=c99 data=0x002da7d4 */
/* Ghidra pseudocode (hstgen.py tag q2) corrected by hand: the member sub-object null test restored (Ghidra folded its offset into the compared constant); readability pass; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002da7d4-0x002da7f0) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/avatar_obj.h"

extern u8 DAT_00308050;
extern u8 DAT_00308064;
extern void FUN_00000a00();
extern u32 * FUN_000918ac();
extern int FUN_000d7e30();
extern int * FUN_000e88e4();
extern void FUN_00126d1c();
extern u32 * FUN_0028686c();

/* Avatar destructor: log, clear the member containers, destroy the bases, free when `flags` > 0. */
Avatar * FUN_00126c2c(Avatar *self,short flags)
{
  void *member;
  
  if (self != (Avatar *)0x0) {
    self->vtbl = &DAT_00308050;
    self->vtbl2 = &DAT_00308064;
    FUN_00126d1c("Avatar: destructor called.\n");
    member = &self->unk414;
    if ((member != (void *)0x0) && (member != (void *)0x0)) {
      FUN_000e88e4(member,0);
    }
    member = &self->parts370;
    if (member != (void *)0x0) {
      member = self->parts370.unk84;
      if ((member != (void *)0x0) && (member != (void *)0x0)) {
        FUN_000e88e4(member,0);
      }
      member = self->parts370.unk70;
      if ((member != (void *)0x0) && (member != (void *)0x0)) {
        FUN_000e88e4(member,0);
      }
    }
    FUN_000d7e30(self->parts258,0xffffffff);
    FUN_0028686c(&self->vtbl2,0);
    FUN_000918ac(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
