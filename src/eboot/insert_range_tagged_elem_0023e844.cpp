/* HSTMATCH module=EBOOT.BIN start=0x0023e844 end=0x0023e930 symbol=FUN_0023e844 lang=c++ */
/* Hand-written reconstruction from the disassembly; readability pass; exact match verified; names and types await human review. */
#include "hst/tagged_deque.h"

struct Base {};
struct Tag : Base {};

/* Inline elements are copied as three floats, as retail does. */
struct Elem { float v[3]; };

extern "C" void FUN_00003ed4(void *, int);
extern "C" void FUN_00003370(void *, int, int, int, int, Tag);

/* Prepends the range [first, last) to the container, walking from the last element backwards. Heap-backed
   elements are rebuilt in the new slot with a fresh block holding the same contents. */
extern "C" void FUN_0023e844(TaggedDeque *deque, TaggedElem *first, TaggedElem *last) {
    TaggedElem *dst = deque->buf + deque->start;
    while (first < last) {
        dst--;
        last--;
        if (dst != 0) {
            if ((last->flags & TAGGED_ON_HEAP) == 0) {
                *(Elem *)dst = *(Elem *)last;
            } else {
                dst->flags = 0;
                dst->len = 0;
                dst->data = 0;
                FUN_00003ed4(dst, last->len);
                FUN_00003370(dst, 0, 0, (int)last->data, (int)last->data + last->len, Tag());
            }
        }
        deque->start = deque->start - 1;
        deque->size = deque->size + 1;
    }
}
