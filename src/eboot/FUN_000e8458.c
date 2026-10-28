/* HSTMATCH module=EBOOT.BIN start=0x000e8458 end=0x000e8468 symbol=FUN_000e8458 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */

void FUN_000e8458(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
