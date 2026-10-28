/* HSTMATCH module=EBOOT.BIN start=0x000da3d4 end=0x000da3e4 symbol=FUN_000da3d4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */

void FUN_000da3d4(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
