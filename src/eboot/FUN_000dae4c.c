/* HSTMATCH module=EBOOT.BIN start=0x000dae4c end=0x000dae5c symbol=FUN_000dae4c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */

void FUN_000dae4c(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
