/* HSTMATCH module=hstp_trans_main.prx start=0x0029a384 end=0x0029a410 symbol=FUN_0029a384 lang=c++ */
/* Clone of src/eboot/check_sub_id_00288be8.cpp (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: C++ mode, struct member access and virtual method call on slot 11; exact match verified; names and types await human review. */

struct Sub2 {
    char pad[0x40];
    short id;
};

struct Obj {
    virtual int v0();
    virtual int v1();
    virtual int v2();
    virtual int v3();
    virtual int v4();
    virtual int v5();
    virtual int v6();
    virtual int v7();
    virtual int v8();
    virtual int v9();
    virtual int v10();
    virtual int v11();

    char pad[0x60 - 4];
    Sub2 *sub;
};

extern "C" void FUN_0029a410(Obj *param_1);

extern "C" bool FUN_0029a384(Obj *param_1, int param_2)
{
  bool bVar1;
  int iVar2;
  
  iVar2 = param_1->v11();
  bVar1 = iVar2 == 2;
  if (!bVar1) {
    iVar2 = param_1->v11();
    bVar1 = iVar2 == 3;
  }
  if (bVar1) {
    if (param_1->sub == 0) {
      FUN_0029a410(param_1);
    }
    bVar1 = param_1->sub->id == param_2;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}
