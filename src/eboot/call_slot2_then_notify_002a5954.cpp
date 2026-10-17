/* HSTMATCH module=EBOOT.BIN start=0x002a5954 end=0x002a59ac symbol=FUN_002a5954 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7/v21) corrected by hand: indirect calls rewritten as virtual calls (slot 2, retail vtable offset 0x10) on typed members; exact match verified; names and types await human review. */
struct VC {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
};

struct Obj {
    char pad0[0x54];
    VC *a;
    char pad1[0x80];
    VC *b;
};

extern "C" void FUN_00103128(Obj *);

extern "C" void FUN_002a5954(Obj *o) {
    if (o->b) o->b->s2();
    o->a->s2();
    FUN_00103128(o);
}
