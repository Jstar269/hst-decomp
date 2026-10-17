/* HSTMATCH module=hstp_trans_main.prx start=0x0020b508 end=0x0020b614 symbol=FUN_0020b508 lang=c++ */
/* Clone of src/eboot/state_dispatch_virtual3_001fcde8.cpp (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
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
extern "C" void FUN_001668dc(int);

extern "C" void FUN_0020b508(Obj *o)
{
    if (o->state == 5)
        return;
    switch (o->state) {
    case 4:
        if (o->f3c->f8c > 0) {
            o->f3c->v3();
        } else {
            FUN_001668dc(o->f48);
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
        FUN_001668dc(o->f48);
        return;
    }
    o->f44->v3();
}
