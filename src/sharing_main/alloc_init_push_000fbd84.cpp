/* HSTMATCH module=hstp_trans_main.prx start=0x000fbd84 end=0x000fbe24 symbol=FUN_000fbd84 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Allocates (72 bytes) and constructs an object, initialises it, and push_back()s the pointer onto the pointer vector at +4; the inline push_back stores through back() = at(size - 1) after incrementing size (index scaled before the data load), the full case calls the out-of-line grow helper with an empty tag. Names provisional. */
struct Tag {};
struct Obj;
struct PtrVec {
  Obj **data;
  unsigned size;
  unsigned cap;
  Obj *&at(unsigned i) { return data[i]; }
  Obj *&back() { return at(size - 1); }
};
struct Self {
  int pad;
  PtrVec items;
};
extern "C" {
void *FUN_00000bcc(unsigned);
Obj *FUN_000518d4(void *);
void FUN_00051ad8(Obj *, int, int);
void FUN_0007021c(PtrVec *, Obj **, Tag);
}

extern "C" void FUN_000fbd84(Self *self, int arg)
{
  Obj *mem = (Obj *)FUN_00000bcc(0x48);
  if (mem) mem = FUN_000518d4(mem);
  Obj *o = mem;
  FUN_00051ad8(o, arg, 0);
  if (self->items.size < self->items.cap) {
    self->items.size++;
    self->items.back() = o;
  } else {
    FUN_0007021c(&self->items, &o, Tag());
  }
}
