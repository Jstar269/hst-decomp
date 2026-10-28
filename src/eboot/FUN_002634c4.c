/* HSTMATCH module=EBOOT.BIN start=0x002634c4 end=0x00263558 symbol=FUN_002634c4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003415ac;
extern u8 DAT_0034a678;
extern void FUN_00103628();
extern void FUN_00234158();
extern void FUN_002815c4();

void FUN_002634c4(int param_1)
{
  FUN_00103628(DAT_003415ac,1);
  *(u32 *)(*(int *)(param_1 + 0x640) + 0x61c) =
       *(u32 *)(*(int *)(param_1 + 0x58) + 0xdc);
  FUN_002815c4(*(u32 *)(param_1 + 0x640));
  if ((*(int *)(*(int *)(param_1 + 0x640) + 0x80) == 1) &&
     (*(int *)(*(int *)(param_1 + 0x640) + 0x61c) == 2)) {
    FUN_00234158(&DAT_0034a678,0x40);
  }
  else {
    FUN_00234158(&DAT_0034a678,0x3f);
  }
}
