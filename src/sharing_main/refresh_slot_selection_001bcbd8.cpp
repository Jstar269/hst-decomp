/* HSTMATCH module=hstp_trans_main.prx start=0x001bcbd8 end=0x001bccd8 symbol=FUN_001bcbd8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: twin of 0x001bcad8 with updated field offsets and mode arguments; exact match verified; names and types await human review. */

#include "hst/types.h"

extern "C" {
extern void FUN_00105470(...);
extern void FUN_001118ac(...);
extern int FUN_001aa91c(...);
extern void FUN_001ba298(...);
extern void FUN_001ba5cc(...);
extern void FUN_001ba9b8(...);
extern void FUN_001bac6c(...);
extern void FUN_001baf04(...);
}

struct List { int pad; unsigned size; };

extern "C" void FUN_001bcbd8(int param_1)
{
  int iVar7 = *(int *)(param_1 + 0xc);
  FUN_00105470(*(u32 *)(iVar7 + 0x60), 1);
  FUN_001118ac(*(u32 *)(iVar7 + 0x914), 0x18, 0x1d);
  unsigned uVar5 = *(unsigned *)(FUN_001aa91c() + 0x2dc);
  int iVar2 = FUN_001aa91c();
  List *pl = (List *)(iVar2 + 0x360);
  unsigned uVar6 = 0;
  if (*(int *)(iVar2 + 0x364) != 0) {
    int iVar4 = 0;
    do {
      int *puVar2 = (int *)(iVar7 + (iVar4 + 0x7bc)) + 9;
      if (uVar5 == uVar6) {
        FUN_00105470(*puVar2, 0);
      }
      else {
        FUN_00105470(*puVar2, 1);
      }
      uVar6 = uVar6 + 1;
      iVar4 = iVar4 + 0x14;
    } while (uVar6 < pl->size);
  }
  FUN_001ba298(iVar7, 0);
  FUN_001ba5cc(iVar7, 0);
  FUN_001ba9b8(iVar7, 0);
  FUN_001bac6c(iVar7, 1);
  FUN_001baf04(iVar7, 0);
}
