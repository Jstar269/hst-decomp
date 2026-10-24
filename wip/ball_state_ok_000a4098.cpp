/* HSTMATCH module=EBOOT.BIN start=0x000a4098 end=0x000a4220 symbol=FUN_000a4098 lang=c++ */
typedef unsigned char u8;

struct Sub {
  int a;
  int limit;
  bool Below(int v) const { return v < limit; }
};
struct Hd {
  char pad0[0x18];
  float f18;
  char pad1[0x230 - 0x1c];
  int f230;
  int GetF230() const { return f230; }
  char pad2[0x268 - 0x234];
  int f268;
  Sub sub;
};
struct Ctl {
  char pad0[0x88];
  Hd *h;
};
struct Gs {
  char pad0[0x5c];
  u8 f5c;
  char pad1[1];
  u8 f5e;
  u8 f5f;
  char pad2[0x84 - 0x60];
  u8 f84;
};
struct Obj {
  char pad0[0x144];
  int f144;
  char pad1[4];
  u8 f14c;
  char pad2[0x4f0 - 0x14d];
  int f4f0;
  char pad3[0x5a8 - 0x4f4];
  float f5a8;
  char pad4[0x800 - 0x5ac];
  int f800;
};

extern "C" Ctl *DAT_003386b0;
extern "C" Gs *DAT_00338b44;
extern "C" u8 DAT_003386b8;

extern "C" unsigned int FUN_000a4098(Obj *o, int param_2)
{
  Hd *h;
  int b;

  if (o->f14c != 0 && o->f800 >= 0) {
    return 0;
  }
  if (param_2 != 0 && 0 < o->f4f0) {
    return 1;
  }
  if (o->f14c == 0) {
    return 1;
  }
  h = DAT_003386b0->h;
  if (h->f230 == (o->f144 ^ 1) && h->sub.Below(h->f268) &&
      o->f5a8 * h->f18 < 0.0f &&
      (DAT_00338b44->f5c == 0 ||
       (DAT_003386b8 == 0 &&
        (DAT_00338b44->f84 != 0 || DAT_00338b44->f5e != 0 ||
         DAT_00338b44->f5f != 0)))) {
    b = 1;
  } else {
    b = 0;
  }
  if (b) {
    return 1;
  }
  if (h->GetF230() < 0) {
    return 1;
  }
  if (h->sub.Below(h->f268) &&
      (DAT_00338b44->f5c == 0 ||
       (DAT_003386b8 == 0 &&
        (DAT_00338b44->f84 != 0 || DAT_00338b44->f5e != 0 ||
         DAT_00338b44->f5f != 0)))) {
    return 1;
  }
  return 0;
}
// NEAR ~6 (97 vs 98 words, lane sn7 2026-10-24). Structure now matches retail: first ladder is
// `if (f230 == (f144^1) && Below && float<0 && (5c==0 || (b8==0 && (84||5e||5f)))) b = 1; else b = 0;`
// (one && chain with an if/else flag, NOT b=0 initialiser: that keeps b in a register of its own),
// then `if (b) return 1; if (h->GetF230() < 0) return 1;` (the inline getter makes the f230 reload
// land in the beqzl delay slot as retail; direct h->f230 CSEs it into an early lw), then the second
// ladder as one && chain. The group (5c/b8/84/5e/5f) is byte-identical to retail.
// Still differs: retail materialises `addiu a1,a2,620` (h+0x26c) in block 1 and `addiu a0,a2,620`
// in block 2 and reads the limit as `lw 4(a1)` while f268 is `616(a2)` (h lives in a2, a1 is taken
// by that pointer); ours folds the limit to 624(h), so h takes a1 and the loads are reordered.
// Ruled out for the pointer (all fold): sub-struct member + getter/Below(int) method, base class at
// +0x26c (struct Hd : Hd0, Sub), int* local, (Sub*)&h->f26c, const-ref params, inline helpers taking
// pointers/refs, getter returning Sub&. Also ruled out: whole ladder as inline functions with
// returns (105 words, chained jumps), nested static inline Grp (not inlined without inline_depth).
// near miss from lane sn7 (unreviewed)
