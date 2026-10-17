/* HSTMATCH module=EBOOT.BIN start=0x000f6690 end=0x000f6730 symbol=FUN_000f6690 lang=c++ */
/* Clone of src/sharing_main/alloc_init_push_000fbd84.cpp (hstclone.py tag s10170049g1r1e): addresses substituted; exact match verified; names and types await human review. */
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
Obj *FUN_00050fc0(void *);
void FUN_000511c4(Obj *, int, int);
void FUN_0006ea5c(PtrVec *, Obj **, Tag);
}

extern "C" void FUN_000f6690(Self *self, int arg)
{
  Obj *mem = (Obj *)FUN_00000bcc(0x48);
  if (mem) mem = FUN_00050fc0(mem);
  Obj *o = mem;
  FUN_000511c4(o, arg, 0);
  if (self->items.size < self->items.cap) {
    self->items.size++;
    self->items.back() = o;
  } else {
    FUN_0006ea5c(&self->items, &o, Tag());
  }
}
