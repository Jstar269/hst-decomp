/* HSTMATCH module=hstp_trans_main.prx start=0x00176fbc end=0x00177234 symbol=FUN_00176fbc lang=c++ */
/* Clone of src/eboot/pose_lerp_0016adf8.cpp (hstclone.py tag ol23c): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#pragma inline_depth(8)
struct Vec4 {
    float x, y, z, w;
    Vec4() {}
} __attribute__((aligned(16)));
struct Mat4 {
    Vec4 r0, r1, r2, r3;
};

extern "C" {
Vec4 *FUN_00022440(Vec4 *out, const Vec4 *a, const Vec4 *b);
Vec4 *FUN_0002245c(Vec4 *out, const Vec4 *a, const Vec4 *b);
Vec4 *FUN_000224c0(Vec4 *out, const Vec4 *v, float s);
}

inline Vec4 operator+(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_00022440(&r, &a, &b);
    return r;
}
inline Vec4 operator-(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_0002245c(&r, &a, &b);
    return r;
}
inline Vec4 operator*(float s, const Vec4 &v)
{
    Vec4 r;
    FUN_000224c0(&r, &v, s);
    return r;
}

struct Pose {
    Mat4 m;
    float f50;
    Vec4 rot;
    float f70;
    float sx __attribute__((aligned(16)));
    float sy, sz;

    Vec4 GetPos() const { return m.r3; }
    Vec4 GetRot() const { return rot; }
};

struct Node {
    char pad[0x10];
    Pose pose;
};

extern "C" void FUN_0006187c(Node *n);

extern "C" void FUN_00176fbc(Node *dst, Node *from, Node *to, float t)
{
    Vec4 a, b;
    dst->pose = to->pose;
    a = from->pose.GetPos();
    b = to->pose.GetPos();
    dst->pose.m.r3 = a + t * (b - a);
    a = from->pose.GetRot();
    b = to->pose.GetRot();
    dst->pose.rot = a + t * (b - a);
    FUN_0006187c(dst);
    dst->pose.sx = from->pose.sx + t * (to->pose.sx - from->pose.sx);
}
