/* HSTMATCH module=hstp_trans_main.prx start=0x002b55cc end=0x002b56a8 symbol=FUN_002b55cc lang=c++ */
/* Hand-written reconstruction from the disassembly (stores the mode, then a two-case switch written case 0, case 1 (MWCC tests the labels in reverse); slot-1 virtual calls on the two parts; FUN_002b6160 takes the new state as its second argument, which Ghidra dropped); exact match verified; names and types await human review. */
struct Part_002b55cc {
  virtual void v0();
  virtual void m1(int on);
};

struct Self_002b55cc {
  char pad0[0x58];
  Part_002b55cc *a;
  Part_002b55cc *b;
  char pad1[0x880 - 0x60];
  int mode;
  int state;
};

extern "C" void FUN_002b6160(Self_002b55cc *self, int state);

extern "C" void FUN_002b55cc(Self_002b55cc *self, int mode)
{
  self->mode = mode;
  switch (mode) {
  case 0:
    self->a->m1(0);
    self->b->m1(1);
    if (self->state >= 2 && self->state < 8) {
      self->state = 1;
      FUN_002b6160(self, 1);
    }
    break;
  case 1:
    self->a->m1(1);
    self->b->m1(0);
    if (self->state == 1) {
      self->state = 2;
      FUN_002b6160(self, 2);
    }
    break;
  }
}
