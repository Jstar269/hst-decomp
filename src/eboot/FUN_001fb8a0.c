/* HSTMATCH module=EBOOT.BIN start=0x001fb8a0 end=0x001fb8b0 symbol=FUN_001fb8a0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

void FUN_001fb8a0(int param_1)
{
  *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + 1;
}
