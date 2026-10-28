/* HSTMATCH module=hstp_trans_main.prx start=0x0026a770 end=0x0026a79c symbol=FUN_0026a770 lang=c99 */
/* Clone of src/eboot/FUN_0025a2c0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

int * FUN_0026a770(int *param_1)
{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = iVar1 + 4;
  if (iVar1 + 4 == param_1[3]) {
    *param_1 = param_1[1];
  }
  return param_1;
}
