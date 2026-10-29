/* HSTMATCH module=EBOOT.BIN start=0x00098b64 end=0x00098c3c symbol=FUN_00098b64 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Vec4 { float x, y, z, w; } __attribute__((aligned(16)));
struct Mat4 { Vec4 r[4]; };

struct Self {
    char pad000[0x5bc];
    void *model;        /* 0x5bc */
    char pad5c0[0x7d0 - 0x5c0];
    Vec4 out_a;         /* 0x7d0 */
    Vec4 out_b;         /* 0x7e0 */
};

extern "C" void FUN_00091dd8(float, void *, int, int, int, int, float);
extern "C" void FUN_0009f0ec(Vec4 *, void *);
extern "C" void *FUN_00093818(void *);
extern "C" void FUN_0004d268(Mat4 *, void *);
extern "C" void FUN_00022548(Vec4 *, Mat4 *, Vec4 *);

/* Fills the two output vectors (and clears their x and z) from the model's matrix and the marker position. */
extern "C" void FUN_00098b64(Self *o) {
    Vec4 a;
    Mat4 ma;
    Vec4 b;
    Mat4 mb;

    FUN_00091dd8(11.0f, o->model, 150, 0, 151, 0, 11.0f);
    FUN_0009f0ec(&a, o);
    FUN_0004d268(&ma, FUN_00093818(o->model));
    FUN_00022548(&o->out_a, &ma, &a);
    *(int *)&o->out_a.x = 0;
    *(int *)&o->out_a.z = 0;

    FUN_00091dd8(11.0f, o->model, 136, 0, 137, 0, 11.0f);
    FUN_0009f0ec(&b, o);
    FUN_0004d268(&mb, FUN_00093818(o->model));
    FUN_00022548(&o->out_b, &mb, &b);
    *(int *)&o->out_b.x = 0;
    *(int *)&o->out_b.z = 0;
}
