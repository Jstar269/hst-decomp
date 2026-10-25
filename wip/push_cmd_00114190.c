/* HSTMATCH module=EBOOT.BIN start=0x00114190 end=0x001142b0 symbol=FUN_00114190 lang=c++ */
/* NEAR 2 (72/72 words). C++ with V4 as float v[4] preserves the batched vector copy, and an empty
   by-value Tag emits the required seb. Separating the destination pointer and count produces retail's
   lw/sll/addu order. The only residue is the ordering of `seb a2,v0` and `addiu a0,a0,140`; a named
   Tag local and an inline Insert wrapper worsened the match. */
typedef struct { int a, b, c, d; } Cmd;
typedef struct { float v[4]; } V4;
struct Tag {};
extern "C" {
extern void FUN_001142b0(int, int, int, int, unsigned);
extern void FUN_0011605c(int *, V4 *, Tag);
}

extern "C" void FUN_00114190(int param_1, int param_2, int param_3, int param_4, unsigned param_5)
{
    Cmd tmp;
    char *p;
    int n;
    V4 *dst;

    switch (param_2) {
    case 6:
        param_5 |= 0xd;
        break;
    }
    if ((param_5 & 1) == 0)
        goto fallback;
    if ((*(unsigned short *)(*(int *)(*(int *)(*(int *)(param_1 + 0x54) + 0x10)) + 0xe) & 3) != 0) {
        if (*(int *)(param_1 + 0x90) == 0)
            goto fallback;
    }
    if (*(int *)(param_1 + 0x68) != 1 || (*(unsigned int *)(param_1 + 0x6c) & 2) != 0)
        goto fallback;
    p = (char *)&tmp;
    n = 16;
    if (p != 0) {
        do {
            *p++ = 0;
        } while (--n);
    }
    tmp.a = param_2;
    tmp.b = param_3;
    tmp.c = param_4;
    tmp.d = param_5;
    if (*(unsigned int *)(param_1 + 0x90) < *(unsigned int *)(param_1 + 0x94)) {
        int *data = *(int **)(param_1 + 0x8c);
        unsigned count = *(unsigned int *)(param_1 + 0x90);
        dst = (V4 *)(data + count * 4);
        if (dst != 0)
            *dst = *(V4 *)&tmp;
        *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + 1;
        return;
    }
    FUN_0011605c((int *)(param_1 + 0x8c), (V4 *)&tmp, Tag());
    return;
fallback:
    FUN_001142b0(param_1, param_2, param_3, param_4, param_5);
}
// near miss from lane fm6 (unreviewed)
// improved by lane lnm3 (unreviewed): 20 -> 2 differing words
