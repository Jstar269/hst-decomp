/* HSTMATCH module=hstp_trans_main.prx start=0x0005fb08 end=0x0005fc4c symbol=FUN_0005fb08 lang=c++ */
/* Clone of src/eboot/set_indexed_value_0005ed18.cpp (hstclone.py tag km1): addresses substituted; exact match verified; names and types await human review. */
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

extern "C" void FUN_0005fc4c(Obj *, unsigned);
extern "C" void FUN_0006037c(int **, unsigned);
extern "C" void FUN_00060020(unsigned **, unsigned);
extern "C" void FUN_000602c8(int **, unsigned, int *, Tag);
extern "C" void FUN_0006011c(unsigned **, unsigned, int);

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

extern "C" void FUN_0005fb08(Obj *self, unsigned index, unsigned value)
{
  FUN_0005fc4c(self, index);
  if (self->fB0 > index) {
  }
  else {
    unsigned n = (index + 16) & 0xfffffff0u;
    if (self->Cap() < n) {
      FUN_0006037c(&self->fA8, n);
    }
    if ((self->fBC << 5) < n) {
      FUN_00060020(&self->fB4, n);
    }
  }
  if (self->fAC > index) {
  }
  else {
    int local_4 = 0;
    unsigned count = index + 1;
    if (self->fAC < count) {
      FUN_000602c8(&self->fA8, count - self->fAC, &local_4, Tag());
    } else if (count < self->fAC) {
      unsigned delta = self->fAC - count;
      self->fAC = self->fAC - delta;
    }
    FUN_0006011c(&self->fB4, count, 0);
  }
  self->fA8[index] = value;
  self->fB4[index >> 5] &= ~(1u << (index & 0x1f));
}
