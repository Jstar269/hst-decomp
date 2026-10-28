/* HSTMATCH module=hstp_trans_main.prx start=0x0016e74c end=0x0016e76c symbol=FUN_0016e74c lang=c99 */
/* Clone of src/eboot/FUN_001621c0.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */

float FUN_0016e74c(int param_1,int param_2)
{
  float fVar1;
  
  fVar1 = *(float *)(param_1 + 0x16c);
  if (param_2 - 1U < 2) {
    fVar1 = fVar1 + *(float *)(param_1 + 0x3c4);
  }
  return fVar1;
}
