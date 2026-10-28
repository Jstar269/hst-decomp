/* HSTMATCH module=EBOOT.BIN start=0x0014b87c end=0x0014b88c symbol=FUN_0014b87c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_0014b87c(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
