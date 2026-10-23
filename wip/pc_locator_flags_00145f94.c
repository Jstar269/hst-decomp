/* HSTMATCH module=EBOOT.BIN start=0x00145f94 end=0x0014613c symbol=FUN_00145f94 lang=c99 */
extern int FUN_00014d64(int, char *);
extern int FUN_0000fe64(char);
extern void FUN_000149a8(char *, char *);
extern int FUN_0000d62c(char *);
extern char DAT_002dbb8c[];
extern char DAT_002dbb98[];
extern char DAT_002dbd48[];
extern char DAT_002dbd4c[];
extern char DAT_002dc10c[];
extern char *DAT_002dc08c[];
extern char *DAT_002dc0dc[];
extern char *DAT_002dc0e0[];

unsigned FUN_00145f94(int param_1, unsigned *param_2, int param_3, char *param_4,
                      unsigned *param_5)
{
    unsigned n;
    char **tab;
    unsigned bits;

    bits = 0;
    n = 0;
    tab = DAT_002dc08c;
    do {
        if (FUN_00014d64(param_3, *tab) != 0)
            bits |= 1 << n;
        n++;
        tab++;
    } while (n < 4);
    if (FUN_00014d64(param_3, DAT_002dbb8c) != 0)
        return bits;
    if (FUN_00014d64(param_3, DAT_002dbb98) != 0)
        return bits;
    {
        char *h = (char *)FUN_00014d64(param_3, DAT_002dbd48);
        if (h != 0 && FUN_0000fe64(h[3]) != 0)
            return bits;
    }
    if (FUN_00014d64(param_3, DAT_002dbd4c) != 0)
        return bits;
    *param_4 = 0;
    n = 0;
    tab = DAT_002dc0dc;
    do {
        if (FUN_00014d64(param_3 + 4, *tab) == param_3 + 4) {
            FUN_000149a8(param_4, DAT_002dc0e0[n * 2]);
            *param_2 = n;
            break;
        }
        n++;
        tab += 2;
    } while (n < 6);
    {
        char *p = (char *)FUN_00014d64(param_3, DAT_002dc10c);
        if (p != 0) {
            *param_5 = FUN_0000d62c(p + 2);
            *p = 0;
        } else {
            *param_5 = 0;
        }
    }
    return bits;
}
// near miss: 108/106 words. Structure fully recovered and instruction-for-instruction aligned
// with retail (both table walks, the sllv/or flag accumulate, the hit==param_3+4 comparison,
// the tail parse), but our build keeps EIGHT saved registers where retail keeps seven, so every
// s-register name is shifted by one past the prologue, and the extra register costs 2 words.
// Retail's map: s6=param_2 s5=n s4=tab s3=param_3 s2=param_4 s1=param_5 s0=bits, with the tail's
// `p` reusing param_4's dead s2. Ours: s7=param_2 s6=param_5 s5=param_3 s4=param_4 s3=bits
// s2=n s1=tab s0=p -- loop 1 uses n=s1/tab=s0 and loop 2 n=s2/tab=s1, i.e. MWCC gave the second
// loop fresh registers instead of reusing the first loop's dead ones.
// Ruled out: declaration orders (n,tab,bits / n,bits,tab / bits,n,tab), n as int vs unsigned,
// `p` hoisted to the top or block-scoped, `if (p == 0)` vs `if (p != 0)` arm order (the reversed
// form is what got 110 -> 108), the `h` local as char* vs int.
// Notable exact pieces: the `&&` chain `if (h != 0 && FUN_0000fe64(h[3]) != 0) return bits;` gives
// retail's plain `beqz v0; nop` (not branch-likely) for the third test while the first two use
// `beqzl v0,next`; the name table is a SEPARATE base (DAT_002dc0e0[n*2]) from the pattern walk
// (DAT_002dc0dc stepped by 2 chars*[]), and the last arm needs `*param_4 = 0` before the walk.
// near miss from lane fm8 (unreviewed)
