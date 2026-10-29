/* HSTMATCH module=EBOOT.BIN start=0x0028a6a8 end=0x0028a780 symbol=FUN_0028a6a8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/effect_source.h"

struct Vec4 { float x, y, z, w; };
struct Mat4 {
    float m00, m01, m02, m03;
    float m10, m11, m12, m13;
    float m20, m21, m22, m23;
    float m30, m31, m32, m33;
    Mat4() {}
    Mat4(const Mat4 &o)
        : m00(o.m00), m01(o.m01), m02(o.m02), m03(o.m03),
          m10(o.m10), m11(o.m11), m12(o.m12), m13(o.m13),
          m20(o.m20), m21(o.m21), m22(o.m22), m23(o.m23),
          m30(o.m30), m31(o.m31), m32(o.m32), m33(o.m33) {}
};
/* Model holder seen through its matrix at +0x30. */
struct HolderMat { char pad[0x30]; Mat4 mat; };
extern "C" void FUN_00055044(void *, Mat4 *);

/* Copies the first holder's matrix, replaces its last row (the position) with v and applies it to both holders. */
extern "C" void FUN_0028a6a8(EffectSource *o, Vec4 *v) {
    HolderMat *h = (HolderMat *)o->modelA;
    Mat4 m = h->mat;
    m.m30 = v->x;
    m.m31 = v->y;
    m.m32 = v->z;
    m.m33 = v->w;
    FUN_00055044(h, &m);
    FUN_00055044(o->modelB, &m);
}
