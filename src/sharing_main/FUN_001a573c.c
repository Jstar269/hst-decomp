/* HSTMATCH module=hstp_trans_main.prx start=0x001a573c end=0x001a576c symbol=FUN_001a573c lang=c99 */
/* Clone of src/eboot/FUN_00198d38.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */

int FUN_001a573c(int param_1,int param_2)
{
  int iVar1;
  
  if (param_2 >= 0 && (param_2 < 4)) {
    iVar1 = param_1 + param_2 * 8 + 0xa0;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}
