/* HSTMATCH module=EBOOT.BIN start=0x0025060c end=0x00250718 symbol=FUN_0025060c lang=c++ */
struct Tag {};
extern "C" int FUN_00250cc4(void *self);
extern "C" void FUN_00250cec(void *self, int idx);
inline int poll(void *self, Tag t) { return FUN_00250cc4(self); }
inline unsigned char *entry(char *self, int idx)
{
  return *(unsigned char **)*(unsigned char **)(*(unsigned char **)(self + 0x350) + idx * 4);
}

extern "C" void FUN_0025060c(char *self)
{
  unsigned char *base;
  unsigned char **p;
  unsigned char *want;
  unsigned char **end;
  int cnt, lim, i, a, b, m;

  if (poll(self, Tag()) != 0) want = entry(self, *(int *)(self + 0x300));
  else want = entry(self, *(int *)(self + 0x2fc));
  cnt = *(int *)(self + 0x354);
  base = *(unsigned char **)(self + 0x350);
  lim = *(int *)(self + 0x308);
  end = (unsigned char **)(base + cnt * 4);
  p = (unsigned char **)base;
  i = 0;
  m = (p == end) ^ 1;
  while (m) {
    if (*(unsigned char **)*p != want) goto next;
    if (lim < 17) {
      *(int *)(self + 0x35c) = i;
      *(int *)(self + 0x364) = 0;
    } else if (!(i + 12 < lim)) {
      *(int *)(self + 0x364) = lim - 16;
      *(int *)(self + 0x35c) = i - (lim - 16);
    } else if (i - 3 > 0) {
      *(int *)(self + 0x35c) = 3;
      *(int *)(self + 0x364) = i - 3;
    } else {
      *(int *)(self + 0x35c) = i;
      *(int *)(self + 0x364) = 0;
    }
    FUN_00250cec(self, i);
    return;
  next:
    p++;
    i++;
    m = (p == end) ^ 1;
  }
}
// near miss from lane dsn3 (unreviewed)
