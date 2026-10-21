/* HSTMATCH module=hstp_trans_main.prx start=0x00176528 end=0x00176640 symbol=FUN_00176528 lang=c++ */
/* Clone of src/eboot/FUN_0016a364.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; matching idioms: a Vec4 with a four-float constructor (arguments evaluated right to left, so t.x/t.z are re-stored from the transformed vector), a local float zero kept in a variable so MWCC does not fold x - 0.0f, and x/y/z of the result read into locals before the stores; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
    Vec4(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}
} __attribute__((aligned(16)));

struct Mat4 {
    Vec4 r[4];
};

extern Mat4 DAT_002cc260;

extern "C" {
float FUN_0000c6f4(float, float);
float FUN_00176640(const Vec4 *, const Vec4 *);
void FUN_0004d644(float, Mat4 *, const Mat4 *);
Vec4 *FUN_00022570(Vec4 *, const Mat4 *, const Vec4 *);
Vec4 *FUN_00022440(Vec4 *, const Vec4 *, const Vec4 *);
}

extern "C" void FUN_00176528(Vec4 *out, Vec4 *pos, float *ang)
{
    Vec4 t;
    Vec4 u;
    Mat4 m;
    Vec4 o;
    Vec4 r;

    float zero = 0.0f;
    float a = FUN_0000c6f4(pos->x - zero, pos->z - zero);
    o = Vec4(0.0f, 0.0f, 0.0f, 1.0f);
    t = Vec4(0.0f, 0.0f, FUN_00176640(pos, &o), 1.0f);
    FUN_0004d644(a + ang[0], &m, &DAT_002cc260);
    FUN_00022570(&t, &m, &t);
    u = Vec4(0.0f, pos->y, 0.0f, 1.0f);
    t = Vec4(t.x, 0.0f, t.z, 1.0f);
    FUN_00022440(&r, &t, &u);
    float x = r.x;
    float y = r.y;
    float z = r.z;
    out->x = x;
    out->y = y;
    out->z = z;
    out->w = 1.0f;
}
