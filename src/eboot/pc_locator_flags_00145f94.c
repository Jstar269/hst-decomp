/* HSTMATCH module=EBOOT.BIN start=0x00145f94 end=0x0014613c symbol=FUN_00145f94 lang=c99 data=0x002dc064 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idioms: the lookup result is held in a local (`hit`) so `path + 4` is not CSE'd into a saved register across the call; local declaration order n, bits, tab, p, h, hit. Started from the fm8 near miss. Data: its string-pointer tables (1 tables, 4 strings, 0x002dc064-0x002dc09c) are defined in place and placed with data= (tools/hstdatapool.py tables); before, the source named them through address externs. */
extern int FUN_00014d64(int, char *);
extern int FUN_0000fe64(char);
extern void FUN_000149a8(char *, char *);
extern int FUN_0000d62c(char *);
extern char DAT_002dbb8c[];
extern char DAT_002dbb98[];
extern char DAT_002dbd48[];
extern char DAT_002dbd4c[];
extern char DAT_002dc10c[];
char *DAT_002dc08c[] = {
    "__singles",
    "__doubles",
    "__bill",
    "__clip",
};
extern char *DAT_002dc0dc[];
extern char *DAT_002dc0e0[];

#define TAG_COUNT 4   /* marker names tested for the flag bits */
#define ALIAS_COUNT 6 /* name/replacement pairs searched */

/* Scan a locator path for marker names and return them as a bit mask; also reports a matched alias (index and replacement name) and a numeric suffix. */
unsigned FUN_00145f94(int unused, unsigned *out_index, int path, char *out_name,
                      unsigned *out_suffix)
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
        if (FUN_00014d64(path, *tab) != 0)
            bits |= 1 << n;
        n++;
        tab++;
    } while (n < TAG_COUNT);
    if (FUN_00014d64(path, DAT_002dbb8c) != 0)
        return bits;
    if (FUN_00014d64(path, DAT_002dbb98) != 0)
        return bits;
    h = (char *)FUN_00014d64(path, DAT_002dbd48);
    if (h != 0 && FUN_0000fe64(h[3]) != 0)
        return bits;
    if (FUN_00014d64(path, DAT_002dbd4c) != 0)
        return bits;
    *out_name = 0;
    n = 0;
    tab = DAT_002dc0dc;
    do {
        hit = FUN_00014d64(path + 4, *tab);
        if (hit == path + 4) {
            FUN_000149a8(out_name, DAT_002dc0e0[n * 2]);
            *out_index = n;
            break;
        }
        n++;
        tab += 2;
    } while (n < ALIAS_COUNT);
    p = (char *)FUN_00014d64(path, DAT_002dc10c);
    if (p != 0) {
        *out_suffix = FUN_0000d62c(p + 2);
        *p = 0;
    } else {
        *out_suffix = 0;
    }
    return bits;
}
