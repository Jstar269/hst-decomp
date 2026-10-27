/* HSTMATCH module=EBOOT.BIN start=0x0025f298 end=0x0025f3a0 symbol=FUN_0025f298 lang=c++ */
/* Clone of src/sharing_main/FUN_002700c0.cpp (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
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
extern void *DAT_002cfc8c;
extern void FUN_00103540(Self *self, float v);
extern void FUN_001037c8(Self *self, int v);
extern void FUN_0001dfe8(void *p, int v);
extern void FUN_0001e23c(void *p, int v, int w);
extern void FUN_00103628(Self *self, int v);
extern void FUN_0025e698(Self *self, int v);
extern void FUN_00261d70(void *p);
extern void FUN_00103480(Self *self);
}
extern "C" void FUN_0025f298(Self *self)
{
  FUN_00103540(self, 1010.0f);
  FUN_001037c8(self, -1);
  FUN_0001dfe8(DAT_002cfc8c, 0x2000);
  FUN_0001e23c(DAT_002cfc8c, 0x2000, 1);
  if (self->f58 != 0)
    self->f58->v10();
  self->f54 = 1;
  self->f55 = 0;
  FUN_00103628(self, 0);
  self->v2();
  self->fe0 = 2;
  self->f5d0 = 2;
  FUN_0025e698(self, 3);
  for (int i = 0; i < 15; i++)
    FUN_00261d70(self->f2f0);
  FUN_00103480(self);
  FUN_00103540(self, 99990.0f);
  FUN_001037c8(self, -1);
}
