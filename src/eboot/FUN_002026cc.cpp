/* HSTMATCH module=EBOOT.BIN start=0x002026cc end=0x00202758 symbol=FUN_002026cc lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_00000a00(...);
}
struct OwnedA { virtual ~OwnedA(); };
struct OwnedB { virtual ~OwnedB(); };

/* Object that owns two polymorphic members. */
struct TwoOwner {
  char pad0[0x520];
  OwnedB *second;  /* 0x520 */
  OwnedA *first;   /* 0x524 */
};

/* Deleting destructor body (short flag): releases both owned members, frees self when flag > 0. */
extern "C" TwoOwner *FUN_002026cc(TwoOwner *self,short flag)
{
  OwnedA *a;
  OwnedB *b;
  
  if (self != 0) {
    a = self->first;
    delete a;
    b = self->second;
    if (b != 0) {
      delete b;
      self->second = 0;
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
