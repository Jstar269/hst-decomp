/* HSTMATCH module=EBOOT.BIN start=0x00128138 end=0x001281e8 symbol=FUN_00128138 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_002da8f8;
extern int DAT_002da8fc;
extern int FUN_0001342c(void);
void FUN_00128138(int *self)
{
  unsigned int r = (unsigned int)FUN_0001342c();
  unsigned int bits = r * 0x343fdU + 0x269ec3U;
  unsigned int sample = (bits >> 16) & 0x7fffU;
  float value = (float)DAT_002da8f8 + (float)sample * (1.0f / 32768.0f) * (float)(DAT_002da8fc - DAT_002da8f8);
  self[0xd0] = (int)value;
}
