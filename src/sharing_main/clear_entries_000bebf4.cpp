/* HSTMATCH module=hstp_trans_main.prx start=0x000bebf4 end=0x000becfc symbol=FUN_000bebf4 lang=c++ */
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
struct C_000c1ff4 {
  Elem **data;
  unsigned size;
  ~C_000c1ff4();
  Iter begin() const { return Iter(data); }
  Iter end() { return Iter(data + size); }
};
struct Vec1 : C_000c1ff4 {
  ~Vec1() {}
};
struct Vec : Vec1 {
  ~Vec() {}
};
struct Self {
  char pad[0x54];
  Vec *vec;
};
extern "C" Elem **FUN_000c1e90(Vec *, Elem **, Tag);

extern "C" void FUN_000bebf4(Self *self)
{
  if (self->vec == 0) return;
  for (Iter it = self->vec->begin(); it != self->vec->end(); it = Iter(FUN_000c1e90(self->vec, it.p, Tag()))) {
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
