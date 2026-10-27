/* HSTMATCH module=EBOOT.BIN start=0x0016ca34 end=0x0016cf60 symbol=FUN_0016ca34 lang=c++ rodata=0x002c1e40 */
/* Clone of src/sharing_main/build_sorted_entries_00178cac.cpp (hstclone.py tag c072920): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (structure and helper types taken from the sibling build_sorted_entries_001782b8.cpp); exact match verified; names and types await human review. */
/* Collects the table entries 0..14 (15 + 1 with the trailing sentinel) into a pointer vector, flags entries whose
   properties fail one of the two filter kinds, appends the sentinel, reorders the vector by sorted (score, index)
   pairs and returns the number of counted items through outCount. Matching idioms (as in the sibling): the entry
   copied into a second pointer (`Entry *m = new Entry; e = m;`); loop push_back through data[size - 1], the
   sentinel's through back() = at(size - 1); an unused empty Tag on the inline push_back; loop bound through a const
   getter; `shrink(n, Alloc())` before the out-of-line destructor call. New here: no opt_strength_reduction pragma
   (MWCC turns kinds[m] into retail's pointer walk); the pair loop keeps data + j * 4 recomputed through an `int` index compared
   against the unsigned size; the filter switch lists every label 0xb..0x14 (jump table). */
struct Tag {};
struct Alloc {};
struct Src {
  char pad[0x5a];
  short f5a;
};
struct Item {
  char pad0[0x24];
  unsigned char f24;
  char pad1[0x2c - 0x25];
  unsigned char f2c;
  char pad2[0x43 - 0x2d];
  unsigned char f43;
  char pad3[0x54 - 0x44];
  char f54[0x9c - 0x54];
};
struct Entry {
  int id;
  int score;
  bool fa;
  bool fb;
  bool fc;
  bool fd;
  bool fe;
  Src *src;
  Entry() {
    score = 0;
    id = 0;
    src = 0;
    fa = false;
    fb = false;
    fc = false;
    fd = false;
    fe = false;
  }
};
struct PtrVec;
extern "C" void FUN_001797fc(PtrVec *, const Entry *const *, Tag);
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
      FUN_001797fc(this, &x, Tag());
    }
  }
  void shrink(int n, Alloc) { size -= n; }
  void push_back(const Entry *const &x, Tag) {
    if (size < cap) {
      size++;
      data[size - 1] = x;
    } else {
      FUN_001797fc(this, &x, Tag());
    }
  }
};
struct Pair {
  unsigned key;
  unsigned idx;
};
struct Glob {
  char pad[1000];
  unsigned char *(*fn)(int);
};
extern "C" {
extern void *DAT_00338b08;
extern Glob *DAT_00341518;
extern Src *FUN_000d8c24(void *, int, unsigned);
extern void FUN_001798f4(PtrVec *, unsigned);
extern void FUN_00179a70(PtrVec *, int);
extern Item *FUN_00193474(int);
extern int FUN_0016bb98(int, void *);
extern void FUN_0001cfa4(Pair *, int, int);
}

extern "C" void FUN_0016ca34(PtrVec *vec, int sel, unsigned char flagA, int, unsigned char extra, int, int *outCount, const int *kinds, unsigned char flagC)
{
  Pair buf[1024];
  Entry *e2;
  Entry *e1;
  PtrVec tmp;
  const Entry *elem;
  int n;
  int count;
  int i;
  int j;
  unsigned k;

  n = 15;
  if (extra) n++;
  if (vec->cap < n) FUN_001798f4(vec, n);
  count = 0;
  for (i = 0; i < n; i++) {
    Src *s = FUN_000d8c24(DAT_00338b08, 0, i);
    if (s != 0) {
      bool ok = false;
      bool flag2 = false;
      bool flag3 = false;
      if (flagA) {
        Item *t = FUN_00193474(i);
        if (t->f43) {
          ok = true;
          count++;
        } else if (!t->f2c) {
          ok = true;
          flag2 = true;
        }
      } else {
        Item *t = FUN_00193474(i);
        int kind = FUN_0016bb98(i, t->f54);
        unsigned char *p = DAT_00341518->fn(i);
        if (*p - 4U < 2) {
          ok = true;
          count++;
          for (int m = 0; m < 2; m++) {
            switch (kinds[m]) {
            case 0xb: if (t->f24 != 0) flag3 = true; break;
            case 0xc: if (t->f24 != 1) flag3 = true; break;
            case 0xd: if (kind != 1) flag3 = true; break;
            case 0xe: if (kind != 3) flag3 = true; break;
            case 0xf: if (kind != 2) flag3 = true; break;
            case 0x10: if (!flagC && i != sel) flag3 = true; break;
            case 0x11:
            case 0x12:
            case 0x13:
              break;
            case 0x14: if (i != 0 && i != 1) flag3 = true; break;
            }
          }
        } else if (!t->f2c) {
          ok = true;
          flag2 = true;
        }
      }
      if (ok) {
        Entry *m2 = new Entry;
        e2 = m2;
        int sc = s->f5a;
        m2->id = i;
        m2->score = sc;
        m2->src = s;
        m2->fa = flag2;
        m2->fb = false;
        m2->fc = false;
        m2->fe = flag3;
        vec->push_back(e2, Tag());
      }
    }
  }
  if (extra) {
    Entry *m1 = new Entry;
    e1 = m1;
    m1->id = 0x7fff;
    m1->score = 0xfff0;
    m1->src = 0;
    m1->fa = false;
    m1->fb = true;
    m1->fc = false;
    m1->fe = false;
    vec->push_back_b(e1, Tag());
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
  FUN_0001cfa4(buf, 0, vec->size - 1);
  tmp.data = 0;
  tmp.size = 0;
  tmp.cap = 0;
  if (tmp.cap < n) FUN_001798f4(&tmp, n);
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
  if (outCount != 0) *outCount = count;
  FUN_00179a70(&tmp, 0);
}
