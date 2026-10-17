/* HSTMATCH module=EBOOT.BIN start=0x0016f970 end=0x0016fab8 symbol=FUN_0016f970 lang=c++ */
/* Clone of src/sharing_main/FUN_0017bbbc.cpp (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: the lookup is a static inline Find() with an early return inside the loop (this alone gives retail's saved-register order cur=s0, this=s1, item=s2); the found item is returned through the const operator[] and the call argument is read through the const getter GetId() so MWCC reloads the data pointer / id instead of CSE-ing them; int index against the unsigned Size() keeps the loops rolled with i*4 recomputed and the count reloaded per pass. */
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
static inline Item *Find(Mgr *m, int sel)
{
  for (int i = 0; i < m->items.Size(); i++) {
    if (m->items[i]->id == sel) return ((const PtrVec &)m->items)[i];
  }
  return 0;
}
extern "C" void FUN_0016f970(Mgr *m, int cur)
{
  Item *it = Find(m, m->fn540());
  if (it == 0) return;
  if (cur != m->fn540() && it->b11 == 0 && it->b12 == 0) return;
  for (int i = 0; i < m->items.Size(); i++) {
    Item *p = m->items[i];
    if (p->id != cur && p->b8 == 0 && p->b9 == 0 && p->b10 == 0 && p->b11 == 0 && p->b12 == 0) {
      m->fn53c(p->GetId());
      return;
    }
  }
}
