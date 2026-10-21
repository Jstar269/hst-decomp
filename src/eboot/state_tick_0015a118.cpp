/* HSTMATCH module=EBOOT.BIN start=0x0015a118 end=0x0015a2b0 symbol=FUN_0015a118 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: rewritten with early returns, the 'f14 == 8 || (unsigned)(f14 - 3) <= 2' guard as one ||, the two arms swapped (f1c != 0 && bits == 0 first) and the 2-bit field read as a signed bitfield; exact match verified; names and types await human review. */
struct Child {
  virtual void m0();
  virtual void m1();
  virtual void m2();
};
struct Cfg {
  char pad[0x8b];
  signed char lo : 2;
  signed char mid : 2;
  signed char hi : 4;
};
struct Obj {
  char pad0[8];
  int f8;
  char pad1[0x14 - 0xc];
  int f14;
  int f18;
  unsigned char f1c;
  char pad2[0x24 - 0x1d];
  Child *a24;
  Child *a28;
  int *objs[2];
};

extern "C" {
extern Cfg *DAT_002cfc8c;
extern char DAT_0034179c[];
void FUN_000ffb3c(int *, int);
void FUN_0015a2b0(Obj *, int);
void FUN_001b1c44(void *, int);
}

extern "C" void FUN_0015a118(Obj *self)
{
  if (self->a24 != 0)
    self->a24->m2();
  if (self->a28 != 0)
    self->a28->m2();
  if (self->f8 > 0) {
    self->f8 = self->f8 - 1;
    return;
  }
  if (self->f14 == 8 || (unsigned)(self->f14 - 3) <= 2)
    return;
  for (int i = 0; i < 2; i++) {
    if (self->objs[i] != 0)
      FUN_000ffb3c(self->objs[i], 0);
  }
  if (self->f1c != 0 && DAT_002cfc8c->mid == 0) {
    FUN_001b1c44(DAT_0034179c, 3);
    FUN_0015a2b0(self, 8);
    for (int i = 0; i < 2; i++) {
      if (self->objs[i] != 0)
        FUN_000ffb3c(self->objs[i], 1);
    }
  } else {
    if (self->f1c == 0 && self->f18 == 0) {
      self->f18 = 1;
      FUN_0015a2b0(self, 8);
      for (int i = 0; i < 2; i++) {
        if (self->objs[i] != 0)
          FUN_000ffb3c(self->objs[i], 1);
      }
    }
  }
}
