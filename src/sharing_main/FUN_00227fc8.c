/* HSTMATCH module=hstp_trans_main.prx start=0x00227fc8 end=0x00227ffc symbol=FUN_00227fc8 lang=c99 */
/* Clone of src/eboot/FUN_00218ab0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

int FUN_00227fc8(int param_1)
{
  int iVar1;
  
  if (param_1 == 500) {
    iVar1 = 9;
  }
  else {
    iVar1 = param_1 / 10;
  }
  return iVar1;
}
