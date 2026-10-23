/* HSTMATCH module=EBOOT.BIN start=0x00092720 end=0x00092790 symbol=FUN_00092720 lang=c99 */
typedef unsigned char bool;
extern int FUN_00095058(int);

bool FUN_00092720(int param_1,int param_2,int param_3)
{
  int off = param_2 * 4;
  int v = *(int *)(off + param_1 + 0x50);
  bool r;

  if (v != 0) {
    if (FUN_00095058(v) != 0) {
      r = 1;
    } else {
      r = 0;
    }
  } else if (param_2 - 3U < 2 && param_3 == 0) {
    r = 1;
  } else if (0 <= param_3) {
    r = 0;
  } else {
    r = 1;
  }
  return r;
}
// NEAR 2 (26 vs 28 words): the call arm and the `i-3U<2 && !flag` arm match exactly; the final
// `flag < 0 ? 1 : 0` selection loses 2 words - retail keeps a plain `bgez a2,0x92780`, a `b`+`li v0,1`
// block and an out-of-line `move v0,zero`, while every spelling tried collapses to `bltzl` (with `li`
// in the slot) or hoists the default `move v0,zero` into a `beqzl` slot.
// Ruled out: if/else with the arms in either order, early returns, default-then-override, bool and
// unsigned int return types, `0 <= x` vs `x >= 0`.
// near miss from lane fm5 (unreviewed)
