/* HSTMATCH module=EBOOT.BIN start=0x002534b4 end=0x002535e0 symbol=FUN_002534b4 lang=c99 */
/* Hand-written reconstruction from the disassembly (restructured from a near-miss wip draft); exact match verified; names and types await human review. */
extern int DAT_0034a7ec;
extern int FUN_0027edbc(int, int);
extern void FUN_000ffb3c(int, int);

void FUN_002534b4(int *param_1, int param_2)
{
    int h = param_1[param_2 + 0xf];
    int e = FUN_0027edbc(DAT_0034a7ec, h);
    int a = 0;
    int b = 0;
    int c = 0;
    int *g;
    int *t;
    int i;
    unsigned j;
    int sum;

    if (e != 0) {
        a = *(short *)(e + 10);
        b = *(short *)(e + 12);
        c = *(short *)(e + 14);
    }
    g = (int *)param_1[0];
    /* matching idiom: the unsigned index keeps MWCC from strength-reducing this loop (retail recomputes the offset) */
    for (i = 0; i < g[5]; i++)
        FUN_000ffb3c(((int *)g[4])[(unsigned)i], i != h - 1);
    sum = param_1[2] + a;
    t = (int *)param_1[1];
    t[9] = sum;
    t[10] = sum;
    for (j = 0; j < 5; j++)
        FUN_000ffb3c(param_1[3 + j], (int)j >= b);
    for (j = 0; j < 5; j++)
        FUN_000ffb3c(param_1[8 + j], (int)j >= c);
}
