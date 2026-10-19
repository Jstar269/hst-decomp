/* HSTMATCH module=hstp_trans_main.prx start=0x001d05fc end=0x001d06dc symbol=FUN_001d05fc lang=c++ */
/* Clone of src/eboot/deleting_dtor_001c23b8.cpp (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct GObj { virtual ~GObj(); };

extern "C" char DAT_003b2608;
extern "C" char DAT_003b261c;
extern "C" GObj *DAT_003f3b4c;
extern "C" void __dl__FPv(void *);

extern "C" void FUN_001d1ef0(void *);
extern "C" void FUN_001d1e1c(void *);
extern "C" void FUN_001d1e6c(void *);
extern "C" void FUN_001d1e74(void *);
extern "C" void FUN_001d1e14(void *);
extern "C" void FUN_001d1da4(void *);
extern "C" void FUN_001d1e24(void *);
extern "C" void FUN_0023876c(void *, int);

extern "C" void *FUN_001d05fc(char *p, short flag) {
    if (p != 0) {
        *(void **)p = &DAT_003b2608;
        if (DAT_003f3b4c != 0) {
            delete DAT_003f3b4c;
            DAT_003f3b4c = 0;
        }
        FUN_001d1ef0(p);
        FUN_001d1e1c(p);
        FUN_001d1e6c(p);
        FUN_001d1e74(p);
        FUN_001d1e14(p);
        FUN_001d1da4(p);
        FUN_001d1e24(p);
        FUN_0023876c(p + 0x34, -1);
        if (p != 0) *(void **)p = &DAT_003b261c;
        if (flag > 0) __dl__FPv(p);
    }
    return p;
}
