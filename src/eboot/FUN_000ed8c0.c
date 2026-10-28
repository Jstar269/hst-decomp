/* HSTMATCH module=EBOOT.BIN start=0x000ed8c0 end=0x000ed8d0 symbol=FUN_000ed8c0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */

void FUN_000ed8c0(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
