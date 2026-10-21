/* HSTMATCH module=hstp_trans_main.prx start=0x001666f0 end=0x00166888 symbol=FUN_001666f0 lang=c++ */
/* Clone of src/eboot/state_tick_0015a118.cpp (hstclone.py tag c21sn4s): addresses substituted; exact match verified; names and types await human review. */
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
extern Cfg *DAT_003751d4;
extern char DAT_003eaad8[];
void FUN_00105470(int *, int);
void FUN_00166888(Obj *, int);
void FUN_001bfc3c(void *, int);
}

extern "C" void FUN_001666f0(Obj *self)
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
      FUN_00105470(self->objs[i], 0);
  }
  if (self->f1c != 0 && DAT_003751d4->mid == 0) {
    FUN_001bfc3c(DAT_003eaad8, 3);
    FUN_00166888(self, 8);
    for (int i = 0; i < 2; i++) {
      if (self->objs[i] != 0)
        FUN_00105470(self->objs[i], 1);
    }
  } else {
    if (self->f1c == 0 && self->f18 == 0) {
      self->f18 = 1;
      FUN_00166888(self, 8);
      for (int i = 0; i < 2; i++) {
        if (self->objs[i] != 0)
          FUN_00105470(self->objs[i], 1);
      }
    }
  }
}
