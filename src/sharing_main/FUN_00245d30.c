/* HSTMATCH module=hstp_trans_main.prx start=0x00245d30 end=0x00245db0 symbol=FUN_00245d30 lang=c99 */
/* Clone of src/eboot/FUN_00235c04.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_00171a30();

int FUN_00245d30(int param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = param_1 + 0xc;
    if ((iVar1 != 0) && (iVar1 != 0)) {
      FUN_00171a30(iVar1,0);
    }
    if ((param_1 != 0) && (param_1 != 0)) {
      FUN_00171a30(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
