/* HSTMATCH module=hstp_trans_main.prx start=0x002745f8 end=0x0027463c symbol=FUN_002745f8 lang=c++ */
/* Clone of src/eboot/virtual_callback_notify_0026377c.cpp (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
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

extern "C" char DAT_003a6ac0[];
extern "C" char DAT_003a6ae0[];
extern "C" void FUN_000692a8(const void*, const void*, int, int, int);

extern "C" void FUN_002745f8(VC *param_1)
{
  param_1->v6();
  FUN_000692a8(DAT_003a6ac0, DAT_003a6ae0, 0x20, 0, 0);
}
