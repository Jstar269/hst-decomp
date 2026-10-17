/* HSTMATCH module=EBOOT.BIN start=0x00265d00 end=0x00265d68 symbol=FUN_00265d00 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: reconstructed C++ virtual method calls on the object and subobject, supplied the missing DAT_003386c8 argument to FUN_0008d994; exact match verified; names and types await human review. */

extern "C" {
extern void *DAT_003386c8;
extern void *FUN_0008d994(void *);
extern void FUN_00259cd8(void *);
}

struct VC_0 {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void m();
};

struct Obj {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual int check();
    char pad[6240 - 4];
    VC_0 sub;
};

extern "C" void FUN_00265d00(Obj *self)
{
    FUN_00259cd8(self);
    if (self->check()) {
        self->sub.m();
        VC_0 *p = (VC_0 *)FUN_0008d994(DAT_003386c8);
        p->m();
    }
}
