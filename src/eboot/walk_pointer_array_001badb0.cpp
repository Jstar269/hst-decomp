/* HSTMATCH module=EBOOT.BIN start=0x001badb0 end=0x001bae28 symbol=FUN_001badb0 lang=c++ */
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
extern "C" void FUN_00205bc0(int);
extern "C" void FUN_001badb0(View *self) {
  It first = self->begin();
  for (; first != self->end(); ++first) FUN_00205bc0(*first);
}
