/* HSTMATCH module=hstp_trans_main.prx start=0x00290d6c end=0x00290e24 symbol=FUN_00290d6c lang=c++ */
/* Hand-written reconstruction from the disassembly (recipe of the exact sibling src/sharing_main/vec_destroy_and_free_002c733c.cpp, 40-byte element with a virtual destructor); exact match verified; matching idiom: one-char-member flag struct Flag set from (int)tag with tag = false in both branches (a single constant folds to `move a2,zero`, 2 words short), giving andi+seb with the seb in the call slot; names and types await human review. */
/* Vector of 40-byte polymorphic elements: destroy every element backwards through its virtual destructor (size cut to
   0 first through cut(n, Alloc()), whose empty allocator temporary is the 16-byte frame slot), free the block, then
   allocate room for n elements again (FUN_00290f24: length check, operator new(n * 40), out-of-memory abort). The
   second parameter is unused. Names provisional. */
struct Alloc {};
struct Flag { unsigned char v; };
struct Elem { virtual ~Elem(); char pad[36]; };
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
extern "C" void FUN_00290f24(Vec *self, int n, Flag tag);

extern "C" void FUN_00290d6c(Vec *self, int unused, int n)
{
  int count = self->size;
  Elem *p = self->cut(count, Alloc());
  for (; count != 0; --count) {
    --p;
    p->~Elem();
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
  FUN_00290f24(self, n, f);
}
