/* HSTMATCH module=EBOOT.BIN start=0x0014f6fc end=0x0014f70c symbol=FUN_0014f6fc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_0014f6fc(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
