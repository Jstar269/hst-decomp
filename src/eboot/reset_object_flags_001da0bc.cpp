/* HSTMATCH module=EBOOT.BIN start=0x001da0bc end=0x001da160 symbol=FUN_001da0bc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Sibling of reset_object_flags_002595e8.cpp (same body, 1010.0f, class has a vptr) plus a final virtual slot-2 call on the object. Names provisional. */
struct VC {
  virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
  virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
  virtual void s10();
};
struct Self {
  virtual void s0(); virtual void s1(); virtual void s2();
  char pad[0x54 - 4];
  unsigned char b54;
  unsigned char b55;
  char pad2[2];
  VC *p58;
};
extern "C" {
extern int *DAT_002cfc8c;
void FUN_00103540(Self *, float);
void FUN_001037c8(Self *, int);
void FUN_0001dfe8(int *, int);
void FUN_0001e23c(int *, int, int);
void FUN_00103628(Self *, int);
}

/* Reset the object: call the two helpers on the global with mask 0x2000, set b54 and clear b55, then call virtual slot 2. */
extern "C" void FUN_001da0bc(Self *self)
{
  FUN_00103540(self, 1010.0f);
  FUN_001037c8(self, -1);
  FUN_0001dfe8(DAT_002cfc8c, 0x2000);
  FUN_0001e23c(DAT_002cfc8c, 0x2000, 1);
  if (self->p58) self->p58->s10();
  self->b54 = 1;
  self->b55 = 0;
  FUN_00103628(self, 0);
  self->s2();
}
