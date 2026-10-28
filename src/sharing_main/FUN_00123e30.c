/* HSTMATCH module=hstp_trans_main.prx start=0x00123e30 end=0x00123e74 symbol=FUN_00123e30 lang=c99 */
/* Clone of src/eboot/FUN_00118c5c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */

void FUN_00123e30(int *param_1,int *param_2)
{
  int iVar1;
  
  *param_1 = param_2[3] + param_2[2] * 4;
  iVar1 = param_2[3];
  param_1[1] = iVar1;
  param_1[2] = iVar1 + param_2[2] * 4;
  param_1[3] = param_1[1] + *param_2 * 4;
}
