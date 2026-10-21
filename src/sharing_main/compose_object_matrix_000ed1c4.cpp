/* HSTMATCH module=hstp_trans_main.prx start=0x000ed1c4 end=0x000ed394 symbol=FUN_000ed1c4 lang=c++ */
/* Clone of src/eboot/compose_object_matrix_000e80f0.cpp (hstclone.py tag c21sn6s): addresses substituted; exact match verified; names and types await human review. */
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
extern int DAT_002cc260;
extern "C" {
void FUN_0001d5e4(Mat4 *, Vec4 *);
void FUN_0004d698(Mat4 *, int *, float);
void FUN_00022598(void *, void *, void *);
void FUN_000ed394(Obj *, Mat4 *);
}

extern "C" void FUN_000ed1c4(Obj *self)
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
        FUN_0001d5e4(&a, &v);
        a.r3.w = 1.0f;
        a.r3.x = 0.0f;
        a.r3.y = 0.0f;
        a.r3.z = 0.0f;
        FUN_0004d698(&b, &DAT_002cc260, 0.017453292f * (float)self->f314);
        FUN_00022598(&b, &a, &b);
        m = self->mat;
        m.r0.x *= self->f310;
        m.r1.y *= self->f310;
        float s = (float)((double)self->f310 + 0.2 * (double)self->f318);
        m.r2.z *= s;
        FUN_00022598(&b, &b, &m);
        FUN_000ed394(self, &b);
    }
}
