/* HSTMATCH module=EBOOT.BIN start=0x00293a74 end=0x00293acc symbol=FUN_00293a74 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_00294020();

int FUN_00293a74(int param_1,short param_2)
{
  if (param_1 != 0) {
    if (param_1 != 0) {
      FUN_00294020(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
