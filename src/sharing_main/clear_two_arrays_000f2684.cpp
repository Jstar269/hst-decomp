/* HSTMATCH module=hstp_trans_main.prx start=0x000f2684 end=0x000f2754 symbol=FUN_000f2684 lang=c++ */
/* Clone of src/eboot/clear_two_arrays_000ecfbc.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: iterator loops over (data,size) vectors with a const begin() and non-const end() (otherwise the entry test folds to size*stride==0) and !(a==b) free operator!=; names and types await human review. */
struct Slot {
  char pad[0x44];
  int state;
  char pad1[0x60 - 0x48];
};
struct Entry {
  char pad[8];
  int state;
  char pad1[0x18 - 12];
};

template <class T>
struct It {
  T *p;
  It(T *q) : p(q) {}
  T *operator->() const { return p; }
  It &operator++() { ++p; return *this; }
};
template <class T>
inline bool operator==(const It<T> &a, const It<T> &b) { return a.p == b.p; }
template <class T>
inline bool operator!=(const It<T> &a, const It<T> &b) { return !(a == b); }

template <class T>
struct Vec {
  T *data;
  int size;
  It<T> begin() const { return It<T>(data); }
  It<T> end() { return It<T>(data + size); }
};

struct Self {
  char pad0[0x58];
  Vec<Slot> slots;
  char pad1[0x68 - 0x60];
  Vec<Entry> entries;
};

extern "C" void FUN_000f2684(Self *self)
{
  for (It<Slot> it = self->slots.begin(); it != self->slots.end(); ++it)
    it->state = 6;
  for (It<Entry> it = self->entries.begin(); it != self->entries.end(); ++it)
    it->state = 2;
}
