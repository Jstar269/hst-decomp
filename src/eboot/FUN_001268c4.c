/* HSTMATCH module=EBOOT.BIN start=0x001268c4 end=0x001268d8 symbol=FUN_001268c4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

int FUN_001268c4(int param_1)
{
  return *(int *)(*(int *)(param_1 + 0x1c) + 0x10) - *(int *)(*(int *)(param_1 + 0x1c) + 0xc);
}
