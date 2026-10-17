/* HSTMATCH module=EBOOT.BIN start=0x000ce69c end=0x000ce70c symbol=FUN_000ce69c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct VC { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); };

extern "C" void FUN_00067500(void *, int);
extern "C" void FUN_00000a00(void *);
extern char DAT_00307578;

extern "C" void *FUN_000ce69c(void *p, short flag)
{
    if (p != 0) {
        *(void **)p = &DAT_00307578;
        ((VC *)p)->s6();
        FUN_00067500(p, 0);
        if (0 < flag) {
            FUN_00000a00(p);
        }
    }
    return p;
}
