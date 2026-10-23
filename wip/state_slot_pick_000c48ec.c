/* HSTMATCH module=EBOOT.BIN start=0x000c48ec end=0x000c4a24 symbol=FUN_000c48ec lang=c99 */
typedef unsigned int undefined4;
typedef unsigned char u8;

extern u8 DAT_003417b8[];
extern int DAT_002d5ae8[];

void FUN_000c48ec(void)
{
  u8 *p;
  int *dst;
  int n;
  int i;
  int a;
  int b;

  n = DAT_003417b8[0] == 0 ? 2 : 4;
  i = 0;
  if (0 < n) {
  p = DAT_003417b8;
  dst = DAT_002d5ae8;
  do {
    *dst = -1;
    if (p[0xe0] == 0) {
      *dst = i;
    } else {
      if (DAT_003417b8[0] == 1) {
        a = (i + 2) % 4;
        if (p[a * 0x120 + 0xe0] == 0) {
          *dst = a;
          dst++;
          p += 0x120;
          continue;
        }
      }
      if ((i & 1) == 0) {
        a = i + 1;
      } else {
        a = i - 1;
      }
      if (p[a * 0x120 + 0xe0] == 0) {
        *dst = a;
      } else {
        b = (a + 2) % 4;
        if (p[b * 0x120 + 0xe0] == 0) {
          *dst = b;
        }
      }
    }
    i++;
    dst++;
    p += 0x120;
  } while (i < n);
  }
}
// NEAR 6 (72 vs 78 words): the whole ladder is transcribed - n = flag ? 4 : 2, the `blez` guard with
// `i = 0` in the delay, the `p[0xe0]` fast path, the flag==1 `(i+2)%4` probe with its early `next`,
// the odd/even neighbour probe and the `(a+2)%4` fallback. Retail additionally keeps three copies of
// the array base pointer (`move v1,t0`, `move t6,t0`, `move t4,t0`) and reads the saved flag byte into
// a2 before the loop, which is where the 6 words sit. Ruled out: for-loop vs do/while (do/while is
// required for `blez` + `move i,zero`), early `if (n == 0) return;`.
// near miss from lane fm5 (unreviewed)
