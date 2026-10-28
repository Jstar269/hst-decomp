/* HSTMATCH module=EBOOT.BIN start=0x000d5798 end=0x000d57a8 symbol=FUN_000d5798 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */

void FUN_000d5798(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
