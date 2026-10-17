/* HSTMATCH module=EBOOT.BIN start=0x0026370c end=0x0026377c symbol=FUN_0026370c lang=c++ */
/* Clone of src/eboot/deleting_dtor_000ce69c.cpp (hstclone.py tag c46): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct VC { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); };

extern "C" void FUN_00067500(void *, int);
extern "C" void FUN_00000a00(void *);
extern char DAT_00309a88;

extern "C" void *FUN_0026370c(void *p, short flag)
{
    if (p != 0) {
        *(void **)p = &DAT_00309a88;
        ((VC *)p)->s6();
        FUN_00067500(p, 0);
        if (0 < flag) {
            FUN_00000a00(p);
        }
    }
    return p;
}
