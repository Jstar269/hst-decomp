/* HSTMATCH module=EBOOT.BIN start=0x002b2dcc end=0x002b2e3c symbol=FUN_002b2dcc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
class Base {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

struct Self {
    char pad0[0x3c];
    Base f3c;
    char pad1[0x90 - 0x40];
    unsigned char f90;
    char pad2[0x38c - 0x91];
    Base *f38c;
    char pad3[0x4a8 - 0x390];
    Base *f4a8;
};

extern "C" void FUN_002b2dcc(Self *self)
{
    if (self->f90 != 0)
        return;
    self->f3c.v3();
    if (self->f38c != 0)
        self->f38c->v3();
    if (self->f4a8 != 0)
        self->f4a8->v3();
}
