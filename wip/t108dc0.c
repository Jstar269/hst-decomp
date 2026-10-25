/* HSTMATCH module=EBOOT.BIN start=0x00108dc0 end=0x00109058 symbol=FUN_00108dc0 lang=c99 */
struct Slot { int *limit; int cnt; };
extern int FUN_00109d30(), FUN_00109ca8(), FUN_00109db8(), FUN_0010a184(), FUN_0010a058();
void FUN_00108dc0(int *a1, int *a2, int *a3, char c, int n5, int n6, int **s7, int **s8)
{
  int *cur7 = (int *)s7[0]; struct Slot *st7 = (struct Slot *)s7[1];
  int *cur8 = (int *)s8[0];
  int *pi, *out;
  int d, i1, i2, i3, i4;
  if (a1 == a2 || a2 == a3) return;
  if (n5 + n6 == 2) {
    int v = *a1;
    if (*(float *)(v + 0x20) < *(float *)(*a2 + 0x20)) { *a1 = *a2; *a2 = v; }
    return;
  }
  d = (int)cur8 - (int)cur7;
  if (d < 0) d += 3;
  if (n6 < n5 || d >> 2 < n5) {
    out = cur7; pi = a2;
    if (d >> 2 < n6) {
      if (n6 < n5) {
        i3 = n5; if (n5 < 0) i3 = n5 + 1; i3 >>= 1;
        pi = a1 + i3;
        FUN_00109d30(&out, a2, a3, pi, (int)c);
        i1 = (int)out - (int)a2;
        i3 = i1 >> 2; if (i1 < 0) i3 = (i1 + 3) >> 2;
        i2 = i1; i2 >>= 2; if (i1 < 0) i2 = (i1 + 3) >> 2;
      } else {
        i2 = n6; if (n6 < 0) i2 = n6 + 1; i2 >>= 1;
        pi = a2 + i2;
        FUN_00109ca8(&out, a1, a2, pi, (int)c);
        i1 = (int)out - (int)a1;
        i3 = i1 >> 2; if (i1 < 0) i3 = (i1 + 3) >> 2;
      }
      {
        int *mid;
        FUN_00109db8(&mid, out, a2, pi, n5 - i3, i2, &cur7, &cur8);
        FUN_00108dc0(a1, out, mid, c, i3, i2, &cur7, &cur8);
        FUN_00108dc0(mid, pi, a3, c, n5 - i3, n6 - i2, &cur7, &cur8);
      }
    } else {
      for (; pi != a3; pi++) {
        d = (int)out - (int)st7->limit;
        if (d < 0) d += 3;
        if (d >> 2 < st7->cnt) *out = *pi;
        else { if (out != 0) *out = *pi; st7->cnt = st7->cnt + 1; }
        out++;
      }
      FUN_0010a184(&out, a1, a2, &cur7, &out, a3, (int)c);
    }
  } else {
    for (pi = a1; pi != a2; pi++) {
      d = (int)out - (int)st7->limit;
      if (d < 0) d += 3;
      if (d >> 2 < st7->cnt) *out = *pi;
      else { if (out != 0) *out = *pi; st7->cnt = st7->cnt + 1; }
      out++;
    }
    FUN_0010a058(&out, &cur7, &out, a2, a3, a1, (int)c);
  }
}
// near miss from lane fm11 (unreviewed)
