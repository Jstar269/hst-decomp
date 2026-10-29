/* HSTMATCH module=hstp_trans_main.prx start=0x0016a328 end=0x0016a3c0 symbol=FUN_0016a328 lang=c++ */
/* Clone of src/eboot/FUN_0015dd9c.cpp (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
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
extern "C" Owner *FUN_0016a328(Owner *self,short delete_flag)
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
