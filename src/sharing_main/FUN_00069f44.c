/* HSTMATCH module=hstp_trans_main.prx start=0x00069f44 end=0x00069fd4 symbol=FUN_00069f44 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int FUN_0006cf54();
extern int * FUN_0006d2a4();

int FUN_00069f44(int param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = param_1 + 0x14;
    if ((((iVar1 != 0) && (iVar1 != 0)) && (iVar1 != 0)) && (iVar1 != 0)) {
      FUN_0006cf54(iVar1,0);
    }
    iVar1 = param_1 + 8;
    if ((iVar1 != 0) && (iVar1 != 0)) {
      FUN_0006d2a4(iVar1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
