/* HSTMATCH module=EBOOT.BIN start=0x001b338c end=0x001b340c symbol=FUN_001b338c lang=c99 */

extern void FUN_00062418(int, int);

void FUN_001b338c(int *param_1, int index)
{
  int *base;
  int b;

  base = (int *)*param_1;
  b = 0;
  if (index < 0x1da) {
    if (base[index] != 0) {
      b = 1;
    }
  }
  if (b && base[index] != 0) {
    FUN_00062418(base[index], 1);
    base[index] = 0;
  }
}
// NEAR 30/32 words (0x001b338c). Same operations and the same short-circuit shape, but MWCC here
// folds the `b` boolean into a `sltu v1,zero,v1` on the recomputed temp (reusing the slti result
// register) and caches &base[index] in s0 across the call, so index never needs s1 and there is no
// `move a0,zero` / `li a0,1`. Retail instead keeps index in s1, computes slti into `at`, and sets
// the bool a0 by branches. Tried: nested ifs instead of &&, unsigned char b, int b, base pointer
// vs param_1[0] — all identical codegen (24 words).
// near miss from lane fm5 (unreviewed)
