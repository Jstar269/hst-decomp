/* HSTMATCH module=EBOOT.BIN start=0x002014d8 end=0x00201604 symbol=FUN_002014d8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Widget {
  virtual void m0();
  virtual void SetVisible(int);
};
struct Self {
  int f0;
  int pad4[5];
  Widget *w6;
  Widget *w7;
};
struct Game {
  char pad[0x54];
  int f54;
  char pad58[0x6c];
  unsigned char fc4;
};
extern "C" {
extern Game *DAT_0034a13c;
void FUN_0019335c(int *, int *, int);
void FUN_00201228(Self *, int, int, int, int);

void FUN_002014d8(Self *self)
{
  int local_4 = 0;
  int local_8 = 0;
  FUN_0019335c(&local_4, &local_8, self->f0);
  self->w6->SetVisible(1);
  self->w7->SetVisible(1);
  if (DAT_0034a13c->fc4 == 0) {
    if (local_4 != 0) {
      self->w7->SetVisible(0);
      FUN_00201228(self, local_4, 0x1b, 0x21, 6);
    }
  } else if (DAT_0034a13c->f54 != 0) {
    if (local_4 != 0) {
      self->w6->SetVisible(0);
      FUN_00201228(self, local_4, 0xd, 0x13, 2);
    }
    if (local_8 != 0) {
      self->w7->SetVisible(0);
      FUN_00201228(self, local_8, 0x1b, 0x21, 6);
    }
  }
}
}
