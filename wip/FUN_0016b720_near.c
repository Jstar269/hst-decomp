/* HSTMATCH module=EBOOT.BIN start=0x0016b720 end=0x0016b7d0 symbol=FUN_0016b720 lang=c99 */
extern int DAT_002e0478;
extern int DAT_002e047c;
extern void *FUN_0016bb88(int a, int b);
void FUN_0016b720(int idx, int value)
{
  void *base = FUN_0016bb88(idx, value);
  unsigned short v = (unsigned short)value;
  char *p;
  if (v < DAT_002e0478) v = (unsigned short)DAT_002e0478;
  else if (v > DAT_002e047c) v = (unsigned short)DAT_002e047c;
  if (idx < 0) p = 0;
  else if (idx >= 15) p = 0;
  else p = (char *)base + idx * 56 + 4;
  *(short *)(p + 2) = v;
}
// near miss from lane dsn3 (unreviewed)
