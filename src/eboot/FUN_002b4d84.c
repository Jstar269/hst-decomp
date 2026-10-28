/* HSTMATCH module=EBOOT.BIN start=0x002b4d84 end=0x002b4d94 symbol=FUN_002b4d84 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_002b4d84(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
