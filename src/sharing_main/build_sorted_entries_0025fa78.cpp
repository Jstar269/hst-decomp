/* HSTMATCH module=hstp_trans_main.prx start=0x0025fa78 end=0x0025ff04 symbol=FUN_0025fa78 lang=c++ */
/* Clone of src/eboot/build_sorted_entries_0024f724.cpp (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Collects entries into a pointer vector and reorders it by sorted (key, index) pairs; the vector is at +0, size at +4, capacity at +8 (vector at +0, size at +4, capacity at +8): matching idioms: `#pragma opt_strength_reduction off`; the entry copied into a second pointer (`Entry *m = new Entry; e = m;`) so field stores do not reload the address-taken local; first push_back through back() = at(size-1) but the later ones through data[size-1] (two inline forms); an unused empty Tag parameter on the inline push_back (frame slots); loop bound through a const getter; a separate counter k for the last loop; `shrink(n, Alloc())` before the out-of-line destructor call. */
#pragma opt_strength_reduction off
struct Tag {};
struct Alloc {};
struct Src {
  char pad[0x5a];
  short f5a;
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
extern "C" void FUN_00185ef0(PtrVec *, const Entry *const *, Tag);
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
      FUN_00185ef0(this, &x, Tag());
    }
  }
  void shrink(int n, Alloc) { size -= n; }
  void push_back(const Entry *const &x, Tag) {
    if (size < cap) {
      size++;
      data[size - 1] = x;
    } else {
      FUN_00185ef0(this, &x, Tag());
    }
  }
};
struct Pair {
  unsigned key;
  unsigned idx;
};
extern "C" {
extern void *DAT_003e1e48;
extern unsigned FUN_000dca08(void *, int);
extern Src *FUN_000dca74(void *, int, unsigned);
extern void FUN_00185fe8(PtrVec *, unsigned);
extern void FUN_00186164(PtrVec *, int);
extern void FUN_0019fc84(int);
extern unsigned char *FUN_001773e0(int);
extern unsigned char *FUN_001774c4(int);
extern unsigned char *FUN_0017750c(int);
extern unsigned char *FUN_00177554(int);
extern unsigned char *FUN_00177478(int);
extern void FUN_0001cbf0(Pair *, int, int);
}

extern "C" int FUN_0025fa78(int kind, PtrVec *vec, int flag)
{
  Pair buf[1024];
  Entry *e1;
  Entry *e2;
  PtrVec tmp;
  const Entry *elem;
  int count = 0;
  int n;
  int i;
  unsigned j;
  unsigned k;

  if (kind == 0) {
    n = 15;
  } else {
    n = FUN_000dca08(DAT_003e1e48, kind);
  }
  if (flag != 0) {
    if (vec->cap < n + 1) FUN_00185fe8(vec, n + 1);
    Entry *m1 = new Entry;
    e1 = m1;
    m1->id = 0x7fffffff;
    m1->score = -1;
    m1->src = 0;
    m1->fa = false;
    m1->fb = false;
    m1->fc = true;
    m1->fe = false;
    vec->push_back_b(e1, Tag());
    count++;
  } else {
    if (vec->cap < n) FUN_00185fe8(vec, n);
  }
  for (i = 0; i < n; i++) {
    Src *s = FUN_000dca74(DAT_003e1e48, kind, i);
    if (s != 0) {
      bool ok = false;
      bool flag2 = false;
      if (kind == 0) {
        FUN_0019fc84(i);
        unsigned char *p = FUN_001773e0(i);
        if (*p - 4U < 2) {
          ok = true;
        } else {
          ok = true;
          flag2 = true;
        }
      } else if (kind == 1) {
        unsigned char *p = FUN_001774c4(i);
        ok = *p - 4U < 2;
      } else if (kind == 2) {
        unsigned char *p = FUN_0017750c(i);
        ok = *p - 4U < 2;
      } else if (kind == 3 || kind == 4) {
        unsigned char *p = FUN_00177554(i);
        ok = *p - 4U < 2;
      } else if (kind == 5) {
        unsigned char *p = FUN_00177478(i);
        if (*p - 4U < 2) {
          ok = true;
        } else {
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
        m2->fe = false;
        vec->push_back(e2, Tag());
        if (!flag2) count++;
      }
    }
  }
  j = 0;
  if (vec->size != 0) {
    Pair *q = buf;
    do {
      q->key = vec->at(j)->score;
      if (vec->at(j)->fa != false) q->key = 100;
      q->idx = j;
      j++;
      q++;
    } while (j < vec->Size2());
  }
  FUN_0001cbf0(buf, 0, vec->size - 1);
  tmp.data = 0;
  tmp.size = 0;
  tmp.cap = 0;
  if (tmp.cap < n) FUN_00185fe8(&tmp, n);
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
  FUN_00186164(&tmp, 0);
  return count;
}
