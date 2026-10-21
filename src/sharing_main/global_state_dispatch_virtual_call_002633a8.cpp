/* HSTMATCH module=hstp_trans_main.prx start=0x002633a8 end=0x0026340c symbol=FUN_002633a8 lang=c++ rodata=0x002dac68 */
/* Clone of src/eboot/global_state_dispatch_virtual_call_00253054.cpp (hstclone.py tag ds1011s2): addresses substituted; exact match verified; names and types await human review. */
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

extern "C" Obj *DAT_003f3ac4;

extern "C" void FUN_002633a8(void)
{
    if (DAT_003f3ac4 != 0) {
        switch (DAT_003f3ac4->state) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            DAT_003f3ac4->sub->v3();
            break;
        }
    }
}
