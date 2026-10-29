/* HSTMATCH module=EBOOT.BIN start=0x0014762c end=0x00147724 symbol=FUN_0014762c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a2/v0) corrected by hand: the three calls to the delete function take their arguments (element buffer field, the buffer pointer *self, and the object itself); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00(void *);
extern int FUN_00147724();
extern int FUN_0014772c();

/* 0x28-byte element; bit 0 of flags marks that it owns the buffer at buf. */
typedef struct OwnedElem {
  u32 flags;   /* 0x00 */
  int unk04;   /* 0x04 */
  void *buf;   /* 0x08 */
  char pad0c[0x1c];
} OwnedElem;   /* size 0x28 */

#define OWNED_ELEM_HAS_BUF 1

/* Array of elements: storage pointer, element count, and the index of the first live element. */
typedef struct ElemArray {
  OwnedElem *data;  /* 0x00 */
  int size;         /* 0x04 */
  char pad08[8];
  int start;        /* 0x10 */
} ElemArray;

/* Deleting destructor: frees the owned buffers of the live elements, then the array and the object. */
ElemArray *FUN_0014762c(ElemArray *self,short flags)
{
  OwnedElem *first;
  OwnedElem *last;
  
  if (self != (ElemArray *)0x0) {
    first = self->data + self->start;
    last = first + self->size;
    if (first < last) {
      do {
        last = last - 1;
        if (((last != (OwnedElem *)0x0) && (last != (OwnedElem *)0x0)) && ((last->flags & OWNED_ELEM_HAS_BUF) != 0)) {
          FUN_00000a00(last->buf);
        }
      } while (first < last);
      self->size = 0;
    }
    else {
      self->size = 0;
    }
    if ((self != (ElemArray *)0x0) && (FUN_0014772c(self), self->data != 0)) {
      FUN_00147724(self);
      FUN_00000a00(self->data);
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
