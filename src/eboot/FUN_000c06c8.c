/* HSTMATCH module=EBOOT.BIN start=0x000c06c8 end=0x000c06dc symbol=FUN_000c06c8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */

int FUN_000c06c8(int param_1)
{
  return *(int *)(*(int *)(param_1 + 0x14) + 0x10) - *(int *)(*(int *)(param_1 + 0x14) + 0xc);
}
