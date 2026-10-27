/* HSTMATCH module=hstp_trans_main.prx start=0x002745f8 end=0x0027463c symbol=FUN_002745f8 lang=c++ data=0x003a6ac0 */
/* Clone of src/eboot/virtual_callback_notify_0026377c.cpp (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x003a6ac0-0x003a6b00) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

extern "C" void FUN_000692a8(const void*, const void*, int, int, int);

extern "C" void FUN_002745f8(VC *param_1)
{
  param_1->v6();
  FUN_000692a8("data/court/particle/texlist.csv", "data/court/particle/motlist.csv", 0x20, 0, 0);
}
