/* HSTMATCH module=hstp_trans_main.prx start=0x0026afc0 end=0x0026aff0 symbol=FUN_0026afc0 lang=c99 */
/* Clone of src/eboot/FUN_0011d864.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

void FUN_0026afc0(int *param_1)
{
  int iVar1;
  
  param_1[1] = param_1[1] + -1;
  iVar1 = param_1[2];
  param_1[2] = iVar1 + 1;
  if (iVar1 + 1 == *param_1) {
    param_1[2] = 0;
  }
}
