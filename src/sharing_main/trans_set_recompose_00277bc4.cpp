/* HSTMATCH module=hstp_trans_main.prx start=0x00277bc4 end=0x00277c80 symbol=FUN_00277bc4 lang=c++ */
/* Clone of src/eboot/trans_set_recompose_00266c48.cpp (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef struct { float v[4]; } Vec4;
typedef struct { float m[16]; } Mat4;

extern "C" Mat4 *mat4_mul_0022570(Mat4 *dst, const Mat4 *l, const Mat4 *r);
extern "C" Mat4 *mat4_rot_y_004d2cc(Mat4 *dst, const Mat4 *src, float angle);
extern "C" Mat4 *mat4_copy_004d270(Mat4 *dst, const Mat4 *src, const float *trans);
extern "C" Mat4 *mat4_store_0055044(void *obj, const Mat4 *src);
extern "C" float FUN_001340b0(float a, float b);

class Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(void *arg);
};

struct Self {
    char pad0[0x70];
    void *obj;
    char pad1[0x130 - 0x74];
    Vec4 trans;
    Vec4 prev;
    char pad2[0x164 - 0x150];
    float angle;
    float f168;
    char pad3[4];
    Mat4 a;
    Mat4 b;
};

extern "C" void FUN_00277bc4(Self *s, const Vec4 *v)
{
    Mat4 m;

    s->prev.v[0] = s->trans.v[0];
    s->prev.v[1] = s->trans.v[1];
    s->prev.v[2] = s->trans.v[2];
    s->prev.v[3] = s->trans.v[3];
    s->trans.v[0] = v->v[0];
    s->trans.v[1] = v->v[1];
    s->trans.v[2] = v->v[2];
    s->trans.v[3] = v->v[3];

    ((Base *)s)->v7((char *)s + 0x150);

    s->angle = FUN_001340b0(s->angle, s->f168);

    mat4_mul_0022570(&m, &s->a, &s->b);
    mat4_rot_y_004d2cc(&m, &m, s->angle);
    mat4_copy_004d270(&m, &m, s->trans.v);
    mat4_store_0055044(s->obj, &m);
}
