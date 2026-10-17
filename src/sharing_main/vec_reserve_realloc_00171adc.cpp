/* HSTMATCH module=hstp_trans_main.prx start=0x00171adc end=0x00171bf0 symbol=FUN_00171adc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
// Vector reallocation for a 20-byte (5-float) element type, same recipe as vec_reserve_realloc_0005e90c.cpp: local zeroed Buf, reserve via FUN_00172770(&buf, n, tag), memberwise user copy ctor (interleaved lwc1/swc1; the implicit copy batches), swap cap/data/size, Buf dtor = shrink FUN_001723f8 + null-checked delete.
struct Alloc {};
inline void *operator new(unsigned, void *p) { return p; }
struct Elem { float a, b, c, d, e; Elem(const Elem &o) : a(o.a), b(o.b), c(o.c), d(o.d), e(o.e) {} ~Elem() {} };
struct Vec { Elem *data; unsigned size; unsigned cap; };
extern "C" void FUN_00172770(void *, unsigned, Alloc);
extern "C" void FUN_001723f8(void *, int, Alloc);
struct Buf {
  Elem *data;
  unsigned size;
  unsigned cap;
  Buf() : data(0), size(0), cap(0) {}
  ~Buf() { FUN_001723f8(this, size, Alloc()); delete data; }
};
template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }
extern "C" void FUN_00171adc(Vec *v, unsigned n)
{
  Buf buf;
  FUN_00172770(&buf, n, Alloc());
  Elem *first = v->data;
  Elem *last = first + v->size;
  Elem *dst = buf.data + buf.size;
  for (; first < last; ++first, ++buf.size, ++dst)
    new (dst) Elem(*first);
  Swap(v->cap, buf.cap);
  Swap(v->data, buf.data);
  Swap(v->size, buf.size);
}
