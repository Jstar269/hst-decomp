/* HSTMATCH module=EBOOT.BIN start=0x0004f374 end=0x0004f540 symbol=FUN_0004f374 lang=c99 */
extern void FUN_00049194(void);
extern void FUN_000491cc(void);
extern int FUN_0002fecc(int);
extern int FUN_0002fed8(int, int);
extern void FUN_0004ea98(const char *);
extern int FUN_0004f6b4(int, int, int, int, int, int, int, int);
extern int FUN_00039914(int, int, int);
extern int FUN_00035094(int, int, int);
extern void FUN_0004f010(int, int, const char *, int, void *);

extern char DAT_002d0d44;
extern char DAT_002d0d60;
extern char DAT_002d0da0;
extern char DAT_002d0d80;
extern char DAT_002d0a6c;
extern int DAT_002d0d40;
extern int DAT_00311170;

void FUN_0004f374(int param_1, int param_2, int param_3, int param_4, int param_5)
{
    int i1;
    int i3;
    int i2;
    int i4;

    i4 = 0;
    FUN_00049194();
    i1 = FUN_0002fecc(param_2);
    FUN_000491cc();
    if (i1 < 0) {
        FUN_0004ea98(&DAT_002d0d44);
    } else {
        i3 = 0;
        if (0 < i1) {
            do {
                FUN_00049194();
                i2 = FUN_0002fed8(param_2, i3);
                FUN_000491cc();
                if (i2 == 0) {
                    FUN_0004ea98(&DAT_002d0d60);
                    goto done;
                }
                i2 = FUN_0004f6b4(param_1, i2, param_3, param_4, 0, param_5, 0x40, 1);
                if (i2 < 0)
                    goto done;
                i3 = i3 + 1;
            } while (i3 < i1);
        }
        FUN_00049194();
        i4 = FUN_00039914(param_1, param_1 + 0x204, 0x240);
        FUN_000491cc();
        if (i4 == 0) {
            FUN_00049194();
            i4 = FUN_00035094(param_2, param_1 + 0x204, 0x240);
            FUN_000491cc();
            if (i4 == 0)
                return;
            FUN_0004ea98(&DAT_002d0da0);
        } else {
            FUN_0004ea98(&DAT_002d0d80);
        }
    }
done:
    FUN_0004f010(DAT_00311170, i4, &DAT_002d0a6c, 0x4af, &DAT_002d0d40);
}
// near miss from lane fm11 (unreviewed)
