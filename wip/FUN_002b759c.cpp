/* HSTMATCH module=EBOOT.BIN start=0x002b759c end=0x002b764c symbol=FUN_002b759c lang=c++ */
struct Alloc {};
struct Elem { virtual void destroy(int flag); int value; };
struct Vec {
  Elem *data;
  int size;
  unsigned capacity;
  Elem *cut(int n, Alloc) {
    Elem *p = data + size;
    size -= n;
    return p;
  }
};
extern "C" void FUN_00000a00(void *p);
extern "C" void FUN_002b764c(Vec *self, int n, signed char tag);

extern "C" void FUN_002b759c(Vec *self, int unused, int n)
{
  int count = self->size;
  Elem *p = self->cut(count, Alloc());
  for (; count != 0; --count) {
    --p;
    p->destroy(-1);
  }
  bool tag;
  if (self->data != 0) {
    FUN_00000a00(self->data);
    self->data = 0;
    self->capacity = 0;
    tag = false;
  } else {
    tag = false;
  }
  int normalized = tag;
  FUN_002b764c(self, n, (signed char)normalized);
}

// Near miss: 3 differing words remain in the final FUN_002b764c setup. Retail emits move a0,s2; move a1,s1; jal; seb a2,v0, while this source emits seb before move a0, then moves a1 in the call delay slot.
// Ruled out so far: C linkage signed-char arguments and a by-value tag wrapper kept the same delayed a1 move; the allocator-temporary frame, reverse virtual destroy loop, data free, and field clears match.
// near miss from lane u6cr4-2 (unreviewed)
