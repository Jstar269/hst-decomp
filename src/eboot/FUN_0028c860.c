/* HSTMATCH module=EBOOT.BIN start=0x0028c860 end=0x0028c870 symbol=FUN_0028c860 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_0028c860(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
