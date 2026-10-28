/* HSTMATCH module=EBOOT.BIN start=0x00235c04 end=0x00235c84 symbol=FUN_00235c04 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_00165840();

int FUN_00235c04(int param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = param_1 + 0xc;
    if ((iVar1 != 0) && (iVar1 != 0)) {
      FUN_00165840(iVar1,0);
    }
    if ((param_1 != 0) && (param_1 != 0)) {
      FUN_00165840(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
