/* HSTMATCH module=hstp_trans_main.prx start=0x0022b3bc end=0x0022b46c symbol=FUN_0022b3bc lang=c++ */
/* Clone of src/eboot/FUN_0021be48.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b2a50;
extern void FUN_00000a00(...);
extern u32 * FUN_001087a8(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

/* Screen object owning two heap children. */
struct OwnerScreen {
  u32 vtable;          /* 0x00 */
  char pad04[0xb4];    /* 0x04 */
  VC_0 *childA;        /* 0xb8 */
  VC_1 *childB;        /* 0xbc */
};

/* Deleting destructor: deletes both children, runs the base destructor, frees when flags > 0. */
extern "C" OwnerScreen * FUN_0022b3bc(OwnerScreen *self,short flags)
{
  if (self != (OwnerScreen *)0x0) {
    self->vtable = (unsigned int)(&DAT_003b2a50);
    if (self->childA != (VC_0 *)0x0) {
      delete self->childA;
      self->childA = 0;
    }
    if (self->childB != (VC_1 *)0x0) {
      delete self->childB;
      self->childB = 0;
    }
    FUN_001087a8(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
