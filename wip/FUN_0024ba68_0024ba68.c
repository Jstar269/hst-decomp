/* HSTMATCH module=EBOOT.BIN start=0x0024ba68 end=0x0024bd80 symbol=FUN_0024ba68 lang=c99 */
typedef unsigned int undefined4;
typedef unsigned int uint;

typedef struct {
  float f[4];
} V4;

extern char *DAT_003402a0;
extern void FUN_000550c8();

void FUN_0024ba68(int param_1, V4 *param_2, V4 *param_3)
{
  V4 t1;
  V4 t2;
  uint uVar1;

  t1 = *param_2;
  t2 = *param_3;
  *(float *)(param_1 + 0x210) = t1.f[0];
  *(float *)(param_1 + 0x214) = t1.f[1];
  *(float *)(param_1 + 0x218) = t1.f[2];
  *(float *)(param_1 + 0x21c) = t1.f[3];
  *(float *)(param_1 + 0x220) = t2.f[0];
  *(float *)(param_1 + 0x224) = t2.f[1];
  *(float *)(param_1 + 0x228) = t2.f[2];
  *(float *)(param_1 + 0x22c) = t2.f[3];
  uVar1 = *(uint *)(DAT_003402a0 + 0x1360) * 0x343fd + 0x269ec3;
  *(uint *)(DAT_003402a0 + 0x1360) = uVar1;
  if (((uVar1 & 0x7fffffff) >> 0x10 & 1) == 0) {
    uVar1 = *(uint *)(DAT_003402a0 + 0x1360) * 0x343fd + 0x269ec3;
    *(uint *)(DAT_003402a0 + 0x1360) = uVar1;
    *(float *)(param_1 + 0x218) =
        (float)((uVar1 & 0x7fffffff) >> 0x10) * 3.0517578e-05f * 11.887199f + 0.0f;
    uVar1 = *(uint *)(DAT_003402a0 + 0x1360) * 0x343fd + 0x269ec3;
    *(uint *)(DAT_003402a0 + 0x1360) = uVar1;
    *(float *)(param_1 + 0x228) =
        (float)((uVar1 & 0x7fffffff) >> 0x10) * 3.0517578e-05f * 11.887199f + 0.0f;
  }
  else {
    uVar1 = *(uint *)(DAT_003402a0 + 0x1360) * 0x343fd + 0x269ec3;
    *(uint *)(DAT_003402a0 + 0x1360) = uVar1;
    *(float *)(param_1 + 0x218) =
        -((float)((uVar1 & 0x7fffffff) >> 0x10) * 3.0517578e-05f * 11.887199f + 0.0f);
    uVar1 = *(uint *)(DAT_003402a0 + 0x1360) * 0x343fd + 0x269ec3;
    *(uint *)(DAT_003402a0 + 0x1360) = uVar1;
    *(float *)(param_1 + 0x228) =
        -((float)((uVar1 & 0x7fffffff) >> 0x10) * 3.0517578e-05f * 11.887199f + 0.0f);
  }
  *(float *)(param_1 + 0x230) = *(float *)(param_1 + 0x210);
  *(float *)(param_1 + 0x234) = *(float *)(param_1 + 0x214);
  *(float *)(param_1 + 0x238) = *(float *)(param_1 + 0x218);
  *(float *)(param_1 + 0x23c) = *(float *)(param_1 + 0x21c);
  FUN_000550c8(param_1 + 0x50, param_1 + 0x210);
  return;
}

// NEAR MISS 0x0024ba68: 186/198 words, 183 words differ, first diff at +0x1c.
// Confirmed shape: frame 0x30 with only ra; two 16-byte vector temps where
// DECLARATION ORDER MATTERS (t1 declared first lands at sp+0x20, t2 at
// sp+0x10, i.e. mwcc lays locals out in reverse); the eight destination
// stores at +0x210..+0x22c must be written ELEMENT-WISE from the temps (a
// struct assignment makes mwcc forward the copy and costs 8 words); the tail
// is four direct float copies +0x210..+0x21c -> +0x230..+0x23c and
// FUN_000550c8(param_1 + 0x50, param_1 + 0x210).
// Literals pinned from the disassembly: 11.887199f is exactly 0x413E31F8
// (11.8872f is 0x413E31F9 and is WRONG), the scale is 2^-15 = 0x38000000
// (3.0517578e-05f), the LCG is state*0x343fd + 0x269ec3 with state at
// *(u32*)(DAT_003402a0 + 0x1360), and DAT_003402a0 is a POINTER global.
// Remaining faults, in the order worth attacking:
//  1. The two arms are 12 words short: retail duplicates the full
//     two-draw sequence in BOTH arms (8 add.s / 20 mtc1 / 23 lui / 14 ori)
//     where ours shares code between them. Write the arms so nothing is
//     common (no shared temporaries, no common subexpression) - that is the
//     main gap.
//  2. `(uVar1 & 0x7fffffff) >> 0x10` compiles to sll/srl/srl here but retail
//     has a single `ext v1,v1,0x10,0xf` (ext 1 vs 5). The `(uVar1 >> 0x10) &
//     0x7fff` spelling was tried and is worse (178 words).
//  3. Retail reloads DAT_003402a0 at every draw (`lui v1,0x34; lw a2,672(v1)`)
//     where ours CSEs it into a3.
//  4. Retail's `(x & 1) == 0` test uses the bgez/andi/beqz/addiu-2/beqzl
//     cluster; ours emits a single bnezl. Probably falls out of 1.
// Ruled out: element-wise temp copies from the params (165), float t[4]
// arrays instead of V4 (165), removing the tail temp (no change).
// near miss from lane fm10 (unreviewed)
