/* HSTMATCH module=EBOOT.BIN start=0x0021aa6c end=0x0021aabc symbol=FUN_0021aa6c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern void FUN_0021ab00();

int FUN_0021aa6c(int param_1,short param_2)
{
  if ((param_1 != 0) && (FUN_0021ab00(), 0 < param_2)) {
    FUN_00000a00(param_1);
  }
  return param_1;
}
