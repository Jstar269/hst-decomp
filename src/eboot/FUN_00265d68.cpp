/* HSTMATCH module=EBOOT.BIN start=0x00265d68 end=0x00265df8 symbol=FUN_00265d68 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_00309ae0;
extern void FUN_00000a00(...);
extern u32 * FUN_0001f0f0(...);
extern void FUN_00254114(...);
}
struct Member { virtual ~Member(); };

struct Owner {
  void *vptr;
  char pad04[0x38];
  Member *member;  /* 0x3c owned object */
};

/* Deleting destructor (short flag): deletes the owned member, then runs the base destruction; frees self when flag > 0. */
extern "C" Owner * FUN_00265d68(Owner *self,short flag)
{
  Member *member;
  
  if (self != 0) {
    self->vptr = &DAT_00309ae0;
    member = self->member;
    if (member != 0) {
      delete member;
      self->member = 0;
    }
    FUN_00254114();
    FUN_0001f0f0(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
