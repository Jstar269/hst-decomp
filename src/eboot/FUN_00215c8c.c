/* HSTMATCH module=EBOOT.BIN start=0x00215c8c end=0x00215c9c symbol=FUN_00215c8c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_00215c8c(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
