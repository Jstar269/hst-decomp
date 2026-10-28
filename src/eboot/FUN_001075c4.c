/* HSTMATCH module=EBOOT.BIN start=0x001075c4 end=0x001075d4 symbol=FUN_001075c4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */

void FUN_001075c4(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
