/* HSTMATCH module=EBOOT.BIN start=0x00216208 end=0x0021624c symbol=FUN_00216208 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed struct with Point3 floats; readability pass; exact match verified; names and types await human review. */
#include "hst/target_obj.h"

/* Reset the object and put the target on the current position. */
void FUN_00216208(TargetObj *self)
{
    self->flag = 0;
    self->unk10 = -1.0f;
    self->unk20 = 0;
    self->unk24 = 0;
    self->unk28 = 0;
    self->unk2c = 1.0f;
    self->unk30 = 0;
    self->unk34 = 0;
    self->target.x = self->pos.x;
    self->target.y = self->pos.y;
    self->target.z = self->pos.z;
}
