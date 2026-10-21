/* HSTMATCH module=EBOOT.BIN start=0x000e80f0 end=0x000e82c0 symbol=FUN_000e80f0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: locals declared b, m, v, a (the translation matrix a completed by its 4th row stores); m = self->mat as an assignment (row-batched lwc1/swc1); the double expression (double)self->f310 + 0.2 * (double)self->f318 written with the field read three times (a local k keeps k in f20 across the helper calls); names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct Mat4 {
    Vec4 r0, r1, r2, r3;
};
struct Obj {
    char pad0[0x40];
    float f40;
    char pad1[0x310 - 0x44];
    float f310;
    int f314;
    int f318;
    char pad2[0x330 - 0x31c];
    float px, py, pz;
    char pad3[0x340 - 0x33c];
    Mat4 mat;
};
extern int DAT_002bc410;
extern "C" {
void FUN_0001d998(Mat4 *, Vec4 *);
void FUN_0004d320(Mat4 *, int *, float);
void FUN_00022570(void *, void *, void *);
void FUN_000e82c0(Obj *, Mat4 *);
}

extern "C" void FUN_000e80f0(Obj *self)
{
    if (self->f40 >= 0.0f) {
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
        FUN_0004d320(&b, &DAT_002bc410, 0.017453292f * (float)self->f314);
        FUN_00022570(&b, &a, &b);
        m = self->mat;
        m.r0.x *= self->f310;
        m.r1.y *= self->f310;
        float s = (float)((double)self->f310 + 0.2 * (double)self->f318);
        m.r2.z *= s;
        FUN_00022570(&b, &b, &m);
        FUN_000e82c0(self, &b);
    }
}
