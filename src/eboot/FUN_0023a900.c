/* HSTMATCH module=EBOOT.BIN start=0x0023a900 end=0x0023a928 symbol=FUN_0023a900 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

extern void FUN_0023c338();

void FUN_0023a900(int param_1)
{
  if (0 < *(int *)(param_1 + 0x3c)) {
    FUN_0023c338(param_1 + 0x50);
  }
}
