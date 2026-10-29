/* HSTMATCH module=EBOOT.BIN start=0x001e7198 end=0x001e71c4 symbol=FUN_001e7198 lang=c99 */
int FUN_001e7198(int self)
{
  int a = *(int *)(self + 0x1d64);
  if (a) {
    int b = *(int *)(a + 0x16c);
    if (!b) return -1;
    return *(int *)(b + 0x6c);
  }
  return -1;
}
// near miss from lane dsn3 (unreviewed)
