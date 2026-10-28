/* HSTMATCH module=EBOOT.BIN start=0x0011931c end=0x001193bc symbol=FUN_0011931c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: loop index declared before the member pointer (s-register order); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern int * FUN_0011aa84(...);
extern int * FUN_0011b5c4(...);
}
struct VC_0 { virtual ~VC_0(); };

extern "C" void FUN_0011931c(int param_1)
{
  int iVar3;
  int iVar2;
  int *piVar1;
  
  iVar3 = 0;
  iVar2 = param_1;
  do {
    piVar1 = *(int **)(iVar2 + 0x48);
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      *(u32 *)(iVar2 + 0x48) = 0;
    }
    iVar3 = iVar3 + 1;
    iVar2 = iVar2 + 4;
  } while (iVar3 < 0x1b);
  if (*(int *)(param_1 + 0x3c) != 0) {
    FUN_0011aa84(*(int *)(param_1 + 0x3c),1);
    *(u32 *)(param_1 + 0x3c) = 0;
  }
  iVar2 = *(int *)(param_1 + 0x40);
  if (iVar2 != 0) {
    FUN_0011b5c4(iVar2,1);
    *(u32 *)(param_1 + 0x40) = 0;
  }
}
