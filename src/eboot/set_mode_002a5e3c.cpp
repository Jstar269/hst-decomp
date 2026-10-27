/* HSTMATCH module=EBOOT.BIN start=0x002a5e3c end=0x002a5f18 symbol=FUN_002a5e3c lang=c++ */
/* Clone of src/sharing_main/set_mode_002b55cc.cpp (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (stores the mode, then a two-case switch written case 0, case 1 (MWCC tests the labels in reverse); slot-1 virtual calls on the two parts; FUN_002a69d0 takes the new state as its second argument, which Ghidra dropped); exact match verified; names and types await human review. */
struct Part_002a5e3c {
  virtual void v0();
  virtual void m1(int on);
};

struct Self_002a5e3c {
  char pad0[0x58];
  Part_002a5e3c *a;
  Part_002a5e3c *b;
  char pad1[0x880 - 0x60];
  int mode;
  int state;
};

extern "C" void FUN_002a69d0(Self_002a5e3c *self, int state);

extern "C" void FUN_002a5e3c(Self_002a5e3c *self, int mode)
{
  self->mode = mode;
  switch (mode) {
  case 0:
    self->a->m1(0);
    self->b->m1(1);
    if (self->state >= 2 && self->state < 8) {
      self->state = 1;
      FUN_002a69d0(self, 1);
    }
    break;
  case 1:
    self->a->m1(1);
    self->b->m1(0);
    if (self->state == 1) {
      self->state = 2;
      FUN_002a69d0(self, 2);
    }
    break;
  }
}
