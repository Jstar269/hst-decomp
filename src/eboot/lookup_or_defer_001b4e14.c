/* HSTMATCH module=EBOOT.BIN start=0x001b4e14 end=0x001b4edc symbol=FUN_001b4e14 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_0034179c[];

extern int FUN_001b1f7c(char *tbl, int v);
extern int FUN_001b2bb8(char *tbl, int v);
extern void FUN_001b9608(int *out, void *a, int *v, void *p);

int FUN_001b4e14(void *a, int b, int c, int *out, int *q)
{
    int v;

    if (c <= 0) {
        if (q != 0) {
            if (FUN_001b1f7c(DAT_0034179c, *q) != 0)
                goto big;
        }
        v = FUN_001b2bb8(DAT_0034179c, b);
        if (out != 0)
            *out = v;
        return v;
    }
big:
    {
        struct P4 {
            int b;
            int c;
            int *out;
            int *q;
        } p;
        struct Pair {
            int v;
            int r;
        } pr;

        pr.v = (int)a + 4;
        p.b = b;
        p.c = c;
        p.out = out;
        p.q = q;
        FUN_001b9608(&pr.r, a, &pr.v, &p);
    }
    return -1;
}
