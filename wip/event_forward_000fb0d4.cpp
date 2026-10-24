/* HSTMATCH module=EBOOT.BIN start=0x000fb0d4 end=0x000fb2d0 symbol=FUN_000fb0d4 lang=c++ */

extern "C" {
extern unsigned char *DAT_00338b44;
extern char *DAT_003386b0;
extern int DAT_002d8250;
extern int DAT_002d8254;
extern int DAT_002d8258;
extern int DAT_002d825c;
extern void FUN_000f5cd8(int a, int b, int c, int d, float *v, int e);
}

extern "C" void FUN_000fb0d4(int a1, int a2, int a3, int a4, int a5, int a6,
                              int a7, int a8)
{
    int t;
    int idx[4];
    float vec[4];

    vec[0] = ((float *)a5)[0];
    vec[1] = ((float *)a5)[1];
    vec[2] = ((float *)a5)[2];
    vec[3] = ((float *)a5)[3];
    if (a2 == 4 && DAT_00338b44[0x45] != 0)
        return;
    if (a2 == 0x11)
        return;
    {
        if (a3 == 0) {
            t = *(int *)(DAT_00338b44 + 0x98);
            if (t < 0)
                t = *(int *)(DAT_00338b44 + 0x50);
            if (a2 == 4) {
                idx[0] = DAT_002d8250;
                idx[1] = DAT_002d8254;
                idx[2] = DAT_002d8258;
                idx[3] = DAT_002d825c;
                t = idx[t];
            }
            t = *(int *)(*(int *)(DAT_003386b0 + 0x70 + t * 4) + 0x5bc);
            a3 = *(int *)(t + 0x58);
            a4 = *(int *)(t + 4);
        }
        if (a2 != 7 && a2 != 0xf && a2 != 0xe && a2 != 0xc && a2 != 2 &&
            a2 != 0xb && a2 != 1)
            a7 = 0;
        if (a2 == 0) {
            if (a8 != 0)
                a2 = 7;
        } else if (a2 == 0xc || a2 == 2) {
            if (a8 != 0)
                a2 = 0xf;
        } else if ((a2 == 0xb || a2 == 1) && a8 != 0) {
            a2 = 0xe;
        }
        if (a3 != 0 && *(int *)(a3 + 0x8c) != 0 && *(int *)(a1 + 0x3c) != 0) {
            t = *(int *)(*(int *)(a1 + 0x3c) + 0x88);
            if (t != 0)
                FUN_000f5cd8(t, a2, a3, a4, vec, a7);
        }
    }
}
// NEAR 116/127 words, 109 differ. Learned from retail: the 16-byte local is a
// COPY of the 6th argument (lwc1 $f3,0(t1) ... swc1 16/20/24/28(sp)), not the
// {0,0,0,1.0f} init Ghidra shows, and the head is two early returns
// (a2==4 && DAT_00338b44[0x45] != 0) then (a2==0x11), not one && chain.
// Remaining: the 0x98/0x50 fallback select, the idx[] table copy (retail builds
// it as 4 lwc1 from the DAT_002d825x block then indexes), the !=7/0xf/0xe/0xc/2
// /0xb/1 chain shape and the final guard nest.
// near miss from lane fm7 (unreviewed)
// improved by lane fm10 (unreviewed): 109 -> 108 differing words
