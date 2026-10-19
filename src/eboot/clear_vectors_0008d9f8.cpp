/* HSTMATCH module=EBOOT.BIN start=0x0008d9f8 end=0x0008da9c symbol=FUN_0008d9f8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" void FUN_00091280(void *, int);

struct Vec {
  void *data;
  unsigned size;
  unsigned cap;
};

struct Buf {
  void *data;
  unsigned size;
  unsigned cap;
  Buf() : data(0), size(0), cap(0) {}
  ~Buf() { FUN_00091280(this, 0); }
};

struct Obj {
  Vec v1;
  Vec v2;
};

template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }

extern "C" void FUN_0008d9f8(Obj *o)
{
  Buf buf1;
  Swap(o->v1.cap, buf1.cap);
  Swap(o->v1.data, buf1.data);
  Swap(o->v1.size, buf1.size);
  Buf buf2;
  Swap(o->v2.cap, buf2.cap);
  Swap(o->v2.data, buf2.data);
  Swap(o->v2.size, buf2.size);
}
