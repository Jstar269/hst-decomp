/* HSTMATCH module=EBOOT.BIN start=0x00190268 end=0x00190288 symbol=FUN_00190268 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

int FUN_00190268(int param_1,int param_2)
{
  return *(int *)(param_1 + 0x34) + param_2 * 0x34;
}
