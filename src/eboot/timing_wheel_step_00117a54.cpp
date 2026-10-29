/* HSTMATCH module=EBOOT.BIN start=0x00117a54 end=0x00117c24 symbol=FUN_00117a54 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   The nine-slot expiry is a real C++ virtual call (a function-pointer call compiles to `lw v0,slot; jalr v0`,
   retail has `lw t9`), the latch test is written as one condition (`f < 0 && -f <= unk58`) which is what puts the
   negation before the field load, and the two stack temporaries must be declared `b` before `a` to land in
   retail's slots (0x2c/0x28). */
#include "hst/wheel_state.h"

extern void *DAT_003386b0;

class Obj {
public:
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6();
  virtual void v7();
  virtual void v8();
  virtual void v9();
  virtual void v10();
};

/* Global object holding the polymorphic helper at 0x88. */
typedef struct Mgr {
  char pad0[0x88];
  Obj *unk88;
} Mgr;

extern "C" void FUN_0001f558(void *, int, int, int);
extern "C" void FUN_001180b0(WheelState *, WheelEntry *, int);
extern "C" void FUN_0008ac88(void *);

/* Advances the nine-slot wheel by one step: expires slots through the virtual call, tracks the latch and notifies when due. */
extern "C" void FUN_00117a54(WheelState *self)
{
  int notify;
  int i;
  int idx;
  int n;
  int f;
  int b;
  int a;
  int *p;
  WheelEntry *e;
  Obj *o;
  int j;

  notify = 0;
  if (self->unk60 < 0)
    goto set_notify;
  {
    if (self->unk58 == self->unk50)
      FUN_0001f558(DAT_003386b0, 0x14, 0, 0);
    i = self->unk68;
    idx = (i + 1) % WHEEL_SLOTS;
    e = &self->ring[idx];
    if (e->unk38 >= 0) {
      if (self->unk58 >= e->unk38) {
        FUN_001180b0(self, e, 1);
        o = ((Mgr *)DAT_003386b0)->unk88;
        n = self->unk58 - e->unk38;
        for (j = 0; j < n; j++)
          o->v10();
        self->unk68 = idx;
        self->unk70 = n - 1;
        i = self->unk68;
        e = &self->ring[(i + 1) % WHEEL_SLOTS];
      }
    }
    f = e->unk38;
    if (f < 0 && -f <= self->unk58)
      notify = 1;
    a = self->ring[i].unk40 - 1;
    b = self->unk70 + 1;
    p = (a < b) ? &a : &b;
    self->unk70 = *p;
    self->unk58 = self->unk58 + 1;
  }
  goto tail;
set_notify:
  notify = 1;
tail:
  if (notify)
    FUN_0008ac88(DAT_003386b0);
}
