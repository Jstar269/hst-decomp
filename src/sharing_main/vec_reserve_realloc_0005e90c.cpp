/* HSTMATCH module=hstp_trans_main.prx start=0x0005e90c end=0x0005ea10 symbol=FUN_0005e90c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector reallocation for a 12-byte element type: a local buffer object (zeroed ctor, inline dtor = shrink through FUN_0005ee3c(this, size, tag) + null-checked delete, the element type has a dtor) is reserved through FUN_0005f194(&buf, n, tag), the old elements are copy-constructed into it with a user memberwise copy ctor (lw/sw pairs; the implicit copy gives lwc1/swc1), then data/size/capacity are swapped. The for-increment list `++first, ++buf.size, ++dst` gives retail's increment order. Names provisional. */
struct Alloc {};
inline void *operator new(unsigned, void *p) { return p; }
struct Elem { int a, b, c; Elem(const Elem &o) : a(o.a), b(o.b), c(o.c) {} ~Elem() {} };
struct Vec { Elem *data; unsigned size; unsigned cap; };
extern "C" void FUN_0005f194(void *, unsigned, Alloc);
extern "C" void FUN_0005ee3c(void *, int, Alloc);
struct Buf {
  Elem *data;
  unsigned size;
  unsigned cap;
  Buf() : data(0), size(0), cap(0) {}
  ~Buf() { FUN_0005ee3c(this, size, Alloc()); delete data; }
};
template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }
extern "C" void FUN_0005e90c(Vec *v, unsigned n)
{
  Buf buf;
  FUN_0005f194(&buf, n, Alloc());
  Elem *first = v->data;
  Elem *last = first + v->size;
  Elem *dst = buf.data + buf.size;
  for (; first < last; ++first, ++buf.size, ++dst)
    new (dst) Elem(*first);
  Swap(v->cap, buf.cap);
  Swap(v->data, buf.data);
  Swap(v->size, buf.size);
}
