/* HSTMATCH module=hstp_trans_main.prx start=0x000d2298 end=0x000d2308 symbol=FUN_000d2298 lang=c++ */
/* Clone of src/eboot/deleting_dtor_000ce69c.cpp (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct VC { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); };

extern "C" void FUN_00068954(void *, int);
extern "C" void FUN_00000a00(void *);
extern char DAT_003b0844;

extern "C" void *FUN_000d2298(void *p, short flag)
{
    if (p != 0) {
        *(void **)p = &DAT_003b0844;
        ((VC *)p)->s6();
        FUN_00068954(p, 0);
        if (0 < flag) {
            FUN_00000a00(p);
        }
    }
    return p;
}
