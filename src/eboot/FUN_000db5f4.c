/* HSTMATCH module=EBOOT.BIN start=0x000db5f4 end=0x000db64c symbol=FUN_000db5f4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int FUN_000db544();

int FUN_000db5f4(int param_1,short param_2)
{
  if (param_1 != 0) {
    if (param_1 != 0) {
      FUN_000db544(param_1,0xffffffff);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
