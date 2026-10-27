/* HSTMATCH module=hstp_trans_main.prx start=0x002700c0 end=0x002701c8 symbol=FUN_002700c0 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Sub {
  virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
  virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
  virtual void v10();
};
struct Self {
  virtual void v0(); virtual void v1(); virtual void v2();
  char pad4[0x54 - 4];
  unsigned char f54;
  unsigned char f55;
  char pad56[2];
  Sub *f58;
  char pad5c[0xe0 - 0x5c];
  int fe0;
  char pade4[0x2f0 - 0xe4];
  char f2f0[0x5d0 - 0x2f0];
  int f5d0;
};
extern "C" {
extern void *DAT_003751d4;
extern void FUN_00108e6c(Self *self, float v);
extern void FUN_001090f4(Self *self, int v);
extern void FUN_0001dc34(void *p, int v);
extern void FUN_0001de88(void *p, int v, int w);
extern void FUN_00108f54(Self *self, int v);
extern void FUN_0026f4c0(Self *self, int v);
extern void FUN_00272b98(void *p);
extern void FUN_00108dac(Self *self);
}
extern "C" void FUN_002700c0(Self *self)
{
  FUN_00108e6c(self, 1010.0f);
  FUN_001090f4(self, -1);
  FUN_0001dc34(DAT_003751d4, 0x2000);
  FUN_0001de88(DAT_003751d4, 0x2000, 1);
  if (self->f58 != 0)
    self->f58->v10();
  self->f54 = 1;
  self->f55 = 0;
  FUN_00108f54(self, 0);
  self->v2();
  self->fe0 = 2;
  self->f5d0 = 2;
  FUN_0026f4c0(self, 3);
  for (int i = 0; i < 15; i++)
    FUN_00272b98(self->f2f0);
  FUN_00108dac(self);
  FUN_00108e6c(self, 99990.0f);
  FUN_001090f4(self, -1);
}
