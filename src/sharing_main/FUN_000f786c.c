/* HSTMATCH module=hstp_trans_main.prx start=0x000f786c end=0x000f78b8 symbol=FUN_000f786c lang=c99 */
/* Clone of src/eboot/FUN_000f21a4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/graded_obj.h"

extern void FUN_000f78b8();
extern void FUN_00116fd4();

/* When enabled: reset the base value, target and level, then refresh through FUN_00116fd4 and FUN_000f78b8. */
void FUN_000f786c(GradedObj *self)
{
  if (self->enabled != '\0') {
    self->unk78 = 0;
    self->target = 0;
    self->level = GRADE_LEVEL_SMALL;
    FUN_00116fd4(self->unk68,self->unk78);
    FUN_000f78b8(self);
  }
}
