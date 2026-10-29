/* HSTMATCH module=EBOOT.BIN start=0x002475bc end=0x00247674 symbol=FUN_002475bc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-s256a/v2) corrected by hand: Vec4 struct value copy, explicit field assignments for subsequent float stores; readability pass; exact match verified; names and types await human review. */
#include "hst/posed_obj.h"

typedef struct {
    float x, y, z, w;
} Vec4;

extern void FUN_000550c8(void *, Vec4 *);

/* Apply a position to the sub-objects (the second one unless the state is 150 or 151) and store it in both position slots. */
void FUN_002475bc(PosedObj *self, const Vec4 *pos)
{
    Vec4 local_pos = *pos;
    FUN_000550c8(self->sub_e0, &local_pos);
    if (self->state != 150 && self->state != 151) {
        FUN_000550c8(self->sub_290, &local_pos);
    }
    self->pos[0] = local_pos.x;
    self->pos[1] = local_pos.y;
    self->pos[2] = local_pos.z;
    self->pos[3] = local_pos.w;
    self->pos2[0] = self->pos[0];
    self->pos2[1] = self->pos[1];
    self->pos2[2] = self->pos[2];
    self->pos2[3] = self->pos[3];
}
