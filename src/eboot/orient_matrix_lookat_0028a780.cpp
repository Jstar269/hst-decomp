/* HSTMATCH module=EBOOT.BIN start=0x0028a780 end=0x0028a8f4 symbol=FUN_0028a780 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: lookat orient matrix computation for the effect source's model holders; exact match verified; names and types await human review. */

#include "hst/effect_source.h"

struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
};

struct Mat4 {
    Vec4 r0, r1, r2, r3;
    Mat4() {}
    Mat4(const Mat4 &o) : r0(o.r0), r1(o.r1), r2(o.r2), r3(o.r3) {}
};

/* Model holder seen through its matrix at +0x30. */
struct HolderMat {
    char pad[0x30];
    Mat4 m;
};

extern "C" {
void FUN_00022434(Vec4 *out, const Vec4 *target, const Vec4 *pos);
void FUN_00048f08(Vec4 *out, const Vec4 *in);
void FUN_00022518(Vec4 *out, const Vec4 *in);
void FUN_000224f8(Vec4 *out, const Vec4 *a, const Vec4 *b);
void FUN_00055044(ModelHolder *obj, const Mat4 *m);
}

/* Re-orients the holders' matrix so its third row looks from its position towards the target. */
extern "C" void FUN_0028a780(EffectSource *self, const Vec4 *target)
{
    Mat4 m = ((HolderMat *)self->modelA)->m;
    Vec4 dir;
    Vec4 diff_copy;
    Vec4 diff;

    FUN_00022434(&diff, target, &m.r3);
    diff_copy = diff;
    FUN_00048f08(&dir, &diff_copy);
    m.r2 = dir;
    FUN_00022518(&m.r1, &m.r1);
    m.r1.w = 0.0f;
    FUN_000224f8(&m.r0, &m.r1, &m.r2);
    FUN_00022518(&m.r0, &m.r0);
    m.r0.w = 0.0f;
    FUN_000224f8(&m.r2, &m.r0, &m.r1);
    m.r3 = m.r3;
    FUN_00055044(self->modelA, &m);
    FUN_00055044(self->modelB, &m);
}
