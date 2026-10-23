/* HSTMATCH module=EBOOT.BIN start=0x001b08a0 end=0x001b0958 symbol=FUN_001b08a0 lang=c99 */
extern void FUN_00062418(int, int);

void FUN_001b08a0(int *arr, int *list, int n)
{
  int i = 0;
  int *p = list;
  int idx;
  int v;
  int ok;

  if (n > 0) {
    do {
      idx = *p;
      ok = 0;
      if (idx < 0x1da) {
        if (arr[idx] != 0) ok = 1;
      }
      if (ok) {
        v = arr[idx];
        if (v != 0) {
          FUN_00062418(v, 1);
          arr[idx] = 0;
        }
      }
      i++;
      p++;
    } while (i < n);
  }
}

// NEAR MISS: 42/46 words, 39 differing words (the whole frame is shifted by one register
// because a saved register is missing).  Retail's per-element flag is MATERIALISED
// (`slti at,s0,0x1da; beqz at,NEXT; move a0,zero` in the delay, `li a0,1` after the second
// test, then `beqzl a0,LATCH` with the counter increment in the delay), and retail loads
// `arr[idx]` twice (once for the flag, once for the body) although the forms are identical.
// Ours folds the flag away: `slti v1; beqz v1` plus `sltu v1,zero,v1` for the second test,
// so idx never gets a saved register and the post-call `arr[idx] = 0` reuses a precomputed
// address (s4) instead of recomputing `idx*4 + arr`.
// Ruled out: `ok = 0; if (a) { if (b) ok = 1; }` (folds), `ok = 0; if (a && b) ok = 1;`
// (folds), `_Bool ok` (folds), `ok = idx < 0x1da; if (ok) ok = arr[idx] != 0;` (folds),
// `if (ok) { v = arr[idx]; if (v) ..}` vs `if (ok && (v = arr[idx]) != 0)` (same), the store
// spelled `*(int *)((char *)arr + idx * 4)` (one word closer only), and the loop as a
// `for (i = 0; i < n; i++)`.  A shape that stops MWCC proving the flag equals the condition
// is still needed (a helper call or a differently-sized flag type are the obvious next
// probes).
// near miss from lane fm5 (unreviewed)
