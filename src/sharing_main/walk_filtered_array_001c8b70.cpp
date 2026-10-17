/* HSTMATCH module=hstp_trans_main.prx start=0x001c8b70 end=0x001c8c14 symbol=FUN_001c8b70 lang=c++ */
/* Clone of src/eboot/walk_filtered_array_001bae28.cpp (hstclone.py tag u2r1s): addresses substituted; exact match verified; names and types await human review. */
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

extern "C" void FUN_00214624(int, int);

extern "C" void FUN_001c8b70(View *self) {
  It first = self->begin();
  int i = 0;
  for (; first != self->end(); ++first, ++i) {
    if (self->flags1[i] != 0) {
      if (self->flags2[i] == 0) {
        FUN_00214624(*first, 0);
      }
    }
  }
}
