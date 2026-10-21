/* HSTMATCH module=EBOOT.BIN start=0x0014ce38 end=0x0014d044 symbol=FUN_0014ce38 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idiom: the iterator advance is an inline bidirectional advance written as 'if (n >= 0) { for (; n > 0; --n) ... } else { for (; n < 0; ++n) ... }' on an address-taken iterator, which MWCC unrolls 8x with the overflow guards seen in retail); names and types await human review. */
struct Node {
  Node *prev;
  Node *next;
};
struct Hdr {
  char pad0[4];
  Node sentinel;
};
struct Obj {
  char pad0[4];
  Hdr *hdr;
  char pad1[0x14 - 8];
  Node *cur;
};
extern "C" void FUN_0014c9b8(float, Obj *, Node **);
static inline void Advance(Node *&it, int n)
{
  if (n >= 0) {
    for (; n > 0; --n)
      it = it->next;
  } else {
    for (; n < 0; ++n)
      it = it->prev;
  }
}

extern "C" bool FUN_0014ce38(Obj *self, int n)
{
  Node *p = self->hdr->sentinel.next;
  Advance(p, n);
  while (self->cur != p && self->cur != &self->hdr->sentinel)
    FUN_0014c9b8(1.0f, self, &p);
  return self->cur == p;
}
