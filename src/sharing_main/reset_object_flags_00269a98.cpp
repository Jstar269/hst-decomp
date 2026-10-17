/* HSTMATCH module=hstp_trans_main.prx start=0x00269a98 end=0x00269b2c symbol=FUN_00269a98 lang=c++ */
/* Clone of src/eboot/reset_object_flags_002595e8.cpp (hstclone.py tag s10170158a1r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Re-initialisation of an object: FUN_00108e6c(this, 1010.0f), FUN_001090f4(this, -1), two calls on the global
   DAT_003751d4 with 0x2000, a virtual slot-10 call on the object at +0x58 when present, then flags +0x54 = 1,
   +0x55 = 0 and FUN_00108f54(this, 0). Names provisional. */
struct VC {
  virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
  virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
  virtual void s10();
};
struct Self {
  char pad[0x54];
  unsigned char b54;
  unsigned char b55;
  char pad2[2];
  VC *p58;
};
extern "C" {
extern int *DAT_003751d4;
void FUN_00108e6c(Self *, float);
void FUN_001090f4(Self *, int);
void FUN_0001dc34(int *, int);
void FUN_0001de88(int *, int, int);
void FUN_00108f54(Self *, int);
}

extern "C" void FUN_00269a98(Self *self)
{
  FUN_00108e6c(self, 1010.0f);
  FUN_001090f4(self, -1);
  FUN_0001dc34(DAT_003751d4, 0x2000);
  FUN_0001de88(DAT_003751d4, 0x2000, 1);
  if (self->p58) self->p58->s10();
  self->b54 = 1;
  self->b55 = 0;
  FUN_00108f54(self, 0);
}
