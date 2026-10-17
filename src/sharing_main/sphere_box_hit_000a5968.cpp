/* HSTMATCH module=hstp_trans_main.prx start=0x000a5968 end=0x000a5bcc symbol=FUN_000a5968 lang=c++ */
/* Clone of src/eboot/sphere_box_hit_000907fc.cpp (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
/* Sphere-vs-oriented-box test: reject when the point is farther than radius + the object's bounding radius
   from its centre; otherwise bring the point into the object's local space (inverse of the matrix at +0x30,
   scaled by 1/scale at +0x84) and compare it with the local box per axis, then run the detailed test
   (0x55b54). Vector helpers are VFPU out-pointer routines. The matrix copy is a named local made by an
   inline by-value getter with a memberwise copy constructor (unscheduled lwc1/swc1 pairs); the scale is read
   through an inline getter (that fixes the div.s register order). Names provisional. */
struct Vec4_000a5968 { float x, y, z, w; };
struct Mat4_000a5968 {
    float m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33;
    Mat4_000a5968() {}
    Mat4_000a5968(const Mat4_000a5968 &o)
        : m00(o.m00), m01(o.m01), m02(o.m02), m03(o.m03), m10(o.m10), m11(o.m11), m12(o.m12), m13(o.m13),
          m20(o.m20), m21(o.m21), m22(o.m22), m23(o.m23), m30(o.m30), m31(o.m31), m32(o.m32), m33(o.m33) {}
};
struct Box_000a5968 { Vec4_000a5968 center; Vec4_000a5968 extent; };
struct Obj_000a5968 {
    char pad[0x30];
    Mat4_000a5968 m;
    char pad2[0x84 - 0x70];
    float scale;
    float GetScale() const { return scale; }
    Mat4_000a5968 GetMatrix() const { return m; }
};
extern "C" {
void FUN_000562d0(Vec4_000a5968 *out, Obj_000a5968 *o);
float FUN_00056314(Obj_000a5968 *o);
Vec4_000a5968 *FUN_0002245c(Vec4_000a5968 *out, const Vec4_000a5968 *a, const Vec4_000a5968 *b);
float FUN_00022500(const Vec4_000a5968 *a, const Vec4_000a5968 *b);
Mat4_000a5968 FUN_0004d5e0(const Mat4_000a5968 &m);
void FUN_0005625c(Obj_000a5968 *o, Box_000a5968 *b);
Vec4_000a5968 *FUN_00022570(Vec4_000a5968 *out, const Mat4_000a5968 *m, const Vec4_000a5968 *v);
Vec4_000a5968 *FUN_000224c0(Vec4_000a5968 *out, const Vec4_000a5968 *v, float s);
bool FUN_00056700(Obj_000a5968 *o, void *a, void *b, int c, int d, int e, int f);
}
inline Vec4_000a5968 operator-(const Vec4_000a5968 &a, const Vec4_000a5968 &b)
{
    Vec4_000a5968 r;
    FUN_0002245c(&r, &a, &b);
    return r;
}
inline float LengthSq_000a5968(const Vec4_000a5968 &v) { return FUN_00022500(&v, &v); }
extern "C" bool FUN_000a5968(void *a, Obj_000a5968 *obj, void *b, const Vec4_000a5968 *point, float r)
{
    bool result = false;
    Vec4_000a5968 center;
    FUN_000562d0(&center, obj);
    float reach = r + FUN_00056314(obj);
    if (LengthSq_000a5968(center - *point) < reach * reach) {
        Mat4_000a5968 m = obj->GetMatrix();
        Mat4_000a5968 inv = FUN_0004d5e0(m);
        Box_000a5968 box;
        FUN_0005625c(obj, &box);
        float s = 1.0f / obj->GetScale();
        r = r * s;
        Vec4_000a5968 lp;
        FUN_00022570(&lp, &inv, point);
        FUN_000224c0(&lp, &lp, s);
        if (-(box.extent.x + r) <= lp.x - box.center.x && box.extent.x + r >= lp.x - box.center.x &&
            -(box.extent.y + r) <= lp.y - box.center.y && box.extent.y + r >= lp.y - box.center.y &&
            -(box.extent.z + r) <= lp.z - box.center.z && box.extent.z + r >= lp.z - box.center.z)
            result = FUN_00056700(obj, a, b, 0, 0, 0, 1);
    }
    return result;
}
