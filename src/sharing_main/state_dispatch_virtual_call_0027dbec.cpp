/* HSTMATCH module=hstp_trans_main.prx start=0x0027dbec end=0x0027dc40 symbol=FUN_0027dbec lang=c++ rodata=0x002daf4c */
/* Clone of src/eboot/state_dispatch_virtual_call_0026cbac.cpp (hstclone.py tag ds1011s2): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: C++ mode, struct member access and virtual method call on slot 3; exact match verified; names and types await human review. */

struct SubObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

struct Obj {
    char pad[0xbb8];
    SubObj *sub;
    char pad2[0xc];
    int state;
};

extern "C" void FUN_0027dbec(Obj *param_1)
{
    switch (param_1->state) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        param_1->sub->v3();
        break;
    default:
        break;
    }
}
