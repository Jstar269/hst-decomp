/* HSTMATCH module=EBOOT.BIN start=0x002af348 end=0x002af480 symbol=FUN_002af348 lang=c99 */
typedef unsigned int undefined4;

void FUN_002af348(char *param_1,int param_2)
{
  char *dst;
  char *src;
  char *ps;
  char *pd;
  char c0;
  char c1;
  int n;

  dst = param_1 + 0x44c0;
  src = dst - param_2 * 0xb0;
  while (param_1 < src) {
    src = src + -0xb0;
    dst = dst + -0xb0;
    n = 8;
    ps = src;
    pd = dst;
    do {
      c0 = ps[0];
      c1 = ps[1];
      n = n + -1;
      pd[0] = c0;
      pd[1] = c1;
      ps = ps + 2;
      pd = pd + 2;
    } while (0 < n);
    *(float *)(dst + 0x10) = *(float *)(src + 0x10);
    *(float *)(dst + 0x14) = *(float *)(src + 0x14);
    ps = src + 0x18;
    pd = dst + 0x18;
    n = 0x15;
    do {
      n = n + -1;
      *pd = *ps;
      ps = ps + 1;
      pd = pd + 1;
    } while (0 < n);
    *(float *)(dst + 0x30) = *(float *)(src + 0x30);
    *(undefined4 *)(dst + 0x34) = *(undefined4 *)(src + 0x34);
    *(undefined4 *)(dst + 0x38) = *(undefined4 *)(src + 0x38);
    ps = src + 0x3c;
    pd = dst + 0x3c;
    n = 0x4b;
    do {
      n = n + -1;
      *pd = *ps;
      ps = ps + 1;
      pd = pd + 1;
    } while (0 < n);
    *(undefined4 *)(dst + 0x88) = *(undefined4 *)(src + 0x88);
    *(undefined4 *)(dst + 0x8c) = *(undefined4 *)(src + 0x8c);
    *(undefined4 *)(dst + 0x90) = *(undefined4 *)(src + 0x90);
    *(undefined4 *)(dst + 0x94) = *(undefined4 *)(src + 0x94);
    *(undefined4 *)(dst + 0x98) = *(undefined4 *)(src + 0x98);
    *(undefined4 *)(dst + 0x9c) = *(undefined4 *)(src + 0x9c);
    *(float *)(dst + 0xa0) = *(float *)(src + 0xa0);
    *(float *)(dst + 0xa4) = *(float *)(src + 0xa4);
    *(undefined4 *)(dst + 0xa8) = *(undefined4 *)(src + 0xa8);
    *(undefined4 *)(dst + 0xac) = *(undefined4 *)(src + 0xac);
  }
}

// NEAR MISS: 78/78 words, 60 differing (mostly register naming: retail keeps the three
// chunk counters in t4/t0/v1, ours in t1/a3/t2). Backward copy of 176-byte elements:
// `dst = param_1 + 0x44c0; src = dst - param_2 * 0xb0;` then
// `while (param_1 < src) { src -= 0xb0; dst -= 0xb0; <176-byte copy> }` with the chunk
// split 16 bytes 2-at-a-time (8 iters), float 0x10/0x14, 21 bytes 0x18.., float 0x30,
// words 0x34/0x38, 75 bytes 0x3c.., words 0x88..0x9c, floats 0xa0/0xa4, words 0xa8/0xac.
// Needed for the head to match: `char *` (not unsigned char) and the `dst - param_2*0xb0`
// form (that is what produces `sll 2/addu/sll 1/addu/sll 4`, i.e. param_2*11*16).
// Ruled out: a real `struct S176` assignment (`*dst = *src`) - MWCC collapses the whole
// aggregate into one 22-word loop (29 words total); direct `pd[0] = ps[0]; pd[1] = ps[1];`
// in the 2-byte chunk - MWCC unrolls it (98 words). Remaining: the two local load order
// in the 2-byte chunk (`lb 0` before `lb 1`) and the counter colouring.
// near miss from lane fm5 (unreviewed)
