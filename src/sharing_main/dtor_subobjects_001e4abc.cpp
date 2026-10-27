/* HSTMATCH module=hstp_trans_main.prx start=0x001e4abc end=0x001e4ba8 symbol=FUN_001e4abc lang=c++ */
/* Hand-written reconstruction (port of src/eboot/dtor_subobjects_001d6ccc.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
extern "C" char DAT_003eaad8[];
extern "C" char DAT_003b26b4[];
extern "C" char DAT_003b2680[];
extern "C" char DAT_003b264c[];
extern "C" void *DAT_003e1a08;

extern "C" void *FUN_0008f170(void *);
extern "C" void FUN_00108f54(void *, int);
extern "C" void FUN_00108dac(void *);
extern "C" void FUN_001c20b8(void *);
extern "C" void FUN_001087a8(void *, int);
extern "C" void FUN_0027cd7c(void *, int);
extern "C" void FUN_002b0294(void *, int);
extern "C" void FUN_00000a00(void *);

extern "C" void *FUN_001e4abc(char *p, short n) {
    void *s;
    if (p != 0) {
        *(void **)p = &DAT_003b26b4;
        s = FUN_0008f170(DAT_003e1a08);
        FUN_00108f54(s, 0);
        *(int *)((char *)(**(void ***)((char *)s + 4)) + 100) = 0;
        FUN_00108dac(s);
        FUN_001c20b8(DAT_003eaad8);
        void **slot = (void **)p + 0x444;
        if (slot != 0 && ((*(void **)(p + 0x1110) = &DAT_003b2680), slot != 0)) {
            *(void **)(p + 0x1110) = &DAT_003b264c;
            FUN_001087a8(slot, 0);
        }
        FUN_0027cd7c(p + 0x530, -1);
        FUN_002b0294(p + 0x290, -1);
        FUN_001087a8(p, 0);
        if (n > 0) FUN_00000a00(p);
    }
    return p;
}
