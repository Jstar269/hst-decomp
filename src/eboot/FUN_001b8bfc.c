/* HSTMATCH module=EBOOT.BIN start=0x001b8bfc end=0x001b8c54 symbol=FUN_001b8bfc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0200_001b8bfc_m12.c); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001b94f8();
extern u32 * FUN_001b9708();

int FUN_001b8bfc(int param_1)
{
  u32 uStack_4;
  int local_8;
  int local_c;
  
  FUN_001b9708((u32 *)param_1);
  *(u8 *)(param_1 + 0xc) = 0;
  local_c = param_1 + 4;
  local_8 = *(int *)(param_1 + 8);
  FUN_001b94f8(&uStack_4,(int *)param_1,&local_8,&local_c);
  *(u32 *)(param_1 + 0x10) = 9;
  return param_1;
}
