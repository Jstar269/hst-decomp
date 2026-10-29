/* HSTMATCH module=EBOOT.BIN start=0x002038ec end=0x00203ba8 symbol=FUN_002038ec lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idioms: the global camera pointer is read twice (the Cam* local is dead before the first call, so the C copy reloads DAT_003313c4), the Vec4 temporaries are named locals declared B, C, D, E (retail slots 80/64/48/32) with helper results written straight into the members, `len <= 0.0f` -> `len = 1.0f`, both thresholds are `if (!(t < 0.01f))` (c.lt.s/bc1t; `t >= 0.01f` gives c.nge), `float sc = 192.0f * t` keeps the product in a fresh register, and the double expression `0.15f + 0.85f * ((double)unk10 / 1.5707963267948966)` compiles to the libm soft-float calls; names and types await human review. */
#include "hst/look_obj.h"

typedef LookVec4 Vec4;

struct Cam {
    char pad0[0x1d0];
    Vec4 v1d0;              /* 0x1d0 */
    Vec4 v1e0;              /* 0x1e0 */
};

extern "C" {
extern Cam *DAT_003313c4;
float FUN_0000c6dc(float y, float x);
float FUN_0000bc34(float x);
float FUN_0000bf34(float x);
void FUN_00022498(Vec4 *out, const Vec4 *v, float s);
void FUN_00022418(Vec4 *out, const Vec4 *a, const Vec4 *b);
void FUN_00022434(Vec4 *out, const Vec4 *a, const Vec4 *b);
void FUN_00022450(Vec4 *out, const Vec4 *a, const Vec4 *b);
float FUN_000224d8(const Vec4 *a, const Vec4 *b);
void FUN_00203dcc(LookObj *self, int a, int b);
float sqrtf(float);
}

/* Looks along the camera's direction: builds the viewing offset from the camera vectors and, when the resulting
   ratio is above the thresholds, activates the overlay and sets its two capped levels, then draws it twice. */
extern "C" void FUN_002038ec(LookObj *self)
{
    self->active = 0;
    Cam *c = DAT_003313c4;
    float x = c->v1e0.x;
    float z = c->v1e0.z;
    float y = c->v1e0.y;
    float yaw = FUN_0000c6dc(x, z);
    float pitch = FUN_0000c6dc(-y, sqrtf(x * x + z * z));
    float sin_pitch = FUN_0000bc34(-pitch);
    float quarter_minus_yaw = 1.5707964f - yaw;
    float sin_h = FUN_0000bc34(quarter_minus_yaw);
    float cos_h = FUN_0000bf34(quarter_minus_yaw);
    Vec4 B;
    B.x = sin_h * sin_pitch;
    B.y = FUN_0000bf34(-pitch);
    B.z = cos_h * sin_pitch;
    Vec4 C = DAT_003313c4->v1d0;
    Vec4 D;
    Vec4 E;
    FUN_00022498(&D, &self->unk00, self->unke0);
    FUN_00022418(&self->unk500, &C, &D);
    FUN_00022498(&E, &B, self->unkdc);
    FUN_00022418(&E, &E, &C);
    FUN_00022434(&self->unk4f0, &E, &self->unk500);
    FUN_00022498(&E, &self->unk4f0, -1.0f);
    float dot = FUN_000224d8(&E, &B);
    FUN_00022450(&E, &self->unk4f0, &self->unk4f0);
    float len = sqrtf(E.z + (E.x + E.y));
    if (len <= 0.0f)
        len = 1.0f;
    float t = dot / len;
    self->unk510 = t;
    if (!(t < 0.01f)) {
        t = t - self->unkf4;
        if (!(t < 0.01f)) {
            self->active = 1;
            self->unk514 = 0.15f + 0.85f * ((double)self->unk10 / 1.5707963267948966);
            float sc = 192.0f * t;
            int n = (int)sc;
            self->unk518 = n;
            if (n > 128)
                self->unk518 = 128;
            int m = (int)(sc * self->unk514);
            self->unk51c = m;
            if (m > 128)
                self->unk51c = 128;
            FUN_00203dcc(self, self->unk18, 1);
            FUN_00203dcc(self, self->unk18, 0);
        }
    }
}
