/* HSTMATCH module=EBOOT.BIN start=0x00198eb4 end=0x00199104 symbol=FUN_00198eb4 lang=c99 rodata=0x002c2a80 */
struct Info {
  char pad[0x3c];
  float a, b, c, d;
  float e, f, g, h;
  float i, j, k, l;
  int m, n, o, p;
  int q;
};

extern int DAT_002e17f8, DAT_002e17fc, DAT_002e1800, DAT_002e1804, DAT_002e1808, DAT_002e180c;
extern int DAT_002e1810, DAT_002e1814, DAT_002e1818, DAT_002e181c, DAT_002e1820, DAT_002e1824;
extern int DAT_002e1828, DAT_002e1830, DAT_002e1838;
extern int DAT_002e185c, DAT_002e1860, DAT_002e1864, DAT_002e1868, DAT_002e186c, DAT_002e1870;
extern int DAT_002e1874, DAT_002e1878, DAT_002e187c, DAT_002e1880, DAT_002e1884, DAT_002e1888;
extern int DAT_002e188c, DAT_002e1890, DAT_002e1894, DAT_002e1898;
extern int DAT_003417a4;
extern void FUN_00199280(void *);

void FUN_00198eb4(struct Info *info)
{
  FUN_00199280(&DAT_002e17f8);
  DAT_002e1828 = 0;
  DAT_002e1838 = 15;
  switch (DAT_003417a4) {
  default:
  case 0:
  case 1:
  case 6:
  case 7:
  case 8:
  case 10:
    DAT_002e1830 = 2;
    break;
  case 2:
    DAT_002e1830 = 3;
    break;
  case 4:
    DAT_002e1830 = 5;
    break;
  case 5:
    DAT_002e1830 = 6;
    break;
  case 3:
    DAT_002e1830 = 4;
    break;
  case 9:
    DAT_002e1830 = 10;
    break;
  }
  DAT_002e185c = DAT_002e17f8;
  DAT_002e1860 = DAT_002e17fc;
  DAT_002e1864 = DAT_002e1800;
  DAT_002e1868 = DAT_002e1804;
  DAT_002e186c = DAT_002e1808;
  DAT_002e1870 = DAT_002e180c;
  DAT_002e1874 = DAT_002e1810;
  DAT_002e1878 = DAT_002e1814;
  DAT_002e187c = DAT_002e1818;
  DAT_002e1880 = DAT_002e181c;
  DAT_002e1884 = DAT_002e1820;
  DAT_002e1888 = DAT_002e1824;
  info->a = *(float *)&DAT_002e185c;
  info->b = *(float *)&DAT_002e1860;
  info->c = *(float *)&DAT_002e1864;
  info->d = *(float *)&DAT_002e1868;
  info->e = *(float *)&DAT_002e186c;
  info->f = *(float *)&DAT_002e1870;
  info->g = *(float *)&DAT_002e1874;
  info->h = *(float *)&DAT_002e1878;
  info->i = *(float *)&DAT_002e187c;
  info->j = *(float *)&DAT_002e1880;
  info->k = *(float *)&DAT_002e1884;
  info->l = *(float *)&DAT_002e1888;
  info->m = DAT_002e188c;
  info->n = DAT_002e1890;
  info->o = DAT_002e1894;
  info->p = DAT_002e1898;
  info->q = 0;
}
// NEAR MISS 2026-10-22: 148/148 words, 83 differ (ours | retail). The jump-table switch now matches
// byte for byte (guard beqzl into the default body, table at 0x2c2a80, bodies in the order
// default,2,4,5,3,9 with `default:` listed first). Everything from 0x198f70 on differs only in
// that MWCC hoists five extra `lui a2/t2/t1/t0/a3,0x2e` for the twelve `DAT_002e185c..1888 =
// DAT_002e17f8..1824` int copies (retail keeps exactly one `lui v1` per source load and one
// `lui a0` per destination store). Ruled out: float-typed globals (lwc1/swc1), struct assignment,
// array subscripts, `rodata=` absent (then no table is emitted at all).
// near miss from lane fm4 (unreviewed)
