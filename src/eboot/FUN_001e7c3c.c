/* HSTMATCH module=EBOOT.BIN start=0x001e7c3c end=0x001e7c64 symbol=FUN_001e7c3c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

extern void FUN_00103628();

void FUN_001e7c3c(int param_1)
{
  if (*(int *)(param_1 + 0x2464) != 0) {
    FUN_00103628(*(int *)(param_1 + 0x2464),1);
  }
}
