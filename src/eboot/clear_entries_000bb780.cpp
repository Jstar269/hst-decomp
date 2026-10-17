/* HSTMATCH module=EBOOT.BIN start=0x000bb780 end=0x000bb888 symbol=FUN_000bb780 lang=c++ */
/* Clone of src/sharing_main/clear_entries_000bebf4.cpp (hstclone.py tag c034920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Frees every entry (and its sub-object at +8) of the pointer vector at +0x54, erasing each slot as it goes (0xc1e90), then deletes the vector itself. Same container idioms as erase_entry_by_key_000bea90.cpp (one-pointer iterator with a free operator!= written !(a == b), const begin(), out-of-line vector destructor under two empty inline derived layers); every access goes through self->vec, a cached local flips the s0/s1 assignment. Names provisional. */
struct Tag {};
struct Sub { int x; };
struct Elem {
  char pad[8];
  Sub *sub;
};
struct Iter {
  Elem **p;
  Iter(Elem **q) : p(q) {}
  Elem *&operator*() const { return *p; }
};
inline bool operator==(const Iter &a, const Iter &b) { return a.p == b.p; }
inline bool operator!=(const Iter &a, const Iter &b) { return !(a == b); }
struct C_000be954 {
  Elem **data;
  unsigned size;
  ~C_000be954();
  Iter begin() const { return Iter(data); }
  Iter end() { return Iter(data + size); }
};
struct Vec1 : C_000be954 {
  ~Vec1() {}
};
struct Vec : Vec1 {
  ~Vec() {}
};
struct Self {
  char pad[0x54];
  Vec *vec;
};
extern "C" Elem **FUN_000be7f0(Vec *, Elem **, Tag);

extern "C" void FUN_000bb780(Self *self)
{
  if (self->vec == 0) return;
  for (Iter it = self->vec->begin(); it != self->vec->end(); it = Iter(FUN_000be7f0(self->vec, it.p, Tag()))) {
    if ((*it)->sub != 0) {
      delete (*it)->sub;
      (*it)->sub = 0;
    }
    if (*it != 0) {
      delete *it;
      *it = 0;
    }
  }
  if (self->vec != 0) {
    delete self->vec;
    self->vec = 0;
  }
}
