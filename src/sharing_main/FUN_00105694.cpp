/* HSTMATCH module=hstp_trans_main.prx start=0x00105694 end=0x001056e8 symbol=FUN_00105694 lang=c++ */
/* Clone of src/eboot/FUN_000ffd60.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
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
extern "C" void FUN_00105694(OwnerObj *self)
{
  OwnedObj *owned;
  
  owned = self->owned;
  if (owned != (OwnedObj *)0x0) {
    delete owned;
    self->owned = 0;
  }
  FUN_00000a00(self);
}
