/* HSTMATCH module=EBOOT.BIN start=0x0008ab10 end=0x0008ac88 symbol=FUN_0008ab10 lang=c99 */
extern unsigned char DAT_003386B8;
extern void *DAT_00348C20;
extern void *DAT_00348B44;
extern char *DAT_002CFC8C;
extern int FUN_000fb7b8(void *p);
extern int FUN_001181c0(void *p);
extern int FUN_000def58(void *p);

void FUN_0008ab10(char *self)
{
  unsigned char g = DAT_003386B8;
  int r = 0;
  int st, f;

  if (g != 0 && *(int *)(self + 0x6c) > 0) {
    if (FUN_000fb7b8(DAT_00348C20) == 0) {
      if (*(unsigned char *)(self + 0x4c) == 0) {
        st = *(int *)(self + 0x3c);
        if (st == 6) {
          if (FUN_001181c0(*(void **)(self + 0x9c)) >= 0)
            r = FUN_000def58(DAT_00348B44) <= 0;
        } else if (st == 7 || st == 5) {
          r = FUN_001181c0(*(void **)(self + 0x9c)) >= 0;
        }
      }
    }
  }
  if (r != 0) r = *(unsigned char *)(self + 0x59) == 0;
  if (r == 0) return;
  f = *(int *)(DAT_002CFC8C + 139);
  if (((f << 24) >> 30) == 0) *(unsigned char *)(self + 0x59) = 1;
  st = *(int *)(self + 0x3c);
  if (st == 7) {
    f = *(int *)(DAT_002CFC8C + 139);
    if (((f << 30) >> 30) == 0) *(unsigned char *)(self + 0x59) = 1;
  }
}
// near miss from lane dsn3 (unreviewed)
