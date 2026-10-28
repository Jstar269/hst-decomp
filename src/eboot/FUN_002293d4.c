/* HSTMATCH module=EBOOT.BIN start=0x002293d4 end=0x0022942c symbol=FUN_002293d4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000009e4();
extern void FUN_000643e8();
extern void FUN_0022995c();

void FUN_002293d4(int param_1)
{
  int local_4;
  
  local_4 = *(int *)(param_1 + 0xc);
  if (local_4 != param_1 + 4) {
    do {
      FUN_000009e4(*(u32 *)(local_4 + 0xc));
      FUN_000643e8(&local_4);
    } while (local_4 != param_1 + 4);
  }
  FUN_0022995c(param_1);
}
