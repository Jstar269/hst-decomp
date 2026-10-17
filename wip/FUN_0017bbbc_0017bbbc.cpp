/* HSTMATCH module=hstp_trans_main.prx start=0x0017bbbc end=0x0017bd04 symbol=FUN_0017bbbc lang=c++ */
struct Item {
  int id;
  int f4;
  unsigned char b8, b9, b10, b11, b12;
  int GetId() const { return id; }
};

struct PtrVec {
  Item **data;
  unsigned size;
  unsigned Size() const { return size; }
  Item *&operator[](unsigned i) { return data[i]; }
  Item *const &operator[](unsigned i) const { return data[i]; }
};

struct Mgr {
  char pad[0x4fc];
  PtrVec items;
  char pad2[0x53c - 0x504];
  void (*fn53c)(int);
  int (*fn540)(void);
};

extern "C" void FUN_0017bbbc(Mgr *m, int cur)
{
  int sel;
  Item *it;
  int i;
  sel = m->fn540();
  it = 0;
  for (i = 0; i < m->items.Size(); i++) {
    if (m->items[i]->id == sel) {
      it = ((const PtrVec &)m->items)[i];
      break;
    }
  }
  if (it == 0)
    return;
  if (cur != m->fn540() && it->b11 == 0 && it->b12 == 0)
    return;
  for (i = 0; i < m->items.Size(); i++) {
    Item *p = m->items[i];
    if (p->id != cur && p->b8 == 0 && p->b9 == 0 && p->b10 == 0 && p->b11 == 0 && p->b12 == 0) {
      m->fn53c(p->GetId());
      return;
    }
  }
}
// agent snS8-00 near miss: structure, loads, branches and delay slots all match; 32 words differ ONLY in saved-register naming.
// Retail: cur=s0, this=s1, found item `it`=s2; ours: cur=s1, this=s2, it=s0 (a pure rotation).
// Matched pieces: PtrVec with `unsigned Size() const` and `operator[]` (int loop index vs unsigned size = rolled, i*4 recomputed, count reloaded
//   per pass); the found-path `it = ((const PtrVec &)m->items)[i];` (const accessor) gives retail's reload of the data pointer; `p->GetId()` as
//   the fn53c argument (const getter) gives retail's reload of the id in the jalr slot.
// Ruled out for the s-reg rotation: all 6 declaration orders of sel/it/i, `it = 0` before the first fn540 call, member-function form,
//   an inline `Inner(m, it, cur)` helper in all 6 parameter orders, plain pointer loops, getter-only forms.
