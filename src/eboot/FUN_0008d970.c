/* HSTMATCH module=EBOOT.BIN start=0x0008d970 end=0x0008d994 symbol=FUN_0008d970 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe1); exact match verified; names and types await human review. */

int FUN_0008d970(int param_1,int param_2)
{
  return *(int *)(param_1 + 0x3c) + param_2 * 0x1b0 + 0x10;
}
