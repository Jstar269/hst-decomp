/* HSTMATCH module=hstp_trans_main.prx start=0x0024b1b8 end=0x0024b314 symbol=FUN_0024b1b8 lang=c++ */
/* Clone of src/eboot/vec_assign_fill_0023b020.cpp (hstclone.py tag s10170158a1r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* vector<8-byte element>::assign(n, x)-style, sibling of vec_assign_fill_00179ad8.cpp: when n exceeds the capacity
   grow (0x23b5d0) and reallocate (0x23b6b4) then append n copies; otherwise copy-assign min(n, size) elements, then
   erase the tail (0x23b5c0) or append n - size copies (placement new, null check). Matching idioms: the body lives
   in an inline function taking n by const reference (early returns directly in the out-of-line function leave the
   original of every copied delay-slot instruction behind as dead code, and the tag/n frame slots come out in the
   wrong order); empty Tag2 by-value parameters on the inline helpers (48-byte frame, n at 24(sp)); Elem has a
   user copy ctor and operator= (lw/sw instead of lwc1/swc1). Names provisional. */
inline void *operator new(unsigned, void *p) { return p; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
struct Tag {};
struct Tag2 {};
struct Elem {
  int a;
  int b;
  Elem(const Elem &o) : a(o.a), b(o.b) {}
  Elem &operator=(const Elem &o) { a = o.a; b = o.b; return *this; }
};
struct Vec {
  Elem *data_;
  unsigned size_;
  unsigned cap_;
};
extern "C" {
unsigned FUN_0024b768(Vec *v, unsigned n);
void FUN_0024b84c(Vec *v, unsigned n, unsigned cap);
void FUN_0024b758(Vec *v, unsigned n, Tag t);
}
inline void Erase(Vec *v, unsigned k, Tag2) { FUN_0024b758(v, k, Tag()); }
inline void Fill(Elem *p, unsigned m, const Elem &x, Tag2)
{
  for (; m != 0; --m, ++p)
    *p = x;
}
inline void Append(Vec *v, unsigned n, const Elem &x, Tag2)
{
  Elem *p = v->data_ + v->size_;
  for (; n != 0; --n) {
    new (p) Elem(x);
    ++p;
    ++v->size_;
  }
}
inline void AssignFill(Vec *v, const unsigned &n, const Elem &x)
{
  unsigned c;
  if (v->cap_ < n) {
    c = FUN_0024b768(v, n - v->cap_);
  } else {
    Fill(v->data_, Min(n, v->size_), x, Tag2());
    if (v->size_ > n) {
      Erase(v, v->size_ - n, Tag2());
      return;
    }
    Append(v, n - v->size_, x, Tag2());
    return;
  }
  FUN_0024b84c(v, n, c);
  Append(v, n, x, Tag2());
}
extern "C" void FUN_0024b1b8(Vec *v, unsigned n, const Elem &x)
{
  AssignFill(v, n, x);
}
