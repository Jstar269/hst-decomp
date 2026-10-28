/* HSTMATCH module=EBOOT.BIN start=0x00238c1c end=0x00238c2c symbol=FUN_00238c1c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_00238c1c(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
