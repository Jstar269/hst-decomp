/* HSTMATCH module=EBOOT.BIN start=0x00294554 end=0x00294564 symbol=FUN_00294554 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_00294554(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
