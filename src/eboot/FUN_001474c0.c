/* HSTMATCH module=EBOOT.BIN start=0x001474c0 end=0x001474d0 symbol=FUN_001474c0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_001474c0(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
