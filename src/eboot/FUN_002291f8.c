/* HSTMATCH module=EBOOT.BIN start=0x002291f8 end=0x002292a8 symbol=FUN_002291f8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern void FUN_002293d4();
extern void FUN_00229774();
extern int FUN_00229a54();
extern int FUN_00229b94();

int FUN_002291f8(int param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    FUN_00229774();
    FUN_002293d4(param_1);
    iVar1 = param_1 + 0x10;
    if ((((iVar1 != 0) && (iVar1 != 0)) && (iVar1 != 0)) && (iVar1 != 0)) {
      FUN_00229b94(iVar1,0);
    }
    if (((param_1 != 0) && (param_1 != 0)) && ((param_1 != 0 && (param_1 != 0)))) {
      FUN_00229a54(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
