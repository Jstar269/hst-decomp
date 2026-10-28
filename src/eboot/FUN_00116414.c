/* HSTMATCH module=EBOOT.BIN start=0x00116414 end=0x00116424 symbol=FUN_00116414 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */

void FUN_00116414(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
