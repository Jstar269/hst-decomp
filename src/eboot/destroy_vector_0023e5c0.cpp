/* HSTMATCH module=EBOOT.BIN start=0x0023e5c0 end=0x0023e680 symbol=FUN_0023e5c0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: vector cut with Alloc tag temporary and element cleanup loop; exact match verified; names and types await human review. */
extern "C" void FUN_00000a00(void *);

struct Alloc {};

struct Elem {
  int flags;
  int pad;
  void *ptr;
};

struct Vector {
  Elem *data;
  int size;
};

static inline Elem *cut(Vector *v, int n, Alloc)
{
  Elem *p = v->data + n;
  v->size -= n;
  return p;
}

extern "C" void *FUN_0023e5c0(Vector *self, short flag)
{
  if (self != 0) {
    int n = self->size;
    Elem *p = cut(self, n, Alloc());
    for (; n != 0; --n) {
      --p;
      if (p != 0 && (p->flags & 1)) {
        FUN_00000a00(p->ptr);
      }
    }
    if (self->data != 0) {
      FUN_00000a00(self->data);
    }
    if (flag > 0) {
      FUN_00000a00(self);
    }
  }
  return self;
}
