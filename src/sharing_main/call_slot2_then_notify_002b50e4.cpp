/* HSTMATCH module=hstp_trans_main.prx start=0x002b50e4 end=0x002b513c symbol=FUN_002b50e4 lang=c++ */
/* Clone of src/eboot/call_slot2_then_notify_002a5954.cpp (hstclone.py tag c025707): addresses substituted; exact match verified; names and types await human review. */
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

extern "C" void FUN_00108a2c(Obj *);

extern "C" void FUN_002b50e4(Obj *o) {
    if (o->b) o->b->s2();
    o->a->s2();
    FUN_00108a2c(o);
}
