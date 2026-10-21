/* HSTMATCH module=EBOOT.BIN start=0x000a938c end=0x000a975c symbol=FUN_000a938c lang=c++ */
/* Hand-written reconstruction from the disassembly (first half is the clamp/limit code of src/sharing_main/check_motion_limits_000ac53c.cpp); NEAR MISS, not exact: 238 of 244 words with 22 aligned words differing; names and types await human review. */
extern "C" {
extern const float DAT_002d46a4;
extern const float DAT_002d46a8;
extern const float DAT_002d46ac;
extern float DAT_0034129c;
extern float DAT_00341294;
extern int DAT_00341284;
extern int DAT_00341288;
extern char DAT_00341120[];
extern void FUN_00022434(void *dst);
extern float FUN_001621c0(void *, int);
extern float FUN_00164474(void *, int);
extern float FUN_0016442c(void *, int);
extern float fabsf(float);
}

template <typename T>
static inline const T &max(const T &a, const T &b) {
    return (a < b) ? b : a;
}

template <typename T>
static inline const T &min(const T &a, const T &b) {
    return (b < a) ? b : a;
}

struct Vec4 {
    float x, y, z, w;
};

struct Ctx {
    char pad0[0x24];
    float f24;
    char pad28[4];
    float f2c;
    char pad30[0x184 - 0x30];
    float f184;
};

struct Obj {
    char pad[0x150];
    int f150;
    char pad154[0x440 - 0x154];
    int f440;
};

extern "C" Ctx *FUN_000b3c68(Obj *);

static inline bool check_range(float y, float lim)
{
    if (y > lim && y < 0.0f) return true;
    return false;
}

extern "C" int FUN_000a938c(Obj *self, int a, int b, unsigned char flag)
{
    Vec4 local_10;
    Vec4 local_20;
    FUN_00022434(&local_20);
    local_10 = local_20;
    if (flag == (self->f150 == 0)) {
        local_10.x = max(DAT_002d46a4, local_10.x);
    } else {
        local_10.x = min(DAT_002d46a8, local_10.x);
    }
    float z, y, x;
    x = local_10.x;
    y = local_10.y;
    z = local_10.z;
    bool ok;
    if (fabsf(x) < FUN_000b3c68(self)->f2c * 0.01f) {
        z = z - DAT_0034129c * 0.01f;
        float t = 0.0f;
        float az = fabsf(z);
        if (az > FUN_001621c0(DAT_00341120, 0) * 0.01f) {
            int sg = z < 0.0f ? -1 : 1;
            float e = FUN_001621c0(DAT_00341120, 0);
            float z2 = z - (float)sg * (e * 0.01f);
            float q;
            if (z2 > 0.0f) q = z2 / (DAT_00341294 * 0.01f * (float)DAT_00341284);
            else q = z2 / (DAT_00341294 * 0.01f * (float)DAT_00341288);
            t = (q > DAT_002d46ac) ? DAT_002d46ac : q;
        }
        float h0, h1;
        h1 = FUN_00164474(FUN_000b3c68(self), self->f440) * 0.01f;
        h0 = FUN_0016442c(FUN_000b3c68(self), self->f440) * 0.01f;
        Ctx *c = FUN_000b3c68(self);
        float thr = (1.0f - (h0 + t * (h1 - h0))) * (c->f2c * 0.01f);
        bool inband = fabsf(x) < thr;
        if (inband) ok = false;
        else ok = true;
    } else {
        ok = false;
    }
    int r;
    if (ok) {
        float lim = -(FUN_000b3c68(self)->f24 * 0.01f);
        if (y > lim && y < 0.0f) ok = true;
        else ok = false;
        if (ok) {
            float k = FUN_000b3c68(self)->f184 * 0.01f;
            float lim2 = (1.0f - k) * -(FUN_000b3c68(self)->f24 * 0.01f);
            if (y <= lim2) ok = true;
            else ok = false;
        } else {
            ok = false;
        }
        if (ok) r = 1;
        else r = 0;
    } else {
        r = 0;
    }
    return r;
}
// NEAR MISS (22 aligned words differ; hstmatch reports 77 because everything after the first hunk shifts).
// Matched exactly: prologue, Vec4 copy, clamp via max/min(const T&), the stage-1 test, the z/y/x loads (declare `float z, y, x;`
// then assign x, y, z: gives f21/f22/f23), the digit/sign/denominator arithmetic (the division belongs INSIDE both arms of
// `if (z2 > 0.0f) q = z2 / (...); else q = z2 / (...);`), `t = (q > DAT_002d46ac) ? DAT_002d46ac : q;` (reproduces the double
// global load and the bc1tl/mov.s slot), `float h0, h1;` declared before the two assignments (f23/f24), `FUN_000b3c68(self)->f184 * 0.01f`
// computed BEFORE the second b6e80 call, and the first stage-3 test via check_range().
// Still different: (1) the thr expression (`(1.0f - (h0 + t * (h1 - h0))) * (c->f2c * 0.01f)`): retail computes 0.01 * f2c before
// `1.0 - sum` and names the temps f0/f2/f1, ours f1/f0/f2 (statement order, operand order, a Lerp() inline, a separate lim/sum local
// all schedule the same); (2) retail's level-2 select `bool inband = fabsf(x) < thr; if (inband) ok = false; else ok = true;` is the unfused
// `bnez v0,P; nop; b Q; li v0,1; P: move v0,zero` while ours fuses it into `beqzl`/`li` (an inline `if (b) return false; return true;`
// becomes sltu/xori, a bool/int variable, ?: and `!` give the fused or xori forms); (3) the two last selects (`y <= lim2` and
// `ok ? 1 : 0`) are unfused in retail (`bc1f P; nop; b Q; li v0,1; P: move v0,zero`), fused (`bc1fl`) in ours. A bool-returning
// inline `le_check()` for the last compare fixed difference (1) as a side effect but adds an `andi` (24 aligned words).
// rt2 2026-10-21 EBOOT twin (remapped from hstp wip/check_motion_limits_000abd80.cpp: DAT 0x2d46a4/a8/ac,
// 0x34129c, 0x341120, 0x341294/84/88; calls 0x22434, 0x1621c0, 0x164474, 0x16442c, getter 0xb3c68).
// Recompiled for EBOOT: 238/244 words, 77 raw diffs / 22 aligned - the SAME three differences as the hstp twin
// (thr FPR temp order; materialised `andi` bool for inband vs our fused branch; unfused last two selects).
// Nothing EBOOT-specific improved; parked with the twin's notes (see wip/check_motion_limits_000abd80.cpp).
// near miss from lane rt2 (unreviewed)
