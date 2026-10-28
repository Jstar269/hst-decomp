/* HSTMATCH module=EBOOT.BIN start=0x00166234 end=0x00166244 symbol=FUN_00166234 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_00166234(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
