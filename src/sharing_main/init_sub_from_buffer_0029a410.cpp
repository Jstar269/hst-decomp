/* HSTMATCH module=hstp_trans_main.prx start=0x0029a410 end=0x0029a490 symbol=FUN_0029a410 lang=c++ data=0x003a7a48 */
/* Clone of src/eboot/init_sub_from_buffer_00288c74.cpp (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x003a7a48-0x003a7a56) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: C++ mode, struct member access and virtual method call on slot 11; exact match verified; names and types await human review. */

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

    char pad[0x34 - 4];
    int arg1;
    int arg2;
    char pad2[0x60 - 0x3c];
    Sub2 *sub;
};

extern "C" void FUN_000143b0(void*, const void*, int, int);
extern "C" Sub2* FUN_0019f834(void*);

extern "C" void FUN_0029a410(Obj *param_1)
{
  bool bVar1;
  int iVar2;
  char auStack_40[64];
  
  iVar2 = param_1->v11();
  bVar1 = iVar2 == 2;
  if (!bVar1) {
    iVar2 = param_1->v11();
    bVar1 = iVar2 == 3;
  }
  if (bVar1) {
    FUN_000143b0(auStack_40, "Npc_%03d_%02d", param_1->arg1, param_1->arg2);
    param_1->sub = FUN_0019f834(auStack_40);
  }
}
