/* HSTMATCH module=EBOOT.BIN start=0x0014fb58 end=0x0014fb68 symbol=FUN_0014fb58 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_0014fb58(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
