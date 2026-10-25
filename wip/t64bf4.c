/* HSTMATCH module=EBOOT.BIN start=0x00064bf4 end=0x00064f40 symbol=FUN_00064bf4 lang=c99 */
typedef unsigned int u32; typedef unsigned char u8;
extern int FUN_0004cad0(); extern int FUN_00015ea0(); extern int FUN_0005da00();
extern int FUN_00065e64(); extern int FUN_00014a40(); extern int FUN_000660dc();
extern int FUN_00064fd0(); extern int FUN_00065ce0(); extern int FUN_000661d8();
extern int FUN_00064f40(); extern int FUN_000104e0(); extern int FUN_00065a88();
extern int FUN_00065fa0(); extern int FUN_0005da44(); extern char DAT_002d11cc[];
u32 FUN_00064bf4(int *a1, u32 a2, int a3, u32 a4)
{
  int len = 0; int n = 0; int cnt = 0; u32 res;
  int *list[1]; int *item;
  char *s; char *q;
  (*(void (**)(int *))(*a1 + 0xc))(a1);
  s = (char *)FUN_0004cad0(a2, &len, 0x10, 1);
  if (s == 0) return 0;
  if (len < 1) return 0;
  s[len - 1] = 0;
  if (*s != 0) {
    char c = *s;
    q = s;
    for (;;) {
      if (c == '\r') *q = '\n';
      q++;
      if (*q == 0) break;
      c = *q;
    }
  }
  item = 0;
  {
    char *z = s;
    if (((u8)s[0] == 0xef) && ((u8)s[1] == 0xbb) && ((u8)s[2] == 0xbf)) z = s + 3;
    item = (int *)FUN_00015ea0(z, DAT_002d11cc);
    while (item != 0) {
      n++;
      if ((1 < n) || (a3 == 0)) {
        if (cnt < 0) list[cnt] = item, cnt++;
        else FUN_0005da00(list, &item, 0);
      }
      item = (int *)FUN_00015ea0(0, DAT_002d11cc);
    }
  }
  if ((u32)a1[3] < 0x10) FUN_00065e64(a1 + 1, 0x10);
  {
    int **pp = list;
    while (pp != list + cnt) {
      if (FUN_00014a40(*pp) != 0) {
        int t1[3], t2[3], t3[3], t4[3];
        t1[0] = 0; t1[1] = 0; t1[2] = 0;
        FUN_000660dc(t1, 0x10);
        FUN_00064fd0(t1, *pp, a4);
        t2[0] = 0; t2[1] = 0; t2[2] = 0;
        FUN_00065ce0(t2, t1[0], t1[0] + t1[1] * 4, 0);
        t3[0] = t1[0]; t3[1] = t1[1]; t3[2] = t1[2];
        t1[0] = t2[0]; t1[1] = t2[1]; t1[2] = t2[2];
        t2[0] = t3[0]; t2[1] = t3[1]; t2[2] = t3[2];
        FUN_000661d8(t1, 0);
        if (t1[1] != 0) FUN_00064f40(a1 + 1, t2);
        FUN_000661d8(t2, 0);
      }
      pp++;
    }
  }
  FUN_000104e0(s);
  {
    int u[3];
    u[0] = 0; u[1] = 0; u[2] = 0;
    FUN_00065a88(u, a1[1], a1[1] + a1[2] * 0xc, 0);
    a1[3] = u[2]; a1[1] = u[0]; a1[2] = u[1];
    FUN_00065fa0(u, 0);
  }
  res = 1;
  return res;
}
// near miss from lane fm11 (unreviewed)
