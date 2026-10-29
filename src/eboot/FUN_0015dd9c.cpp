/* HSTMATCH module=EBOOT.BIN start=0x0015dd9c end=0x0015de34 symbol=FUN_0015dd9c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern void FUN_00000a00(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

struct Owner {
  char pad00[0x20];
  VC_0 *objA;  /* 0x20 */
  char pad24[0x40 - 0x24];
  VC_1 *objB;  /* 0x40 */
};

/* Releases the two owned objects, then frees the owner itself when delete_flag is positive. */
extern "C" Owner *FUN_0015dd9c(Owner *self,short delete_flag)
{
  if (self != 0) {
    if (self->objA != 0) {
      delete self->objA;
      self->objA = 0;
    }
    if (self->objB != 0) {
      delete self->objB;
      self->objB = 0;
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
