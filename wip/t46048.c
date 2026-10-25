/* HSTMATCH module=EBOOT.BIN start=0x00046048 end=0x00046280 symbol=FUN_00046048 lang=c99 */
typedef unsigned int u32; typedef unsigned char u8;
extern int FUN_0000fe3c(); extern int FUN_0000f3e8(); extern int FUN_0000d518();
extern int FUN_00000bcc(); extern int FUN_000111c0(); extern int FUN_00000a00();
extern char DAT_002d01fc[]; extern char DAT_002bc1a4[];
void FUN_00046048(u32 *p, u32 n)
{
  int small; u32 len, oldcap, want, flag; char *dst, *src; int i2, k;
  if (0x7ffffffe < n) {
    int e = FUN_0000fe3c();
    FUN_0000f3e8(*(u32 *)(e + 0xc), DAT_002d01fc);
    FUN_0000d518();
  }
  small = (*p & 1) == 0;
  if (small) { len = (u8)((u8)*p >> 1); oldcap = 5; }
  else { len = p[1]; oldcap = *p >> 1; }
  want = len;
  if (len <= n) want = n;
  if (want + 1 < 6) want = 5;
  else want = (want + 8) & 0xfffffff8;
  if (want != oldcap) {
    if (want == 5) { src = (char *)p[2]; dst = (char *)p + 2; flag = 0; }
    else {
      dst = (char *)FUN_00000bcc(want << 1);
      if (dst == 0) {
        int e = FUN_0000fe3c();
        FUN_0000f3e8(*(u32 *)(e + 0xc), DAT_002bc1a4);
        FUN_0000d518();
        if (oldcap > want) return;
      }
      flag = 1;
      if (small) src = (char *)p + 2; else src = (char *)p[2];
    }
    i2 = len << 1;
    if ((int)(len * 2) < 0) i2 = len * 2 + 1;
    i2 = (i2 >> 1) * 2;
    FUN_000111c0(dst, src, i2);
    *(dst + i2) = 0; *(dst + i2 + 1) = 0;
    if (!small) FUN_00000a00(src);
    *p = (*p & 0xfffffffe) | flag;
    if (flag == 0) *(u8 *)p = (u8)(*p & 1) | (u8)((len & 0x7f) << 1);
    else { p[2] = (u32)dst; p[1] = len; *p = (*p & 1) | (want << 1); }
  }
}
// near miss from lane fm11 (unreviewed)
