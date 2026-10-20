/* HSTMATCH module=EBOOT.BIN start=0x001d9b98 end=0x001d9c64 symbol=FUN_001d9b98 lang=c++ */
/* WIP: 3 words differ (branch form only). Retail tests the `case 3` label with `bnel a0,v1,next; li v0,8`
   + `b END`; ours emits `beq a0,v1,END; nop` and is one instruction shorter. Every other instruction matches after
   the shift. Semantics (f54 gate, f5c==7 + FUN_002a234c(f84) gate, case 5/7/6/8 -> FUN_00233c48(DAT_0034a664),
   default -> virtual slot 8 then FUN_001031e8) confirmed. */
struct Obj {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6();
  virtual void v7();
  virtual int v8();
  char pad4[0x54 - 4];
  unsigned char f54;
  char pad55[0x5c - 0x55];
  int f5c;
  char pad60[0x84 - 0x60];
  int f84;
};

extern "C" {
extern int DAT_0034a664;
int FUN_002a234c(int a);
void FUN_00233c48(int a);
void FUN_001031e8(Obj *self);
}

extern "C" void FUN_001d9b98(Obj *self)
{
  if (!self->f54)
    return;
  if (self->f5c == 7) {
    if (FUN_002a234c(self->f84) != 0)
      return;
  }
  switch (self->f5c) {
  case 5:
  case 7:
  case 6:
  case 8:
    FUN_00233c48(DAT_0034a664);
    break;
  case 3:
    break;
  default:
    if (self->v8())
      FUN_001031e8(self);
  }
}
// near miss from lane ds6 (unreviewed)
