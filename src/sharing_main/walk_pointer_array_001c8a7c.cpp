/* HSTMATCH module=hstp_trans_main.prx start=0x001c8a7c end=0x001c8af8 symbol=FUN_001c8a7c lang=c++ */
/* Clone of src/eboot/walk_pointer_array_001bad34.cpp (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; matching idiom: one-pointer iterator with a user-declared copy constructor and free bool operator!=; exact match verified; names and types await human review. */
struct It {
  int *p;
  It(int *x) : p(x) {}
  It(const It& x) : p(x.p) {}
  It& operator++() { ++p; return *this; }
  int operator*() const { return *p; }
};
static inline bool operator!=(It a,It b) { return (a.p == b.p) ^ 1; }
struct View { char pad[4]; int *data; volatile int count; It begin() { return It(data); } It end() { return It(data + count); } };
extern "C" void FUN_002143b4(int,int);
extern "C" void FUN_001c8a7c(View *self) {
  It first = self->begin();
  for (; first != self->end(); ++first) FUN_002143b4(*first,2);
}
