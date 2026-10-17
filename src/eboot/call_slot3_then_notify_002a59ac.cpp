/* HSTMATCH module=EBOOT.BIN start=0x002a59ac end=0x002a5a04 symbol=FUN_002a59ac lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7/v21) corrected by hand: indirect calls rewritten as virtual calls (slot 3, retail vtable offset 0x14) on typed members; exact match verified; names and types await human review. */
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

extern "C" void FUN_001031e8(Obj *);

extern "C" void FUN_002a59ac(Obj *o) {
    if (o->b) o->b->s3();
    o->a->s3();
    FUN_001031e8(o);
}
