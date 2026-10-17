/* HSTMATCH module=EBOOT.BIN start=0x0015474c end=0x001547dc symbol=FUN_0015474c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256b) corrected by hand: typed struct params, FUN_002879e0 prototyped (int,int,float,int,int,int) for the argument-setup order, (double)s->f variadic argument for the extendsfdf2 call; exact match verified; names and types await human review. */
typedef struct { int pad0, pad4; int a; float f; int b; int c; } S154;
typedef struct { int pad0, pad4, pad8; int p; } T154;
extern unsigned char DAT_003402f0;
extern char DAT_002dc908[];
extern void FUN_0014d044(void *p);
extern void FUN_0014fd94(const char *fmt, ...);
extern void FUN_002879e0(int p, int a, float f, int b, int c, int d);

int FUN_0015474c(S154 *s, T154 *t)
{
    if (DAT_003402f0 != 0) {
        FUN_0014d044(t);
        FUN_0014fd94(DAT_002dc908, s->a, (double)s->f, s->b, s->c);
    }
    if (t->p != 0) {
        FUN_002879e0(t->p, s->a, s->f, s->b, s->c, 0);
    }
    return 0;
}
