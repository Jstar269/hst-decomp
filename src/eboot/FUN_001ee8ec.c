/* HSTMATCH module=EBOOT.BIN start=0x001ee8ec end=0x001ee950 symbol=FUN_001ee8ec lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_00054554();

int FUN_001ee8ec(int param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = param_1 + 0x28;
    if ((iVar1 != 0) && (iVar1 != 0)) {
      FUN_00054554(iVar1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
