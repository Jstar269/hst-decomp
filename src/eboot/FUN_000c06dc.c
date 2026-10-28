/* HSTMATCH module=EBOOT.BIN start=0x000c06dc end=0x000c06f0 symbol=FUN_000c06dc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */

int FUN_000c06dc(int param_1)
{
  return *(int *)(*(int *)(param_1 + 0x18) + 0x10) - *(int *)(*(int *)(param_1 + 0x18) + 0xc);
}
