/* HSTMATCH module=EBOOT.BIN start=0x000fc91c end=0x000fcb7c symbol=FUN_000fc91c lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen-side ram dump) corrected by hand: the four texture selections are written out once per slot (a loop is not unrolled by MWCC here because each block calls out), the shared flag is a plain `char` (lb), the registered callback is FUN_000fcb7c (0x10 << 16 with the sign-extended -13444), and the fallback strings are the empty names at 0x2c0e18/1c/20; exact match verified; names and types await human review. */
extern char DAT_0033a040;
extern unsigned char DAT_0033a050;
extern int DAT_0033a054;
extern void *DAT_0033a058;
extern int *DAT_0033a05c;
extern char DAT_0033a044[];
extern char DAT_0033a060[];
extern char DAT_0033a1e0[];
extern char DAT_0033a360[];
extern char DAT_0033a4e0[];
extern void *DAT_002d836c;
extern void *DAT_002d8370;
extern void *DAT_002d8374;
extern void *DAT_002d8378;
extern char DAT_002c0e20[];
extern char DAT_002c0e1c[];
extern char DAT_002c0e18[];
extern int DAT_0034176c;
extern void FUN_00000f74(void *, void (*)(void), void *);
extern void FUN_0010ad1c(void *, int);
extern void *FUN_00198278(int, void *, int, void *);
extern void FUN_000fcb7c(void);

void FUN_000fc91c(int param_1)
{
    int *row;
    void *sel;

    if (DAT_0033a040 == 0) {
        DAT_0033a050 = 0;
        DAT_0033a054 = 0;
        FUN_00000f74(&DAT_0033a050, FUN_000fcb7c, DAT_0033a044);
        DAT_0033a040 = 1;
    }
    FUN_0010ad1c(&DAT_0033a050, param_1);

    if (DAT_0033a054 == 0) {
        sel = DAT_002c0e20;
    } else if (*(int *)((char *)DAT_0033a058 + 8) < 1) {
        sel = DAT_002c0e1c;
    } else if ((row = DAT_0033a05c)[1] < 1) {
        sel = DAT_002c0e18;
    } else {
        sel = *(void **)((char *)row[0] + 0);
    }
    DAT_002d836c = FUN_00198278(DAT_0034176c, sel, 0x180, DAT_0033a060);

    if (DAT_0033a054 == 0) {
        sel = DAT_002c0e20;
    } else if (*(int *)((char *)DAT_0033a058 + 8) < 1) {
        sel = DAT_002c0e1c;
    } else if ((row = DAT_0033a05c)[1] < 2) {
        sel = DAT_002c0e18;
    } else {
        sel = *(void **)((char *)row[0] + 4);
    }
    DAT_002d8370 = FUN_00198278(DAT_0034176c, sel, 0x180, DAT_0033a1e0);

    if (DAT_0033a054 == 0) {
        sel = DAT_002c0e20;
    } else if (*(int *)((char *)DAT_0033a058 + 8) < 1) {
        sel = DAT_002c0e1c;
    } else if ((row = DAT_0033a05c)[1] < 3) {
        sel = DAT_002c0e18;
    } else {
        sel = *(void **)((char *)row[0] + 8);
    }
    DAT_002d8374 = FUN_00198278(DAT_0034176c, sel, 0x180, DAT_0033a360);

    if (DAT_0033a054 == 0) {
        sel = DAT_002c0e20;
    } else if (*(int *)((char *)DAT_0033a058 + 8) < 1) {
        sel = DAT_002c0e1c;
    } else if ((row = DAT_0033a05c)[1] < 4) {
        sel = DAT_002c0e18;
    } else {
        sel = *(void **)((char *)row[0] + 0xc);
    }
    DAT_002d8378 = FUN_00198278(DAT_0034176c, sel, 0x180, DAT_0033a4e0);
}
