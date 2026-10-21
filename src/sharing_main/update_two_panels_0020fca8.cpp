/* HSTMATCH module=hstp_trans_main.prx start=0x0020fca8 end=0x0020fdd4 symbol=FUN_0020fca8 lang=c++ */
/* Clone of src/eboot/update_two_panels_002014d8.cpp (hstclone.py tag c21sn35s): addresses substituted; exact match verified; names and types await human review. */
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
extern Game *DAT_003f3474;
void FUN_0019fb6c(int *, int *, int);
void FUN_0020f9f8(Self *, int, int, int, int);

void FUN_0020fca8(Self *self)
{
  int local_4 = 0;
  int local_8 = 0;
  FUN_0019fb6c(&local_4, &local_8, self->f0);
  self->w6->SetVisible(1);
  self->w7->SetVisible(1);
  if (DAT_003f3474->fc4 == 0) {
    if (local_4 != 0) {
      self->w7->SetVisible(0);
      FUN_0020f9f8(self, local_4, 0x1b, 0x21, 6);
    }
  } else if (DAT_003f3474->f54 != 0) {
    if (local_4 != 0) {
      self->w6->SetVisible(0);
      FUN_0020f9f8(self, local_4, 0xd, 0x13, 2);
    }
    if (local_8 != 0) {
      self->w7->SetVisible(0);
      FUN_0020f9f8(self, local_8, 0x1b, 0x21, 6);
    }
  }
}
}
