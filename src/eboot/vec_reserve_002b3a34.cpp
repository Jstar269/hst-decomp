/* HSTMATCH module=EBOOT.BIN start=0x002b3a34 end=0x002b3c04 symbol=FUN_002b3a34 lang=c++ */
/* Clone of src/sharing_main/vec_reserve_002c34f4.cpp (hstclone.py tag a0db26EBhs): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (recipe of src/eboot/vec_reserve_00236e38.cpp, element layout of src/eboot/swap_item_002b3738.cpp); exact match verified; names and types await human review. */
/* Container reserve(n) for the 100-byte element type: allocate a temporary vector of capacity n (FUN_002b4bac, empty tag
   by value), copy-construct the old elements at its end, swap capacity/data/size with the temporary and let its
   destructor free the old block (the element destructor is trivial, so only `size -= n` remains: retail's
   `subu v1,v1,v1`). Unlike the 560-byte instance the copy helper is inlined here; `#pragma inline_depth(8)` is needed
   so that the element's implicit memberwise copy constructor (Elem has a user default constructor, so the copy is
   memberwise: 2-bytes-per-pass loops for the char arrays) is inlined into it instead of being emitted out of line. */
#pragma inline_depth(8)
struct Tag {};
struct Alloc {};
struct Elem {
  int f0;
  char name[32];
  char desc[32];
  char c68;
  char c69;
  char c70;
  unsigned char u71;
  unsigned char u72;
  char c73;
  char c74;
  char c75;
  int f76;
  int f80;
  char extra[16];
  Elem() {}
};
inline void *operator new(unsigned, void *p) { return p; }
extern "C" void FUN_00000a00(void *);

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
    cut(n, Alloc());
    if (data) FUN_00000a00(data);
  }
};
extern "C" void FUN_002b4bac(Vec *v, unsigned n, Tag);

inline void CopyBack(Vec *b, Elem *first, Elem *last, Tag)
{
  Elem *p = b->data + b->size;
  for (; first < last; ++first) {
    new (p) Elem(*first);
    ++p;
    ++b->size;
  }
}

extern "C" void FUN_002b3a34(Vec *v, unsigned n)
{
  Vec buf;
  FUN_002b4bac(&buf, n, Tag());
  CopyBack(&buf, v->data, v->data + v->size, Tag());
  Swap(v->capacity, buf.capacity);
  Swap(v->data, buf.data);
  Swap(v->size, buf.size);
}
