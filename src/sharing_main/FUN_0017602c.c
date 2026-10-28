/* HSTMATCH module=hstp_trans_main.prx start=0x0017602c end=0x00176064 symbol=FUN_0017602c lang=c99 */
/* Clone of src/eboot/FUN_00169e68.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */

void FUN_0017602c(float *param_1,float *param_2,float *param_3,float *param_4)
{
  *param_1 = *param_2;
  param_1[1] = *param_3;
  param_1[3] = *param_4;
  param_1[2] = (*param_3 + *param_2) / 2.0f;
}
