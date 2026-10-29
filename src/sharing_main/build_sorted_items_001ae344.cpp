/* HSTMATCH module=hstp_trans_main.prx start=0x001ae344 end=0x001ae634 symbol=FUN_001ae344 lang=c++ */
/* Clone of src/eboot/build_sorted_items_001a0d78.cpp (hstclone.py tag c064507): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (structure taken from the sibling build_sorted_items_001a1068.cpp: collects one 12-byte item per qualifying slot into the pointer vector passed in, rebuilds it in order of (score, index) pairs sorted by FUN_0001cbf0 and swaps it in; matching idioms as in the sibling: opt_strength_reduction off, the item copied into a second pointer, an unused empty Tag on push_back, shrink(n, Alloc()) before the buffer destructor call, bool ok declared inside the non-null branch); exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
struct Tag {};
struct Alloc {};
struct Src {
  char pad[8];
  short f8;
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
extern "C" void FUN_001b3974(PtrVec *, const Entry *const *, Tag);
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
      FUN_001b3974(this, &x, Tag());
    }
  }
  void shrink(int n, Alloc) { size -= n; }
  void push_back(const Entry *const &x, Tag) {
    if (size < cap) {
      size++;
      data[size - 1] = x;
    } else {
      FUN_001b3974(this, &x, Tag());
    }
  }
};
struct Pair {
  unsigned key;
  unsigned idx;
};
extern "C" {
extern void *DAT_003f3b1c;
extern unsigned FUN_00290228(void *);
extern Src *FUN_00290230(void *, int);
extern unsigned char *FUN_00177684(int);
extern void FUN_001b39b8(PtrVec *, unsigned);
extern void FUN_001b3ab4(PtrVec *, int);
extern void FUN_0001cbf0(Pair *, int, int);
extern void FUN_001ae344(PtrVec *vec, int a1, int tab, int sel, int flag);
}

void FUN_001ae344(PtrVec *vec, int a1, int tab, int sel, int flag)
{
  Pair buf[1024];
  Entry *e2;
  PtrVec tmp;
  const Entry *elem;
  unsigned n;
  int i;
  unsigned j;
  unsigned k;

  n = FUN_00290228(DAT_003f3b1c);
  if (vec->cap < n)
    FUN_001b39b8(vec, n);
  for (i = 0; i < (int)n; i++) {
    Src *s = FUN_00290230(DAT_003f3b1c, i);
    if (s != 0) {
      bool ok = false;
      if (flag != 0) {
        ok = true;
      } else {
        unsigned char *p = FUN_00177684(i);
        if (*p - 4U < 2) {
          ok = true;
        } else if (a1 != 0 && *(signed char *)(tab + (int)s + 0x12) == 2) {
          ok = true;
        } else if (sel != 0 && sel == i) {
          ok = true;
        }
      }
      if (ok) {
        Entry *m2 = new Entry;
        e2 = m2;
        int sc = s->f8;
        m2->id = i;
        m2->score = sc;
        m2->f8 = 0;
        vec->push_back(e2, Tag());
      }
    }
  }
  j = 0;
  if (vec->size != 0) {
    Pair *q = buf;
    do {
      q->key = vec->at(j)->score;
      q->idx = j;
      j++;
      q++;
    } while (j < vec->Size2());
  }
  FUN_0001cbf0(buf, 0, vec->size - 1);
  tmp.data = 0;
  tmp.size = 0;
  tmp.cap = 0;
  if (tmp.cap < n)
    FUN_001b39b8(&tmp, n);
  k = 0;
  if (vec->size != 0) {
    Pair *q = buf;
    do {
      elem = vec->data[q->idx];
      tmp.push_back(elem, Tag());
      k++;
      q++;
    } while (k < vec->size);
  }
  {
    unsigned t;
    t = vec->cap; vec->cap = tmp.cap; tmp.cap = t;
    const Entry **d = vec->data; vec->data = tmp.data; tmp.data = d;
    t = vec->size; vec->size = tmp.size; tmp.size = t;
    int m = tmp.size;
    tmp.shrink(m, Alloc());
  }
  FUN_001b3ab4(&tmp, 0);
}
