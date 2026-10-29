/* HSTMATCH module=EBOOT.BIN start=0x0023eb04 end=0x0023ebec symbol=FUN_0023eb04 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: declared the nested delete helper arguments and passed the deleted fields; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/tagged_deque.h"

extern void FUN_00000a00(void *);
extern int FUN_0023ebec();

/* Deleting destructor of the container: frees the heap block of every tagged element (last to first), releases the storage, then the object when delete_flag > 0. */
TaggedDeque * FUN_0023eb04(TaggedDeque *self,short delete_flag)
{
  TaggedElem *first;
  TaggedElem *last;
  
  if (self != (TaggedDeque *)0x0) {
    first = self->buf + self->start;
    last = first + self->size;
    if (first < last) {
      do {
        last = last + -1;
        if ((last != (TaggedElem *)0x0) && ((last->flags & TAGGED_ON_HEAP) != 0)) {
          FUN_00000a00(last->data);
        }
      } while (first < last);
      self->size = 0;
    }
    else {
      self->size = 0;
    }
    if ((self != (TaggedDeque *)0x0) && (FUN_0023ebec(self), self->buf != 0)) {
      FUN_00000a00(self->buf);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
