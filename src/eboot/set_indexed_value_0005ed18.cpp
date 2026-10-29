/* HSTMATCH module=EBOOT.BIN start=0x0005ed18 end=0x0005ee5c symbol=FUN_0005ed18 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Sets an element of a growable int array (the data pointer `values`, the count `count`, the capacity
   `capacity`) and clears the element's bit in the parallel bitmap (`bits`, one bit per element).
   Matching idioms: the fourth argument of the grow helper is an EMPTY tag struct passed BY VALUE
   (not a literal 0), which is what produces retail's `move v0,zero; seb a3,v0`; the capacity is read
   through a const inline getter so the second access is not CSE'd with the first (retail reloads it);
   and both range tests are spelled `value > index` with the tested arm inverted, which puts the compare
   result in `at` and the branch in the `bnezl` form. */
#include "hst/indexed_bits.h"

typedef IndexedBits Obj;

struct Tag {
};

extern "C" void FUN_0005ee5c(Obj *, unsigned);
extern "C" void FUN_0005f58c(int **, unsigned);
extern "C" void FUN_0005f230(unsigned **, unsigned);
extern "C" void FUN_0005f4d8(int **, unsigned, int *, Tag);
extern "C" void FUN_0005f32c(unsigned **, unsigned, int);

/* Const getter so the capacity is re-read for the second test. */
inline unsigned Cap(const Obj *o) { return o->capacity; }

extern "C" void FUN_0005ed18(Obj *self, unsigned index, unsigned value)
{
  FUN_0005ee5c(self, index);
  if (self->capacity > index) {
  }
  else {
    unsigned n = (index + 16) & 0xfffffff0u;
    if (Cap(self) < n) {
      FUN_0005f58c(&self->values, n);
    }
    if ((self->bitWords << 5) < n) {
      FUN_0005f230(&self->bits, n);
    }
  }
  if (self->count > index) {
  }
  else {
    int zero = 0;
    unsigned count = index + 1;
    if (self->count < count) {
      FUN_0005f4d8(&self->values, count - self->count, &zero, Tag());
    } else if (count < self->count) {
      unsigned delta = self->count - count;
      self->count = self->count - delta;
    }
    FUN_0005f32c(&self->bits, count, 0);
  }
  self->values[index] = value;
  self->bits[index >> 5] &= ~(1u << (index & 0x1f));
}
