/* HSTMATCH module=EBOOT.BIN start=0x001d76d8 end=0x001d7734 symbol=FUN_001d76d8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

#define TWO_PI 6.2831855f

extern float FUN_0000bc34(float angle);

/* Periodic value in 0..1 from step modulo period: (1 - wave(2*pi*phase)) * 0.5. */
float FUN_001d76d8(int step,int period)
{
  float wave;
  
  wave = (float)FUN_0000bc34(((float)(step % period) * TWO_PI) / (float)period);
  return (1.0f - wave) * 0.5f;
}
