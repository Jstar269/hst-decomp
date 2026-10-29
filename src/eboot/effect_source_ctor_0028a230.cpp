/* HSTMATCH module=EBOOT.BIN start=0x0028a230 end=0x0028a328 symbol=FUN_0028a230 lang=c++ data=0x002fed44 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002fed44-0x002fed4c) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (generated draft FUN_0028a230.c, no tag) corrected by hand: the two new/ctor pairs
   use the null-case-else shape (`if (p != 0) modelA = ctor(p); else modelA = p;`), the stream choice is the
   ternary `init->stream2 ? init->stream2 : init->stream0` and the effect handle is the ternary
   `x ? FUN_0002fe80(x, str) : -1`; readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/effect_source.h"

extern "C" {
extern char DAT_00309d08;
extern void *FUN_00000bcc(...);
extern unsigned FUN_0002fe80(...);
extern ModelHolder *FUN_00056b98(...);
extern void *FUN_00286790(...);
}
/* Virtual view of a model holder: slot 1 attaches a stream. */
struct HolderA { virtual void d0(); virtual void SetStream(I3rStream *); };
struct HolderB { virtual void d0(); virtual void SetStream(I3rStream *); };

extern "C" EffectSource *FUN_0028a230(EffectSource *self,EffectInit *init)
{
  ModelHolder *holder;
  
  FUN_00286790(self);
  self->vtable = &DAT_00309d08;
  self->stream = 0;
  self->modelA = 0;
  self->modelB = 0;
  self->unk7c = 0;
  self->recs.data = 0;
  self->recs.count = 0;
  self->recs.cap = 0;
  holder = (ModelHolder *)FUN_00000bcc(MODEL_HOLDER_SIZE);
  if (holder != 0) {
    self->modelA = FUN_00056b98(holder);
  }
  else {
    self->modelA = holder;
  }
  holder = (ModelHolder *)FUN_00000bcc(MODEL_HOLDER_SIZE);
  if (holder != 0) {
    self->modelB = FUN_00056b98(holder);
  }
  else {
    self->modelB = holder;
  }
  self->stream = init->stream2 ? init->stream2 : init->stream0;
  ((HolderA *)self->modelA)->SetStream(init->stream0);
  ((HolderB *)self->modelB)->SetStream(init->stream1);
  self->unk7c = init->unk0c;
  self->started = 0;
  self->effect = self->stream->unk8 ? FUN_0002fe80(self->stream->unk8,"eff_get") : EFFECT_NONE;
  return self;
}
