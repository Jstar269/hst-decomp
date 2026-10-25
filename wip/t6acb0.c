/* HSTMATCH module=EBOOT.BIN start=0x0006acb0 end=0x0006af9c symbol=FUN_0006acb0 lang=c99 */
typedef unsigned int u32; typedef unsigned char u8;
void FUN_0006acb0(int *p1, int **p2, int *p3, u32 *p4)
{
  int n = 0; int i, k, step, s8; int *q; u32 v; int down;
  for (i = **p2; i != *p3; i = *(int *)(i + 4)) n++;
  if (n > 0) {
    q = (int *)**p2;
    for (;;) {
      k = n; if (n < 0) k = n + 1; k = k >> 1;
      if (k < 0) {
        step = k;
        if (-k > 8) {
          down = (k < 1) && (k < 0x7fffffff);
          if (down && k != (int)0x80000000) {
            do { step += 8;
              for (s8 = 0; s8 < 8; s8++) q = (int *)*q;
            } while (step < -8);
          }
        }
        for (; step < 0; step++) q = (int *)*q;
      } else {
        if (k > 0) {
          step = k;
          if (k > 8) {
            do { step -= 8;
              for (s8 = 0; s8 < 8; s8++) q = (int *)*(int *)(q[1] + 4);
            } while (step > 8);
          }
          for (; step > 0; step--) q = (int *)q[1];
        }
      }
      v = (u32)q[4];
      if (v < *p4) down = 1; else down = *(u8 *)(q + 0x2e) < (u8)p4[0x2a];
      if (down) { k = n - (k + 1); *p2 = q; }
      if (k < 1) break;
      q = (int *)*p2; n = k;
    }
  }
  *p1 = (int)*p2;
}
// near miss from lane fm11 (unreviewed)
