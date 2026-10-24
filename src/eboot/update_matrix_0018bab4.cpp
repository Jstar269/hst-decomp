/* HSTMATCH module=EBOOT.BIN start=0x0018bab4 end=0x0018bd64 symbol=FUN_0018bab4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Mat4 {
    float m[16];
    Mat4& operator=(const Mat4 &o) {
        m[0] = o.m[0];
        m[1] = o.m[1];
        m[2] = o.m[2];
        m[3] = o.m[3];
        m[4] = o.m[4];
        m[5] = o.m[5];
        m[6] = o.m[6];
        m[7] = o.m[7];
        m[8] = o.m[8];
        m[9] = o.m[9];
        m[10] = o.m[10];
        m[11] = o.m[11];
        m[12] = o.m[12];
        m[13] = o.m[13];
        m[14] = o.m[14];
        m[15] = o.m[15];
        return *this;
    }
};

struct Target;

struct SubObj {
    char pad_00[0x30];
    Mat4 matrix;        /* 0x30 */
};

struct Target {
    virtual void func0();
    virtual void func4();
    virtual void func10(int);

    char pad_04[0x50 - 0x04];
    SubObj *f50;        /* 0x50 */
    SubObj *f54;        /* 0x54 */
    SubObj *f58;        /* 0x58 */
    SubObj *f5c;        /* 0x5c */
    SubObj *f60;        /* 0x60 */
};

struct Obj {
    char pad_00[0x3c];
    int f3c;            /* 0x3c */
    Target *target;     /* 0x40 */
    unsigned char pad_44;
    unsigned char f45;  /* 0x45 */
};

extern "C" {
extern const Mat4 DAT_002bc410;
Mat4 *mat4_rot_y_004d2cc(Mat4 *, const Mat4 *, float);
Mat4 *mat4_store_0055044(SubObj *, const Mat4 *);
void FUN_000943d0(Target *, int);
void FUN_00094424(Target *);
}

extern "C" void FUN_0018bab4(Obj *self)
{
    if (self->f45 != 0) {
        Target *t = self->target;
        SubObj *s4 = t->f58;
        Mat4 m2;
        Mat4 m1;

        m2 = s4->matrix;
        m1 = DAT_002bc410;

        SubObj *s3 = t->f50;
        SubObj *s2 = t->f54;
        SubObj *s1 = t->f5c;
        SubObj *s0 = t->f60;

        mat4_rot_y_004d2cc(&m1, &m1, 0.0f);

        if (s4 != 0) mat4_store_0055044(s4, &m1);
        if (s3 != 0) mat4_store_0055044(s3, &m1);
        if (s2 != 0) mat4_store_0055044(s2, &m1);
        if (s1 != 0) mat4_store_0055044(s1, &m1);
        if (s0 != 0) mat4_store_0055044(s0, &m1);

        FUN_000943d0(t, 5);
        t->func10(self->f3c);
        FUN_00094424(t);

        if (s4 != 0) mat4_store_0055044(s4, &m2);
        if (s3 != 0) mat4_store_0055044(s3, &m2);
        if (s2 != 0) mat4_store_0055044(s2, &m2);
        if (s1 != 0) mat4_store_0055044(s1, &m2);
        if (s0 != 0) mat4_store_0055044(s0, &m2);
    }
}
