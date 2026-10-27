/* HSTMATCH module=hstp_trans_main.prx start=0x00102058 end=0x001022b8 symbol=FUN_00102058 lang=c99 */
/* Hand-written reconstruction (port of src/eboot/page_textures_000fc91c.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen-side ram dump) corrected by hand: the four texture selections are written out once per slot (a loop is not unrolled by MWCC here because each block calls out), the shared flag is a plain `char` (lb), the registered callback is FUN_001022b8 (0x10 << 16 with the sign-extended -13444), and the fallback strings are the empty names at 0x2d10cc/1c/20; exact match verified; names and types await human review. */
extern char DAT_003e3380;
extern unsigned char DAT_003e3390;
extern int DAT_003e3394;
extern void *DAT_003e3398;
extern int *DAT_003e339c;
extern char DAT_003e3384[];
extern char DAT_003e33a0[];
extern char DAT_003e3520[];
extern char DAT_003e36a0[];
extern char DAT_003e3820[];
extern void *DAT_0037f18c;
extern void *DAT_0037f190;
extern void *DAT_0037f194;
extern void *DAT_0037f198;
extern char DAT_002d10d4[];
extern char DAT_002d10d0[];
extern char DAT_002d10cc[];
extern int DAT_003eaaac;
extern void FUN_00000f74(void *, void (*)(void), void *);
extern void FUN_00110adc(void *, int);
extern void *FUN_001a4bcc(int, void *, int, void *);
extern void FUN_001022b8(void);

void FUN_00102058(int param_1)
{
    int *row;
    void *sel;

    if (DAT_003e3380 == 0) {
        DAT_003e3390 = 0;
        DAT_003e3394 = 0;
        FUN_00000f74(&DAT_003e3390, FUN_001022b8, DAT_003e3384);
        DAT_003e3380 = 1;
    }
    FUN_00110adc(&DAT_003e3390, param_1);

    if (DAT_003e3394 == 0) {
        sel = DAT_002d10d4;
    } else if (*(int *)((char *)DAT_003e3398 + 8) < 1) {
        sel = DAT_002d10d0;
    } else if ((row = DAT_003e339c)[1] < 1) {
        sel = DAT_002d10cc;
    } else {
        sel = *(void **)((char *)row[0] + 0);
    }
    DAT_0037f18c = FUN_001a4bcc(DAT_003eaaac, sel, 0x180, DAT_003e33a0);

    if (DAT_003e3394 == 0) {
        sel = DAT_002d10d4;
    } else if (*(int *)((char *)DAT_003e3398 + 8) < 1) {
        sel = DAT_002d10d0;
    } else if ((row = DAT_003e339c)[1] < 2) {
        sel = DAT_002d10cc;
    } else {
        sel = *(void **)((char *)row[0] + 4);
    }
    DAT_0037f190 = FUN_001a4bcc(DAT_003eaaac, sel, 0x180, DAT_003e3520);

    if (DAT_003e3394 == 0) {
        sel = DAT_002d10d4;
    } else if (*(int *)((char *)DAT_003e3398 + 8) < 1) {
        sel = DAT_002d10d0;
    } else if ((row = DAT_003e339c)[1] < 3) {
        sel = DAT_002d10cc;
    } else {
        sel = *(void **)((char *)row[0] + 8);
    }
    DAT_0037f194 = FUN_001a4bcc(DAT_003eaaac, sel, 0x180, DAT_003e36a0);

    if (DAT_003e3394 == 0) {
        sel = DAT_002d10d4;
    } else if (*(int *)((char *)DAT_003e3398 + 8) < 1) {
        sel = DAT_002d10d0;
    } else if ((row = DAT_003e339c)[1] < 4) {
        sel = DAT_002d10cc;
    } else {
        sel = *(void **)((char *)row[0] + 0xc);
    }
    DAT_0037f198 = FUN_001a4bcc(DAT_003eaaac, sel, 0x180, DAT_003e3820);
}
