/* HSTMATCH module=hstp_trans_main.prx start=0x00276c08 end=0x00276c70 symbol=FUN_00276c08 lang=c++ */
/* Clone of src/eboot/FUN_00265d00.cpp (hstclone.py tag u5fr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: reconstructed C++ virtual method calls on the object and subobject, supplied the missing DAT_003e1a08 argument to FUN_0008f170; exact match verified; names and types await human review. */

extern "C" {
extern void *DAT_003e1a08;
extern void *FUN_0008f170(void *);
extern void FUN_0026a188(void *);
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

extern "C" void FUN_00276c08(Obj *self)
{
    FUN_0026a188(self);
    if (self->check()) {
        self->sub.m();
        VC_0 *p = (VC_0 *)FUN_0008f170(DAT_003e1a08);
        p->m();
    }
}
