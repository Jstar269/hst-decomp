/* HSTMATCH module=hstp_trans_main.prx start=0x00274588 end=0x002745f8 symbol=FUN_00274588 lang=c++ */
/* Clone of src/eboot/deleting_dtor_000ce69c.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct VC { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); };

extern "C" void FUN_00068954(void *, int);
extern "C" void FUN_00000a00(void *);
extern char DAT_003b2d70;

extern "C" void *FUN_00274588(void *p, short flag)
{
    if (p != 0) {
        *(void **)p = &DAT_003b2d70;
        ((VC *)p)->s6();
        FUN_00068954(p, 0);
        if (0 < flag) {
            FUN_00000a00(p);
        }
    }
    return p;
}
