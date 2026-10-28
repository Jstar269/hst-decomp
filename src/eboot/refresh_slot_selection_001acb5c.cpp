/* HSTMATCH module=EBOOT.BIN start=0x001acb5c end=0x001acc30 symbol=FUN_001acb5c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5, variant v17) corrected by hand: the loop bound read through a pointer to the sub-object at +0x360 (reloaded each iteration), the element address written (param_1 + (offset + 0x7bc)) + 9 words, locals declared counter/selected/offset; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_000ffb3c(...);
extern void FUN_0010b980(...);
extern u32 FUN_0019d474(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };
struct List { int pad; unsigned size; };
struct Obj { char pad[0x360]; List l; };

extern "C" void FUN_001acb5c(int param_1,int param_2)
{
  int iVar1;
  int *puVar2;
  List *pl;
  unsigned uVar6;
  unsigned uVar5;
  int iVar4;

  iVar1 = FUN_0019d474();
  uVar5 = *(unsigned *)(iVar1 + 0x2dc);
  if (param_2 != 0) {
    ((VC_0 *)(*(int **)(param_1 + 0x914)))->m((int)(0));
    FUN_0010b980(*(u32 *)(param_1 + 0x914),uVar5,0);
  }
  iVar1 = FUN_0019d474();
  pl = (List *)(iVar1 + 0x360);
  uVar6 = 0;
  if (*(int *)(iVar1 + 0x364) != 0) {
    iVar4 = 0;
    do {
      puVar2 = (int *)(param_1 + (iVar4 + 0x7bc)) + 9;
      if (uVar5 == uVar6) {
        FUN_000ffb3c(*puVar2,0);
      }
      else {
        FUN_000ffb3c(*puVar2,1);
      }
      uVar6 = uVar6 + 1;
      iVar4 = iVar4 + 0x14;
    } while (uVar6 < pl->size);
  }
}
