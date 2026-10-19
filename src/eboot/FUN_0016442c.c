/* HSTMATCH module=EBOOT.BIN start=0x0016442c end=0x00164474 symbol=FUN_0016442c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern float DAT_003414d4[];

float FUN_0016442c(int param_1, int param_2)
{
  unsigned m = param_2 - 1;
  float f = *(float *)(param_1 + 0x30);

  if ((int)m >= 0 && m < 2)
    f = f * (DAT_003414d4[m] * 0.01f);
  return f;
}
