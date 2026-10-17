/* HSTMATCH module=EBOOT.BIN start=0x001fcde8 end=0x001fcef4 symbol=FUN_001fcde8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Iface {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};
struct Dev : Iface {
    char pad[0x88];
    int f8c;
};
struct Obj {
    char pad[0x3c];
    Dev *f3c;
    Iface *f40;
    Iface *f44;
    int f48;
    int state;
};
extern "C" void FUN_0015a304(int);

extern "C" void FUN_001fcde8(Obj *o)
{
    if (o->state == 5)
        return;
    switch (o->state) {
    case 4:
        if (o->f3c->f8c > 0) {
            o->f3c->v3();
        } else {
            FUN_0015a304(o->f48);
        }
        return;
    case 0:
        o->f3c->v3();
        break;
    case 1:
        o->f40->v3();
        break;
    case 2:
    case 3:
        o->f40->v3();
        FUN_0015a304(o->f48);
        return;
    }
    o->f44->v3();
}
