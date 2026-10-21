/* HSTMATCH module=hstp_trans_main.prx start=0x000a54fc end=0x000a5680 symbol=FUN_000a54fc lang=c++ */
/* Clone of src/eboot/FUN_000a2d90.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (tag a1 candidate used only for the pseudocode shape); the 16-byte vector locals are declared in slot order (matrix, v, r, d), v = d is the struct copy that moves z through a GPR; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

struct Mat4 {
    float m[16];
} __attribute__((aligned(16)));

struct Params {
    char pad[0xc4];
    float f0;
    float f1;
    float f2;
};

struct Obj {
    char pad0[0x550];
    float mat[12];
    Vec4 pos;
    Vec4 vel;
};

extern Mat4 DAT_002cc260;

extern "C" {
void FUN_0004d64c(float, Mat4 *, const Mat4 *);
Vec4 *FUN_000224c0(Vec4 *, const Vec4 *, float);
Vec4 *FUN_00022440(Vec4 *, const Vec4 *, const Vec4 *);
void FUN_000a5bcc(Vec4 *, Obj *, Vec4 *, Vec4 *);
Params *FUN_000b6e80(Obj *);
}

extern "C" void FUN_000a54fc(Obj *self, float angle, float scale)
{
    Mat4 m;
    Vec4 v;
    Vec4 r;
    Vec4 d;

    FUN_0004d64c(angle, &m, &DAT_002cc260);
    self->mat[0] = m.m[0];
    self->mat[1] = m.m[1];
    self->mat[2] = m.m[2];
    self->mat[3] = m.m[3];
    self->mat[4] = m.m[4];
    self->mat[5] = m.m[5];
    self->mat[6] = m.m[6];
    self->mat[7] = m.m[7];
    self->mat[8] = m.m[8];
    self->mat[9] = m.m[9];
    self->mat[10] = m.m[10];
    self->mat[11] = m.m[11];
    FUN_000224c0(&d, (Vec4 *)&m.m[8], scale);
    v = d;
    float k;
    if (v.z > 0.0f) {
        k = FUN_000b6e80(self)->f0;
    } else {
        k = FUN_000b6e80(self)->f1;
    }
    v.z = v.z * (k * 0.01f);
    v.x = v.x * (FUN_000b6e80(self)->f2 * 0.01f);
    FUN_00022440(&self->pos, &self->pos, &v);
    FUN_000a5bcc(&r, self, &self->pos, &self->vel);
    self->pos.x = r.x;
    self->pos.y = r.y;
    self->pos.z = r.z;
    self->pos.w = r.w;
}
