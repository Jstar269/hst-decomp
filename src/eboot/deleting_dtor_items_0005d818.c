/* HSTMATCH module=EBOOT.BIN start=0x0005d818 end=0x0005d8c4 symbol=FUN_0005d818 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Deleting destructor of an object holding a pointer array: every element is destroyed through
   FUN_0005ce3c(elem, 1), the member at +0 is destroyed through FUN_000104e0, the vector-like member
   at +4 through FUN_0005dca4 (behind a doubled null test on its address, as in destroy_buffers_0005ce3c.c),
   and a positive flag deletes the object. Names provisional. */
#include "hst/types.h"

extern void FUN_00000a00(void *);
extern void FUN_000104e0(void *);
extern void FUN_0005ce3c(void *, int);
extern void FUN_0005dca4(void *, int);

typedef struct {
  void *f0;
  void **items;
  u32 count;
} Obj;

#pragma opt_strength_reduction off
Obj *FUN_0005d818(Obj *self, short flag)
{
  char *p;
  u32 i;
  if (self != 0) {
    for (i = 0; i < self->count; i++) {
      FUN_0005ce3c(self->items[i], 1);
    }
    FUN_000104e0(self->f0);
    p = (char *)self + 4;
    if (p != 0) {
      if (p != 0) {
        FUN_0005dca4(p, 0);
      }
    }
    if (flag > 0) {
      FUN_00000a00(self);
    }
  }
  return self;
}
