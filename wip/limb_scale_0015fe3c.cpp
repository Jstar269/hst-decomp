/* HSTMATCH module=EBOOT.BIN start=0x0015fe3c end=0x00160058 symbol=FUN_0015fe3c lang=c++ */
struct Vec4 {
    float x, y, z, w;
};

extern "C" float FUN_0000c000(float);
extern "C" void FUN_00022498(Vec4 *out, const Vec4 *in, float s);
extern "C" void FUN_00022518(Vec4 *out, const Vec4 *in);
extern "C" void FUN_00022418(Vec4 *out, const Vec4 *a, const Vec4 *b);
extern const float DAT_002de878;
extern const float DAT_002de87c;

static inline float Clamp(const float &v, const float &lo, const float &hi)
{
    return v < lo ? lo : (!(v > hi) ? v : hi);
}

struct Obj {
    unsigned char pad00[0x30];
    float f30[4];
    Vec4 m40;
    float f50;
    unsigned char pad54[0x80 - 0x54];
    float f80;
};

extern "C" void FUN_0015fe3c(float angle, Obj *self)
{
    float c = Clamp(angle, DAT_002de878, DAT_002de87c);
    float sc = self->f50;
    float k = sc * FUN_0000c000((self->f80 * 0.017453292f) / 2.0f);
    Vec4 v;
    Vec4 a;
    Vec4 b;
    Vec4 n;
    Vec4 m;
    Vec4 s;
    Vec4 t;
    Vec4 u;
    Vec4 w;
    Vec4 x;
    Vec4 y;
    Vec4 z;

    k = k / FUN_0000c000((c * 0.017453292f) / 2.0f);

    v.x = -self->f30[0];
    v.y = -self->f30[1];
    v.z = -self->f30[2];
    v.w = -self->f30[3];
    FUN_00022498(&a, &v, self->f50);
    b = a;
    FUN_00022518(&n, &b);
    m.x = n.x;
    m.y = n.y;
    m.z = n.z;
    m.w = 0.0f;
    FUN_00022498(&s, &m, k);
    t = s;
    FUN_00022498(&u, (const Vec4 *)self->f30, self->f50);
    w = u;
    FUN_00022418(&x, &self->m40, &w);
    y = x;
    FUN_00022418(&z, &y, &t);
    self->m40 = z;
    self->f80 = c;
}
// NEAR 90/135 words, function #4 of batch fm4-00.
// Scalar head MATCHED: the Clamp is `v < lo ? lo : (!(v > hi) ? v : hi)` on by-CONST-REF params (that
// pair gives retail's c.lt.s + bc1f / c.ngt.s + bc1tl with the lo/hi globals loaded twice), and the ratio
// needs the limb scale in its own local read BEFORE the first call (`float sc = self->f50;`) so it lands
// in the callee-saved $f21 and is multiplied by the sin result after it: `k = sc * sin((f80*rad)/2);
// k = k / sin((c*rad)/2);`.
// WHAT DIFFERS (all in the Vec4 chain): the 12 temporary slots are permuted - retail uses
// 0x20,0x30,0x40,0x50,0x60,0x70,0x80,0x90,0xa0,0xb0,0xc0,0xd0 in creation order a,x,u,n,neg,w,s,z,b,m,t,y
// while ours hands them out in declaration order, so every lwc1/swc1 displacement of the copies is
// shifted; the ops, the copies themselves (pipelined lwc1 x4 / swc1 x4) and the helper calls with their
// argument setup are unchanged. Also the two literal setups differ by one FPR ($f2 vs $f0 for
// 0.017453292f) and the f21 load sits one slot later.
// Layout confirmed: f30 at +0x30 (Vec4), m40 at +0x40, f50 at +0x50, f80 at +0x80; frame 0xe0 = 0x20 of
// saved regs + 12 Vec4 slots. Helpers are FUN_00022498(Vec4 *out, const Vec4 *in, float scale),
// FUN_00022518(Vec4 *out, const Vec4 *in), FUN_00022418(Vec4 *out, const Vec4 *a, const Vec4 *b).
// near miss from lane fm4 (unreviewed)
