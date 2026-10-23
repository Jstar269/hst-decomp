/* HSTMATCH module=EBOOT.BIN start=0x000c4a24 end=0x000c4ba0 symbol=FUN_000c4a24 lang=c99 */
typedef unsigned char undefined1;

extern void FUN_000c48ec(void);
extern undefined1 DAT_003417b8;
extern int DAT_002d5ae8[];
extern int DAT_002d5af8[];
extern int DAT_002d5b08[];
extern int DAT_00338af4[];

void FUN_000c4a24(void)
{
  int n;
  int i;
  int j;
  int k;
  int hits;
  int next;
  int *fill;
  int *cnt;
  int *dst;
  int *grp;

  FUN_000c48ec();
  n = DAT_003417b8 == 0 ? 2 : 4;
  i = 0;
  if (0 < n) {
    fill = DAT_002d5af8;
    do {
      *fill = -1;
      i++;
      fill++;
    } while (i < n);
  }
  i = 0;
  if (0 < n) {
    dst = DAT_002d5b08;
    grp = DAT_00338af4;
    next = 0;
    do {
      j = 0;
      hits = 0;
      k = 0;
      fill = DAT_002d5af8;
      cnt = DAT_002d5ae8;
      if (n != 0) {
        do {
          if (*cnt == i) {
            *fill = next;
            next++;
            hits++;
          }
          k++;
          fill++;
          cnt++;
        } while (k < n);
      }
      if (hits < 1) {
        *dst = -1;
        *grp = 0;
      } else {
        *dst = i;
        *grp = hits;
      }
      i++;
      dst++;
      grp++;
    } while (i < n);
  }
}
// NEAR 32 (127 vs 95 words): retail's first loop is an INLINED memset (-1 over n*4 bytes): the
// `slti at,n,9` split with an 8-at-a-time unrolled body plus a remainder loop, exactly MWCC's
// inline memset; the source almost certainly calls memset(DAT_002d5af8, -1, n << 2). Writing the
// fill as a plain for loop yields 127 words. `memset` is not yet in symbols/EBOOT.BIN.txt, so a
// memset spelling cannot be linked here. Everything else (the n = 2/4 select, the nested marking
// loops over the four arrays) is transcribed and still unmatched because the frame shifted.
// near miss from lane fm5 (unreviewed)
