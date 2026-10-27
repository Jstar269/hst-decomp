/* HSTMATCH module=hstp_trans_main.prx start=0x000ad1f4 end=0x000ad468 symbol=FUN_000ad1f4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idioms: the vector type is `#pragma pack(1)` with its y/z/w tail in a sub-struct and a memberwise copy constructor `x(o.x), t(o.t)`, which reproduces retail's lwc1/swc1 for x plus the 6-pass lb/lb/sb/sb copy of the tail; both band tests are bool inlines with a named limit local so the y load follows the scaled limit); names and types await human review. */
/* Reads a vector (FUN_0002245c), clamps x to the side-dependent bound DAT_0037acac / DAT_0037acb0, and asks
   FUN_000acd4c about it; if that passes, returns 1 when y lies in the negative band above -(0.01 * ctx->f24), or,
   with p6 == 0, when y lies above -(0.01 * ctx->f3c) and below zero but outside that first band. */
#pragma pack(1)
struct VecTail { float y, z, w; };
struct Vec4 {
    float x;
    VecTail t;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), t(o.t) {}
};
#pragma pack()

struct Ctx_000ad1f4 {
    char pad0[0x24];
    float f24;
    char pad1[0x14];
    float f3c;
};
struct Obj_000ad1f4 {
    char pad[0x150];
    int f150;
};

extern "C" {
extern const float DAT_0037acac;
extern const float DAT_0037acb0;
void FUN_0002245c(Vec4 *dst);
int FUN_000acd4c(Obj_000ad1f4 *self, Vec4 *v, int a, unsigned char side);
Ctx_000ad1f4 *FUN_000b6e80(Obj_000ad1f4 *self);
}

template <typename T>
static inline const T &max(const T &a, const T &b) { return (a < b) ? b : a; }
template <typename T>
static inline const T &min(const T &a, const T &b) { return (b < a) ? b : a; }

static inline Vec4 GetClampedInput(Obj_000ad1f4 *self, unsigned char side)
{
    Vec4 r;
    Vec4 raw;
    FUN_0002245c(&raw);
    r = raw;
    if (side == (self->f150 == 0)) {
        r.x = max(DAT_0037acac, r.x);
    } else {
        r.x = min(DAT_0037acb0, r.x);
    }
    return r;
}

static inline bool InInnerBand(Obj_000ad1f4 *self, Vec4 *v)
{
    float lim = -(FUN_000b6e80(self)->f24 * 0.01f);
    bool b;
    if (v->t.y > lim && v->t.y < 0.0f) {
        b = true;
    } else {
        b = false;
    }
    return b;
}

static inline bool InOuterBand(Obj_000ad1f4 *self, Vec4 *v)
{
    float lim = -(FUN_000b6e80(self)->f3c * 0.01f);
    if (v->t.y > lim) {
        if (!InInnerBand(self, v) && v->t.y < 0.0f) {
            return true;
        }
    }
    return false;
}

extern "C" int FUN_000ad1f4(Obj_000ad1f4 *self, int a1, int a2, unsigned char side, int p5, int p6)
{
    Vec4 v = GetClampedInput(self, side);
    if (FUN_000acd4c(self, &v, p5, side) != 0) {
        bool r = InInnerBand(self, &v) || (!p6 && InOuterBand(self, &v));
        if (r) {
            return 1;
        }
    }
    return 0;
}
