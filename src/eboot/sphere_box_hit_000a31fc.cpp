/* HSTMATCH module=EBOOT.BIN start=0x000a31fc end=0x000a3460 symbol=FUN_000a31fc lang=c++ */
/* Clone of src/eboot/sphere_box_hit_000907fc.cpp (hstclone.py tag c29): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* Sphere-vs-oriented-box test: reject when the point is farther than radius + the object's bounding radius
   from its centre; otherwise bring the point into the object's local space (inverse of the matrix at +0x30,
   scaled by 1/scale at +0x84) and compare it with the local box per axis, then run the detailed test
   (0x55b54). Vector helpers are VFPU out-pointer routines. The matrix copy is a named local made by an
   inline by-value getter with a memberwise copy constructor (unscheduled lwc1/swc1 pairs); the scale is read
   through an inline getter (that fixes the div.s register order). Names provisional. */
struct Vec4_000a31fc { float x, y, z, w; };
struct Mat4_000a31fc {
    float m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33;
    Mat4_000a31fc() {}
    Mat4_000a31fc(const Mat4_000a31fc &o)
        : m00(o.m00), m01(o.m01), m02(o.m02), m03(o.m03), m10(o.m10), m11(o.m11), m12(o.m12), m13(o.m13),
          m20(o.m20), m21(o.m21), m22(o.m22), m23(o.m23), m30(o.m30), m31(o.m31), m32(o.m32), m33(o.m33) {}
};
struct Box_000a31fc { Vec4_000a31fc center; Vec4_000a31fc extent; };
struct Obj_000a31fc {
    char pad[0x30];
    Mat4_000a31fc m;
    char pad2[0x84 - 0x70];
    float scale;
    float GetScale() const { return scale; }
    Mat4_000a31fc GetMatrix() const { return m; }
};
extern "C" {
void FUN_00055724(Vec4_000a31fc *out, Obj_000a31fc *o);
float FUN_00055768(Obj_000a31fc *o);
Vec4_000a31fc *FUN_00022434(Vec4_000a31fc *out, const Vec4_000a31fc *a, const Vec4_000a31fc *b);
float FUN_000224d8(const Vec4_000a31fc *a, const Vec4_000a31fc *b);
Mat4_000a31fc FUN_0004d268(const Mat4_000a31fc &m);
void FUN_000556b0(Obj_000a31fc *o, Box_000a31fc *b);
Vec4_000a31fc *FUN_00022548(Vec4_000a31fc *out, const Mat4_000a31fc *m, const Vec4_000a31fc *v);
Vec4_000a31fc *FUN_00022498(Vec4_000a31fc *out, const Vec4_000a31fc *v, float s);
bool FUN_00055b54(Obj_000a31fc *o, void *a, void *b, int c, int d, int e, int f);
}
inline Vec4_000a31fc operator-(const Vec4_000a31fc &a, const Vec4_000a31fc &b)
{
    Vec4_000a31fc r;
    FUN_00022434(&r, &a, &b);
    return r;
}
inline float LengthSq_000a31fc(const Vec4_000a31fc &v) { return FUN_000224d8(&v, &v); }
extern "C" bool FUN_000a31fc(void *a, Obj_000a31fc *obj, void *b, const Vec4_000a31fc *point, float r)
{
    bool result = false;
    Vec4_000a31fc center;
    FUN_00055724(&center, obj);
    float reach = r + FUN_00055768(obj);
    if (LengthSq_000a31fc(center - *point) < reach * reach) {
        Mat4_000a31fc m = obj->GetMatrix();
        Mat4_000a31fc inv = FUN_0004d268(m);
        Box_000a31fc box;
        FUN_000556b0(obj, &box);
        float s = 1.0f / obj->GetScale();
        r = r * s;
        Vec4_000a31fc lp;
        FUN_00022548(&lp, &inv, point);
        FUN_00022498(&lp, &lp, s);
        if (-(box.extent.x + r) <= lp.x - box.center.x && box.extent.x + r >= lp.x - box.center.x &&
            -(box.extent.y + r) <= lp.y - box.center.y && box.extent.y + r >= lp.y - box.center.y &&
            -(box.extent.z + r) <= lp.z - box.center.z && box.extent.z + r >= lp.z - box.center.z)
            result = FUN_00055b54(obj, a, b, 0, 0, 0, 1);
    }
    return result;
}
