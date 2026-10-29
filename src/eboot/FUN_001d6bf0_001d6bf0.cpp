/* HSTMATCH module=EBOOT.BIN start=0x001d6bf0 end=0x001d6ccc symbol=FUN_001d6bf0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: passed the module address through its address-named symbol; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_00309364;
extern u8 DAT_0034179c;
extern u32 DAT_0034a120;
extern u32 DAT_0034a65c;
extern u32 DAT_0034a664;
extern void FUN_00000a00(...);
extern void * FUN_0001f0f0(...);
extern void FUN_001b2d88(...);
extern int FUN_00231114(...);
extern int FUN_00232c58(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Object that owns one heap child, deleted by the destructor. */
struct Owner {
  const void *vtable; /* 0x00 */
  char pad04[0x38];
  void *child;        /* 0x3c */
};

/* Deleting destructor: installs the vtable, destroys the two global helper objects and the owned child, releases
   the DAT_0034179c object, runs the base destructor and frees the object when flag > 0. */
extern "C" Owner * FUN_001d6bf0(Owner *self,short flag)
{
  void *child;

  if (self != (Owner *)0x0) {
    self->vtable = &DAT_00309364;
    if (DAT_0034a65c != 0) {
      FUN_00231114(DAT_0034a65c,1);
      DAT_0034a65c = 0;
    }
    if (DAT_0034a664 != 0) {
      FUN_00232c58(DAT_0034a664,1);
      DAT_0034a664 = 0;
    }
    child = self->child;
    if (child != (void *)0x0) {
      delete ((VC_0 *)(child));
      self->child = 0;
    }
    FUN_001b2d88(&DAT_0034179c);
    DAT_0034a120 = 0;
    FUN_0001f0f0(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
