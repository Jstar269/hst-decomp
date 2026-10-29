/* HSTMATCH module=EBOOT.BIN start=0x000ffd60 end=0x000ffdb4 symbol=FUN_000ffd60 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_00000a00(...);
}
struct OwnedObj { virtual ~OwnedObj(); };

/* Object that owns one virtual-destructor object at 0x20. */
struct OwnerObj {
  char pad0[0x20];
  OwnedObj *owned; /* 0x20 */
};

/* Deletes the owned object (clearing the pointer), then frees the owner. */
extern "C" void FUN_000ffd60(OwnerObj *self)
{
  OwnedObj *owned;
  
  owned = self->owned;
  if (owned != (OwnedObj *)0x0) {
    delete owned;
    self->owned = 0;
  }
  FUN_00000a00(self);
}
