/* HSTMATCH module=hstp_trans_main.prx start=0x00210e9c end=0x00210f28 symbol=FUN_00210e9c lang=c++ */
/* Clone of src/eboot/FUN_002026cc.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
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
extern "C" TwoOwner *FUN_00210e9c(TwoOwner *self,short flag)
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
