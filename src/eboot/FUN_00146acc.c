/* HSTMATCH module=EBOOT.BIN start=0x00146acc end=0x00146adc symbol=FUN_00146acc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_00146acc(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
