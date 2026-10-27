/* HSTMATCH module=EBOOT.BIN start=0x000465dc end=0x00046820 symbol=FUN_000465dc lang=c++ data=0x002d02b8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (15 strings, 0x002d02b8-0x002d0419) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
extern "C" {
extern int DAT_00311020;
extern int DAT_00311024;
extern int DAT_00310fcc;
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
            FUN_00046564("fatal error : sceUmdWaitDriveStat(SCE_UMD_MEDIA_IN) %d\n", r);
            return -1;
        }
    }
    int r = FUN_002b7d08(1, "disc0:");
    if (r < 0) {
        FUN_00046564("fatal error : sceUmdActivate(SCE_UMD_MODE_POWERON, UMD_ALIAS_NAME) %d\n", r);
        return -1;
    }
    FUN_002b7d00(32);
    int id = FUN_002b7920("main", FUN_000468c8, 38, 0x40000, 0x4000, 0);
    DAT_00310fcc = id;
    if (id == (int)0x80020190)
        FUN_00046564("no memory\n");
    else if (id == (int)0x80020191)
        FUN_00046564("illegal attr\n");
    else if (id == (int)0x80020194)
        FUN_00046564("illegal stack size\n");
    else if (id == (int)0x80020064)
        FUN_00046564("illegal context\n");
    else if (id == (int)0x80020193)
        FUN_00046564("illegal priority\n");
    else if (id == (int)0x80020192)
        FUN_00046564("illegal entry\n");
    else if (id == (int)0x800201b9)
        FUN_00046564("spad inuse\n");
    else {
        int s = FUN_002b78d8(id, 0, 0);
        if (s == (int)0x80020198)
            FUN_00046564("unknown thid\n");
        else if (s == (int)0x80020197)
            FUN_00046564("illegal thid\n");
        else if (s == (int)0x80020064)
            FUN_00046564("illegal context\n");
        else if (s == (int)0x800201a4)
            FUN_00046564("not dormant\n");
        else {
            FUN_00046564("initial thread going to sleep, night night!\n");
            FUN_002b79a0();
        }
    }
    FUN_000029e8();
    return 0;
}
