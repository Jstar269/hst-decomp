/* HSTMATCH module=hstp_trans_main.prx start=0x0029b620 end=0x0029b720 symbol=FUN_0029b620 lang=c++ */
/* Clone of src/eboot/clear_owned_entries_00289e84.cpp (hstclone.py tag s10170158a1r2s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Elem {
  int *f0;
  int *f4;
  int *f8;
  int *fc;
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
};

extern "C" int FUN_000569f4(int *, int);
extern "C" int FUN_000541d8(int *, int);
extern "C" void FUN_00000a00(void *);

extern "C" void FUN_0029b620(Vec<Elem *> *v)
{
  for (It<Elem *> it = v->begin(); it != v->end(); ++it) {
    Elem *e = *it;
    if (e != 0) {
      if (e->fc != 0) { FUN_000569f4(e->fc, 1); e->fc = 0; }
      if (e->f8 != 0) { FUN_000541d8(e->f8, 1); e->f8 = 0; }
      if (e->f4 != 0) { FUN_000541d8(e->f4, 1); e->f4 = 0; }
      if (e->f0 != 0) { FUN_000541d8(e->f0, 1); e->f0 = 0; }
      if (e != 0) FUN_00000a00(e);
    }
  }
  int n = v->size_;
  v->shrink(n, Alloc());
}
