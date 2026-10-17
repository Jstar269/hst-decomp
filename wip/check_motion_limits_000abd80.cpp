/* HSTMATCH module=hstp_trans_main.prx start=0x000abd80 end=0x000ac150 symbol=FUN_000abd80 lang=c++ */
/* Hand-written reconstruction from the disassembly (first half is the clamp/limit code of src/sharing_main/check_motion_limits_000ac53c.cpp); NEAR MISS, not exact: 238 of 244 words with 22 aligned words differing; names and types await human review. */
extern "C" {
extern const float DAT_0037acac;
extern const float DAT_0037acb0;
extern const float DAT_0037acb4;
extern float DAT_003ea5dc;
extern float DAT_003ea5d4;
extern int DAT_003ea5c4;
extern int DAT_003ea5c8;
extern char DAT_003ea460[];
extern void FUN_0002245c(void *dst);
extern float FUN_0016e74c(void *, int);
extern float FUN_001709e8(void *, int);
extern float FUN_001709a0(void *, int);
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

extern "C" Ctx *FUN_000b6e80(Obj *);

static inline bool check_range(float y, float lim)
{
    if (y > lim && y < 0.0f) return true;
    return false;
}

extern "C" int FUN_000abd80(Obj *self, int a, int b, unsigned char flag)
{
    Vec4 local_10;
    Vec4 local_20;
    FUN_0002245c(&local_20);
    local_10 = local_20;
    if (flag == (self->f150 == 0)) {
        local_10.x = max(DAT_0037acac, local_10.x);
    } else {
        local_10.x = min(DAT_0037acb0, local_10.x);
    }
    float z, y, x;
    x = local_10.x;
    y = local_10.y;
    z = local_10.z;
    bool ok;
    if (fabsf(x) < FUN_000b6e80(self)->f2c * 0.01f) {
        z = z - DAT_003ea5dc * 0.01f;
        float t = 0.0f;
        float az = fabsf(z);
        if (az > FUN_0016e74c(DAT_003ea460, 0) * 0.01f) {
            int sg = z < 0.0f ? -1 : 1;
            float e = FUN_0016e74c(DAT_003ea460, 0);
            float z2 = z - (float)sg * (e * 0.01f);
            float q;
            if (z2 > 0.0f) q = z2 / (DAT_003ea5d4 * 0.01f * (float)DAT_003ea5c4);
            else q = z2 / (DAT_003ea5d4 * 0.01f * (float)DAT_003ea5c8);
            t = (q > DAT_0037acb4) ? DAT_0037acb4 : q;
        }
        float h0, h1;
        h1 = FUN_001709e8(FUN_000b6e80(self), self->f440) * 0.01f;
        h0 = FUN_001709a0(FUN_000b6e80(self), self->f440) * 0.01f;
        Ctx *c = FUN_000b6e80(self);
        float thr = (1.0f - (h0 + t * (h1 - h0))) * (c->f2c * 0.01f);
        bool inband = fabsf(x) < thr;
        if (inband) ok = false;
        else ok = true;
    } else {
        ok = false;
    }
    int r;
    if (ok) {
        float lim = -(FUN_000b6e80(self)->f24 * 0.01f);
        if (y > lim && y < 0.0f) ok = true;
        else ok = false;
        if (ok) {
            float k = FUN_000b6e80(self)->f184 * 0.01f;
            float lim2 = (1.0f - k) * -(FUN_000b6e80(self)->f24 * 0.01f);
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
// `if (z2 > 0.0f) q = z2 / (...); else q = z2 / (...);`), `t = (q > DAT_0037acb4) ? DAT_0037acb4 : q;` (reproduces the double
// global load and the bc1tl/mov.s slot), `float h0, h1;` declared before the two assignments (f23/f24), `FUN_000b6e80(self)->f184 * 0.01f`
// computed BEFORE the second b6e80 call, and the first stage-3 test via check_range().
// Still different: (1) the thr expression (`(1.0f - (h0 + t * (h1 - h0))) * (c->f2c * 0.01f)`): retail computes 0.01 * f2c before
// `1.0 - sum` and names the temps f0/f2/f1, ours f1/f0/f2 (statement order, operand order, a Lerp() inline, a separate lim/sum local
// all schedule the same); (2) retail's level-2 select `bool inband = fabsf(x) < thr; if (inband) ok = false; else ok = true;` is the unfused
// `bnez v0,P; nop; b Q; li v0,1; P: move v0,zero` while ours fuses it into `beqzl`/`li` (an inline `if (b) return false; return true;`
// becomes sltu/xori, a bool/int variable, ?: and `!` give the fused or xori forms); (3) the two last selects (`y <= lim2` and
// `ok ? 1 : 0`) are unfused in retail (`bc1f P; nop; b Q; li v0,1; P: move v0,zero`), fused (`bc1fl`) in ours. A bool-returning
// inline `le_check()` for the last compare fixed difference (1) as a side effect but adds an `andi` (24 aligned words).
