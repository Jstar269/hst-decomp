/* HSTMATCH module=hstp_trans_main.prx start=0x00158920 end=0x00158b2c symbol=FUN_00158920 lang=c++ */
/* Clone of src/eboot/list_seek_0014ce38.cpp (hstclone.py tag c21sn4s): addresses substituted; exact match verified; names and types await human review. */
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
extern "C" void FUN_001584a0(float, Obj *, Node **);
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

extern "C" bool FUN_00158920(Obj *self, int n)
{
  Node *p = self->hdr->sentinel.next;
  Advance(p, n);
  while (self->cur != p && self->cur != &self->hdr->sentinel)
    FUN_001584a0(1.0f, self, &p);
  return self->cur == p;
}
