/* HSTMATCH module=EBOOT.BIN start=0x0017c284 end=0x0017c304 symbol=FUN_0017c284 lang=c++ */
/* Hand-written reconstruction from the disassembly; matching idiom: one-pointer iterator with a user-declared copy constructor and free bool operator!=; exact match verified; names and types await human review. */
struct It {
  int *p;
  It(int *x) : p(x) {}
  It(const It& x) : p(x.p) {}
  It& operator++() { ++p; return *this; }
  int operator*() const { return *p; }
};
static inline bool operator!=(It a,It b) { return (a.p == b.p) ^ 1; }
struct View { char pad[8]; int *data; volatile int count; It begin() { return It(data); } It end() { return It(data + count); } };
extern "C" void FUN_00091c48(int,int);
extern "C" void FUN_0017c284(View *self) {
  It first = self->begin();
  for (; first != self->end(); ++first) FUN_00091c48(*first + 0x10,0);
}
