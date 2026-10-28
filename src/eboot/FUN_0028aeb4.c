/* HSTMATCH module=EBOOT.BIN start=0x0028aeb4 end=0x0028af58 symbol=FUN_0028aeb4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern void FUN_0028b5f4();
extern int * FUN_0028c6f8();
extern int * FUN_0028c7b4();
extern int * FUN_0028c870();

int FUN_0028aeb4(int param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    FUN_0028b5f4();
    iVar1 = param_1 + 0x18;
    if ((iVar1 != 0) && (iVar1 != 0)) {
      FUN_0028c870(iVar1,0);
    }
    iVar1 = param_1 + 0xc;
    if ((iVar1 != 0) && (iVar1 != 0)) {
      FUN_0028c7b4(iVar1,0);
    }
    if ((param_1 != 0) && (param_1 != 0)) {
      FUN_0028c6f8(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
