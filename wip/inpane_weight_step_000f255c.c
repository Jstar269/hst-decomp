/* HSTMATCH module=EBOOT.BIN start=0x000f255c end=0x000f27a0 symbol=FUN_000f255c lang=c99 */
struct Self {
  char pad0[0x54];
  int *slots[3];
  char pad1[0x84 - 0x60];
  unsigned char b84;
  char pad2[3];
  int f88;
  int f8c;
  int f90;
  float w[3];
  unsigned char vis[3];
};

extern unsigned char DAT_003386b8;
extern void *DAT_003386b0;
extern int *DAT_00338ac4;
extern int *DAT_00338b44;
extern int FUN_000dbc54(void *, int);
extern unsigned char FUN_00096c2c(void *, int);
extern void FUN_00103628(struct Self *, int);
extern void FUN_00103480(struct Self *);
extern void FUN_00103128(struct Self *);
extern float fabsf(float);

void FUN_000f255c(struct Self *self)
{
  if (self->b84 != 0) {
    return;
  }
  int idx = 0;
  if (DAT_003386b8 != 0) {
    if (DAT_00338ac4 == 0) {
      idx = 0;
    } else {
      idx = *(int *)((char *)DAT_00338ac4 + 0x198);
    }
  } else {
    idx = 0;
  }
  char *entry = (char *)DAT_003386b0 + idx * 4;
  if (idx != *(int *)((char *)DAT_00338b44 + 0x50)) {
    self->b84 = 1;
    FUN_00103628(self, 1);
    return;
  }
  void *pl = *(void **)(entry + 0x70);
  unsigned char s0 = !FUN_000dbc54(DAT_00338b44, 1) && !FUN_000dbc54(DAT_00338b44, 3);
  unsigned char s3 = !FUN_000dbc54(DAT_00338b44, 2) && !FUN_000dbc54(DAT_00338b44, 3);
  unsigned char v = (unsigned char)FUN_00096c2c(pl, 8);
  self->vis[0] = s3 && v;
  self->vis[1] = s0;
  self->vis[2] = 1;
  for (int i = 0; i < 3; i++) {
    float f7 = 0.0f;
    if (self->f90 == 0 || (self->f90 == 1 && i == self->f8c)) {
      if (self->vis[i] != 0) {
        f7 = 1.0f;
      }
    }
    float f4 = self->w[i];
    float d = f7 - f4;
    if (fabsf(d) >= 0.01f) {
      f7 = f4 + 0.3f * d;
    }
    self->w[i] = f7;
    *(float *)((char *)self->slots[i] + 0x78) = f7;
  }
  if (self->w[0] > 0.0f || self->w[1] > 0.0f || self->w[2] > 0.0f) {
    FUN_00103480(self);
  }
  FUN_00103128(self);
  self->f88 = self->f88 + 1;
}
// NEAR MISS 2026-10-22: 143/145 words, 90 differ (ours | retail), differences confined to +0x28..+0x40:
//  * table base loads into v1 (retail a0) and idx lives in a2 (retail a1); retail's `addu v1,v1,a0`
//    is hoisted before the game-state load while ours sinks it into the beq delay slot, which also
//    moves `lw s1,112(v1)` after the branch instead of into the slot.
//  * otherwise identical: idx chain (beqzl/bnezl/move), li a1,1; sb a1; jal 0x103628, the four
//    FUN_000dbc54 calls with sltu/xori merges, the weight loop and the tail `||` chain.
// Ruled out: pl statement before/after the guard, `void** entry` vs `char*`+0x70, array subscript
// form entry[0x1c], nested if/else-inverted idx chains (v4/v6/v9), inline `!(a&&b&&c)` tail (wrong
// call condition: retail calls 0x103480 when ANY weight is positive).
// near miss from lane fm4 (unreviewed)
