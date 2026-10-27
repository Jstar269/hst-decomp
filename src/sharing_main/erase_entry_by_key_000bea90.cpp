/* HSTMATCH module=hstp_trans_main.prx start=0x000bea90 end=0x000bebf4 symbol=FUN_000bea90 lang=c++ data=0x0037bbac */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x0037bbac-0x0037bbe0) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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
struct C_000c1ff4 {
  Elem **data;
  unsigned size;
  ~C_000c1ff4();
  Iter begin() const { return Iter(data); }
  Iter end() { return Iter(data + size); }
  unsigned Size() const { return size; }
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
extern "C" {
int FUN_0001100c(Elem *, const void *, int);
void FUN_000c1e90(Vec *, Elem **, Tag);
void FUN_000bd6f0(const char *);
}

extern "C" int FUN_000bea90(Self *self, const void *key)
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
        FUN_000c1e90(self->vec, it.p, Tag());
        FUN_000bd6f0("DeleteJoinRequest Success\n");
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
  FUN_000bd6f0("DeleteJoinRequest Fail\n");
  return 0;
}
