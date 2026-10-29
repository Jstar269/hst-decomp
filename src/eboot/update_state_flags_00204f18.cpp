/* HSTMATCH module=EBOOT.BIN start=0x00204f18 end=0x0020507c symbol=FUN_00204f18 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: retail has two call sites of FUN_00204c88 (one per arm of the flag test), so both arms spell the call;
   the two Info bytes are read into locals before the test. */
#include "hst/chrsel_unit.h"

typedef unsigned char u8;

/* Shared object; only its second virtual method is called here. */
struct Obj0 { virtual void d0(); virtual void v1(); };
/* Info record looked up by the unit's first attribute id. */
struct Info { u8 pad0[12]; u8 unk0c; u8 unk0d; u8 pad1[0x24 - 14]; u8 unk24; };

extern "C" Info *FUN_00193474(int);
extern "C" void FUN_00204c88(void *, u8 *, u8 *, u8 *, int *, u8, u8, u8, u8, u8, int);
extern "C" void FUN_0020507c(ChrSelUnit *, int);
extern "C" void FUN_002052b8(ChrSelUnit *, int, u8);
extern "C" void FUN_00205374(ChrSelUnit *, int, u8);
extern "C" void FUN_00092630(void *, u8);
extern "C" void FUN_00205b54(ChrSelUnit *, int);
extern "C" void FUN_00205b4c(ChrSelUnit *, int);

/* Refreshes the unit from its info record: applies the attributes (flagged units report all three as changed)
   and updates the parts that changed. */
extern "C" void FUN_00204f18(ChrSelUnit *self)
{
  u8 changed2 = 0;
  u8 changed0 = 0;
  u8 changed5 = 0;
  Info *info = FUN_00193474(self->attr[0]);
  u8 hi = info->unk0d;
  u8 lo = info->unk0c;
  u8 w = self->unk78;
  if (self->flag == 0) {
    FUN_00204c88(self->handle, &changed0, &changed2, &changed5, self->attr, self->unk76, self->unk77, w, hi, lo, 0);
  } else {
    FUN_00204c88(self->handle, &changed0, &changed2, &changed5, self->attr, self->unk76, self->unk77, w, hi, lo, 0);
    changed0 = 1;
    changed2 = 1;
    changed5 = 1;
  }
  if (changed0 != 0) {
    FUN_0020507c(self, self->attr[0]);
  }
  if (changed2 != 0) {
    FUN_002052b8(self, 1, w);
  }
  if (changed5 != 0) {
    FUN_00205374(self, 1, w);
  }
  self->unk70 = info->unk24;
  FUN_00092630(self->handle, self->unk75);
  ((Obj0 *)self->handle)->v1();
  FUN_00205b54(self, 3);
  FUN_00205b4c(self, 1);
}
