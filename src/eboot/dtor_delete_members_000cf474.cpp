/* HSTMATCH module=EBOOT.BIN start=0x000cf474 end=0x000cf54c symbol=FUN_000cf474 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: loop index declared before the member pointer (s-register order); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern char DAT_003074dc;
extern void FUN_00000a00(...);
extern u32 * FUN_0001f0f0(...);
}
struct Member { virtual ~Member(); };
struct Extra { virtual ~Extra(); };

#define MEMBER_COUNT 0x16 /* owned member pointers, starting at 0x40 */

struct Owner {
  void *vptr;
  char pad04[0x3c];
  Member *members[MEMBER_COUNT];  /* 0x40 */
  char pad98[4];
  Extra *extra;                   /* 0x9c */
};

/* Deleting destructor (short flag): deletes every owned member, then the extra object; frees self when flag > 0. */
extern "C" Owner * FUN_000cf474(Owner *self,short flag)
{
  int i;
  Member *obj;
  Extra *extra;
  
  if (self != 0) {
    self->vptr = &DAT_003074dc;
    i = 0;
    do {
      obj = self->members[i];
      if (obj != 0) {
        delete obj;
        self->members[i] = 0;
      }
      i = i + 1;
    } while (i < MEMBER_COUNT);
    extra = self->extra;
    if (extra != 0) {
      delete extra;
      self->extra = 0;
    }
    FUN_0001f0f0(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
