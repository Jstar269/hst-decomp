/* HSTMATCH module=EBOOT.BIN start=0x000ea7b8 end=0x000ea868 symbol=FUN_000ea7b8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/pair_owner.h"

extern "C" {
extern u8 DAT_003076f0;
extern void FUN_00000a00(...);
extern PairOwner * FUN_0001f0f0(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

/* Deleting destructor: installs the vtable, deletes both owned children, runs the base destructor and frees
   the object when flag > 0. */
extern "C" PairOwner * FUN_000ea7b8(PairOwner *self,short flag)
{
  void *child;

  if (self != (PairOwner *)0x0) {
    self->vtable = &DAT_003076f0;
    child = self->first;
    if (child != (void *)0x0) {
      delete ((VC_0 *)(child));
      self->first = 0;
    }
    child = self->second;
    if (child != (void *)0x0) {
      delete ((VC_1 *)(child));
      self->second = 0;
    }
    FUN_0001f0f0(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
