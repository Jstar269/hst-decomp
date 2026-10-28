/* HSTMATCH module=EBOOT.BIN start=0x00068a54 end=0x00068af0 symbol=FUN_00068a54 lang=c99 */
/* Clone of src/sharing_main/FUN_00069ea8.c (hstclone.py tag u1ae): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: expressed the guard as param_1 + 4 != 0; matching idiom: retained repeated null guards to match the retail branch sequence; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int FUN_0006b96c();
extern int * FUN_0006bcbc();

int FUN_00068a54(int param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    if ((param_1 + 4) != 0) {
      iVar1 = param_1 + 0x18;
      if ((((iVar1 != 0) && (iVar1 != 0)) && (iVar1 != 0)) && (iVar1 != 0)) {
        FUN_0006b96c(iVar1,0);
      }
      iVar1 = param_1 + 0xc;
      if ((iVar1 != 0) && (iVar1 != 0)) {
        FUN_0006bcbc(iVar1,0);
      }
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
