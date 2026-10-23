/* HSTMATCH module=EBOOT.BIN start=0x001b7328 end=0x001b7564 symbol=FUN_001b7328 lang=c99 */
struct Self {
  char pad0[0x3c];
  int f3c;
  int f40;
  char pad1[8];
  int f4c;
  int f50;
  int f54;
  int f58;
  char pad2[0x78 - 0x5c];
  unsigned char b78;
  unsigned char b79;
  char pad3[0x7c - 0x7a];
  int f7c;
  int f80;
};

struct Msg {
  int a, b, c, d;
};

struct R {
  int x;
};

extern int FUN_001b1f7c(void *);
extern void FUN_001b2bb8(void *, int);
extern void FUN_001b9608(struct R *, void *, int *, struct Msg *);
extern void FUN_001b413c(float, float, void *);
extern void FUN_001b5c44(const char *);
extern void FUN_001b3f1c(void *);
extern void FUN_001b4418(float, float, void *);
extern int FUN_001b2af0(void *, int);
extern char DAT_0034179c;
struct Game { char pad[0x3c]; int mode; };
extern struct Game *DAT_003386b0;
extern char DAT_002e99d8[];

void FUN_001b7328(struct Self *self)
{
  if (self->f4c >= 0) {
    if (FUN_001b1f7c(&DAT_0034179c) == 0) {
      self->f4c = -1;
      if (DAT_003386b0->mode == 2) {
        struct Msg m;
        struct R res;
        int arg;
        FUN_001b2bb8(&DAT_0034179c, 0xbc);
        m.a = 0xb6;
        m.b = 0xf;
        arg = (int)((char *)self + 0x40);
        m.c = 0;
        m.d = 0;
        FUN_001b9608(&res, (char *)self + 0x3c, &arg, &m);
      }
    }
  }
  int t1;
  if (self->f54 >= 0) {
    if (FUN_001b1f7c(&DAT_0034179c) == 0) {
      if (DAT_003386b0->mode == 4 && self->f50 < 0) {
        FUN_001b413c(1.0f, 0.5f, &DAT_0034179c);
        self->f54 = -1;
      }
    }
    t1 = self->f50;
  } else {
    t1 = self->f50;
  }
  int t2;
  if (t1 >= 0) {
    if (FUN_001b1f7c(&DAT_0034179c) == 0) {
      if (DAT_003386b0->mode != 3) {
        FUN_001b5c44(DAT_002e99d8);
        if (DAT_003386b0->mode != 9 && self->b78 != 0) {
          if (self->b79 != 0) {
            FUN_001b3f1c(&DAT_0034179c);
            self->b79 = 0;
          } else {
            FUN_001b413c(1.0f, 0.5f, &DAT_0034179c);
          }
        }
        self->f50 = -1;
      }
    }
    t2 = self->f58;
  } else {
    t2 = self->f58;
  }
  int t3;
  if (t2 >= 0) {
    if (FUN_001b1f7c(&DAT_0034179c) == 0) {
      self->f58 = -1;
    }
    t3 = self->f7c;
  } else {
    t3 = self->f7c;
  }
  int t4;
  if (t3 >= 1) {
    self->f7c = t3 - 1;
    if (t3 - 1 < 1) {
      FUN_001b4418(0.5f, 7.0f, &DAT_0034179c);
      self->f7c = 0;
    }
    t4 = self->f80;
  } else {
    t4 = self->f80;
  }
  if (t4 > 0) {
    self->f80 = t4 - 1;
    if (t4 - 1 < 1) {
      self->f50 = FUN_001b2af0(&DAT_0034179c, 0x16);
    }
  }
}
// NEAR MISS: 143/143 words, 17 differ (all register naming + 3 branch-likely slots, no size difference).
// Retail keeps the chained timer value in a1 and uses `bnez v0,TARGET` (target = the following load,
// nop in the delay slot); every source form tried gives v1 for the value and `bnezl v0,TARGET+4` with
// the load duplicated into the delay slot (same word count, same semantics). Arms must be written
// inverted (`if (member >= 0) { body; t = next; } else { t = next; }`) for retail's bltzl shapes;
// t1..t4 as one variable or four locals, declared at top or mid-block, all give the same 17.
// Also: the Game global is a POINTER (lui 0x34; lw -31056 -> 0x3386b0; lw 60(a0)); writing
// &DAT_003386b0 + 0x3c folds the %lo and breaks 3 words.
// near miss from lane fm4 (unreviewed)
