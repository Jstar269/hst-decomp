/* HSTMATCH module=EBOOT.BIN start=0x0026377c end=0x002637c0 symbol=FUN_0026377c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: C++ virtual method call on slot 6, typed helper call; exact match verified; names and types await human review. */

struct VC {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
};

extern "C" char DAT_002fde6c[];
extern "C" char DAT_002fde8c[];
extern "C" void FUN_00067e54(const void*, const void*, int, int, int);

extern "C" void FUN_0026377c(VC *param_1)
{
  param_1->v6();
  FUN_00067e54(DAT_002fde6c, DAT_002fde8c, 0x20, 0, 0);
}
