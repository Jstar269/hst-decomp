/* HSTMATCH module=EBOOT.BIN start=0x0008b1a8 end=0x0008b1b8 symbol=FUN_0008b1a8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe1); exact match verified; names and types await human review. */

void FUN_0008b1a8(int param_1,int param_2)
{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) - param_2;
}
