/* HSTMATCH module=EBOOT.BIN start=0x001281e8 end=0x00128298 symbol=FUN_001281e8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern int DAT_002da900;
extern int DAT_002da904;
extern int FUN_0001342c(void);
void FUN_001281e8(int *self)
{
  unsigned int r = (unsigned int)FUN_0001342c();
  unsigned int bits = r * 0x343fdU + 0x269ec3U;
  unsigned int sample = (bits >> 16) & 0x7fffU;
  float value = (float)DAT_002da900 + (float)sample * (1.0f / 32768.0f) * (float)(DAT_002da904 - DAT_002da900);
  self[0xd1] = (int)value;
}
