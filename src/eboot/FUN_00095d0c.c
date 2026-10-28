/* HSTMATCH module=EBOOT.BIN start=0x00095d0c end=0x00095d64 symbol=FUN_00095d0c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_000b42f8();

int FUN_00095d0c(int param_1,short param_2)
{
  if (param_1 != 0) {
    if (param_1 != 0) {
      FUN_000b42f8(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
