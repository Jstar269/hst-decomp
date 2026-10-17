/* HSTMATCH module=EBOOT.BIN start=0x001c68a8 end=0x001c6908 symbol=FUN_001c68a8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* push_back(x) onto the int vector at +0x58 (data, size, capacity): with spare capacity size++ then back() = x
   (index scaled before the data load), otherwise the out-of-line grow FUN_001ce554 gets &x and an empty tag.
   x is address-taken, so the by-value parameter lives in the frame (sp+20). Matching idiom: push_back takes
   an UNUSED empty Tag by value (two hidden 4-byte slots above x, as in the 0x97d64 note); without it x is at sp+24. */
struct Tag {};
struct IntVec;
extern "C" void FUN_001ce554(IntVec *, const int *, Tag);
struct IntVec {
  int *data;
  unsigned size;
  unsigned cap;
  int &at(unsigned i) { return data[i]; }
  int &back() { return at(size - 1); }
  void push_back(const int &x, Tag)
  {
    if (size < cap) {
      size++;
      back() = x;
    } else {
      FUN_001ce554(this, &x, Tag());
    }
  }
};
struct Self {
  char pad[0x58];
  IntVec items;
};

extern "C" void FUN_001c68a8(Self *self, int x)
{
  self->items.push_back(x, Tag());
}
