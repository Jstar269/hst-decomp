/* HSTMATCH module=EBOOT.BIN start=0x001d7690 end=0x001d76a0 symbol=FUN_001d7690 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_001d7690(int param_1,int param_2)
{
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x28) + param_2;
}
