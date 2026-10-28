/* HSTMATCH module=EBOOT.BIN start=0x001183cc end=0x00118424 symbol=FUN_001183cc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int FUN_0011c88c();

int FUN_001183cc(int param_1,short param_2)
{
  if (param_1 != 0) {
    if (param_1 != 0) {
      FUN_0011c88c(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
