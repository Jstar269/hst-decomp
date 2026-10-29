/* HSTMATCH module=EBOOT.BIN start=0x000f2220 end=0x000f22ac symbol=FUN_000f2220 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed struct with unsigned char flag (lbu), range test rewritten as if (v >= 100) / else if (v >= 30) / else; readability pass; exact match verified; names and types await human review. */
#include "hst/graded_obj.h"

extern "C" int FUN_0000d530(int);
extern "C" void FUN_0010f5d4(int, int);

/* When enabled: reset unk70/unk74 and, if `value` differs from the target, take it and grade its distance from unk78 into level. */
extern "C" void FUN_000f2220(GradedObj *self, int value)
{
  if (self->enabled != 0) {
    self->unk70 = 0;
    self->unk74 = 1.0f;
    if (self->target != value) {
      self->target = value;
      int distance = FUN_0000d530(value - self->unk78);
      if (distance >= GRADE_DISTANCE_LARGE) self->level = GRADE_LEVEL_LARGE;
      else if (distance >= GRADE_DISTANCE_MEDIUM) self->level = GRADE_LEVEL_MEDIUM;
      else self->level = GRADE_LEVEL_SMALL;
      FUN_0010f5d4(self->unk68, self->unk78);
    }
  }
}
