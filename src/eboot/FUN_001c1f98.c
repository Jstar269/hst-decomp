/* HSTMATCH module=EBOOT.BIN start=0x001c1f98 end=0x001c1ff8 symbol=FUN_001c1f98 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128b); exact match verified; names and types await human review. */

extern int FUN_00000788();
extern void FUN_00000a00();
extern void FUN_0008d07c();

int FUN_001c1f98(int param_1,short param_2)
{
  if ((param_1 != 0) && (FUN_00000788(param_1 + 0x18,FUN_0008d07c,0x120,4), 0 < param_2)) {
    FUN_00000a00(param_1);
  }
  return param_1;
}
