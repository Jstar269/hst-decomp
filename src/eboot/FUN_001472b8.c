/* HSTMATCH module=EBOOT.BIN start=0x001472b8 end=0x001472c8 symbol=FUN_001472b8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_001472b8(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
