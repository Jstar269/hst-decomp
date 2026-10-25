/* HSTMATCH module=EBOOT.BIN start=0x00218c00 end=0x00218f98 symbol=FUN_00218c00 lang=c99 */
typedef unsigned int u32; typedef unsigned short u16;
extern int FUN_00000bcc(); extern int FUN_0004e780(); extern int FUN_00051050();
extern int FUN_00051450(); extern int FUN_00000a90(); extern int FUN_000008d8();
extern int FUN_0005a500(); extern int FUN_0005a650(); extern int FUN_0006de18();
extern int FUN_00192ce0(); extern int FUN_0006dc58(); extern int FUN_0005a670();
extern int FUN_0001342c(); extern int FUN_00054330(); extern int FUN_00219150();
extern int FUN_002190e4(); extern char DAT_002efb30[]; extern char DAT_0034a154;
extern char DAT_002c9850[];
u32 *FUN_00218c00(u32 *p)
{
  int a4, a8, m1[4], m2[4], m3[4], m4[4], m5[4], m6[4], v1[4];
  int i, n, e; u32 v, k;
  p[0] = 0; p[1] = 0; p[2] = 0;
  v = FUN_00000bcc(0x48);
  if (v == 0) v = 0;
  else v = FUN_00051050(v, DAT_002efb30, FUN_0004e780(&a4, &a8, 1, 0, 8, 8), 0);
  *p = v;
  {
    u16 *q = (u16 *)FUN_00051450(v);
    int j = 0;
    do {
      q[0] = 0xffff; q[1] = 0xffff; q[2] = 0xffff; q[3] = 0xffff;
      q[4] = 0xffff; q[5] = 0xffff; q[6] = 0xffff; q[7] = 0xffff;
      j += 8; q += 8;
    } while (j < 0x40);
  }
  p[1] = FUN_000008d8(FUN_00000a90(0x7d10), FUN_00219150, FUN_002190e4, 0xa0, 200);
  k = 0; n = 0;
  do {
    e = p[1] + n;
    FUN_0005a500(e, 1, 4, 0, 1, 0);
    FUN_0005a650(e);
    FUN_00192ce0(e, 0, FUN_0006de18(0xbccccccc, 0xbccccccc, 0, 0x3f800000, m1));
    FUN_00192ce0(e, 1, FUN_0006de18(0xbccccccc, 0x3ccccccc, 0, 0x3f800000, m2));
    FUN_00192ce0(e, 2, FUN_0006de18(0x3ccccccc, 0xbccccccc, 0, 0x3f800000, m3));
    FUN_00192ce0(e, 3, FUN_0006de18(0x3ccccccc, 0x3ccccccc, 0, 0x3f800000, m4));
    if (DAT_0034a154 == 0) {
      FUN_0006de18(0x43480000, 0, 0, 0x43000000, &DAT_002c9850[0]);
      FUN_0006de18(0, 0x41a00000, 0x43480000, 0x43000000, &DAT_002c9850[0x10]);
      FUN_0006de18(0x43750000, 0x43780000, 0, 0x43000000, &DAT_002c9850[0x20]);
      FUN_0006de18(0, 0x43560000, 0x41700000, 0x43000000, &DAT_002c9850[0x30]);
      FUN_0006de18(0x43640000, 0, 0x431c0000, 0x43000000, &DAT_002c9850[0x40]);
      FUN_0006de18(0, 0x436a0000, 0x436d0000, 0x43000000, &DAT_002c9850[0x50]);
      FUN_0006de18(0x43750000, 0x432d0000, 0, 0x43000000, &DAT_002c9850[0x60]);
      DAT_0034a154 = 1;
    }
    {
      u32 *pv = (u32 *)(DAT_002c9850 + (k % 7) * 0x10);
      FUN_0006dc58(e, 0, pv); FUN_0006dc58(e, 1, pv);
      FUN_0006dc58(e, 2, pv); FUN_0006dc58(e, 3, pv);
    }
    FUN_0005a670(e, 4);
    {
      int r = FUN_0001342c();
      float f = (1.0f - ((float)r * 2.0f) / 2147483648.0f) * 2.5f;
      int r2 = FUN_0001342c(0x4f000000, 0x40000000);
      int r3 = FUN_0001342c();
      u32 m = FUN_0006de18(f, ((float)r3 / 2147483648.0f) * -3.5f,
                            (1.0f - ((float)r2 * 2.0f) / 2147483648.0f) * 2.5f, 0, m5);
      FUN_00054330(e + 0x90, m);
    }
    *(u32 *)(e + 0x70) = (k & 1) == 0 ? 0xbf5f66f3 : 0x3f5f66f3;
    FUN_00054330(e + 0x80, FUN_0006de18(0, 0, 0, 0, m6));
    k++; n += 0xa0;
  } while ((int)k < 200);
  return p;
}
// near miss from lane fm11 (unreviewed)
