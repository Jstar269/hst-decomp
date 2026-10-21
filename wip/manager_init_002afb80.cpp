/* HSTMATCH module=EBOOT.BIN start=0x002afb80 end=0x002afcd0 symbol=FUN_002afb80 lang=c++ */

extern "C" void *__nw__FUi(unsigned n);
extern "C" void FUN_00103628(void *p, int n);
extern "C" void *FUN_002afd70(void *p, void *self);
extern "C" void FUN_002affdc(void *p, void *n);
extern "C" void FUN_00063478(int a, float f);
extern "C" void FUN_00063830(int a, void *b, void *c, int d, int e, int f);

extern char *DAT_0034b5d8;
extern float DAT_00302e20;
extern int DAT_00302e4c;
extern int DAT_00331b84;

struct Vec4_2afb80 {
    float x, y, z, w;
};

extern "C" int FUN_002afb80(char *self, char *n)
{
    if (n != 0 && *(signed char *)(n + 0x2f) == 0)
        return 0;
    if (DAT_0034b5d8 == 0) {
        char *p = (char *)__nw__FUi(1200);
        if (p != 0)
            p = (char *)FUN_002afd70(p, self);
        DAT_0034b5d8 = p;
        FUN_002affdc(DAT_0034b5d8, n);
        FUN_00103628(DAT_0034b5d8 + 0x3c, 0);
        return 1;
    }
    FUN_002affdc(DAT_0034b5d8, n);
    FUN_00103628(DAT_0034b5d8 + 0x3c, 0);
    DAT_0034b5d8[0x90] = 0;
    FUN_00063478(DAT_00331b84, DAT_00302e20 - 20.0f);
    Vec4_2afb80 b;
    Vec4_2afb80 a;
    a.x = 0.0f;
    a.y = 0.0f;
    a.z = 0.0f;
    a.w = 0.5f;
    b.x = 0.0f;
    b.y = 0.0f;
    b.z = 0.0f;
    b.w = 0.5f;
    FUN_00063830(DAT_00331b84, &b, &a, -1, 0, 0);
    return 1;
}
// NEAR MISS: 76/84 words. The tail (global manager pointer, 20.0f subtract, two 16-byte (0,0,0,0.5) vectors
// at sp+16/sp+32, FUN_00063830 with f12/f13) matches; the guard does not: retail materialises the flag
// (`beqzl v0,L; move v0,zero; li v0,1; L: bnez v0,BODY`) which is 2 words longer than our plain
// `if (n != 0 && *(signed char *)(n+0x2f) == 0) return 0;`. Ruled out: `||` form, `bool bad = ...`,
// `bool ok = (n == 0) || (f2f != 0)`, `int guard` / `bool guard` two-step assignment (all give sltu forms).
// Semantics are certain: n == 0 falls INTO the body (beqz targets the body), f2f == 0 returns 0.
// near miss from lane ds10 (unreviewed)
