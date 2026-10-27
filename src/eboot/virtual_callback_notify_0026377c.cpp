/* HSTMATCH module=EBOOT.BIN start=0x0026377c end=0x002637c0 symbol=FUN_0026377c lang=c++ data=0x002fde6c */
/* LoadCourtParticleLists: data/court/particle/{texlist,motlist}.csv; see docs/DATA-TABLES.md Data: its string literals (2 strings, 0x002fde6c-0x002fdeac) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern "C" void FUN_00067e54(const void*, const void*, int, int, int);

extern "C" void FUN_0026377c(VC *param_1)
{
  param_1->v6();
  FUN_00067e54("data/court/particle/texlist.csv", "data/court/particle/motlist.csv", 0x20, 0, 0);
}
