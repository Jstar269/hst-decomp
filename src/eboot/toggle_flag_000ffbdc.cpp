/* HSTMATCH module=EBOOT.BIN start=0x000ffbdc end=0x000ffc3c symbol=FUN_000ffbdc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Target {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
};

struct Obj {
    char pad[14];
    unsigned short flags;
    char pad2[16];
    Target *target;

    bool IsSet() const {
        return (flags & 2) != 0;
    }
};

extern "C" void FUN_000ffbdc(Obj *self)
{
    if (self->IsSet() ^ true) {
        self->flags |= 2;
    } else {
        self->flags &= ~2;
    }
    if (self->target != 0) {
        self->target->m3();
    }
}
