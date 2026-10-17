/* HSTMATCH module=EBOOT.BIN start=0x000d9e3c end=0x000d9f40 symbol=FUN_000d9e3c lang=c++ */
/* Clone of src/sharing_main/vec_reserve_realloc_000dddfc.cpp (hstclone.py tag s10170158a3r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Vector reallocation for a 6-byte element type (three shorts), same recipe as vec_reserve_realloc_0005e90c.cpp: local buffer object with zeroing ctor and inline dtor (shrink + null-checked delete), copy-construct the old elements with a user memberwise copy ctor (lh/sh pairs), swap data/size/capacity; increment list `++first, ++buf.size, ++dst`. Names provisional. */
struct Alloc {};
inline void *operator new(unsigned, void *p) { return p; }
struct Elem { short a, b, c; Elem(const Elem &o) : a(o.a), b(o.b), c(o.c) {} ~Elem() {} };
struct Vec { Elem *data; unsigned size; unsigned cap; };
extern "C" void FUN_000da72c(void *, unsigned, Alloc);
extern "C" void FUN_000da3d4(void *, int, Alloc);
struct Buf {
  Elem *data;
  unsigned size;
  unsigned cap;
  Buf() : data(0), size(0), cap(0) {}
  ~Buf() { FUN_000da3d4(this, size, Alloc()); delete data; }
};
template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }
extern "C" void FUN_000d9e3c(Vec *v, unsigned n)
{
  Buf buf;
  FUN_000da72c(&buf, n, Alloc());
  Elem *first = v->data;
  Elem *last = first + v->size;
  Elem *dst = buf.data + buf.size;
  for (; first < last; ++first, ++buf.size, ++dst)
    new (dst) Elem(*first);
  Swap(v->cap, buf.cap);
  Swap(v->data, buf.data);
  Swap(v->size, buf.size);
}
