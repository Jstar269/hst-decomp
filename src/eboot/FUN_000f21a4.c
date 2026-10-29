/* HSTMATCH module=EBOOT.BIN start=0x000f21a4 end=0x000f21f0 symbol=FUN_000f21a4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/graded_obj.h"

extern void FUN_000f21f0();
extern void FUN_0010f5d4();

/* When enabled: reset the base value, target and level, then refresh through FUN_0010f5d4 and FUN_000f21f0. */
void FUN_000f21a4(GradedObj *self)
{
  if (self->enabled != '\0') {
    self->unk78 = 0;
    self->target = 0;
    self->level = GRADE_LEVEL_SMALL;
    FUN_0010f5d4(self->unk68,self->unk78);
    FUN_000f21f0(self);
  }
}
