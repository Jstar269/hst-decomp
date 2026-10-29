/* HSTMATCH module=EBOOT.BIN start=0x001414e4 end=0x001415e8 symbol=FUN_001414e4 lang=c99 */
extern void FUN_000ce8e8(void *p);
extern void FUN_00058694(void *p, void *src);
extern void FUN_00067790(void *a, void *b);
extern char DAT_00307564[];
extern char DAT_0030753C[];

void FUN_001414e4(char *self, void *arg)
{
  char b[112];
  char *p;
  int i, off;

  if (*(int *)(self + 0x7a8) == 0) return;
  for (i = 0; i < *(int *)(self + 0x7a8); i++) {
    off = i * 80;
    p = (char *)(*(int *)(self + 0x7a4) + off);
    FUN_000ce8e8(b);
    *(char **)b = DAT_00307564;
    FUN_00058694(b + 16, p);
    *(int *)(b + 80) = 0;
    *(int *)(b + 84) = 0x3f800000;
    *(int *)(b + 88) = 0x453b8000;
    *(int *)(b + 92) = 0;
    *(char *)(b + 96) = 0;
    *(int *)(b + 80) = *(int *)(p + 0x40);
    *(int *)(b + 84) = 0x3f800000;
    *(int *)(b + 88) = 0x455ac000;
    *(char *)(b + 96) = 0;
    FUN_00067790(arg, b);
    *(char **)b = DAT_0030753C;
  }
}
// near miss from lane dsn3 (unreviewed)
