/* HSTMATCH module=EBOOT.BIN start=0x00091800 end=0x00091810 symbol=FUN_00091800 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe1); exact match verified; names and types await human review. */

void FUN_00091800(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
