/* HSTMATCH module=EBOOT.BIN start=0x001cc8e8 end=0x001cc988 symbol=FUN_001cc8e8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Base0 { char pad[0x1320]; };
struct Base1 { int x; };
struct Derived : Base0, Base1 { };

extern Derived *DAT_0033b574;
extern "C" void FUN_00286c6c(Base1 *);

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
  It<T> begin() const { return It<T>(data_); }
  It<T> end() { return It<T>(data_ + size_); }
};

struct Obj { char pad[0x40]; Vec<Base1 *> ents; };

extern "C" void FUN_001cc8e8(Obj *o)
{
  for (It<Base1 *> it = o->ents.begin(); it != o->ents.end(); ++it) {
    Base1 *e = *it;
    if (e != 0 && e != DAT_0033b574) {
      FUN_00286c6c(e);
    }
  }
}
