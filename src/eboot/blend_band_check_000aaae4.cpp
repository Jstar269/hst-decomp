/* HSTMATCH module=EBOOT.BIN start=0x000aaae4 end=0x000aaf54 symbol=FUN_000aaae4 lang=c++ */
/* Clone of src/sharing_main/blend_band_check_000ad4d8.cpp (hstclone.py tag s10170158a1r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified (the blend arithmetic and idioms follow the sibling src/sharing_main/blend_range_check_000ab274.cpp: locals declared v, y, x, z, res, av, w2, w1, blend; matching idioms: the three Vec4 components read into locals before the z test, `unsigned char` flag set as (p != 0) ^ 1, final compare written `y >= F(..)`); names and types await human review. */
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
struct Ctx {
    char pad00[0x2c];
    float f2c;
    char pad30[0xc];
    float f3c;
};
struct Sub {
    char pad[8];
    float f8;
};
struct Obj {
    char pad00[0x150];
    int f150;
    char pad154[0x440 - 0x154];
    int f440;
};
extern Ctx *FUN_000b3c68(void *obj);
extern float FUN_001621c0(char *, int);
extern float FUN_0016442c(void *, int);
extern float FUN_00164474(void *, int);
extern float FUN_000aaf54(float, Obj *);
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

static inline bool check_range(float y, float lim) {
    if (y > lim && y < 0.0f) {
        return true;
    }
    return false;
}

struct Vec4 {
    float x, y, z, w;
};

extern "C" int FUN_000aaae4(Obj *param_1, Sub *param_2, Sub *param_3, unsigned char param_4, int param_5, int param_6, unsigned char *param_7) {
    Vec4 local_10;
    Vec4 local_20;
    float v;
    float y;
    float x;
    float z;
    float res;
    float av;
    float w2;
    float w1;
    float blend;
    unsigned char cond1;
    int r = 0;

    FUN_00022434(&local_20, (int)param_2, (int)param_3);
    local_10 = local_20;

    if (param_4 == (param_1->f150 == 0)) {
        local_10.x = max(DAT_002d46a4, local_10.x);
    } else {
        local_10.x = min(DAT_002d46a8, local_10.x);
    }

    x = local_10.x;
    y = local_10.y;
    z = local_10.z;
    if (param_3->f8 >= -6.4007998f) {
        if (param_5 == 0) {
            if (param_6 == 0 || fabsf(x) < FUN_000b3c68(param_1)->f2c * 0.01f) {
                Ctx *c = FUN_000b3c68(param_1);
                if (check_range(y, -(c->f3c * 0.01f))) {
                    r = 1;
                }
            }
        } else {
            cond1 = (param_6 != 0) ^ 1;
            if (!cond1) {
                v = z - DAT_0034129c * 0.01f;
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
                blend = (1.0f - (w2 + res * (w1 - w2))) * (FUN_000b3c68(param_1)->f2c * 0.01f);
                cond1 = fabsf(x) < blend;
            }
            if (cond1) {
                Ctx *c = FUN_000b3c68(param_1);
                if (check_range(y, -(c->f3c * 0.01f))) {
                    r = 1;
                }
            }
        }
    }
    if (param_7 != 0) {
        *param_7 = 0;
        if (r != 0 && y >= FUN_000aaf54(param_2->f8, param_1)) {
            *param_7 = 1;
        }
    }
    return r;
}
