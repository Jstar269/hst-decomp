/* HSTMATCH module=EBOOT.BIN start=0x001b6a7c end=0x001b6b5c symbol=FUN_001b6a7c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_0034179c;

extern "C" void FUN_001b42b8(void *, int);
extern "C" void FUN_001b8754(void *, int);
extern "C" void FUN_001b87e8(void *, int, int);
extern "C" void FUN_001b94f8(int *, void *, int *, int *);
extern "C" void FUN_000623e8(int, float);

extern "C" void FUN_001b6a7c(char *o) {
    int out;
    int v;
    int p;
    FUN_001b42b8(&DAT_0034179c, 37);
    if (*(int *)(o + 0x84) < 2) {
        FUN_001b8754(o, 1);
        *(int *)(o + 0x84) = 1;
    }
    else {
        FUN_001b87e8(o, 1, 1);
        *(int *)(o + 0x84) = 1;
    }
    p = (int)o + 0x40;
    v = *(int *)(o + 0x44);
    FUN_001b94f8(&out, o + 0x3c, &v, &p);
    FUN_000623e8(2, 0.1f);
    FUN_000623e8(4, 0.1f);
    FUN_000623e8(8, 0.1f);
    *(int *)(o + 0x54) = -1;
    *(int *)(o + 0x50) = -1;
    *(int *)(o + 0x64) = -1;
    *(char *)(o + 0x7b) = 0;
}
