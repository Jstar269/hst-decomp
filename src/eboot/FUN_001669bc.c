/* HSTMATCH module=EBOOT.BIN start=0x001669bc end=0x001669cc symbol=FUN_001669bc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_001669bc(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
