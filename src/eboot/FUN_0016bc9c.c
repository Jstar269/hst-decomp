/* HSTMATCH module=EBOOT.BIN start=0x0016bc9c end=0x0016bcec symbol=FUN_0016bc9c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_0016bc9c.c) corrected by hand: expressed the final status result with explicit 1/0 branches and the positive branch first; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00331c30;
extern u32 DAT_00341518;
extern int FUN_00000bcc();
extern u32 * FUN_0016d194();

int FUN_0016bc9c(void)
{
  int iVar1;
  
  DAT_00331c30 = 0xbc75c28f;
  iVar1 = FUN_00000bcc(0xdbc);
  if (iVar1 != 0) {
    FUN_0016d194(iVar1);
  }
  if (DAT_00341518 != 0) return 1;
  return 0;
}
