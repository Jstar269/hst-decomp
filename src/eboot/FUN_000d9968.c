/* HSTMATCH module=EBOOT.BIN start=0x000d9968 end=0x000d99b8 symbol=FUN_000d9968 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int FUN_00004138();

int FUN_000d9968(int param_1,short param_2)
{
  if ((param_1 != 0) && (FUN_00004138(param_1,0xffffffff), 0 < param_2)) {
    FUN_00000a00(param_1);
  }
  return param_1;
}
