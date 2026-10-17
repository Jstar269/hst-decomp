/* HSTMATCH module=EBOOT.BIN start=0x001c6180 end=0x001c627c symbol=FUN_001c6180 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: pointer-vector loop rewritten with the It<T>/Vec<T> idiom of clear_item_flags_00102194.cpp (const begin(), non-const end(), free operator!= as !(a == b)), the && test kept as a materialised int flag, typed views of the object; exact match verified; names and types await human review. */
struct Ent {
  virtual void v0();
  virtual void v1();
};

template <class T> struct It {
  T *p_;
  It(T *p) : p_(p) {}
  T &operator*() const { return *p_; }
  It &operator++() { ++p_; return *this; }
};
template <class T> inline bool operator==(const It<T> &a, const It<T> &b) { return a.p_ == b.p_; }
template <class T> inline bool operator!=(const It<T> &a, const It<T> &b) { return !(a == b); }

template <class T> struct Vec {
  T *data_;
  unsigned size_;
  unsigned cap_;
  It<T> begin() const { return It<T>(data_); }
  It<T> end() { return It<T>(data_ + size_); }
};

struct State {
  int f0;
  int kind;
  int f8;
  char pad[0xfc - 0xc];
  int ffc;
};

struct Obj {
  char pad0[0x40];
  Vec<Ent *> ents;
  char pad1[0xc4 - 0x4c];
  int fc4;
  int fc8;
  char pad2[0x15c - 0xcc];
  State *state;
};

extern "C" void FUN_0001ebd4(void);
extern "C" void FUN_0001efac(void);
extern "C" void FUN_001c2498(State *);
extern "C" void FUN_00286f2c(Ent *);

extern "C" void FUN_001c6180(Obj *o)
{
  FUN_001c2498(o->state);
  FUN_0001ebd4();
  State *s = o->state;
  int ok = s->kind == 0xc;
  if (ok) ok = s->f8 < s->ffc;
  if (ok) {
    for (It<Ent *> it = o->ents.begin(); it != o->ents.end(); ++it) {
      Ent *e = *it;
      FUN_00286f2c(e);
      e->v1();
    }
  }
  if (o->state->kind != 0xc) {
    o->fc4 = 2;
    o->fc8 = 0;
  }
  FUN_0001efac();
}
