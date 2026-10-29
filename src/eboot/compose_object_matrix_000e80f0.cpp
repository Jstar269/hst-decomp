/* HSTMATCH module=EBOOT.BIN start=0x000e80f0 end=0x000e82c0 symbol=FUN_000e80f0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: locals declared b, m, v, a (the translation matrix a completed by its 4th row stores); m = self->mat as an assignment (row-batched lwc1/swc1); the double expression (double)self->scale + 0.2 * (double)self->ticks written with the field read three times (a local k keeps k in f20 across the helper calls); names and types await human review. */
#include "hst/spin_obj.h"

typedef SpinVec4 Vec4;
typedef SpinMat4 Mat4;
extern int DAT_002bc410;
extern "C" {
void FUN_0001d998(Mat4 *, Vec4 *);
void FUN_0004d320(Mat4 *, int *, float);
void FUN_00022570(void *, void *, void *);
void FUN_000e82c0(SpinObj *, Mat4 *);
}

/* Builds the object's world matrix: rotation by its angle times a translation to its position, with the stored matrix scaled. */
extern "C" void FUN_000e80f0(SpinObj *self)
{
    if (self->timer >= 0.0f) {
        Mat4 b;
        Mat4 m;
        Vec4 v;
        Mat4 a;
        v.x = self->px;
        v.y = self->py;
        v.z = self->pz;
        v.w = 1.0f;
        FUN_0001d998(&a, &v);
        a.r3.w = 1.0f;
        a.r3.x = 0.0f;
        a.r3.y = 0.0f;
        a.r3.z = 0.0f;
        FUN_0004d320(&b, &DAT_002bc410, 0.017453292f * (float)self->angle);
        FUN_00022570(&b, &a, &b);
        m = self->mat;
        m.r0.x *= self->scale;
        m.r1.y *= self->scale;
        float s = (float)((double)self->scale + 0.2 * (double)self->ticks);
        m.r2.z *= s;
        FUN_00022570(&b, &b, &m);
        FUN_000e82c0(self, &b);
    }
}
