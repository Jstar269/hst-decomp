/* HSTMATCH module=hstp_trans_main.prx start=0x0008f208 end=0x0008f2ac symbol=FUN_0008f208 lang=c++ */
/* Clone of src/eboot/clear_vectors_0008d9f8.cpp (hstclone.py tag s10172123g4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

extern "C" void FUN_00092f18(void *, int);

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
  ~Buf() { FUN_00092f18(this, 0); }
};

struct Obj {
  Vec v1;
  Vec v2;
};

template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }

extern "C" void FUN_0008f208(Obj *o)
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
