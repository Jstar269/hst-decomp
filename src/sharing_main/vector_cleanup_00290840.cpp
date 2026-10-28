/* HSTMATCH module=hstp_trans_main.prx start=0x00290840 end=0x002908f4 symbol=FUN_00290840 lang=c++ */
/* Clone of src/eboot/vector_cleanup_0027f3cc.cpp (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the deleting virtual call and modeled count clearing through an allocator-tagged shrink; exact match verified; names and types await human review. */

extern "C" void FUN_00000a00(void *);

struct Item {
  virtual void destroy(int);
};
struct AllocatorTag {};
struct VectorView {
  int *data;
  int size;
  void shrink(int n,AllocatorTag tag) { size -= n; }
};

extern "C" int * FUN_00290840(int *param_1,short param_2)
{
  int iVar1;
  Item *piVar2;
  
  if (param_1 != (int *)0x0) {
    iVar1 = param_1[1];
    piVar2 = (Item *)(*param_1 + iVar1 * 0x28);
    ((VectorView *)param_1)->shrink(iVar1,AllocatorTag());
    for (; iVar1 != 0; iVar1 = iVar1 + -1) {
      piVar2 = (Item *)((char *)piVar2 - 0x28);
      piVar2->destroy(-1);
    }
    if (*param_1 != 0) {
      FUN_00000a00((void *)*param_1);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
