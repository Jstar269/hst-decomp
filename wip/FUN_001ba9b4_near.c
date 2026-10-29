/* HSTMATCH module=EBOOT.BIN start=0x001ba9b4 end=0x001baac0 symbol=FUN_001ba9b4 lang=c99 */
extern int FUN_001feec4(void);
extern unsigned char FUN_001baf80(int p);
extern void FUN_002060f8(int a0, int a1, void *a2, int a3, int a4, int a5, int a6);

void FUN_001ba9b4(char *self, int idx, int **arr)
{
  char *e = (char *)*arr + idx * 48;
  char *o;
  unsigned char r;
  int first, el, b0, b1, b2, is2;
  short s66, s68, s70, s72, s74;

  if (*(unsigned char *)e == 0) return;
  o = (char *)FUN_001feec4();
  first = *(short *)(o + 64);
  {
  char buf[24] = {0};
  *(int *)(buf + 0) = first;
  *(int *)(buf + 4) = *(short *)(o + 66);
  *(int *)(buf + 8) = *(short *)(o + 68);
  *(int *)(buf + 12) = *(short *)(o + 70);
  *(int *)(buf + 16) = *(short *)(o + 72);
  *(int *)(buf + 20) = *(short *)(o + 74);
  r = FUN_001baf80(*(int *)(*(int *)(*(int *)(self + 4) + idx * 4) + 4));
  el = *(int *)(*(int *)(self + 4) + idx * 4);
  b0 = *(unsigned char *)(o + 0xde);
  b1 = *(unsigned char *)(o + 0xdc);
  b2 = *(unsigned char *)(o + 0xdd);
  is2 = (*(unsigned char *)(o + 0xa6) ^ 2) == 0;
  FUN_002060f8(el, r, buf, b0, b1, b2, is2);
  *(char *)(self + idx + 0x10) = 1;
  *(char *)(self + idx + 0x14) = 0;
  }
}
// near miss from lane dsn3 (unreviewed)
