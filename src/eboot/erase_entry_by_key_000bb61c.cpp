/* HSTMATCH module=EBOOT.BIN start=0x000bb61c end=0x000bb780 symbol=FUN_000bb61c lang=c++ */
/* Clone of src/sharing_main/erase_entry_by_key_000bea90.cpp (hstclone.py tag s10170049g1r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Removes the entry whose first 6 bytes (memcmp 0x1100c) equal the key from the pointer vector at +0x54: frees its sub-object (+8) and itself, erases the slot (0xc1e90), reports 0xbd6f0 and returns 1. Matching idioms: the iterator is a one-pointer class with a free operator!= written !(a == b) (materialised xor/sltiu/xori) and a const begin(); the vector class has an out-of-line destructor (0xc1ff4, symbol __dt__10C_000c1ff4Fv) under two empty inline derived layers, which gives retail's three nested null tests around dtor(w, 0) + operator delete; the emptiness test goes through a const Size() so size is reloaded. When no entry is left the vector itself is deleted. Names provisional. */
struct Tag {};
struct Sub { int x; };
struct Elem {
  char key[8];
  Sub *sub;
};
struct Iter {
  Elem **p;
  Iter(Elem **q) : p(q) {}
  Iter &operator++() { ++p; return *this; }
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
  unsigned Size() const { return size; }
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
extern "C" {
int FUN_0001100c(Elem *, const void *, int);
void FUN_000be7f0(Vec *, Elem **, Tag);
void FUN_000ba3ac(const char *);
}
extern "C" char DAT_002d52a0[];
extern "C" char DAT_002d52bc[];

extern "C" int FUN_000bb61c(Self *self, const void *key)
{
  Vec *v = self->vec;
  if (v == 0) return 0;
  Iter it = v->begin();
  Vec *w;
  if (it != v->end()) {
    do {
      if (FUN_0001100c(*it, key, 6) == 0) {
        if ((*it)->sub != 0) {
          delete (*it)->sub;
          (*it)->sub = 0;
        }
        if (*it != 0) {
          delete *it;
          *it = 0;
        }
        FUN_000be7f0(self->vec, it.p, Tag());
        FUN_000ba3ac(DAT_002d52a0);
        return 1;
      }
      w = self->vec;
      if (w->Size() == 0) {
        if (w != 0) {
          delete w;
          self->vec = 0;
        }
        break;
      }
      ++it;
    } while (it != w->end());
  }
  FUN_000ba3ac(DAT_002d52bc);
  return 0;
}
