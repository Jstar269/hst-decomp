/* HSTMATCH module=EBOOT.BIN start=0x00236fe8 end=0x002370b0 symbol=FUN_00236fe8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: restructured as a vector deleting destructor (size read into n, inline cut(n, Alloc()) and destroy walk as in vec_shrink_destroy_00236db4.cpp, then delete of the data block and of the vector when the flag is positive); exact match verified; names and types await human review. */
struct Elem { char pad[0xc4]; char arr[0x18 * 3]; char pad2[0x230 - 0xc4 - 0x18 * 3]; };
struct Alloc {};
extern "C" void FUN_00000788(void *, void *, int, int);
extern "C" void FUN_00000a00(void *);
extern "C" void FUN_00235c04(void);

struct Vec {
  Elem *data;
  int size;
  Elem *cut(int n, Alloc) {
    Elem *p = data + size;
    size -= n;
    return p;
  }
};

extern "C" Vec *FUN_00236fe8(Vec *v, short flag)
{
  if (v) {
    int n = v->size;
    Elem *p = v->cut(n, Alloc());
    for (; n != 0; n--) {
      --p;
      if (p) FUN_00000788(p->arr, (void *)FUN_00235c04, 0x18, 3);
    }
    if (v->data) FUN_00000a00(v->data);
    if (0 < flag) FUN_00000a00(v);
  }
  return v;
}
