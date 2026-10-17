/* HSTMATCH module=EBOOT.BIN start=0x00288be8 end=0x00288c74 symbol=FUN_00288be8 lang=c++ */
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

extern "C" void FUN_00288c74(Obj *param_1);

extern "C" bool FUN_00288be8(Obj *param_1, int param_2)
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
      FUN_00288c74(param_1);
    }
    bVar1 = param_1->sub->id == param_2;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}
