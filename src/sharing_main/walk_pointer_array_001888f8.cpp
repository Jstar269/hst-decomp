/* HSTMATCH module=hstp_trans_main.prx start=0x001888f8 end=0x00188978 symbol=FUN_001888f8 lang=c++ */
/* Clone of src/eboot/walk_pointer_array_0017c204.cpp (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; matching idiom: one-pointer iterator with a user-declared copy constructor and free bool operator!=; exact match verified; names and types await human review. */
struct It {
  int *p;
  It(int *x) : p(x) {}
  It(const It& x) : p(x.p) {}
  It& operator++() { ++p; return *this; }
  int operator*() const { return *p; }
};
static inline int operator!=(It a,It b) { return (a.p == b.p) ^ 1; }
struct View { char pad[8]; int *data; volatile int count; It begin() { return It(data); } It end() { return It(data + count); } };
extern "C" void FUN_000938e0(int,int);
extern "C" void FUN_001888f8(View *self) {
  It first = self->begin();
  for (; first != self->end(); ++first) FUN_000938e0(*first + 0x10,-1);
}
