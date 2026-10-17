/* HSTMATCH module=hstp_trans_main.prx start=0x00133458 end=0x00133508 symbol=FUN_00133458 lang=c99 */
/* Clone of src/eboot/random_range_001281e8.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_00381980;
extern int DAT_00381984;
extern int FUN_0001342c(void);
void FUN_00133458(int *self)
{
  unsigned int r = (unsigned int)FUN_0001342c();
  unsigned int bits = r * 0x343fdU + 0x269ec3U;
  unsigned int sample = (bits >> 16) & 0x7fffU;
  float value = (float)DAT_00381980 + (float)sample * (1.0f / 32768.0f) * (float)(DAT_00381984 - DAT_00381980);
  self[0xd1] = (int)value;
}
