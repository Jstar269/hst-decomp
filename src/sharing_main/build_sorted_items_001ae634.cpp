/* HSTMATCH module=hstp_trans_main.prx start=0x001ae634 end=0x001ae96c symbol=FUN_001ae634 lang=c++ */
/* Hand-written reconstruction from the disassembly (structure taken from the sibling build_sorted_entries_0025fa78.cpp); exact match verified; names and types await human review. */
/* Collects a sentinel item (id -1, score -1) plus one 12-byte item per qualifying slot (all of them when `flag` is set, otherwise the selected index and the slots whose state byte is 4 or 5) into the pointer vector at +900, then rebuilds that vector in order of (score, index) pairs sorted by FUN_0001cbf0 and swaps it in. Matching idioms (as in the sibling): `#pragma opt_strength_reduction off`; the item copied into a second pointer (`Entry *m = new Entry; e = m;`); first push_back through back() = at(size - 1), the later ones through data[size - 1]; an unused empty Tag on the inline push_back; loop bound through a const getter; `bool ok = false` declared BEFORE the lookup call (it lands in the call's delay slot); the `flag != 0` arm written first. */
#pragma opt_strength_reduction off
struct Tag {};
struct Alloc {};
struct Src {
  char pad[5];
  signed char f5;
};
struct Entry {
  int id;
  int score;
  int f8;
  Entry() {
    score = 0;
    id = 0;
    f8 = 0;
  }
};
struct PtrVec;
extern "C" void FUN_001b3b1c(PtrVec *, const Entry *const *, Tag);
struct PtrVec {
  const Entry **data;
  unsigned size;
  unsigned cap;
  const Entry *&at(unsigned i) { return data[i]; }
  unsigned Size2() const { return size; }
  const Entry *&back() { return at(size - 1); }
  void push_back_b(const Entry *const &x, Tag) {
    if (size < cap) {
      size++;
      back() = x;
    } else {
      FUN_001b3b1c(this, &x, Tag());
    }
  }
  void shrink(int n, Alloc) { size -= n; }
  void push_back(const Entry *const &x, Tag) {
    if (size < cap) {
      size++;
      data[size - 1] = x;
    } else {
      FUN_001b3b1c(this, &x, Tag());
    }
  }
};
struct Pair {
  unsigned key;
  unsigned idx;
};
struct Obj {
  char pad[900];
  PtrVec vec;
};
extern "C" {
extern void *DAT_003f4920;
extern int FUN_002c6fac(void *);
extern Src *FUN_002c6fb4(void *, int);
extern unsigned char *FUN_00177720(int);
extern void FUN_001b3b60(PtrVec *, unsigned);
extern void FUN_001b3c5c(PtrVec *, int);
extern void FUN_0001cbf0(Pair *, int, int);
extern void FUN_001ae634(Obj *self, int a1, int sel, int flag);
}

void FUN_001ae634(Obj *self, int a1, int sel, int flag)
{
  Pair buf[1024];
  Entry *e1;
  Entry *e2;
  PtrVec tmp;
  const Entry *elem;
  int n;
  int i;
  unsigned j;
  unsigned k;

  n = FUN_002c6fac(DAT_003f4920);
  if (sel >= 0)
    sel = sel % 50;
  if (self->vec.cap < n + 1)
    FUN_001b3b60(&self->vec, n + 1);
  Entry *m1 = new Entry;
  e1 = m1;
  m1->id = -1;
  m1->score = -1;
  m1->f8 = 0;
  self->vec.push_back_b(e1, Tag());
  for (i = 0; i < n; i++) {
    bool ok = false;
    Src *s = FUN_002c6fb4(DAT_003f4920, i);
    if (s != 0) {
      if (flag != 0) {
        ok = true;
      } else {
        if (i == sel) {
          ok = true;
        } else {
          unsigned char *p = FUN_00177720(i);
          if (*p - 4U < 2)
            ok = true;
        }
      }
      if (ok) {
        Entry *m2 = new Entry;
        e2 = m2;
        int sc = s->f5;
        m2->id = i;
        m2->score = sc;
        m2->f8 = 0;
        self->vec.push_back(e2, Tag());
      }
    }
  }
  j = 0;
  if (self->vec.size != 0) {
    Pair *q = buf;
    do {
      q->key = self->vec.at(j)->score;
      q->idx = j;
      j++;
      q++;
    } while (j < self->vec.Size2());
  }
  FUN_0001cbf0(buf, 0, self->vec.size - 1);
  tmp.data = 0;
  tmp.size = 0;
  tmp.cap = 0;
  if (tmp.cap < n)
    FUN_001b3b60(&tmp, n);
  k = 0;
  if (self->vec.size != 0) {
    Pair *q = buf;
    do {
      elem = self->vec.data[q->idx];
      tmp.push_back(elem, Tag());
      k++;
      q++;
    } while (k < self->vec.size);
  }
  {
    unsigned t;
    t = self->vec.cap; self->vec.cap = tmp.cap; tmp.cap = t;
    const Entry **d = self->vec.data; self->vec.data = tmp.data; tmp.data = d;
    t = self->vec.size; self->vec.size = tmp.size; tmp.size = t;
    int m = tmp.size;
    tmp.shrink(m, Alloc());
  }
  FUN_001b3c5c(&tmp, 0);
}
