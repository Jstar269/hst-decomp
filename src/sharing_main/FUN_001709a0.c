/* HSTMATCH module=hstp_trans_main.prx start=0x001709a0 end=0x001709e8 symbol=FUN_001709a0 lang=c99 */
/* Clone of src/eboot/FUN_0016442c.c (hstclone.py tag c192707): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern float DAT_003ea814[];

float FUN_001709a0(int param_1, int param_2)
{
  unsigned m = param_2 - 1;
  float f = *(float *)(param_1 + 0x30);

  if ((int)m >= 0 && m < 2)
    f = f * (DAT_003ea814[m] * 0.01f);
  return f;
}
