/* HSTMATCH module=EBOOT.BIN start=0x00141c10 end=0x00141c2c symbol=FUN_00141c10 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

int FUN_00141c10(int *param_1)
{
  return *param_1 + param_1[1] * 0x50;
}
