/* HSTMATCH module=EBOOT.BIN start=0x00236e38 end=0x00236f44 symbol=FUN_00236e38 lang=c++ */
/* Hand-written reconstruction from the disassembly (recipes of src/eboot/vec_reserve_member_00237138.cpp and vec_shrink_destroy_00236db4.cpp); exact match verified; names and types await human review. */
/* Container reserve(n) for the 560-byte element type: allocate a temporary vector of capacity n (0x23790c, empty tag by value),
   copy-construct the old elements into it (0x236f44), swap capacity/data/size with the temporary and let its destructor
   destroy the old elements (sub-array dtor loop as in 0x236db4) and free the old block. Names provisional. */
#pragma inline_depth(8)
struct Tag {};
struct Alloc {};
struct Elem { char pad[0xc4]; char arr[0x18 * 3]; char pad2[0x230 - 0xc4 - 0x18 * 3]; };
extern "C" void FUN_00000788(void *, void *, int, int);
extern "C" void FUN_00000a00(void *);
extern "C" void FUN_00235c04(void);

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
      if (p) FUN_00000788(p->arr, (void *)FUN_00235c04, 0x18, 3);
    }
    if (data) FUN_00000a00(data);
  }
};
extern "C" void FUN_0023790c(Vec *v, unsigned n, Tag);
extern "C" void FUN_00236f44(Vec *v, Elem *first, Elem *last, Tag);

extern "C" void FUN_00236e38(Vec *v, unsigned n)
{
  Vec buf;
  FUN_0023790c(&buf, n, Tag());
  FUN_00236f44(&buf, v->data, v->data + v->size, Tag());
  Swap(v->capacity, buf.capacity);
  Swap(v->data, buf.data);
  Swap(v->size, buf.size);
}
