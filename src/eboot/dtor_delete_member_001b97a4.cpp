/* HSTMATCH module=EBOOT.BIN start=0x001b97a4 end=0x001b982c symbol=FUN_001b97a4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: C++ virtual deleting-destructor call (struct with a 4-byte non-polymorphic base so the vptr is at +4), delete of the member; readability pass; exact match verified; names and types await human review. */
#include "hst/owned_member_obj.h"

extern char DAT_003092f8;
extern "C" void FUN_00000a00(void *);
extern "C" void FUN_0001f0f0(void *, int);
struct VB_0 { int x; };
struct VC_0 : VB_0 { virtual ~VC_0(); };

/* Deleting destructor: sets the vtable, deletes the owned member, runs the base teardown, frees when flag > 0. */
extern "C" OwnedMemberObj *FUN_001b97a4(OwnedMemberObj *self, short flag)
{
  if (self != 0) {
    self->vtable = (unsigned)&DAT_003092f8;
    VC_0 *m = (VC_0 *)self->member;
    if (m != 0) {
      delete m;
      self->member = 0;
    }
    FUN_0001f0f0(self, 0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
