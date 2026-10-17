/* HSTMATCH module=EBOOT.BIN start=0x00130274 end=0x00130304 symbol=FUN_00130274 lang=c++ */

extern "C" {
extern const char DAT_002db0e4;
extern const char DAT_002db0ec;
extern const char DAT_002db0f8;
extern char *FUN_00014d64(const char *, const char *);

int FUN_00130274(int param_1, const char *param_2)
{
  int res = 0;
  if (param_2 == 0) {
    return 0;
  }
  if (FUN_00014d64(param_2, &DAT_002db0e4) != 0) {
    res = 50;
  } else if (FUN_00014d64(param_2, &DAT_002db0ec) != 0) {
    res = 60;
  } else if (FUN_00014d64(param_2, &DAT_002db0f8) != 0) {
    res = 999;
  }
  return res;
}
}

// WIP (2026-10-15): 3 words from exact (33/36 words match).
// Retail assigns `res` to s0 and `param_2` to s1. Discrepancies:
// 1. +0x20: retail early return delay slot executes `move v0, s0` (0), ours emits `move v0, zero`
//    due to constant propagation of res=0.
// 2. +0x6c/+0x70: retail final strstr test uses `beqz v0, 0x1302ec; nop; li s0, 999`, while
//    ours uses `beqzl v0, 0x1302f0; move v0, s0; li s0, 999`.
// Ruled out: C99 mode (uses only s0 with constant returns), do-while(0) breaks, and direct early returns.
// near miss from lane ag1 (unreviewed)
