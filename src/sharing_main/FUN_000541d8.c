/* HSTMATCH module=hstp_trans_main.prx start=0x000541d8 end=0x00054260 symbol=FUN_000541d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern void FUN_000544f8();
extern int * FUN_000550a0();
extern int * FUN_0005514c();

int FUN_000541d8(int param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    FUN_000544f8();
    iVar1 = param_1 + 0x24;
    if ((iVar1 != 0) && (iVar1 != 0)) {
      FUN_0005514c(iVar1,0);
    }
    iVar1 = param_1 + 0x18;
    if ((iVar1 != 0) && (iVar1 != 0)) {
      FUN_000550a0(iVar1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
