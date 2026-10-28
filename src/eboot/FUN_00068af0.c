/* HSTMATCH module=EBOOT.BIN start=0x00068af0 end=0x00068b80 symbol=FUN_00068af0 lang=c99 */
/* Clone of src/sharing_main/FUN_00069f44.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int FUN_0006b96c();
extern int * FUN_0006bcbc();

int FUN_00068af0(int param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = param_1 + 0x14;
    if ((((iVar1 != 0) && (iVar1 != 0)) && (iVar1 != 0)) && (iVar1 != 0)) {
      FUN_0006b96c(iVar1,0);
    }
    iVar1 = param_1 + 8;
    if ((iVar1 != 0) && (iVar1 != 0)) {
      FUN_0006bcbc(iVar1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
