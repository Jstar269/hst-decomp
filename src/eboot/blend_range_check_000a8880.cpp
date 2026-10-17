/* HSTMATCH module=EBOOT.BIN start=0x000a8880 end=0x000a8c18 symbol=FUN_000a8880 lang=c++ */
/* Clone of src/sharing_main/blend_range_check_000ab274.cpp (hstclone.py tag c17b203): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Same blend-factor arithmetic as src/sharing_main/blend_factor_000aacac.cpp but expanded flat (an inline copy of it gave the wrong FP callee-saved numbering). Matching idioms: locals declared in the order v, y, x ... w2, w1 (earlier-declared float = higher callee-saved register), the comparison stored in a bool before the branch, max/min const-reference helpers as in check_motion_limits_000ac53c.cpp. */
extern "C" {
extern const float DAT_002d46a4;
extern const float DAT_002d46a8;
extern float DAT_002d46ac;
extern char DAT_00341120[];
extern int DAT_00341284;
extern int DAT_00341288;
extern float DAT_00341294;
extern float DAT_0034129c;
extern void FUN_00022434(void *dst, int, int);
extern int FUN_000a8de0(void *, int, int, unsigned char);
extern int FUN_000aaae4(void *, int, int, unsigned char, int, int, int);
extern char *FUN_000b3c68(void *obj);
extern float FUN_001621c0(char *, int);
extern float FUN_0016442c(void *, int);
extern float FUN_00164474(void *, int);
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

static inline float Min(const float &a, const float &b)
{
  return !(a > b) ? a : b;
}

static inline bool check_range(float y, float lim2) {
    if (y > lim2 && y < 0.0f) {
        return true;
    }
    return false;
}

struct Vec4 {
    float x, y, z, w;
};

struct Obj {
    char pad00[0x150];
    int f150;
    char pad154[0x440 - 0x154];
    int f440;
};

extern "C" int FUN_000a8880(Obj *param_1, int param_2, int param_3, unsigned char param_4, int param_5) {
    Vec4 local_10;
    Vec4 local_20;
    float v;
    float y;
    float x;
    float res;
    float av;
    float w2;
    float w1;
    float blend;
    bool cond1;

    FUN_00022434(&local_20, param_2, param_3);
    local_10 = local_20;

    if (param_4 == (param_1->f150 == 0)) {
        local_10.x = max(DAT_002d46a4, local_10.x);
    } else {
        local_10.x = min(DAT_002d46a8, local_10.x);
    }

    x = local_10.x;
    y = local_10.y;
    v = local_10.z - DAT_0034129c * 0.01f;
    res = 0.0f;
    av = fabsf(v);
    if (av > FUN_001621c0(DAT_00341120, 0) * 0.01f) {
        int sign;
        float w;
        float q;
        if (v < 0.0f) {
            sign = -1;
        } else {
            sign = 1;
        }
        w = v - (float)sign * (FUN_001621c0(DAT_00341120, 0) * 0.01f);
        if (w > 0.0f) {
            q = w / (DAT_00341294 * 0.01f * (float)DAT_00341284);
        } else {
            q = w / (DAT_00341294 * 0.01f * (float)DAT_00341288);
        }
        res = Min(q, DAT_002d46ac);
    }
    w1 = FUN_00164474(FUN_000b3c68(param_1), param_1->f440) * 0.01f;
    w2 = FUN_0016442c(FUN_000b3c68(param_1), param_1->f440) * 0.01f;
    blend = (1.0f - (w2 + res * (w1 - w2))) * (*(float *)(FUN_000b3c68(param_1) + 0x2c) * 0.01f);
    cond1 = fabsf(x) < blend;
    if (cond1) {
        float neg = -(*(float *)(FUN_000b3c68(param_1) + 0x24) * 0.01f);
        if (check_range(y, neg) && FUN_000a8de0(param_1, param_2, param_3, param_4) == 0 &&
            FUN_000aaae4(param_1, param_2, param_3, param_4, param_5, 1, 0) == 0) {
            return 1;
        }
    }
    return 0;
}
