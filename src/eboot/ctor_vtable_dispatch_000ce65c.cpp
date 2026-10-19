/* HSTMATCH module=EBOOT.BIN start=0x000ce65c end=0x000ce69c symbol=FUN_000ce65c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" void FUN_00067498(void *);
extern "C" void *DAT_00307578[8];

struct VObj {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
};

extern "C" void *FUN_000ce65c(void *p)
{
    FUN_00067498(p);
    *(void **)p = DAT_00307578;
    ((VObj *)p)->m5();
    return p;
}
