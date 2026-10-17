/* HSTMATCH module=hstp_trans_main.prx start=0x002b513c end=0x002b5194 symbol=FUN_002b513c lang=c++ */
/* Clone of src/eboot/call_slot3_then_notify_002a59ac.cpp (hstclone.py tag c025707): addresses substituted; exact match verified; names and types await human review. */
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

extern "C" void FUN_00108aec(Obj *);

extern "C" void FUN_002b513c(Obj *o) {
    if (o->b) o->b->s3();
    o->a->s3();
    FUN_00108aec(o);
}
