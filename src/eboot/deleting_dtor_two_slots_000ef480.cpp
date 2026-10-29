/* HSTMATCH module=EBOOT.BIN start=0x000ef480 end=0x000ef564 symbol=FUN_000ef480 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5, variant v17c) corrected by hand: flag byte typed unsigned char, the global pointer read once into a local inside the flag block, locals declared index/walking pointer/element; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

enum { SLOT_COUNT = 2 };

struct VC_0 { virtual ~VC_0(); };

struct GlobalState {
  char pad00[0xc];
  int unkc;                 /* 0x0c */
  char pad10[0x52 - 0x10];
  u8 unk52;                 /* 0x52 */
};

struct Self {
  const void *vtable;       /* 0x00 */
  char pad04[0x55 - 0x4];
  u8 registered;            /* 0x55 when set, the global state is reset on destruction */
  char pad56[0x94 - 0x56];
  VC_0 *slots[SLOT_COUNT];  /* 0x94 */
  void *owned;              /* 0x9c released with FUN_0005ba00 */
};

extern "C" {
extern u8 DAT_003078f4;
extern GlobalState * DAT_00331b84;
extern void FUN_00000a00(...);
extern int FUN_0005ba00(...);
extern u32 * FUN_00102ea4(...);
}

/* Deleting destructor: releases the owned object and the two slot objects, then runs the base destructor. */
extern "C" Self * FUN_000ef480(Self *self,short delete_flag)
{
  int i;
  VC_0 *item;

  if (self != 0) {
    self->vtable = &DAT_003078f4;
    if (self->owned != 0) {
      FUN_0005ba00(self->owned,1);
      self->owned = 0;
    }
    i = 0;
    do {
      item = self->slots[i];
      if (item != 0) {
        delete item;
        self->slots[i] = 0;
      }
      i = i + 1;
    } while (i < SLOT_COUNT);
    if (self->registered != 0) {
      GlobalState *g = DAT_00331b84;
      g->unkc = 0;
      g->unk52 = 0;
    }
    FUN_00102ea4(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
