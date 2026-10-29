/* HSTMATCH module=hstp_trans_main.prx start=0x001e5484 end=0x001e54e0 symbol=FUN_001e5484 lang=c99 */
/* Clone of src/eboot/FUN_001d76d8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */

#define TWO_PI 6.2831855f

extern float FUN_0000bc4c(float angle);

/* Periodic value in 0..1 from step modulo period: (1 - wave(2*pi*phase)) * 0.5. */
float FUN_001e5484(int step,int period)
{
  float wave;
  
  wave = (float)FUN_0000bc4c(((float)(step % period) * TWO_PI) / (float)period);
  return (1.0f - wave) * 0.5f;
}
