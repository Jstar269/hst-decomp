/* HSTMATCH module=EBOOT.BIN start=0x00145f94 end=0x0014613c symbol=FUN_00145f94 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idioms: the lookup result is held in a local (`hit`) so `param_3 + 4` is not CSE'd into a saved register across the call; local declaration order n, bits, tab, p, h, hit. Started from the fm8 near miss. */
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
    unsigned bits;
    char **tab;
    char *p;
    char *h;
    int hit;

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
    h = (char *)FUN_00014d64(param_3, DAT_002dbd48);
    if (h != 0 && FUN_0000fe64(h[3]) != 0)
        return bits;
    if (FUN_00014d64(param_3, DAT_002dbd4c) != 0)
        return bits;
    *param_4 = 0;
    n = 0;
    tab = DAT_002dc0dc;
    do {
        hit = FUN_00014d64(param_3 + 4, *tab);
        if (hit == param_3 + 4) {
            FUN_000149a8(param_4, DAT_002dc0e0[n * 2]);
            *param_2 = n;
            break;
        }
        n++;
        tab += 2;
    } while (n < 6);
    p = (char *)FUN_00014d64(param_3, DAT_002dc10c);
    if (p != 0) {
        *param_5 = FUN_0000d62c(p + 2);
        *p = 0;
    } else {
        *param_5 = 0;
    }
    return bits;
}
