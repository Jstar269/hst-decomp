/* HSTMATCH module=hstp_trans_main.prx start=0x00246f9c end=0x002470a8 symbol=FUN_00246f9c lang=c++ */
/* Clone of src/eboot/vec_reserve_00236e38.cpp (hstclone.py tag s10170158a2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (recipes of src/eboot/vec_reserve_member_00237138.cpp and vec_shrink_destroy_00236db4.cpp); exact match verified; names and types await human review. */
/* Container reserve(n) for the 560-byte element type: allocate a temporary vector of capacity n (0x24790c, empty tag by value),
   copy-construct the old elements into it (0x246f44), swap capacity/data/size with the temporary and let its destructor
   destroy the old elements (sub-array dtor loop as in 0x246db4) and free the old block. Names provisional. */
#pragma inline_depth(8)
struct Tag {};
struct Alloc {};
struct Elem { char pad[0xc4]; char arr[0x18 * 3]; char pad2[0x230 - 0xc4 - 0x18 * 3]; };
extern "C" void FUN_00000788(void *, void *, int, int);
extern "C" void FUN_00000a00(void *);
extern "C" void FUN_00245d30(void);

template <class T> inline void Swap(T &a, T &b) { T t = a; a = b; b = t; }

struct Vec {
  Elem *data;
  int size;
  unsigned capacity;
  Vec() : data(0), size(0), capacity(0) {}
  Elem *cut(int n, Alloc) {
    Elem *p = data + size;
    size -= n;
    return p;
  }
  ~Vec() {
    int n = size;
    Elem *p = cut(n, Alloc());
    for (; n != 0; n--) {
      --p;
      if (p) FUN_00000788(p->arr, (void *)FUN_00245d30, 0x18, 3);
    }
    if (data) FUN_00000a00(data);
  }
};
extern "C" void FUN_00247a44(Vec *v, unsigned n, Tag);
extern "C" void FUN_002470a8(Vec *v, Elem *first, Elem *last, Tag);

extern "C" void FUN_00246f9c(Vec *v, unsigned n)
{
  Vec buf;
  FUN_00247a44(&buf, n, Tag());
  FUN_002470a8(&buf, v->data, v->data + v->size, Tag());
  Swap(v->capacity, buf.capacity);
  Swap(v->data, buf.data);
  Swap(v->size, buf.size);
}
