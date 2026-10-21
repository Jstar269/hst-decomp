/* HSTMATCH module=EBOOT.BIN start=0x00166ec0 end=0x001672a4 symbol=FUN_00166ec0 lang=c++ */
struct Curve {
    char pad[20];
};

struct Obj {
    char pad0[0x30];
    float f30;
    float f34;
    float f38;
    char pad3c[4];
    float f40;
    float f44;
    float f48;
    float f4c;
    float f50;
    float f54;
    float f58;
    float f5c;
    float f60;
    char pad64[0x90 - 0x64];
    float f90;
    float f94;
    float f98;
    float f9c;
    int fa0;
    int fa4;
};

extern "C" {
extern float DAT_002e0400;
extern float DAT_002e0404;
extern float DAT_002e03fc;
extern float DAT_002e0408;
extern float DAT_002e040c;
extern float DAT_002e0410;
extern float DAT_002e0414;
void FUN_00168388(Curve *c);
void FUN_001683b0(Curve *c, int n);
float FUN_0016aafc(float a, float b);
void FUN_001683f0(Curve *c, float *a, float *b, float *k);
float FUN_00168430(Curve *c, float *p0, float *p1, float *k);
}

extern "C" void FUN_00166ec0(Obj *self)
{
    Curve c;
    FUN_00168388(&c);
    float v = 57.29578f * FUN_0016aafc(self->f94, self->f9c);
    float lo = FUN_0016aafc(self->f94, self->f9c - 1.7453292e-05f);
    float hi = FUN_0016aafc(self->f94, self->f9c);
    if (lo > hi) {
        float lim = self->f40 * (self->f30 * DAT_002e0400);
        if (v < lim) {
            self->f34 = self->f40;
        } else if (v < self->f60) {
            float t1;
            float t0 = self->f60 - lim;
            t1 = v - self->f40 * (self->f30 * DAT_002e0400);
            FUN_001683f0(&c, &t1, &t0, &DAT_002e0408);
            self->f34 = FUN_00168430(&c, &self->f40, &self->f50, &DAT_002e03fc);
        } else {
            self->f34 = self->f50;
        }
    } else {
        float lim = self->f44 * (self->f30 * DAT_002e0400);
        if (v < lim) {
            self->f34 = self->f44;
        } else if (v < self->f60) {
            float t1;
            float t0 = self->f60 - lim;
            t1 = v - self->f44 * (self->f30 * DAT_002e0400);
            FUN_001683f0(&c, &t1, &t0, &DAT_002e040c);
            self->f34 = FUN_00168430(&c, &self->f44, &self->f54, &DAT_002e03fc);
        } else {
            self->f34 = self->f54;
        }
    }
    v = 57.29578f * FUN_0016aafc(self->f90, self->f98);
    lo = FUN_0016aafc(self->f90, self->f98 + 1.7453292e-05f);
    hi = FUN_0016aafc(self->f90, self->f98);
    if (lo < hi) {
        float lim = self->f48 * (self->f30 * DAT_002e0404);
        if (v < lim) {
            self->f38 = self->f48;
        } else if (v < self->f60) {
            float t1;
            float t0 = self->f60 - lim;
            t1 = v - self->f48 * (self->f30 * DAT_002e0404);
            FUN_001683f0(&c, &t1, &t0, &DAT_002e0410);
            self->f38 = FUN_00168430(&c, &self->f48, &self->f58, &DAT_002e03fc);
        } else {
            self->f38 = self->f58;
        }
    } else {
        float lim = self->f4c * (self->f30 * DAT_002e0404);
        if (v < lim) {
            self->f38 = self->f4c;
        } else if (v < self->f60) {
            float t1;
            float t0 = self->f60 - lim;
            t1 = v - self->f4c * (self->f30 * DAT_002e0404);
            FUN_001683f0(&c, &t1, &t0, &DAT_002e0414);
            self->f38 = FUN_00168430(&c, &self->f4c, &self->f5c, &DAT_002e03fc);
        } else {
            self->f38 = self->f5c;
        }
    }
    if (self->fa4 == 0 && FUN_0016aafc(self->f90, self->f98) > 1.5707964f) {
        float a = FUN_0016aafc(self->f90, self->f98 + 1.7453292e-05f);
        float b = FUN_0016aafc(self->f90, self->f98);
        if (a > b)
            self->fa4 = 2;
        else
            self->fa4 = 1;
    }
    FUN_001683b0(&c, -1);
}
// NEAR MISS (lane sn2, ~12 compiles): 24 words differ, ALL in six places (3 per angle block pair x ... ) of one FPR swap: retail keeps the tuning constant (DAT_002e0400/0404) in
// $f2 and the field (f40/f44/f48/f4c) in $f3 (`lwc1 f2,DAT; lwc1 f0,48(s0); lwc1 f3,64(s0); mul.s f0,f0,f2; mul.s f1,f3,f0`), ours has them the other way round (f3 / f2).
// Everything else is exact: the ctor/dtor of the 20-byte local (0x168388 / 0x1683b0(c,-1)), the atan-like calls with +-1.7453292e-05f, `lo > hi` (variable left), the t1/t0
// locals declared t1 first (retail &t1 = sp+72, &t0 = sp+68), the final `a > b` -> 2 else 1.
// Ruled out for the swap: lim via a named product local, constant copied to a local first, the field copied to a local, multiplication operand order (normalised), lim/t0/t1 hoisted to
// function-scope declarations (53 off), constants cached in two locals at the top (213 off).
// near miss from lane sn2 (unreviewed)
