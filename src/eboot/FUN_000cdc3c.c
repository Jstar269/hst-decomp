/* HSTMATCH module=EBOOT.BIN start=0x000cdc3c end=0x000cdc50 symbol=FUN_000cdc3c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe2); exact match verified; names and types await human review. */

int FUN_000cdc3c(int *param_1)
{
  return *param_1 + param_1[1] * 0x40;
}
