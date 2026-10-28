/* HSTMATCH module=EBOOT.BIN start=0x00169e28 end=0x00169e68 symbol=FUN_00169e28 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

extern void FUN_00000a00();

int FUN_00169e28(int param_1,short param_2)
{
  if ((param_1 != 0) && (0 < param_2)) {
    FUN_00000a00();
  }
  return param_1;
}
