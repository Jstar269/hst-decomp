/* HSTMATCH module=EBOOT.BIN start=0x0028a8f4 end=0x0028a9ac symbol=FUN_0028a8f4 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/effect_source.h"

extern "C" void FUN_00057b58(float, ModelHolder *, int, int);
extern "C" void FUN_00058ec4(float, ModelHolder *, int);
extern "C" void FUN_00058f38(float, ModelHolder *, int);
extern "C" void FUN_0005f110(float, ModelHolder *);
extern "C" void FUN_00058ddc(ModelHolder *, int, int);
extern "C" void FUN_00059084(ModelHolder *, int);

/* Resets the first model holder's state, passing a1 and a2 to the setters. */
extern "C" void FUN_0028a8f4(EffectSource *self, int a1, int a2)
{
  FUN_00057b58(0.0f, self->modelA, 0, a1);
  ModelHolder *p = self->modelA;
  FUN_00058ec4(1.0f, p, -1);
  p->unkc4 = 1.0f;
  p = self->modelA;
  FUN_00058f38(0.0f, p, -1);
  FUN_0005f110(0.0f, p);
  p = self->modelA;
  FUN_00058ddc(p, a2, -1);
  p->unkc0 = a2;
  p = self->modelA;
  FUN_00059084(p, -1);
  p->unkd0 = p->unkc4;
}
