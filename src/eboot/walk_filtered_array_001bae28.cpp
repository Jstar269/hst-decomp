/* HSTMATCH module=EBOOT.BIN start=0x001bae28 end=0x001baecc symbol=FUN_001bae28 lang=c++ */
/* Hand-written reconstruction from the disassembly; matching idiom: one-pointer iterator with a user-declared copy constructor and free bool operator!=; exact match verified; names and types await human review. */

struct It {
  int *p;
  It(int *x) : p(x) {}
  It(const It& x) : p(x.p) {}
  It& operator++() { ++p; return *this; }
  int operator*() const { return *p; }
};
static inline bool operator!=(It a,It b) { return (a.p == b.p) ^ 1; }

struct View {
  char pad[4];
  int *data;
  volatile int count;
  char pad_c[0x8];
  unsigned char flags1[4]; /* 0x14 */
  unsigned char flags2[4]; /* 0x18 */

  It begin() { return It(data); }
  It end() { return It(data + count); }
};

extern "C" void FUN_00205dbc(int, int);

extern "C" void FUN_001bae28(View *self) {
  It first = self->begin();
  int i = 0;
  for (; first != self->end(); ++first, ++i) {
    if (self->flags1[i] != 0) {
      if (self->flags2[i] == 0) {
        FUN_00205dbc(*first, 0);
      }
    }
  }
}
