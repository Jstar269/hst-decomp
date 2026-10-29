/* HSTMATCH module=EBOOT.BIN start=0x00266a9c end=0x00266b1c symbol=FUN_00266a9c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: typed Vec4 difference assignment and Vec3Pad local; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mover.h"

struct Vec4 {
    float x, y, z, w;
};

struct Vec3Pad {
    float x, y, z;
    int pad;
};

extern void FUN_00022434(struct Vec4 *, const void *, const void *);
extern void FUN_00022518(struct Vec3Pad *, const void *);
extern float FUN_0000c6dc(float, float);

/* While the update flag is set: heading = atan2(x, z) of (latched vector - current vector). */
void FUN_00266a9c(Mover *self)
{
    struct Vec4 diff;
    struct Vec3Pad dir;
    struct Vec4 raw;

    if (self->unk160 != 0) {
        FUN_00022434(&raw, self->unk150, self->unk130);
        diff = raw;
        self->prevHeading = self->heading;
        FUN_00022518(&dir, &diff);
        dir.pad = 0;
        self->heading = FUN_0000c6dc(dir.x, dir.z);
    }
}
