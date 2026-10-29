/* HSTMATCH module=EBOOT.BIN start=0x0021624c end=0x002162dc symbol=FUN_0021624c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256b) corrected by hand: typed float structs, field-by-field copy, early return on byte flag; readability pass; exact match verified; names and types await human review. */
#include "hst/target_obj.h"

extern float FUN_00169f08(void *a, void *b);
extern float FUN_00169f24(void *a, void *b);

/* Unless the flag is set, reset the object from the two arguments and put the target on the current position. */
void FUN_0021624c(TargetObj *self, void *arg_a, void *arg_b)
{
    if (self->flag != 0) {
        return;
    }
    self->unk10 = 0;
    self->unk20 = 0.0f;
    self->unk24 = 0.0f;
    self->unk28 = 0.0f;
    self->unk2c = 1.0f;
    self->unk30 = FUN_00169f08(arg_a, arg_b);
    self->unk34 = FUN_00169f24(arg_a, arg_b);
    self->target.x = self->pos.x;
    self->target.y = self->pos.y;
    self->target.z = self->pos.z;
}
