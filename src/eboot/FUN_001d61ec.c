/* HSTMATCH module=EBOOT.BIN start=0x001d61ec end=0x001d6200 symbol=FUN_001d61ec lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

int FUN_001d61ec(int param_1)
{
  return (int)(short)(*(short *)(param_1 + 10) - *(short *)(param_1 + 6));
}
