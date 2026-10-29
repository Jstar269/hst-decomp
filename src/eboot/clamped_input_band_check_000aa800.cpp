/* HSTMATCH module=EBOOT.BIN start=0x000aa800 end=0x000aaa74 symbol=FUN_000aa800 lang=c++ */
/* Hand-written reconstruction from the disassembly (EBOOT twin of src/sharing_main/clamped_input_band_check_000ad1f4.cpp, identical masked code: addresses substituted); exact match verified (matching idioms: the vector type is `#pragma pack(1)` with its y/z/w tail in a sub-struct and a memberwise copy constructor `x(o.x), t(o.t)`, which reproduces retail's lwc1/swc1 for x plus the 6-pass lb/lb/sb/sb copy of the tail; both band tests are bool inlines with a named limit local so the y load follows the scaled limit); names and types await human review. */
/* Reads a vector (FUN_00022434), clamps x to the side-dependent bound DAT_002d46a4 / DAT_002d46a8, and asks
   FUN_000aa358 about it; if that passes, returns 1 when y lies in the negative band above -(0.01 * ctx->unk24), or,
   with p6 == 0, when y lies above -(0.01 * ctx->unk3c) and below zero but outside that first band. */
#pragma pack(1)
struct VecTail { float y, z, w; };
struct Vec4 {
    float x;
    VecTail t;
    Vec4() {}
    Vec4(const Vec4 &o) : x(o.x), t(o.t) {}
};
#pragma pack()

struct Limits {
    char pad0[0x24];
    float unk24;
    char pad1[0x14];
    float unk3c;
};
struct Unit {
    char pad[0x150];
    int unk150;
};

extern "C" {
extern const float DAT_002d46a4;
extern const float DAT_002d46a8;
void FUN_00022434(Vec4 *dst);
int FUN_000aa358(Unit *self, Vec4 *v, int a, unsigned char side);
Limits *FUN_000b3c68(Unit *self);
}

template <typename T>
static inline const T &max(const T &a, const T &b) { return (a < b) ? b : a; }
template <typename T>
static inline const T &min(const T &a, const T &b) { return (b < a) ? b : a; }

static inline Vec4 GetClampedInput(Unit *self, unsigned char side)
{
    Vec4 r;
    Vec4 raw;
    FUN_00022434(&raw);
    r = raw;
    if (side == (self->unk150 == 0)) {
        r.x = max(DAT_002d46a4, r.x);
    } else {
        r.x = min(DAT_002d46a8, r.x);
    }
    return r;
}

static inline bool InInnerBand(Unit *self, Vec4 *v)
{
    float lim = -(FUN_000b3c68(self)->unk24 * 0.01f);
    bool b;
    if (v->t.y > lim && v->t.y < 0.0f) {
        b = true;
    } else {
        b = false;
    }
    return b;
}

static inline bool InOuterBand(Unit *self, Vec4 *v)
{
    float lim = -(FUN_000b3c68(self)->unk3c * 0.01f);
    if (v->t.y > lim) {
        if (!InInnerBand(self, v) && v->t.y < 0.0f) {
            return true;
        }
    }
    return false;
}

extern "C" int FUN_000aa800(Unit *self, int a1, int a2, unsigned char side, int p5, int p6)
{
    Vec4 v = GetClampedInput(self, side);
    if (FUN_000aa358(self, &v, p5, side) != 0) {
        bool r = InInnerBand(self, &v) || (!p6 && InOuterBand(self, &v));
        if (r) {
            return 1;
        }
    }
    return 0;
}
