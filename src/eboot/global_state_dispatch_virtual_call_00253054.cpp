/* HSTMATCH module=EBOOT.BIN start=0x00253054 end=0x002530b8 symbol=FUN_00253054 lang=c++ rodata=0x002ca6a8 */
/* Ghidra pseudocode (hstgen.py tag a6) corrected by hand: C++ mode, struct member access and virtual method call on slot 3; exact match verified; names and types await human review. */

struct SubObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

struct Obj {
    SubObj *sub;
    int state;
};

extern "C" Obj *DAT_0034a794;

extern "C" void FUN_00253054(void)
{
    if (DAT_0034a794 != 0) {
        switch (DAT_0034a794->state) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            DAT_0034a794->sub->v3();
            break;
        }
    }
}
