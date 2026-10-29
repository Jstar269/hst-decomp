/* HSTMATCH module=EBOOT.BIN start=0x002595e8 end=0x0025967c symbol=FUN_002595e8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Re-initialisation of an object: FUN_00103540(this, 1010.0f), FUN_001037c8(this, -1), two calls on the global
   DAT_002cfc8c with 0x2000, a virtual slot-10 call on the object at +0x58 when present, then flags +0x54 = 1,
   +0x55 = 0 and FUN_00103628(this, 0). Names provisional. */
struct VC {
  virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
  virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
  virtual void s10();
};
#define INIT_FLOAT_VALUE 1010.0f
#define INIT_INDEX_NONE (-1)
#define GLOBAL_MASK_BIT 0x2000 /* bit passed to both calls on the global */

struct Self {
  char pad[0x54];
  unsigned char b54;  /* 0x54 set to 1 by the reset */
  unsigned char b55;  /* 0x55 cleared by the reset */
  char pad2[2];
  VC *p58;            /* 0x58 optional child, notified through virtual slot 10 */
};
extern "C" {
extern int *DAT_002cfc8c;
void FUN_00103540(Self *, float);
void FUN_001037c8(Self *, int);
void FUN_0001dfe8(int *, int);
void FUN_0001e23c(int *, int, int);
void FUN_00103628(Self *, int);
}

extern "C" void FUN_002595e8(Self *self)
{
  FUN_00103540(self, INIT_FLOAT_VALUE);
  FUN_001037c8(self, INIT_INDEX_NONE);
  FUN_0001dfe8(DAT_002cfc8c, GLOBAL_MASK_BIT);
  FUN_0001e23c(DAT_002cfc8c, GLOBAL_MASK_BIT, 1);
  if (self->p58) self->p58->s10();
  self->b54 = 1;
  self->b55 = 0;
  FUN_00103628(self, 0);
}
