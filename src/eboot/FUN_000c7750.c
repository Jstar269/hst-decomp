/* HSTMATCH module=EBOOT.BIN start=0x000c7750 end=0x000c776c symbol=FUN_000c7750 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */

int FUN_000c7750(int *param_1)
{
  return *param_1 + param_1[1] * 0x18;
}
