/* HSTMATCH module=EBOOT.BIN start=0x002afb80 end=0x002afcd0 symbol=FUN_002afb80 lang=c++ */

extern "C" void *__nw__FUi(unsigned n);
extern "C" void FUN_00103628(void *p, int n);
extern "C" void *FUN_002afd70(void *p, void *self);
extern "C" void FUN_002affdc(void *p, void *n);
extern "C" void FUN_00063478(int a, float f);
extern "C" void FUN_00063830(int a, void *b, void *c, int d, int e, int f, float g, float h);

extern char *DAT_0034b5d8;
extern float DAT_00302e20;
extern int DAT_00302e4c;
extern int DAT_00331b84;

struct Vec4_2afb80 {
    float x, y, z, w;
};

extern "C" int FUN_002afb80(char *self, char *n)
{
    if (n != 0) {
        int on = *(signed char *)(n + 0x2f) != 0 ? 1 : 0;
        if (!on)
            return 0;
    }
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
    FUN_00063830(DAT_00331b84, &b, &a, -1, 0, 0, (float)DAT_00302e4c, -1.0f);
    return 1;
}
// sy1: 82/84 words; everything but the guard is exact. New vs the older wip: FUN_00063830 takes two more args,
// (float)DAT_00302e4c in f12 and -1.0f in f13 (`FUN_00063830(a, &b, &a2, -1, 0, 0, (float)G, -1.0f)`), which closes 5 words.
// Remaining 2 words: retail materialises the flag branchily (`beqzl v0,L; move v0,zero; li v0,1; L: bnez v0,BODY; nop; b RET0; move v0,zero`)
// with n==0 jumping straight into the body. Tried: `x ? 1 : 0`, if/else assign to int/bool, inline int/bool IsOn() with
// early returns / ternary / if-else r, flag hoisted over both arms (jump-threads, 85 words). All fold to sltu or thread.
// near miss from lane sy1 (unreviewed)
