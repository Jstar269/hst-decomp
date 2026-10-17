/* HSTMATCH module=hstp_trans_main.prx start=0x00160b04 end=0x00160b94 symbol=FUN_00160b04 lang=c99 */
/* Clone of src/eboot/debug_print_effect_params_0015474c.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256b) corrected by hand: typed struct params, FUN_00299114 prototyped (int,int,float,int,int,int) for the argument-setup order, (double)s->f variadic argument for the extendsfdf2 call; exact match verified; names and types await human review. */
typedef struct { int pad0, pad4; int a; float f; int b; int c; } S154;
typedef struct { int pad0, pad4, pad8; int p; } T154;
extern unsigned char DAT_003e9630;
extern char DAT_00383df0[];
extern void FUN_00158b2c(void *p);
extern void FUN_0015bb68(const char *fmt, ...);
extern void FUN_00299114(int p, int a, float f, int b, int c, int d);

int FUN_00160b04(S154 *s, T154 *t)
{
    if (DAT_003e9630 != 0) {
        FUN_00158b2c(t);
        FUN_0015bb68(DAT_00383df0, s->a, (double)s->f, s->b, s->c);
    }
    if (t->p != 0) {
        FUN_00299114(t->p, s->a, s->f, s->b, s->c, 0);
    }
    return 0;
}
