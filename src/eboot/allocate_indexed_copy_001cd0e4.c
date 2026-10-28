/* HSTMATCH module=EBOOT.BIN start=0x001cd0e4 end=0x001cd13c symbol=FUN_001cd0e4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reused the allocation result for the conditional copy and return; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00000bcc();
extern u32 * FUN_0028a230();

u32 FUN_001cd0e4(int param_1,int param_2)
{
  int value = *(int *)(*(int *)(param_1 + 0x180) + param_2 * 4);
  int result;

  if (value == 0) return 0;
  result = FUN_00000bcc(0x100);
  if (result != 0) result = (int)FUN_0028a230((int *)result,value);
  return (u32)result;
}
