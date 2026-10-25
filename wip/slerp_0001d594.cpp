/* HSTMATCH module=EBOOT.BIN start=0x0001d594 end=0x0001d7cc symbol=FUN_0001d594 lang=c++ */
struct Vec4 { float x, y, z, w; void Neg() { x = -x; y = -y; z = -z; w = -w; } };

extern "C" float FUN_0000c5bc(float);
extern "C" float FUN_0000bf34(float);
extern "C" Vec4 FUN_00022498(float, const Vec4 &);
extern "C" Vec4 FUN_00022418(Vec4, Vec4);

extern "C" void FUN_0001d594(float t, Vec4 *out, const Vec4 *a, const Vec4 *b)
{
    Vec4 q1 = *a;
    float d;
    float ad;
    float ang;
    float s;
    float k1;
    float k2;

    d = q1.x * b->x + q1.y * b->y + q1.z * b->z + q1.w * b->w;
    if (d < 0.0f) {
        q1.Neg();
        d = -d;
    }
    ad = d < 0.0f ? -d : d;
    if (ad >= 1.0f) {
        *out = *b;
        return;
    }
    ang = FUN_0000c5bc(d);
    s = FUN_0000bf34(ang);
    if (s == 0.0f) {
        *out = *b;
        return;
    }
    k1 = FUN_0000bf34(ang * (1.0f - t)) / s;
    k2 = FUN_0000bf34(ang * t) / s;
    {
        Vec4 v1 = FUN_00022498(k2, *b);
        Vec4 v2 = FUN_00022498(k1, q1);
        *out = FUN_00022418(v2, v1);
    }
}
// 0x0001d594: 138/142 words, 112 differ. Quaternion slerp; structure fully recovered:
//   q1 = *a; d = dot(q1,*b); if (d<0) {q1 = -q1; d = -d;} ad = d<0?-d:d;
//   if (ad >= 1.0f) {*out = *b; return;} ang = acosf(d); s = sin(ang); if (s==0) {*out=*b;return;}
//   k1 = sin(ang*(1-t))/s; k2 = sin(ang*t)/s;
//   Vec4 v1 = Scale(k2,*b); Vec4 v2 = Scale(k1,q1); *out = Add(v2,v1);
// Helper shapes proved: FUN_00022498 is `Vec4 f(float,const Vec4&)` (sret a0, ref a1),
// FUN_00022418 is `Vec4 f(Vec4,Vec4)` by value (a0 sret, a1/a2 = caller copies) -- the two
// 16-byte copies right after each Scale are its by-value arg copies.
// Remainder: FPR colouring. Retail keeps d in $f12 and reuses $f2/$f6/$f4/$f2 for the dot
// product, ours holds the pre-store values live ($f8/$f6/$f4/$f2) and negates them from
// registers where retail re-loads all four fields from the stack. Tried: field negations,
// member Neg() (identical), inline ratios, ternary abs (kept: removed the abs.s intrinsic).
// near miss from lane fm11 (unreviewed)
