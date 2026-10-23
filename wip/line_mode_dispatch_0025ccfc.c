/* HSTMATCH module=EBOOT.BIN start=0x0025ccfc end=0x0025cf20 symbol=FUN_0025ccfc lang=c99 */
extern void *FUN_0018c9f4(int);
extern void FUN_00114168(int, int, void *, int, int);
extern void FUN_00114178(int, int, void *, int);
extern void FUN_0025d580(void *);
extern void FUN_0025cf20(void *);
extern void FUN_000baa34(int, int);
extern void FUN_001b1c44(int, int);
extern void FUN_00103628(void *, int);
extern int DAT_003415ac;
extern int DAT_00338ac4;
extern char DAT_002c0e18;
extern char DAT_002c0e1c;
extern char DAT_002c0e20;

void FUN_0025ccfc(int p, int mode)
{
    unsigned char *s;
    int *h;

    *(int *)(p + 0x60) = mode;
    switch (mode) {
    case 3:
        h = (int *)FUN_0018c9f4(0x11);
        if (h[1] == 0)
            s = (unsigned char *)&DAT_002c0e20;
        else if (*(int *)(h[2] + 8) < 0x11)
            s = (unsigned char *)&DAT_002c0e1c;
        else if (*(int *)(h[3] + 0xc4) < 7)
            s = (unsigned char *)&DAT_002c0e18;
        else
            s = *(unsigned char **)(*(int *)(h[3] + 0xc0) + 0x18);
        FUN_00114168(DAT_003415ac, 2, s, 0, 0);
        FUN_0025d580((void *)p);
        FUN_000baa34(DAT_00338ac4, 5);
        break;
    case 2:
        FUN_001b1c44(0x34179c, 3);
        *((unsigned char *)*(int *)(p + 0x5c) + 0x2c02) = 1;
        h = (int *)FUN_0018c9f4(0x11);
        if (h[1] == 0)
            s = (unsigned char *)&DAT_002c0e20;
        else if (*(int *)(h[2] + 8) < 0x11)
            s = (unsigned char *)&DAT_002c0e1c;
        else if (*(int *)(h[3] + 0xc4) < 2)
            s = (unsigned char *)&DAT_002c0e18;
        else
            s = *(unsigned char **)(*(int *)(h[3] + 0xc0) + 4);
        FUN_00114168(DAT_003415ac, 0, s, 0, 0);
        FUN_0025d580((void *)p);
        *(int *)(p + 100) = 0;
        break;
    case 1:
        FUN_00103628((void *)DAT_003415ac, 1);
        FUN_00103628((void *)p, 0);
        FUN_0025cf20((void *)p);
        break;
    case 0:
        h = (int *)FUN_0018c9f4(0x11);
        if (h[1] == 0)
            s = (unsigned char *)&DAT_002c0e20;
        else if (*(int *)(h[2] + 8) < 0x11)
            s = (unsigned char *)&DAT_002c0e1c;
        else if (*(int *)(h[3] + 0xc4) < 1)
            s = (unsigned char *)&DAT_002c0e18;
        else
            s = *(unsigned char **)*(int *)(h[3] + 0xc0);
        FUN_00114178(DAT_003415ac, 3, s, 8);
        FUN_0025d580((void *)p);
        break;
    }
}

// 136/137 words as a switch (ascending compare order 0,1,2,3 and one word short);
// the if/else chain form is 135/137 with descending order but bodies inline.
// Retail emits all four compares first (beql 3 / beql 2 / beql 1 / beqzl 0, each
// jumping to an out-of-line body) then `b end`, then the four bodies - neither the
// if-chain nor the switch spelling reproduces that layout.
// near miss from lane fm8 (unreviewed)
