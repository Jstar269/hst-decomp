/* HSTMATCH module=hstp_trans_main.prx start=0x001fcce8 end=0x001fcd4c symbol=FUN_001fcce8 lang=c99 */
/* Clone of src/eboot/FUN_001ee8ec.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern void FUN_00000a00();
extern int * FUN_000550a0();

int FUN_001fcce8(int param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = param_1 + 0x28;
    if ((iVar1 != 0) && (iVar1 != 0)) {
      FUN_000550a0(iVar1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
