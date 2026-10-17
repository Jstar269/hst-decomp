/* HSTMATCH module=EBOOT.BIN start=0x000a8608 end=0x000a8810 symbol=FUN_000a8608 lang=c++ */
/* Clone of src/sharing_main/check_blend_threshold_000aaffc.cpp (hstclone.py tag s10170158a1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v1) corrected by hand: const-ref Min helper, float locals, and explicit if/return 1/0; exact match verified; names and types await human review. */
extern "C" {
extern float DAT_002d46ac;
extern char DAT_00341120[];
extern int DAT_00341284;
extern int DAT_00341288;
extern float DAT_00341294;
extern float DAT_0034129c;
extern int FUN_000b3c68(int);
extern float FUN_001621c0(char *, int);
extern float FUN_0016442c(int, int);
extern float FUN_00164474(int, int);
extern float fabsf(float);
}

static inline float Min(const float &a, const float &b)
{
    return !(a > b) ? a : b;
}

extern "C" int FUN_000a8608(int param_1, float *param_2)
{
    float v = param_2[2] - DAT_0034129c * 0.01f;
    float w2;
    float w1;
    float res = 0.0f;
    float av = fabsf(v);
    if (av > FUN_001621c0(DAT_00341120, 0) * 0.01f) {
        int sign;
        if (v < 0.0f) {
            sign = -1;
        } else {
            sign = 1;
        }
        float w = v - (float)sign * (FUN_001621c0(DAT_00341120, 0) * 0.01f);
        float q;
        if (w > 0.0f) {
            q = w / (DAT_00341294 * 0.01f * (float)DAT_00341284);
        } else {
            q = w / (DAT_00341294 * 0.01f * (float)DAT_00341288);
        }
        res = Min(q, DAT_002d46ac);
    }
    w1 = FUN_00164474(FUN_000b3c68(param_1), *(int *)(param_1 + 0x440)) * 0.01f;
    w2 = FUN_0016442c(FUN_000b3c68(param_1), *(int *)(param_1 + 0x440)) * 0.01f;
    if (fabsf(*param_2) < (1.0f - (w2 + res * (w1 - w2))) * (*(float *)(FUN_000b3c68(param_1) + 0x2c) * 0.01f)) {
        return 1;
    }
    return 0;
}
