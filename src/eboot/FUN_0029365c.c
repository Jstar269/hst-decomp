/* HSTMATCH module=EBOOT.BIN start=0x0029365c end=0x0029368c symbol=FUN_0029365c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00059174();
extern void FUN_0005f0d8();

void FUN_0029365c(int param_1)
{
  u32 uVar1;
  
  uVar1 = *(u32 *)(param_1 + 0x78);
  FUN_00059174(uVar1);
  FUN_0005f0d8(uVar1);
}
