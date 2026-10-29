/* HSTMATCH module=hstp_trans_main.prx start=0x00092e14 end=0x00092f18 symbol=FUN_00092e14 lang=c++ */
/* Clone of src/eboot/vec_reserve_copy_0009117c.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (recipe of src/eboot/vec_reserve_copy_001160a0.cpp with a 32-byte element: int, byte, int, then a 16-aligned Vec4 member whose user memberwise copy ctor gives the interleaved lwc1/swc1 pairs; the destructor clears size through shrink(n, Alloc()) before operator delete); exact match verified; names and types await human review. */
struct Tag {};
struct Alloc {};
struct Vec4 {
  float x, y, z, w;
  Vec4() {}
  Vec4(const Vec4 &o) : x(o.x), y(o.y), z(o.z), w(o.w) {}
} __attribute__((aligned(16)));
struct Elem {
  int a;
  unsigned char b;
  int c;
  Vec4 v;
  Elem() {}
};
inline void *operator new(unsigned, void *p) { return p; }
struct Vec;
extern "C" void FUN_000932e8(Vec *, unsigned, Tag);
template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }
struct Vec {
  Elem *data;
  int size;
  unsigned capacity;
  Vec() : data(0), size(0), capacity(0) {}
  void shrink(int n, Alloc) { size -= n; }
  ~Vec()
  {
    int n = size;
    shrink(n, Alloc());
    if (data)
      operator delete(data);
  }
};
extern "C" void FUN_00092e14(Vec *v, unsigned n)
{
  Vec buf;
  FUN_000932e8(&buf, n, Tag());
  Elem *first = v->data;
  Elem *last = first + v->size;
  Elem *p = buf.data + buf.size;
  for (; first < last; ++first) {
    new (p) Elem(*first);
    ++p;
    ++buf.size;
  }
  Swap(v->capacity, buf.capacity);
  Swap(v->data, buf.data);
  Swap(v->size, buf.size);
}
