/* HSTMATCH module=EBOOT.BIN start=0x000d7d60 end=0x000d7d70 symbol=FUN_000d7d60 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */

void FUN_000d7d60(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
