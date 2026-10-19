/* HSTMATCH module=hstp_trans_main.prx start=0x001c2a28 end=0x001c2af0 symbol=FUN_001c2a28 lang=c99 */
/* Clone of src/eboot/lookup_or_defer_001b4e14.c (hstclone.py tag c155507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_003eaad8[];

extern int FUN_001c0010(char *tbl, int v);
extern int FUN_001c0ce8(char *tbl, int v);
extern void FUN_001c72f4(int *out, void *a, int *v, void *p);

int FUN_001c2a28(void *a, int b, int c, int *out, int *q)
{
    int v;

    if (c <= 0) {
        if (q != 0) {
            if (FUN_001c0010(DAT_003eaad8, *q) != 0)
                goto big;
        }
        v = FUN_001c0ce8(DAT_003eaad8, b);
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
        FUN_001c72f4(&pr.r, a, &pr.v, &p);
    }
    return -1;
}
