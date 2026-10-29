/* HSTMATCH module=EBOOT.BIN start=0x0027ba20 end=0x0027bad0 symbol=FUN_0027ba20 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5/v17c) corrected by hand: declared the loop index before the cursor to match saved-register allocation; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

#define OWNED_COUNT 3

extern "C" {
extern u8 DAT_00309c44;
extern void FUN_00000a00(...);
extern void * FUN_0001f0f0(...);
}
struct Owned { virtual ~Owned(); };
struct Holder {
  const void *vptr;           /* 0x00 */
  char pad04[0x3c - 4];
  Owned *owned[OWNED_COUNT];  /* 0x3c */
};

/* Destructor: delete the owned objects, run the base destructor and free the object when flag > 0. */
extern "C" Holder * FUN_0027ba20(Holder *self,short flag)
{
  Owned *child;
  int i;
  Holder *cursor; /* walks the holder base 4 bytes per child */
  
  if (self != (Holder *)0x0) {
    self->vptr = &DAT_00309c44;
    i = 0;
    cursor = self;
    do {
      child = cursor->owned[0];
      if (child != 0) {
        delete child;
        cursor->owned[0] = 0;
      }
      i = i + 1;
      cursor = (Holder *)((char *)cursor + 4);
    } while (i < OWNED_COUNT);
    FUN_0001f0f0(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
