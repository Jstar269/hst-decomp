/* HSTMATCH module=EBOOT.BIN start=0x00003ed4 end=0x0000411c symbol=FUN_00003ed4 lang=c99 */
typedef unsigned int u32; typedef unsigned char u8;
extern int FUN_00003b30(); extern int FUN_00003ab0(); extern int FUN_0000260c();
extern int FUN_000039e8(); extern int FUN_000030d0(); extern int FUN_00003168();
extern int FUN_00003190(); extern int FUN_00003c50(); extern int FUN_000039b8();
extern int FUN_000031d0(); extern int FUN_000031b0(); extern int FUN_00003994();
extern int FUN_00003978(); extern int FUN_0000411c(); extern int FUN_00003900();
extern int FUN_000038c4(); extern int FUN_0000371c(); extern int FUN_00003880();
extern char DAT_002cf2c4[]; extern char DAT_002cf254[];
void FUN_00003ed4(int p, u32 n)
{
  char buf[12];
  u32 cap = FUN_00003b30();
  char small; u32 len, oldcap, want;
  if (cap < n) { int e = FUN_00003ab0(buf, DAT_002cf2c4); FUN_0000260c(DAT_002cf254, e, FUN_000039e8); }
  small = (char)FUN_000030d0(p);
  if (small == 0) { len = FUN_00003168(p) & 0xff; oldcap = 0xb; }
  else { len = *(u32 *)FUN_00003190(p); oldcap = FUN_00003c50(p); }
  want = len;
  if (len <= n) want = n;
  if (want + 1 < 0xc) want = 0xb;
  else want = FUN_000039b8(want);
  if (want != oldcap) {
    int store, flag, old;
    char *dst;
    if (want == 0xb) { store = FUN_000031d0(p); flag = 0; old = *(int *)FUN_000031b0(p); }
    else {
      store = FUN_00003994(p);
      store = FUN_00003978(store, want, 0);
      flag = 1;
      if (small == 0) old = FUN_000031d0(p); else old = *(int *)FUN_000031b0(p);
    }
    dst = (char *)FUN_0000411c(old, old + len, store);
    *dst = 0;
    if (small != 0) FUN_00003900(FUN_00003994(p), old, oldcap);
    FUN_000038c4(p, flag);
    if (flag == 0) FUN_0000371c(p, len);
    else {
      *(u32 *)FUN_000031b0(p) = store;
      *(u32 *)FUN_00003190(p) = len;
      FUN_00003880(p, want);
    }
  }
}
// near miss from lane fm11 (unreviewed)
