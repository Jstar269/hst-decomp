/* HSTMATCH module=EBOOT.BIN start=0x0028df14 end=0x0028e02c symbol=FUN_0028df14 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the virtual dispatches, float argument, and module data address; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002cfc8c;
struct RouteObj;
struct Sub;
extern "C" void FUN_0001dfe8(int,int);
extern "C" void FUN_0001e23c(int,int,int);
extern "C" void FUN_00103540(float,RouteObj *);
extern "C" void FUN_00103628(RouteObj *,int);
extern "C" void FUN_001037c8(RouteObj *,int);
extern "C" void FUN_001b3ce8(int *,int);
extern "C" void FUN_00280830(Sub *,int,int);
extern "C" void FUN_00281128(Sub *);
extern "C" void FUN_002817e0(Sub *);
extern "C" void FUN_0028e074(RouteObj *,int);
extern "C" int DAT_0034179c;

struct V30 {
  virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
  virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
  virtual void m8(); virtual void m9(); virtual void m10();
};
struct V10 { virtual void m0(); virtual void m1(); virtual void m2(); };
struct V0C { virtual void m0(); virtual void m1(int); };

/* Sub-object that the route object points at. */
struct Sub {
  char pad0[0x615];
  unsigned char unk615;     /* 0x615 */
  char pad616[6];
  unsigned int unk61c;      /* 0x61c */
};

struct RouteObj {
  char pad0[0x54];
  unsigned char unk54;      /* 0x54 */
  unsigned char unk55;      /* 0x55 */
  char pad56[2];
  V30 *unk58;               /* 0x58 */
  char pad5c[0x640 - 0x5c];
  Sub *sub;                 /* 0x640 */
  char pad644[0x65c - 0x644];
  V0C *unk65c;              /* 0x65c */
};

/* Sets up the route: configures the sub-object, runs the fixed setup calls and the virtual calls. */
extern "C" void FUN_0028df14(RouteObj *self)
{
  FUN_00281128(self->sub);
  FUN_00280830(self->sub,2,1);
  self->sub->unk61c = 1;
  self->sub->unk615 = 1;
  FUN_002817e0(self->sub);
  FUN_00103540(1010.0f,self);
  FUN_001037c8(self,0xffffffff);
  FUN_0001dfe8(DAT_002cfc8c,0x2000);
  FUN_0001e23c(DAT_002cfc8c,0x2000,1);
  if (self->unk58 != (V30 *)0x0) {
    self->unk58->m10();
  }
  self->unk54 = 1;
  self->unk55 = 0;
  FUN_00103628(self,0);
  ((V10 *)self)->m2();
  FUN_001037c8(self,0x10);
  self->unk65c->m1(1);
  FUN_0028e074(self,0);
  FUN_001b3ce8(&DAT_0034179c,4);
}
