/* HSTMATCH module=EBOOT.BIN start=0x0029ab94 end=0x0029acec symbol=FUN_0029ab94 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/net_adhoc.h"

struct RefObj {
  virtual void Release(int);
  virtual void Slot0();
};

extern "C" void FUN_002b7960(int, int);
extern "C" void FUN_000c06f0(RefObj *);
extern "C" int FUN_002b7dc0(void);
extern "C" void FUN_002b7738(int);
extern "C" void FUN_0029a584(const char *fmt, ...);
extern "C" void FUN_000ba78c(RefObj *);
extern "C" void FUN_00000a00(MatchState *);
extern "C" char DAT_002cb8bc[];
extern "C" char DAT_002cb8d0[];
extern "C" char DAT_002cb8f4[];
extern "C" RefObj *DAT_00338ac4;

/* Match state deleting destructor: leaves the ad-hoc session, releases its objects, frees when flag > 0. */
extern "C" MatchState *FUN_0029ab94(MatchState *self,short flag)
{
  RefObj *p;
  int r;

  if (self != 0) {
    FUN_002b7960(0,0x26);
    if (self->ref != 0) {
      FUN_000c06f0(self->ref);
    }
    p = self->ref;
    if (p != 0) {
      if (p != 0) {
        p->Release(1);
      }
      self->ref = 0;
    }
    r = self->handle;
    if (r >= 0) {
      FUN_002b7738(r);
      self->handle = -1;
    }
    if (self->active != 0) {
      self->active = 0;
      r = FUN_002b7dc0();
      if (r < 0) {
        FUN_0029a584(DAT_002cb8f4,r);
      } else {
        FUN_0029a584(DAT_002cb8d0);
      }
      FUN_000ba78c(DAT_00338ac4);
    }
    if (DAT_00338ac4 != 0) {
      if (DAT_00338ac4 != 0) {
        DAT_00338ac4->Release(1);
      }
      DAT_00338ac4 = 0;
    }
    FUN_0029a584(DAT_002cb8bc);
    p = self->obj1c;
    if (p != 0) {
      if (p != 0) {
        p->Release(1);
      }
      self->obj1c = 0;
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
