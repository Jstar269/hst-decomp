/* HSTMATCH module=EBOOT.BIN start=0x0005ed18 end=0x0005ee5c symbol=FUN_0005ed18 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Sets an element of a growable int array (the data pointer at +0xa8, the count at +0xac, the capacity
   at +0xb0) and clears the element's bit in the parallel bitmap (+0xb4, one bit per element).
   Matching idioms: the fourth argument of the grow helper is an EMPTY tag struct passed BY VALUE
   (not a literal 0), which is what produces retail's `move v0,zero; seb a3,v0`; the capacity is read
   through a const inline getter so the second access is not CSE'd with the first (retail reloads it);
   and both range tests are spelled `value > index` with the tested arm inverted, which puts the compare
   result in `at` and the branch in the `bnezl` form. */
typedef struct Obj Obj;

struct Tag {
};

extern "C" void FUN_0005ee5c(Obj *, unsigned);
extern "C" void FUN_0005f58c(int **, unsigned);
extern "C" void FUN_0005f230(unsigned **, unsigned);
extern "C" void FUN_0005f4d8(int **, unsigned, int *, Tag);
extern "C" void FUN_0005f32c(unsigned **, unsigned, int);

struct Obj {
  int pad[0x2a];
  int *fA8;
  unsigned fAC;
  unsigned fB0;
  unsigned *fB4;
  unsigned fB8;
  unsigned fBC;
  unsigned Cap() const { return fB0; }
};

extern "C" void FUN_0005ed18(Obj *self, unsigned index, unsigned value)
{
  FUN_0005ee5c(self, index);
  if (self->fB0 > index) {
  }
  else {
    unsigned n = (index + 16) & 0xfffffff0u;
    if (self->Cap() < n) {
      FUN_0005f58c(&self->fA8, n);
    }
    if ((self->fBC << 5) < n) {
      FUN_0005f230(&self->fB4, n);
    }
  }
  if (self->fAC > index) {
  }
  else {
    int local_4 = 0;
    unsigned count = index + 1;
    if (self->fAC < count) {
      FUN_0005f4d8(&self->fA8, count - self->fAC, &local_4, Tag());
    } else if (count < self->fAC) {
      unsigned delta = self->fAC - count;
      self->fAC = self->fAC - delta;
    }
    FUN_0005f32c(&self->fB4, count, 0);
  }
  self->fA8[index] = value;
  self->fB4[index >> 5] &= ~(1u << (index & 0x1f));
}
