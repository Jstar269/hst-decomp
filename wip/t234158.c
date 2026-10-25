/* HSTMATCH module=EBOOT.BIN start=0x00234158 end=0x00234604 symbol=FUN_00234158 lang=c99 */
typedef unsigned int u32; typedef unsigned char u8;
extern int FUN_0023412c(), FUN_000478ac(), FUN_0008d964(), FUN_00047864(), FUN_00047898();
extern int FUN_0004784c(), FUN_0008d958(), FUN_0008d90c(), FUN_000478c0(), FUN_0004787c();
extern int FUN_001cd584(), FUN_00063d08(), FUN_002932b8();
extern char DAT_003417b8; extern int DAT_003386c8, DAT_0034a114, DAT_0034a820, DAT_00331b88;
extern char DAT_002f471c[]; extern char *PTR_002f471c[]; extern char DAT_002f48b0[], DAT_002f4884[];
void FUN_00234158(int *a, int n)
{
  int i, b3, b2, prev;
  char *pname;
  if (n == 0x59 || *a == n) goto lab4418;
  pname = PTR_002f471c[n];
  FUN_0023412c(DAT_002f48b0, PTR_002f471c[*a], *pname);
  if ((char)a[0xb] == 0) {
    i = 9;
    {
      int *p = a + 9;
      do {
        i -= 3;
        p[1] = *p; *p = p[-1]; p[-1] = p[-2];
        p -= 3;
      } while (0 < i);
    }
    a[1] = *a;
    *a = n;
  }
  if (n == 2 || n == 0x20) {
    if ((char)a[0xb] == 0) goto lab4418;
    if (FUN_000478c0() == 0) {
      FUN_0004787c();
      b3 = 0;
      if (n == 0x24 || n == 0x23 || n == 0x22 || n == 0x21) b3 = 1;
      if (b3) FUN_0023412c(DAT_002f4884, *pname);
    }
    if (DAT_0034a114 != 0) FUN_001cd584(DAT_0034a114, n);
    goto lab4418;
  }
  if (n == 0) {
    if ((char)a[0xb] == 0 && FUN_000478ac() == 0) {
      DAT_003417b8 = FUN_0008d964() == 0;
      FUN_00047864();
    }
    goto lab4418;
  }
  b3 = (n == 0x24 || n == 0x23 || n == 0x22 || n == 0x21);
  if (!b3) {
    if ((char)a[0xb] == 0) {
      if (FUN_00047898() == 0) { FUN_0004784c(); FUN_0008d958(n); }
      else if (DAT_003386c8 != 0) FUN_0008d90c(DAT_003386c8, n);
    }
    goto lab4418;
  }
  if ((char)a[0xb] != 0) goto lab4418;
  if (FUN_000478c0() == 0) {
    FUN_0004787c();
    b3 = (n == 0x24 || n == 0x23 || n == 0x22 || n == 0x21);
    if (b3) FUN_0023412c(DAT_002f4884, *pname);
  }
  if (DAT_0034a114 != 0) FUN_001cd584(DAT_0034a114, n);
lab4418:
  prev = a[1];
  b3 = 0; b2 = 0;
  if (n == 0x20) {
    if (prev == 0x4c || prev == 0x4b) b2 = 1;
    else if (prev == 0x26) b3 = 1;
    else if (prev == 0x25 || prev == 0x24 || prev == 0x23 || prev == 0x22) b3 = 1;
  } else if (!(n == 0x57 || n == 0x4c || n == 0x4b || n == 0x44 || n == 0x31 || n == 0x2a || n == 0x21 || n == 0x1d)) {
    b3 = 1;
  }
  if (n == 0x2b && prev == 0x31) b3 = 0;
  else if (n == 0x1e && prev == 0x44) b3 = 0;
  if (b3) FUN_00063d08(0x477fff00, 0x48435000, DAT_00331b88, 0xf);
  else if (b2 && DAT_0034a820 != 0) FUN_002932b8(0x477fff00, DAT_0034a820, 5);
}
// near miss from lane fm11 (unreviewed)
