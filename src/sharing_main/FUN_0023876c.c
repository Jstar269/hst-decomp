/* HSTMATCH module=hstp_trans_main.prx start=0x0023876c end=0x0023881c symbol=FUN_0023876c lang=c99 */
/* Clone of src/eboot/FUN_002291f8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern void FUN_00238948();
extern void FUN_00238ce8();
extern int FUN_00238fc8();
extern int FUN_00239108();

int FUN_0023876c(int param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    FUN_00238ce8();
    FUN_00238948(param_1);
    iVar1 = param_1 + 0x10;
    if ((((iVar1 != 0) && (iVar1 != 0)) && (iVar1 != 0)) && (iVar1 != 0)) {
      FUN_00239108(iVar1,0);
    }
    if (((param_1 != 0) && (param_1 != 0)) && ((param_1 != 0 && (param_1 != 0)))) {
      FUN_00238fc8(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
