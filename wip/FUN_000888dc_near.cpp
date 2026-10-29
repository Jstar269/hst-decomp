/* HSTMATCH module=EBOOT.BIN start=0x000888dc end=0x000889ec symbol=FUN_000888dc lang=c++ */
extern unsigned char DAT_003386B8;
extern void *DAT_00348C20;
extern void *DAT_00348B44;
extern "C" int FUN_000fb7b8(void *p);
extern "C" int FUN_001181c0(void *p);
extern "C" int FUN_000def58(void *p);

extern "C" bool FUN_000888dc(char *self)
{
  unsigned char g = DAT_003386B8;
  bool r;
  int st;

  if (g != 0) {
    if (*(int *)(self + 0x6c) <= 0) return false;
    if (FUN_000fb7b8(DAT_00348C20) != 0) return false;
  }
  if (*(unsigned char *)(self + 0x4c) != 0) return false;
  st = *(int *)(self + 0x3c);
  if (st == 6) {
    if (FUN_001181c0(*(void **)(self + 0x9c)) >= 0) r = FUN_000def58(DAT_00348B44) <= 0;
    else r = false;
  } else if (st == 7 || st == 5) {
    r = FUN_001181c0(*(void **)(self + 0x9c)) >= 0;
  } else {
    r = false;
  }
  if (!r) return false;
  return *(unsigned char *)(self + 0x59) == 0;
}
// near miss from lane dsn3 (unreviewed)
