/* HSTMATCH module=EBOOT.BIN start=0x001d6ccc end=0x001d6db8 symbol=FUN_001d6ccc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" char DAT_0034179c[];
extern "C" char DAT_003093e8[];
extern "C" char DAT_003093b4[];
extern "C" char DAT_00309380[];
extern "C" void *DAT_003386c8;

extern "C" void *FUN_0008d994(void *);
extern "C" void FUN_00103628(void *, int);
extern "C" void FUN_00103480(void *);
extern "C" void FUN_001b3e2c(void *);
extern "C" void FUN_00102ea4(void *, int);
extern "C" void FUN_0026bda4(void *, int);
extern "C" void FUN_002a0e88(void *, int);
extern "C" void FUN_00000a00(void *);

extern "C" void *FUN_001d6ccc(char *p, short n) {
    void *s;
    if (p != 0) {
        *(void **)p = &DAT_003093e8;
        s = FUN_0008d994(DAT_003386c8);
        FUN_00103628(s, 0);
        *(int *)((char *)(**(void ***)((char *)s + 4)) + 100) = 0;
        FUN_00103480(s);
        FUN_001b3e2c(DAT_0034179c);
        void **slot = (void **)p + 0x444;
        if (slot != 0 && ((*(void **)(p + 0x1110) = &DAT_003093b4), slot != 0)) {
            *(void **)(p + 0x1110) = &DAT_00309380;
            FUN_00102ea4(slot, 0);
        }
        FUN_0026bda4(p + 0x530, -1);
        FUN_002a0e88(p + 0x290, -1);
        FUN_00102ea4(p, 0);
        if (n > 0) FUN_00000a00(p);
    }
    return p;
}
