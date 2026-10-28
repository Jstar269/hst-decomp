/* HSTMATCH module=EBOOT.BIN start=0x001af500 end=0x001af600 symbol=FUN_001af500 lang=c++ */
/* Clone of src/sharing_main/refresh_slot_selection_001bcbd8.cpp (hstclone.py tag u3r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: twin of 0x001bcad8 with updated field offsets and mode arguments; exact match verified; names and types await human review. */

#include "hst/types.h"

extern "C" {
extern void FUN_000ffb3c(...);
extern void FUN_0010b6d4(...);
extern int FUN_0019d474(...);
extern void FUN_001acc30(...);
extern void FUN_001acf64(...);
extern void FUN_001ad350(...);
extern void FUN_001ad604(...);
extern void FUN_001ad89c(...);
}

struct List { int pad; unsigned size; };

extern "C" void FUN_001af500(int param_1)
{
  int iVar7 = *(int *)(param_1 + 0xc);
  FUN_000ffb3c(*(u32 *)(iVar7 + 0x60), 1);
  FUN_0010b6d4(*(u32 *)(iVar7 + 0x914), 0x18, 0x1d);
  unsigned uVar5 = *(unsigned *)(FUN_0019d474() + 0x2dc);
  int iVar2 = FUN_0019d474();
  List *pl = (List *)(iVar2 + 0x360);
  unsigned uVar6 = 0;
  if (*(int *)(iVar2 + 0x364) != 0) {
    int iVar4 = 0;
    do {
      int *puVar2 = (int *)(iVar7 + (iVar4 + 0x7bc)) + 9;
      if (uVar5 == uVar6) {
        FUN_000ffb3c(*puVar2, 0);
      }
      else {
        FUN_000ffb3c(*puVar2, 1);
      }
      uVar6 = uVar6 + 1;
      iVar4 = iVar4 + 0x14;
    } while (uVar6 < pl->size);
  }
  FUN_001acc30(iVar7, 0);
  FUN_001acf64(iVar7, 0);
  FUN_001ad350(iVar7, 0);
  FUN_001ad604(iVar7, 1);
  FUN_001ad89c(iVar7, 0);
}
