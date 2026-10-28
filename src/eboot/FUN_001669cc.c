/* HSTMATCH module=EBOOT.BIN start=0x001669cc end=0x001669dc symbol=FUN_001669cc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_001669cc(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
