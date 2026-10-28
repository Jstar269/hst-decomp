/* HSTMATCH module=hstp_trans_main.prx start=0x001e5484 end=0x001e54e0 symbol=FUN_001e5484 lang=c99 */
/* Clone of src/eboot/FUN_001d76d8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

extern float FUN_0000bc4c(float param_1);

float FUN_001e5484(int param_1,int param_2)
{
  float fVar1;
  
  fVar1 = (float)FUN_0000bc4c(((float)(param_1 % param_2) * 6.2831855f) / (float)param_2);
  return (1.0f - fVar1) * 0.5f;
}
