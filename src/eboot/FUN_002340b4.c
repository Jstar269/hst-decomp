/* HSTMATCH module=EBOOT.BIN start=0x002340b4 end=0x002340f4 symbol=FUN_002340b4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s64a); exact match verified; names and types await human review. */

extern void FUN_00000a00();

int FUN_002340b4(int param_1,short param_2)
{
  if ((param_1 != 0) && (0 < param_2)) {
    FUN_00000a00();
  }
  return param_1;
}
