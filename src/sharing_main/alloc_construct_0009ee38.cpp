/* HSTMATCH module=hstp_trans_main.prx start=0x0009ee38 end=0x0009eed0 symbol=FUN_0009ee38 lang=c++ */
/* Clone of src/eboot/alloc_construct_0009c90c.cpp (hstclone.py tag c41): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* allocator::construct(p, x) for the 80-byte element of the vec_push_0009c864 vector: placement new (null
   check on p) of a copy; the element is a matrix with a memberwise copy constructor (unscheduled lwc1/swc1
   pairs) plus an int, copied through the implicit copy constructor, which needs inline_depth to inline the
   matrix copy. The allocator (a0) is unused. Names provisional. */
#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }
struct Mat4_0009ee38 {
    float m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33;
    Mat4_0009ee38() {}
    Mat4_0009ee38(const Mat4_0009ee38 &o)
        : m00(o.m00), m01(o.m01), m02(o.m02), m03(o.m03), m10(o.m10), m11(o.m11), m12(o.m12), m13(o.m13),
          m20(o.m20), m21(o.m21), m22(o.m22), m23(o.m23), m30(o.m30), m31(o.m31), m32(o.m32), m33(o.m33) {}
};
struct Elem_0009ee38 { Mat4_0009ee38 m; int id; };
struct Alloc_0009ee38 {};
extern "C" void FUN_0009ee38(Alloc_0009ee38 *a, Elem_0009ee38 *p, const Elem_0009ee38 &x)
{
    new (p) Elem_0009ee38(x);
}
