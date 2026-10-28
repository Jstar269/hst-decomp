/* HSTMATCH module=EBOOT.BIN start=0x00147374 end=0x00147384 symbol=FUN_00147374 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_00147374(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
