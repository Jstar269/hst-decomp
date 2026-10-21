/* HSTMATCH module=EBOOT.BIN start=0x002b759c end=0x002b764c symbol=FUN_002b759c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; matching idiom: one-char-member flag struct Flag set from (int)tag with tag = false in both branches, giving andi+seb with the seb in the call slot; names and types await human review. */
struct Alloc {};
struct Flag { unsigned char v; };
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
extern "C" void FUN_002b764c(Vec *self, int n, Flag tag);

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
  Flag f;
  f.v = (int)tag;
  FUN_002b764c(self, n, f);
}
