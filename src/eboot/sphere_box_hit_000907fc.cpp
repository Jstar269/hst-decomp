/* HSTMATCH module=EBOOT.BIN start=0x000907fc end=0x00090a60 symbol=FUN_000907fc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* Sphere-vs-oriented-box test: reject when the point is farther than radius + the object's bounding radius
   from its centre; otherwise bring the point into the object's local space (inverse of the matrix at +0x30,
   scaled by 1/scale at +0x84) and compare it with the local box per axis, then run the detailed test
   (0x55b54). Vector helpers are VFPU out-pointer routines. The matrix copy is a named local made by an
   inline by-value getter with a memberwise copy constructor (unscheduled lwc1/swc1 pairs); the scale is read
   through an inline getter (that fixes the div.s register order). Names provisional. */
struct Vec4 { float x, y, z, w; };
struct Mat4 {
    float m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33;
    Mat4() {}
    Mat4(const Mat4 &o)
        : m00(o.m00), m01(o.m01), m02(o.m02), m03(o.m03), m10(o.m10), m11(o.m11), m12(o.m12), m13(o.m13),
          m20(o.m20), m21(o.m21), m22(o.m22), m23(o.m23), m30(o.m30), m31(o.m31), m32(o.m32), m33(o.m33) {}
};
struct Box { Vec4 center; Vec4 extent; };
struct Obj {
    char pad[0x30];
    Mat4 m;
    char pad2[0x84 - 0x70];
    float scale;
    float GetScale() const { return scale; }
    Mat4 GetMatrix() const { return m; }
};
extern "C" {
void FUN_00055724(Vec4 *out, Obj *o);
float FUN_00055768(Obj *o);
Vec4 *FUN_00022434(Vec4 *out, const Vec4 *a, const Vec4 *b);
float FUN_000224d8(const Vec4 *a, const Vec4 *b);
Mat4 FUN_0004d268(const Mat4 &m);
void FUN_000556b0(Obj *o, Box *b);
Vec4 *FUN_00022548(Vec4 *out, const Mat4 *m, const Vec4 *v);
Vec4 *FUN_00022498(Vec4 *out, const Vec4 *v, float s);
bool FUN_00055b54(Obj *o, void *a, void *b, int c, int d, int e, int f);
}
inline Vec4 operator-(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_00022434(&r, &a, &b);
    return r;
}
inline float LengthSq(const Vec4 &v) { return FUN_000224d8(&v, &v); }
extern "C" bool FUN_000907fc(void *a, Obj *obj, void *b, const Vec4 *point, float r)
{
    bool result = false;
    Vec4 center;
    FUN_00055724(&center, obj);
    float reach = r + FUN_00055768(obj);
    if (LengthSq(center - *point) < reach * reach) {
        Mat4 m = obj->GetMatrix();
        Mat4 inv = FUN_0004d268(m);
        Box box;
        FUN_000556b0(obj, &box);
        float s = 1.0f / obj->GetScale();
        r = r * s;
        Vec4 lp;
        FUN_00022548(&lp, &inv, point);
        FUN_00022498(&lp, &lp, s);
        if (-(box.extent.x + r) <= lp.x - box.center.x && box.extent.x + r >= lp.x - box.center.x &&
            -(box.extent.y + r) <= lp.y - box.center.y && box.extent.y + r >= lp.y - box.center.y &&
            -(box.extent.z + r) <= lp.z - box.center.z && box.extent.z + r >= lp.z - box.center.z)
            result = FUN_00055b54(obj, a, b, 0, 0, 0, 1);
    }
    return result;
}
