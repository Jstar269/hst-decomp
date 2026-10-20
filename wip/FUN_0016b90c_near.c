/* HSTMATCH module=EBOOT.BIN start=0x0016b90c end=0x0016b998 symbol=FUN_0016b90c lang=c99 */
extern int DAT_002e04a0;
extern int DAT_002e04a4;
extern char DAT_00341ccc[];

void FUN_0016b90c(int idx, int val)
{
  unsigned short v = val;
  int bound = *(volatile int *)&DAT_002e04a0;
  unsigned char *e;
  if (v < DAT_002e04a0) {
    ;
  } else {
    bound = *(volatile int *)&DAT_002e04a4;
    if (v > DAT_002e04a4) bound = v;
  }
  idx &= 0xffff;
  if (idx >= 0 && idx < 15) e = (unsigned char *)(DAT_00341ccc + idx * 56 + 200);
  else e = 0;
  *(unsigned char *)(e + 1) = bound;
}
// near miss from lane ds4 (unreviewed)
