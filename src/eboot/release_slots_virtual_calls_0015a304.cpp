/* HSTMATCH module=EBOOT.BIN start=0x0015a304 end=0x0015a3cc symbol=FUN_0015a304 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: byte flag unsigned char (lbu), the two indirect calls written as C++ virtual calls (slot 3), loop index declared before the walking pointer for the s-registers; exact match verified; names and types await human review. */
typedef unsigned char uchar;

extern "C" void FUN_0015a3cc(...);

struct VC_0 {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
};

extern "C" void FUN_0015a304(int param_1)
{
  VC_0 *piVar1;
  int iVar3;
  int iVar2;
  
  if ((*(uchar *)(param_1 + 0x1c) == '\0') ||
     (((*(int *)(param_1 + 0x18) == 0 && (*(int *)(param_1 + 0x14) != 8)) &&
      (*(int *)(param_1 + 0x14) != 3)))) {
    if (*(VC_0 **)(param_1 + 0x24) != (VC_0 *)0x0) {
      (*(VC_0 **)(param_1 + 0x24))->v3();
    }
    piVar1 = *(VC_0 **)(param_1 + 0x28);
    if (piVar1 != (VC_0 *)0x0) {
      piVar1->v3();
    }
    iVar3 = 0;
    iVar2 = param_1;
    do {
      if (*(int *)(iVar2 + 0x34) != 0) {
        FUN_0015a3cc(param_1,*(int *)(iVar2 + 0x34),iVar3);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar3 < 3);
  }
  return;
}
