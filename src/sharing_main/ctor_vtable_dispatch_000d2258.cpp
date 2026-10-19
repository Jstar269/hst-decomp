/* HSTMATCH module=hstp_trans_main.prx start=0x000d2258 end=0x000d2298 symbol=FUN_000d2258 lang=c++ */
/* Clone of src/eboot/ctor_vtable_dispatch_000ce65c.cpp (hstclone.py tag ds1018ar2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" void FUN_000688ec(void *);
extern "C" void *DAT_003b0844[8];

struct VObj {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
};

extern "C" void *FUN_000d2258(void *p)
{
    FUN_000688ec(p);
    *(void **)p = DAT_003b0844;
    ((VObj *)p)->m5();
    return p;
}
