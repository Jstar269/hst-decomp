/* HSTMATCH module=hstp_trans_main.prx start=0x001d4ca0 end=0x001d4d00 symbol=FUN_001d4ca0 lang=c++ */
/* Clone of src/eboot/vec_push_back_int_001c68a8.cpp (hstclone.py tag s10170158a1r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* push_back(x) onto the int vector at +0x58 (data, size, capacity): with spare capacity size++ then back() = x
   (index scaled before the data load), otherwise the out-of-line grow FUN_001dcc30 gets &x and an empty tag.
   x is address-taken, so the by-value parameter lives in the frame (sp+20). Matching idiom: push_back takes
   an UNUSED empty Tag by value (two hidden 4-byte slots above x, as in the 0x97d64 note); without it x is at sp+24. */
struct Tag {};
struct IntVec;
extern "C" void FUN_001dcc30(IntVec *, const int *, Tag);
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
      FUN_001dcc30(this, &x, Tag());
    }
  }
};
struct Self {
  char pad[0x58];
  IntVec items;
};

extern "C" void FUN_001d4ca0(Self *self, int x)
{
  self->items.push_back(x, Tag());
}
