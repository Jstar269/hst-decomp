/* HSTMATCH module=EBOOT.BIN start=0x001ea854 end=0x001ea8c4 symbol=FUN_001ea854 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */

#include "hst/child_owner.h"

extern "C" {
extern void FUN_00000a00(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Deleting destructor: deletes the owned child and frees the object when flag > 0. */
extern "C" ChildOwner * FUN_001ea854(ChildOwner *self,short flag)
{
  VC_0 *child;

  if (self != (ChildOwner *)0x0) {
    child = (VC_0 *)self->child;
    if (child != (VC_0 *)0x0) {
      delete child;
      self->child = 0;
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
