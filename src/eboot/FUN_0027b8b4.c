/* HSTMATCH module=EBOOT.BIN start=0x0027b8b4 end=0x0027b8c4 symbol=FUN_0027b8b4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_0027b8b4(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
