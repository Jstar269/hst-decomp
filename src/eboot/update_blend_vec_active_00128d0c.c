/* HSTMATCH module=EBOOT.BIN start=0x00128d0c end=0x00128d8c symbol=FUN_00128d0c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: typed Vec4 difference assignment and Vec3Pad local; readability pass; exact match verified; names and types await human review. */
#include "hst/avatar_move.h"

extern void FUN_00022434(Float4 *, const Float4 *, const Float4 *); /* a - b */
extern void FUN_00022518(Float4 *, const Float4 *); /* normalise */
extern float FUN_0000c6dc(float, float); /* heading from a horizontal direction */

/* While the reference is active, turns the direction to it into the new heading. */
void FUN_00128d0c(AvatarMove *self)
{
    Float4 diff;
    Float4 unit;
    Float4 tmp;

    if (self->active != 0) {
        FUN_00022434(&tmp, &self->ref_pos, &self->pos);
        diff = tmp;
        self->prev_angle = self->angle;
        FUN_00022518(&unit, &diff);
        unit.w = 0;
        self->angle = FUN_0000c6dc(unit.x, unit.z);
    }
}
