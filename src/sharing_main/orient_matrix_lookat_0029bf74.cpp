/* HSTMATCH module=hstp_trans_main.prx start=0x0029bf74 end=0x0029c0e8 symbol=FUN_0029bf74 lang=c++ */
/* Clone of src/eboot/orient_matrix_lookat_0028a780.cpp (hstclone.py tag s10171846g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: lookat orient matrix computation for Obj sub-objects; exact match verified; names and types await human review. */

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

struct SubObj {
    char pad[0x30];
    Mat4 m;
};

struct Obj {
    char pad[0x74];
    SubObj *f74;
    SubObj *f78;
};

extern "C" {
void FUN_0002245c(Vec4 *out, const Vec4 *target, const Vec4 *pos);
void FUN_00048bfc(Vec4 *out, const Vec4 *in);
void FUN_00022540(Vec4 *out, const Vec4 *in);
void FUN_00022520(Vec4 *out, const Vec4 *a, const Vec4 *b);
void FUN_00055b64(SubObj *obj, const Mat4 *m);
}

extern "C" void FUN_0029bf74(Obj *self, const Vec4 *target)
{
    Mat4 m = self->f74->m;
    Vec4 dir;
    Vec4 diff_copy;
    Vec4 diff;

    FUN_0002245c(&diff, target, &m.r3);
    diff_copy = diff;
    FUN_00048bfc(&dir, &diff_copy);
    m.r2 = dir;
    FUN_00022540(&m.r1, &m.r1);
    m.r1.w = 0.0f;
    FUN_00022520(&m.r0, &m.r1, &m.r2);
    FUN_00022540(&m.r0, &m.r0);
    m.r0.w = 0.0f;
    FUN_00022520(&m.r2, &m.r0, &m.r1);
    m.r3 = m.r3;
    FUN_00055b64(self->f74, &m);
    FUN_00055b64(self->f78, &m);
}
