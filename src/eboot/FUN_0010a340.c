/* HSTMATCH module=EBOOT.BIN start=0x0010a340 end=0x0010a350 symbol=FUN_0010a340 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */

void FUN_0010a340(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
