/* HSTMATCH module=hstp_trans_main.prx start=0x0019d7e0 end=0x0019d810 symbol=FUN_0019d7e0 lang=c99 */
/* Clone of src/eboot/FUN_0011d864.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */

void FUN_0019d7e0(int *param_1)
{
  int iVar1;
  
  param_1[1] = param_1[1] + -1;
  iVar1 = param_1[2];
  param_1[2] = iVar1 + 1;
  if (iVar1 + 1 == *param_1) {
    param_1[2] = 0;
  }
}
