/* HSTMATCH module=EBOOT.BIN start=0x001c23b8 end=0x001c2498 symbol=FUN_001c23b8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct GObj { virtual ~GObj(); };

extern "C" char DAT_0030933c;
extern "C" char DAT_00309350;
extern "C" GObj *DAT_0034a81c;
extern "C" void __dl__FPv(void *);

extern "C" void FUN_001c3b64(void *);
extern "C" void FUN_001c3a90(void *);
extern "C" void FUN_001c3ae0(void *);
extern "C" void FUN_001c3ae8(void *);
extern "C" void FUN_001c3a88(void *);
extern "C" void FUN_001c3a18(void *);
extern "C" void FUN_001c3a98(void *);
extern "C" void FUN_002291f8(void *, int);

extern "C" void *FUN_001c23b8(char *p, short flag) {
    if (p != 0) {
        *(void **)p = &DAT_0030933c;
        if (DAT_0034a81c != 0) {
            delete DAT_0034a81c;
            DAT_0034a81c = 0;
        }
        FUN_001c3b64(p);
        FUN_001c3a90(p);
        FUN_001c3ae0(p);
        FUN_001c3ae8(p);
        FUN_001c3a88(p);
        FUN_001c3a18(p);
        FUN_001c3a98(p);
        FUN_002291f8(p + 0x34, -1);
        if (p != 0) *(void **)p = &DAT_00309350;
        if (flag > 0) __dl__FPv(p);
    }
    return p;
}
