/* HSTMATCH module=EBOOT.BIN start=0x000e5580 end=0x000e5650 symbol=FUN_000e5580 lang=c99 */
extern void __ct__10B_0001f06cFv(void *self);
extern char DAT_00307654;
void FUN_000e5580(char *self)
{
  int i, n;
  char *p;
  __ct__10B_0001f06cFv(self);
  *(void **)self = &DAT_00307654;
  p = self + 60;
  n = 192 - (int)(p - self);
  for (i = 0; i < n; i++) ((char *)self)[60 + i] = 0;
}
// near miss from lane dsn3 (unreviewed)
