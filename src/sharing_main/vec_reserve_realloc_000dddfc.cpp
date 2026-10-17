/* HSTMATCH module=hstp_trans_main.prx start=0x000dddfc end=0x000ddf00 symbol=FUN_000dddfc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector reallocation for a 6-byte element type (three shorts), same recipe as vec_reserve_realloc_0005e90c.cpp: local buffer object with zeroing ctor and inline dtor (shrink + null-checked delete), copy-construct the old elements with a user memberwise copy ctor (lh/sh pairs), swap data/size/capacity; increment list `++first, ++buf.size, ++dst`. Names provisional. */
struct Alloc {};
inline void *operator new(unsigned, void *p) { return p; }
struct Elem { short a, b, c; Elem(const Elem &o) : a(o.a), b(o.b), c(o.c) {} ~Elem() {} };
struct Vec { Elem *data; unsigned size; unsigned cap; };
extern "C" void FUN_000de6ec(void *, unsigned, Alloc);
extern "C" void FUN_000de394(void *, int, Alloc);
struct Buf {
  Elem *data;
  unsigned size;
  unsigned cap;
  Buf() : data(0), size(0), cap(0) {}
  ~Buf() { FUN_000de394(this, size, Alloc()); delete data; }
};
template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }
extern "C" void FUN_000dddfc(Vec *v, unsigned n)
{
  Buf buf;
  FUN_000de6ec(&buf, n, Alloc());
  Elem *first = v->data;
  Elem *last = first + v->size;
  Elem *dst = buf.data + buf.size;
  for (; first < last; ++first, ++buf.size, ++dst)
    new (dst) Elem(*first);
  Swap(v->cap, buf.cap);
  Swap(v->data, buf.data);
  Swap(v->size, buf.size);
}
