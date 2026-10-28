/* HSTMATCH module=hstp_trans_main.prx start=0x001db84c end=0x001db8a4 symbol=FUN_001db84c lang=c99 */
/* Clone of src/eboot/allocate_indexed_copy_001cd0e4.c (hstclone.py tag u5cr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reused the allocation result for the conditional copy and return; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00000bcc();
extern u32 * FUN_0029b9cc();

u32 FUN_001db84c(int param_1,int param_2)
{
  int value = *(int *)(*(int *)(param_1 + 0x180) + param_2 * 4);
  int result;

  if (value == 0) return 0;
  result = FUN_00000bcc(0x100);
  if (result != 0) result = (int)FUN_0029b9cc((int *)result,value);
  return (u32)result;
}
