/* HSTMATCH module=hstp_trans_main.prx start=0x000aaffc end=0x000ab204 symbol=FUN_000aaffc lang=c++ */
/* Ghidra pseudocode (hstgen.py tag gen-sh2/v1) corrected by hand: const-ref Min helper, float locals, and explicit if/return 1/0; exact match verified; names and types await human review. */
extern "C" {
extern float DAT_0037acb4;
extern char DAT_003ea460[];
extern int DAT_003ea5c4;
extern int DAT_003ea5c8;
extern float DAT_003ea5d4;
extern float DAT_003ea5dc;
extern int FUN_000b6e80(int);
extern float FUN_0016e74c(char *, int);
extern float FUN_001709a0(int, int);
extern float FUN_001709e8(int, int);
extern float fabsf(float);
}

static inline float Min(const float &a, const float &b)
{
    return !(a > b) ? a : b;
}

extern "C" int FUN_000aaffc(int param_1, float *param_2)
{
    float v = param_2[2] - DAT_003ea5dc * 0.01f;
    float w2;
    float w1;
    float res = 0.0f;
    float av = fabsf(v);
    if (av > FUN_0016e74c(DAT_003ea460, 0) * 0.01f) {
        int sign;
        if (v < 0.0f) {
            sign = -1;
        } else {
            sign = 1;
        }
        float w = v - (float)sign * (FUN_0016e74c(DAT_003ea460, 0) * 0.01f);
        float q;
        if (w > 0.0f) {
            q = w / (DAT_003ea5d4 * 0.01f * (float)DAT_003ea5c4);
        } else {
            q = w / (DAT_003ea5d4 * 0.01f * (float)DAT_003ea5c8);
        }
        res = Min(q, DAT_0037acb4);
    }
    w1 = FUN_001709e8(FUN_000b6e80(param_1), *(int *)(param_1 + 0x440)) * 0.01f;
    w2 = FUN_001709a0(FUN_000b6e80(param_1), *(int *)(param_1 + 0x440)) * 0.01f;
    if (fabsf(*param_2) < (1.0f - (w2 + res * (w1 - w2))) * (*(float *)(FUN_000b6e80(param_1) + 0x2c) * 0.01f)) {
        return 1;
    }
    return 0;
}
