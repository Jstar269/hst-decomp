/* HSTMATCH module=EBOOT.BIN start=0x001b25bc end=0x001b28f0 symbol=FUN_001b25bc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: `p4 = p4 ? p4 : &G->v1d0` (a ternary keeps the null test's else-first layout and duplicated first load), Vec4 temporaries declared in frame order and copied field by field, distance test written `d2 >= r*r` (c.nge.s), inline Clamp(const float &v, const float &lo, const float &hi) { return v < lo ? lo : (v > hi ? hi : v); } with the global read directly in the arguments; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));
struct Inner {
    char pad[0x7dd];
    unsigned char f7dd;
};
struct Ctx {
    Inner *in;
};
struct Glob {
    char pad[0x1d0];
    Vec4 v1d0;
    Vec4 v1e0;
    Vec4 v1f0;
};
extern Glob *DAT_003313c4;
extern float DAT_002e9924[];
extern float DAT_002e9930[];
extern float DAT_002e993c;
extern "C" {
void FUN_00022498(Vec4 *, Vec4 *, float);
void FUN_00022434(Vec4 *, Vec4 *, Vec4 *);
void FUN_00048f08(Vec4 *, Vec4 *);
float FUN_000224d8(Vec4 *, Vec4 *);
void FUN_00022518(Vec4 *, Vec4 *);
float FUN_0000c5bc(float);
void FUN_000224f8(Vec4 *, Vec4 *, Vec4 *);
}

static inline float Clamp(const float &v, const float &lo, const float &hi) { return v < lo ? lo : (v > hi ? hi : v); }
extern "C" float FUN_001b25bc(Ctx *ctx, Vec4 *p2, int flag, Vec4 *p4)
{
    Vec4 *s1 = &DAT_003313c4->v1f0;
    Vec4 *s0 = &DAT_003313c4->v1e0;
    Vec4 v;
    Vec4 L;
    Vec4 X;
    Vec4 Y;
    Vec4 W;
    Vec4 Z;
    Vec4 t0;
    Vec4 r;
    Vec4 cr;
    Vec4 n;
    Vec4 t1;
    p4 = p4 ? p4 : &DAT_003313c4->v1d0;
    v.x = p4->x;
    v.y = p4->y;
    v.z = p4->z;
    v.w = p4->w;
    if (ctx->in->f7dd != 0) {
        unsigned i = 0;
        float *q = DAT_002e9924;
        do {
            if (v.x * v.x + v.z * v.z >= q[0] * q[0]) {
                FUN_00022498(&v, &v, DAT_002e9930[i]);
                break;
            }
            i++;
            q++;
        } while (i < 3);
        v.w = 1.0f;
    }
    FUN_00022434(&t0, p2, &v);
    W.x = t0.x;
    W.y = t0.y;
    W.z = t0.z;
    W.w = t0.w;
    FUN_00048f08(&L, &W);
    float d = FUN_000224d8(&L, s1);
    FUN_00022498(&r, s1, d);
    X.x = r.x;
    X.y = r.y;
    X.z = r.z;
    X.w = r.w;
    FUN_00022434(&t1, &L, &X);
    Z.x = t1.x;
    Z.y = t1.y;
    Z.z = t1.z;
    Z.w = t1.w;
    FUN_00022518(&n, &Z);
    L.x = n.x;
    L.y = n.y;
    L.z = n.z;
    n.w = 0.0f;
    L.w = 0.0f;
    float a = FUN_0000c5bc(FUN_000224d8(&L, s0));
    FUN_000224f8(&cr, s1, s0);
    Y.x = cr.x;
    Y.y = cr.y;
    Y.z = cr.z;
    Y.w = cr.w;
    if (FUN_000224d8(&L, &Y) < 0.0f) {
        a = -a;
    }
    a = a / 6.2831855f;
    if (flag != 0) {
        if (0.25f <= a && a < 0.75f) {
            a = 0.5f - a;
        } else if (-0.75f <= a && a < -0.25f) {
            a = -0.5f - a;
        }
        a = Clamp(a * DAT_002e993c, -DAT_002e993c * 0.25f, DAT_002e993c * 0.25f);
    }
    return a;
}
