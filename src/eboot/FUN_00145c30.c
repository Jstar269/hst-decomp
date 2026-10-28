/* HSTMATCH module=EBOOT.BIN start=0x00145c30 end=0x00145c4c symbol=FUN_00145c30 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

int FUN_00145c30(int *param_1)
{
  return *param_1 + param_1[1] * 0x50;
}
