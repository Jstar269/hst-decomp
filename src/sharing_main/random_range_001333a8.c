/* HSTMATCH module=hstp_trans_main.prx start=0x001333a8 end=0x00133458 symbol=FUN_001333a8 lang=c99 */
/* Clone of src/eboot/random_range_00128138.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_00381978;
extern int DAT_0038197c;
extern int FUN_0001342c(void);
void FUN_001333a8(int *self)
{
  unsigned int r = (unsigned int)FUN_0001342c();
  unsigned int bits = r * 0x343fdU + 0x269ec3U;
  unsigned int sample = (bits >> 16) & 0x7fffU;
  float value = (float)DAT_00381978 + (float)sample * (1.0f / 32768.0f) * (float)(DAT_0038197c - DAT_00381978);
  self[0xd0] = (int)value;
}
