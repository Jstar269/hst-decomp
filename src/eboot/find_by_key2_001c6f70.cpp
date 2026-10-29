/* HSTMATCH module=EBOOT.BIN start=0x001c6f70 end=0x001c70c0 symbol=FUN_001c6f70 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idiom: same by-value one-word iterator/key classes as find_by_key_001c70c0.cpp; the two search arms share one trailing return 0. */
struct Elem { char pad[0x30]; int f30; int f34; };
struct Owner { char pad[0x70]; Elem **beg; int count; };
struct It {
  Elem **p;
  It() {}
  It(Elem **q) : p(q) {}
  Elem *&operator*() const { return *p; }
  Elem **Ptr() const { return p; }
  It &operator++() { ++p; return *this; }
};
struct Key {
  int v;
  Key(int k) : v(k) {}
};
struct Key2 {
  int v;
  int w;
  Key2(int k, int n) : v(k), w(n) {}
  bool Match(const Elem *e) const { return v == e->f30 && w == e->f34; }
};

static inline bool operator!=(const It &a, const It &b) { return (a.p == b.p) ^ 1; }

static inline It Find(It first, It last, Key key)
{
  while (first.p != last.p && key.v != (*first.Ptr())->f30)
    ++first;
  return first;
}

static inline It Find2(It first, It last, Key2 key)
{
  while (first.p != last.p && !key.Match(*first.Ptr()))
    ++first;
  return first;
}

extern "C" Elem *FUN_001c6f70(Owner *m, int kid, int n) {
  if (n < 1) {
    It it = Find(It(m->beg), It(m->beg + m->count), Key(kid));
    if (it != It(m->beg + m->count))
      return *it;
  } else {
    It it = Find2(It(m->beg), It(m->beg + m->count), Key2(kid, n));
    if (it != It(m->beg + m->count))
      return *it;
  }
  return 0;
}
