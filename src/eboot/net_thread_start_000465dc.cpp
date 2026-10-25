/* HSTMATCH module=EBOOT.BIN start=0x000465dc end=0x00046820 symbol=FUN_000465dc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
extern int DAT_00311020;
extern int DAT_00311024;
extern int DAT_00310fcc;
extern char DAT_002d02b8[];
extern char DAT_002d02f0[];
extern char DAT_002d02f8[];
extern char DAT_002d0340[];
extern char DAT_002d0348[];
extern char DAT_002d0354[];
extern char DAT_002d0364[];
extern char DAT_002d0378[];
extern char DAT_002d038c[];
extern char DAT_002d03a0[];
extern char DAT_002d03b0[];
extern char DAT_002d03bc[];
extern char DAT_002d03cc[];
extern char DAT_002d03dc[];
extern char DAT_002d03ec[];
void FUN_000029f0(void);
void FUN_000029e8(void);
int FUN_002b7ce8(void);
int FUN_002b7d00(int);
int FUN_002b7d08(int, const char *);
void FUN_00046564(const char *, ...);
int FUN_000468c8(int, void *);
int FUN_002b7920(const char *, int (*)(int, void *), int, int, int, void *);
int FUN_002b78d8(int, int, void *);
void FUN_002b79a0(void);
}

extern "C" int FUN_000465dc(int a, int b)
{
    FUN_000029f0();
    DAT_00311020 = a;
    DAT_00311024 = b;
    if (FUN_002b7ce8() == 0) {
        int r = FUN_002b7d00(2);
        if (r != 0) {
            FUN_00046564(DAT_002d02b8, r);
            return -1;
        }
    }
    int r = FUN_002b7d08(1, DAT_002d02f0);
    if (r < 0) {
        FUN_00046564(DAT_002d02f8, r);
        return -1;
    }
    FUN_002b7d00(32);
    int id = FUN_002b7920(DAT_002d0340, FUN_000468c8, 38, 0x40000, 0x4000, 0);
    DAT_00310fcc = id;
    if (id == (int)0x80020190)
        FUN_00046564(DAT_002d0348);
    else if (id == (int)0x80020191)
        FUN_00046564(DAT_002d0354);
    else if (id == (int)0x80020194)
        FUN_00046564(DAT_002d0364);
    else if (id == (int)0x80020064)
        FUN_00046564(DAT_002d0378);
    else if (id == (int)0x80020193)
        FUN_00046564(DAT_002d038c);
    else if (id == (int)0x80020192)
        FUN_00046564(DAT_002d03a0);
    else if (id == (int)0x800201b9)
        FUN_00046564(DAT_002d03b0);
    else {
        int s = FUN_002b78d8(id, 0, 0);
        if (s == (int)0x80020198)
            FUN_00046564(DAT_002d03bc);
        else if (s == (int)0x80020197)
            FUN_00046564(DAT_002d03cc);
        else if (s == (int)0x80020064)
            FUN_00046564(DAT_002d0378);
        else if (s == (int)0x800201a4)
            FUN_00046564(DAT_002d03dc);
        else {
            FUN_00046564(DAT_002d03ec);
            FUN_002b79a0();
        }
    }
    FUN_000029e8();
    return 0;
}
