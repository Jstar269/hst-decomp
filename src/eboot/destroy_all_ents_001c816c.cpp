/* HSTMATCH module=EBOOT.BIN start=0x001c816c end=0x001c821c symbol=FUN_001c816c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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

struct Alloc {};
template <class T> struct Vec {
  T *data_;
  unsigned size_;
  It<T> begin() const { return It<T>(data_); }
  It<T> end() { return It<T>(data_ + size_); }
  void shrink(int n, Alloc) { size_ -= n; }
  unsigned Size() const { return size_; }
};

struct Obj {
  char pad[0x58];
  Vec<Ent *> ents;
};

extern "C" void FUN_001c67e8(Obj *, Ent *);

extern "C" void FUN_001c816c(Obj *o)
{
  if (o->ents.Size() != 0) {
    for (It<Ent *> it = o->ents.begin(); it != o->ents.end(); ++it) {
      Ent *e = *it;
      FUN_001c67e8(o, e);
      e->v1();
    }
    int n = o->ents.size_;
    o->ents.shrink(n, Alloc());
  }
}
