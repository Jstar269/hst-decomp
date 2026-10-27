/* HSTMATCH module=EBOOT.BIN start=0x0008dd24 end=0x0008df24 symbol=FUN_0008dd24 lang=c99 */
// NEAR MISS 128/128 words, 6 words differ: (a) the virtual call at 0x8de14 is
// `lw t9,656(s0); lw t9,16(t9); jalr t9` in retail, this build goes through v0
// (3 words); (b) the 20-byte local buffer sits at sp+28 here and sp+16 in
// retail, i.e. retail has a 16-byte array at sp+16 plus a float at sp+32 that
// the array is passed to (`unsigned char b[16]; float f;` layout) -- a plain
// `char[20]` gets the top of the local area instead (2 words); (c) the final
// `mul.s` operand order (1 word), which swaps whenever the source order of the
// two float factors is swapped, so the load order and the multiply order
// cannot both be satisfied from one expression order.
// Matching notes: FUN_0006e094 takes (float, float, float, void *, int) -- the
// 0x89 field is a float (lwc1/f14), not an int; the strings are DAT_002d27a7+1
// ("..."), DAT_002d27c0 and DAT_002d27e4; `(int)f` style int->float conversions
// must not appear (all four 0x110/0x21c/0x224 fields are floats).
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

int *FUN_0008dd24(int *param_1)
{
    unsigned char buf[20];

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
    (*(void (**)(void *, const char *, int, int, int, int, int))(param_1[0xa4] + 0x10))
        (param_1 + 0xa4, DAT_002d27c0, 0, 0, 0, 0, 0);
    FUN_000511c4(param_1 + 0x114, DAT_002d27e4, 0);
    FUN_0001cb88(&DAT_0030ebf4);
    FUN_000556b0(param_1 + 0xa4, buf);
    *(float *)(param_1 + 0x110) = *(float *)(buf + 16);
    param_1[0x110] = 0x3d066e44;
    FUN_0008e01c(param_1);
    param_1[0x111] = 1;
    param_1[0x87] = 0x40400000;
    param_1[0x88] = 0x3fc00000;
    param_1[0x89] = 0x3f7ae148;
    param_1[0x8a] = 0x3f266666;
    {
        float f = *(float *)(param_1 + 0x44) * *(float *)(param_1 + 0x87);
        FUN_0006e094(f, f, *(float *)(param_1 + 0x89), param_1 + 0x112, 0);
    }
    if ((unsigned int)param_1[0x9d] < 600)
        FUN_0009117c(param_1 + 0x9b, 600);
    if ((unsigned int)param_1[0xa0] < 2)
        FUN_0009117c(param_1 + 0x9e, 2);
    return param_1;
}
// near miss from lane fm8 (unreviewed)
// improved by lane wf20261026-e01-04 (unreviewed): 6 -> 1 differing words
