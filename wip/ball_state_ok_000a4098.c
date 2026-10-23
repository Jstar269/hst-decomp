/* HSTMATCH module=EBOOT.BIN start=0x000a4098 end=0x000a4220 symbol=FUN_000a4098 lang=c99 */
typedef unsigned int undefined4;
typedef unsigned char u8;

extern undefined4 *DAT_003386b0;
extern u8 *DAT_00338b44;
extern u8 DAT_003386b8;

undefined4 FUN_000a4098(int param_1,int param_2)
{
  int h;
  undefined4 r;
  int b;

  if ((*(u8 *)(param_1 + 0x14c) != 0) && (*(int *)(param_1 + 0x800) >= 0)) {
    return 0;
  }
  if ((param_2 != 0) && (0 < *(int *)(param_1 + 0x4f0))) {
    return 1;
  }
  if (*(u8 *)(param_1 + 0x14c) == 0) {
    return 1;
  }
  h = *(int *)((int)DAT_003386b0 + 0x88);
  b = 0;
  if (*(undefined4 *)(h + 0x230) == (*(undefined4 *)(param_1 + 0x144) ^ 1)) {
    if (*(int *)(h + 0x268) >= *(int *)(h + 0x270)) {
      b = 0;
    } else if (*(float *)(param_1 + 0x5a8) * *(float *)(h + 0x18) < 0.0f) {
      if (*(u8 *)((int)DAT_00338b44 + 0x5c) == 0) {
        b = 1;
      } else if ((DAT_003386b8 == 0) &&
                 ((*(u8 *)((int)DAT_00338b44 + 0x84) != 0 ||
                   *(u8 *)((int)DAT_00338b44 + 0x5e) != 0) ||
                  *(u8 *)((int)DAT_00338b44 + 0x5f) != 0)) {
        b = 1;
      }
    }
  }
  if (b) {
    r = 1;
  } else if (*(int *)(h + 0x230) < 0) {
    r = 1;
  } else if (*(int *)(h + 0x268) < *(int *)(h + 0x270)) {
    if (*(u8 *)((int)DAT_00338b44 + 0x5c) == 0) {
      r = 1;
    } else if ((DAT_003386b8 == 0) &&
               ((*(u8 *)((int)DAT_00338b44 + 0x84) != 0 ||
                 *(u8 *)((int)DAT_00338b44 + 0x5e) != 0) ||
                *(u8 *)((int)DAT_00338b44 + 0x5f) != 0)) {
      r = 1;
    } else {
      r = 0;
    }
  } else {
    r = 0;
  }
  return r;
}
// NEAR 1 (99 vs 98 words): the whole ladder matches (two early returns, the `(f144 ^ 1) == h->f230`
// guard, the f268/f270 ordering, the float sign test, the pending-flag group and the trailing
// b/230/268 ladder). Remaining: retail keeps h in a2 and derives `a1 = h + 620`, ours pins h in a1;
// one extra word follows from that. Ruled out: mirrored compare operands (fixes the load order but
// not the colouring), a local for h, `-1 < x` vs `x >= 0` (the latter is required).
// near miss from lane fm5 (unreviewed)
