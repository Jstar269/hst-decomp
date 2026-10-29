/* HSTMATCH module=EBOOT.BIN start=0x0016adf8 end=0x0016b070 symbol=FUN_0016adf8 lang=c++ */
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
Vec4 *FUN_00022418(Vec4 *out, const Vec4 *a, const Vec4 *b);
Vec4 *FUN_00022434(Vec4 *out, const Vec4 *a, const Vec4 *b);
Vec4 *FUN_00022498(Vec4 *out, const Vec4 *v, float s);
}

inline Vec4 operator+(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_00022418(&r, &a, &b);
    return r;
}
inline Vec4 operator-(const Vec4 &a, const Vec4 &b)
{
    Vec4 r;
    FUN_00022434(&r, &a, &b);
    return r;
}
inline Vec4 operator*(float s, const Vec4 &v)
{
    Vec4 r;
    FUN_00022498(&r, &v, s);
    return r;
}

struct Pose {
    Mat4 m;
    float unk40;       /* 0x40 */
    Vec4 rot;
    float unk60;       /* 0x60 */
    float sx __attribute__((aligned(16)));
    float sy, sz;

    Vec4 GetPos() const { return m.r3; }
    Vec4 GetRot() const { return rot; }
};

struct Node {
    char pad[0x10];
    Pose pose;
};

extern "C" void FUN_000609f8(Node *n);

/* Copies the pose of `to` into dst, then blends position, rot and sx from `from` towards `to` by t. */
extern "C" void FUN_0016adf8(Node *dst, Node *from, Node *to, float t)
{
    Vec4 a, b;
    dst->pose = to->pose;
    a = from->pose.GetPos();
    b = to->pose.GetPos();
    dst->pose.m.r3 = a + t * (b - a);
    a = from->pose.GetRot();
    b = to->pose.GetRot();
    dst->pose.rot = a + t * (b - a);
    FUN_000609f8(dst);
    dst->pose.sx = from->pose.sx + t * (to->pose.sx - from->pose.sx);
}
