/* HSTMATCH module=EBOOT.BIN start=0x00106958 end=0x00106a34 symbol=FUN_00106958 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0027fc70();

void FUN_00106958(int param_1)
{
  if (*(int *)(param_1 + 0xd4) == 2) {
    FUN_0027fc70(param_1 + 0xd8,
                 *(u32 *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xd0) * 4),1);
  }
  else if (*(int *)(param_1 + 0xd4) == 3) {
    FUN_0027fc70(param_1 + 0xd8,*(u32 *)(*(int *)(param_1 + 0x10) + 4),0);
    FUN_0027fc70(param_1 + 0xd8,*(u32 *)(*(int *)(param_1 + 0x10) + 8),1);
  }
  else {
    FUN_0027fc70(param_1 + 0xd8,*(u32 *)(*(int *)(param_1 + 0x10) + 4),0);
    FUN_0027fc70(param_1 + 0xd8,*(u32 *)(*(int *)(param_1 + 0x10) + 8),0);
    FUN_0027fc70(param_1 + 0xd8,*(u32 *)(*(int *)(param_1 + 0x10) + 0xc),0);
    FUN_0027fc70(param_1 + 0xd8,*(u32 *)(*(int *)(param_1 + 0x10) + 0x10),1);
  }
}
