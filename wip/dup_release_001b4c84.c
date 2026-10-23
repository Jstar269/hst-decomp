/* HSTMATCH module=EBOOT.BIN start=0x001b4c84 end=0x001b4d4c symbol=FUN_001b4c84 lang=c99 */
extern void FUN_00062418(int, int);

void FUN_001b4c84(int *param_1,int param_2)
{
  int *base;
  int *slot;
  int *p;
  int n;
  int i;
  int off;

  base = (int *)*param_1;
  off = param_2 * 4;
  slot = (int *)(off + (int)base + 0x778);
  if (*slot == 0) {
    return;
  }
  n = 0;
  for (p = (int *)((char *)base + 0x778); p != (int *)((char *)base + 0x788); p++) {
    if (*p == *slot) {
      n = n + 1;
    }
  }
  if (n >= 2) {
    *slot = 0;
    return;
  }
  for (i = 0; i < 0x1da; i++) {
    if (base[i] == *slot) {
      if (base[i] != 0) {
        FUN_00062418(base[i],1);
        base[i] = 0;
      }
      break;
    }
  }
  *slot = 0;
}

// NEAR MISS: 48/50 words. Shape: `slot = base + 0x778 + index*4` in a shared object
// (base = *(int**)param_1); early return when *slot == 0; count the 4 entries at
// base+0x778..0x787 equal to *slot; if that count >= 2 just clear the slot, otherwise
// find the first matching index in base[0..0x1d9], delete it (FUN_00062418(v,1); v = 0)
// and clear the slot.
// Differing: retail materialises the slot address BEFORE the load
// (`addu v1,v1,t0; addiu s0,v1,0x778; lw v1,0x778(v1)`) and branches with `beqzl` to the
// epilogue (delay = `lw ra`); ours loads first, then the addiu, and uses `beqz` + nop.
// Ruled out: `if (*slot != 0) {...} *slot = 0;` (v3), `if (*slot == 0) return;` (v5), and
// the value-first add via a product local (kept: it fixed `addu v1,v1,t0`).
// near miss from lane fm5 (unreviewed)
