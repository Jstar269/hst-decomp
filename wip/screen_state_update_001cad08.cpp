/* HSTMATCH module=EBOOT.BIN start=0x001cad08 end=0x001caee4 symbol=FUN_001cad08 lang=c++ */
struct VC {
  virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4();
  virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9();
  virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14();
  virtual void d15(); virtual void d16(); virtual void d17();
  virtual void m();
};
struct Sub {
  int f0;
  int f4;
  int f8;
  int fc;
  int f10;
};
struct Self {
  char pad0[0xf3];
  unsigned char bf3;
  unsigned char bf4;
  unsigned char bf5;
  unsigned char bf6;
  char pad1[0x114 - 0xf7];
  char b114;
  char pad2[0x15c - 0x115];
  Sub *p15c;
};
struct Ent {
  char pad0[0x2f];
  char b2f;
  char pad1[6];
  short s36;
  short s38;
};
struct Game {
  char pad[0x1324];
  int f1324;
};
extern "C" {
extern Game *DAT_0033b574;
extern char DAT_002eaa70[];
int *FUN_0014c344(int, int);
Ent *FUN_001930c4(int);
int FUN_0019319c(void);
void FUN_001cc830(Self *);
VC *FUN_001cd30c(Self *);
int FUN_0022ada4(int, int);
int FUN_0022c9ac(void);
void FUN_002869cc(VC *, char *, int);
}

extern "C" void FUN_001cad08(Self *self)
{
  if (self->bf3 != 0 && (self->p15c->f4 == 0 || self->p15c->f10 == 0)) {
    self->bf3 = 0;
    VC *o = FUN_001cd30c(self);
    if (o != 0) {
      o->m();
      FUN_002869cc(o, DAT_002eaa70, 1);
      if (FUN_0022c9ac() != 0 && self->bf5 != 0) {
        self->bf4 = 1;
      }
      int ok = 0;
      int c1 = 0;
      if (DAT_0033b574 != 0 && *FUN_0014c344(DAT_0033b574->f1324, 0xbe) > 1) {
        c1 = 1;
      }
      if (c1 != 0) {
        c1 = 0;
        if (DAT_0033b574 != 0 && *FUN_0014c344(DAT_0033b574->f1324, 0xbf) != 0) {
          c1 = 1;
        }
        if (c1 == 0) {
          ok = 1;
          int i = 0;
          if (FUN_0019319c() > 0) {
            do {
              Ent *e = FUN_001930c4(i);
              if (e != 0 && e->b2f != 0 && FUN_0022ada4(e->s36, e->s38) == 0) {
                ok = 0;
                break;
              }
              i++;
            } while (i < FUN_0019319c());
          }
        }
      }
      if (ok != 0) {
        self->bf6 = 1;
      }
      if (self->b114 != 0) {
        FUN_001cc830(self);
      }
    } else {
      if (FUN_0022c9ac() != 0 && self->bf5 != 0) {
        self->bf4 = 1;
      }
    }
    self->bf5 = 0;
  }
}

// Near miss (snE7-00): all 119 words are the right opcodes, 32 words differ ONLY in saved-register naming.
// retail: self=s2, ok=s1, {o, flag c1, loop index i}=s0; ours: self=s1, {ok, o}=s0, {c1, i}=s2.
// Ruled out (no effect on the mapping): declaration order of {o, ok, c1, i} (all 24 permutations, at function top or
// inline, with/without top-level initialisers), reusing i as the flag, a separate second flag c2, bool/unsigned char
// flags (adds andi), for/while/do-while/goto loop forms, ablating the else branch / b114 tail / first bf4 block,
// the flag computation as a static inline int-returning helper. In small toys (t2/t4) the first-declared of two
// interfering locals gets the HIGHER s-register and the param s0, but here the param lands in the middle.
