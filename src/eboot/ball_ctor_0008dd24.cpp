/* HSTMATCH module=EBOOT.BIN start=0x0008dd24 end=0x0008df24 symbol=FUN_0008dd24 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the 0x110 float read through the inline accessor Field44() (orders the commutative mul.s operands); names and types await human review. */
extern "C" {
extern void FUN_000c2158(void);
extern void FUN_0001f06c(void *);
extern void FUN_00056b98(void *);
extern void FUN_0006dfe4(void *);
extern void FUN_00050fc0(void *);
extern void FUN_000007f4(void *, void (*)(void), void (*)(void), int, int);
extern void FUN_0005a8ec(void);
extern void FUN_0005aeac(void);
extern void FUN_0001ca58(void *, const char *);
extern void FUN_000511c4(void *, const char *, int);
extern void FUN_0001cb88(void *);
extern void FUN_000556b0(void *, void *);
extern void FUN_0008e01c(void *);
extern void FUN_0006e094(float, float, float, void *, int);
extern void FUN_0009117c(void *, int);
extern int DAT_0030722c;
extern int DAT_00307238;
extern int DAT_0030ebf4;
extern const char DAT_002d27a7[];
extern const char DAT_002d27c0[];
extern const char DAT_002d27e4[];
}
struct Snd { virtual void s0(); virtual void s1(); virtual void s2(const char *, int, int, int, int, int); };
struct Buf { unsigned char b[16] __attribute__((aligned(16))); float f; };
static inline float Field44(const int *p) { return *(const float *)(p + 0x44); }

extern "C" int *FUN_0008dd24(int *param_1)
{
    Buf buf;

    FUN_000c2158();
    FUN_0001f06c(param_1 + 0x78);
    *param_1 = (int)&DAT_0030722c;
    param_1[0x78] = (int)&DAT_00307238;
    param_1[0x8b] = 5;
    param_1[0x8c] = 0xffffffff;
    param_1[0x8d] = 0xffffffff;
    param_1[0x8e] = 3;
    param_1[0x8f] = 0xd;
    *(unsigned char *)(param_1 + 0x90) = 0;
    param_1[0x91] = 0x3f800000;
    param_1[0x92] = 0;
    param_1[0x94] = 0;
    param_1[0x95] = 0;
    param_1[0x96] = 0;
    param_1[0x97] = 0;
    param_1[0x98] = 0xffffffff;
    param_1[0x99] = 0;
    param_1[0x9a] = 0;
    param_1[0x9b] = 0;
    param_1[0x9c] = 0;
    param_1[0x9d] = 0;
    param_1[0x9e] = 0;
    param_1[0x9f] = 0;
    param_1[0xa0] = 0;
    *(unsigned char *)(param_1 + 0xa1) = 0;
    param_1[0xa2] = 0;
    FUN_00056b98(param_1 + 0xa4);
    FUN_0006dfe4(param_1 + 0x112);
    FUN_00050fc0(param_1 + 0x114);
    FUN_000007f4(param_1 + 0x128, FUN_0005a8ec, FUN_0005aeac, 0x70, 2);
    FUN_0001ca58(&DAT_0030ebf4, DAT_002d27a7 + 1);
    ((Snd *)(param_1 + 0xa4))->s2(DAT_002d27c0, 0, 0, 0, 0, 0);
    FUN_000511c4(param_1 + 0x114, DAT_002d27e4, 0);
    FUN_0001cb88(&DAT_0030ebf4);
    FUN_000556b0(param_1 + 0xa4, &buf);
    *(float *)(param_1 + 0x110) = buf.f;
    param_1[0x110] = 0x3d066e44;
    FUN_0008e01c(param_1);
    param_1[0x111] = 1;
    param_1[0x87] = 0x40400000;
    param_1[0x88] = 0x3fc00000;
    param_1[0x89] = 0x3f7ae148;
    param_1[0x8a] = 0x3f266666;
    {
        float f = Field44(param_1) * *(float *)(param_1 + 0x87);
        FUN_0006e094(f, f, *(float *)(param_1 + 0x89), param_1 + 0x112, 0);
    }
    if ((unsigned int)param_1[0x9d] < 600)
        FUN_0009117c(param_1 + 0x9b, 600);
    if ((unsigned int)param_1[0xa0] < 2)
        FUN_0009117c(param_1 + 0x9e, 2);
    return param_1;
}
// Sound object: C++ class with three declared virtuals (`Snd::s2(const char *, 5 ints)`, slot 2 = vtable +16) cast over
// param_1+0xa4 (a C function pointer would call through v0); the local is `struct Buf { unsigned char b[16]
// __attribute__((aligned(16))); float f; }` (32-byte aligned slot at sp+16, f at sp+32).
// matching idiom: the 0x110 float is read through the inline accessor Field44(). MWCC orders the operands of a commutative
// operator by Sethi-Ullman weight before inlining (a call, inline or not, weighs 4, a field load 1) and puts the lighter one
// in fs: retail's `mul.s $f12,$f0(0x21c),$f1(0x110)` with the 0x110 load issued first. Both direct spellings tie (weight 1)
// and keep source order: `f110 * f21c` gives the right loads but fs=0x110, `f21c * f110` swaps the loads.
