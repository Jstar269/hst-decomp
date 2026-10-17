/* HSTMATCH module=EBOOT.BIN start=0x001e611c end=0x001e617c symbol=FUN_001e611c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: the two member addresses are taken into locals before the branch; names and types await human review. */
extern "C" void FUN_000ffb3c(void *p, int v);
struct Holder {
    void *w;
    int pad[4];
    void Set(int v) { FUN_000ffb3c(w, v); }
};
struct Obj {
    char pad0[0x1a84];
    Holder h0;
    Holder h1;
};
extern "C" void FUN_001e611c(Obj *o, int enable)
{
    Holder *a = &o->h0;
    Holder *b = &o->h1;
    if (enable != 0) {
        a->Set(0);
        b->Set(0);
    } else {
        a->Set(1);
        b->Set(1);
    }
}
