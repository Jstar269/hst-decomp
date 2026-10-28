/* HSTMATCH module=EBOOT.BIN start=0x00289cf4 end=0x00289d60 symbol=FUN_00289cf4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern void FUN_00289e84();
extern int * FUN_0028c98c();

int FUN_00289cf4(int param_1,short param_2)
{
  if (param_1 != 0) {
    FUN_00289e84();
    if ((param_1 != 0) && (param_1 != 0)) {
      FUN_0028c98c(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
