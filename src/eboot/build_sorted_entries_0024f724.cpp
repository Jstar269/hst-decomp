/* HSTMATCH module=EBOOT.BIN start=0x0024f724 end=0x0024fbb0 symbol=FUN_0024f724 lang=c++ */
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
extern "C" {
extern void *DAT_00338b08;
extern unsigned FUN_000d8bfc(void *, int);
extern Src *FUN_000d8c24(void *, int, unsigned);
extern void FUN_001798f4(PtrVec *, unsigned);
extern void FUN_00179a70(PtrVec *, int);
extern void FUN_00193474(int);
extern unsigned char *FUN_0016b21c(int);
extern unsigned char *FUN_0016b300(int);
extern unsigned char *FUN_0016b348(int);
extern unsigned char *FUN_0016b390(int);
extern unsigned char *FUN_0016b2b4(int);
extern void FUN_0001cfa4(Pair *, int, int);
}

extern "C" int FUN_0024f724(int kind, PtrVec *vec, int flag)
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
    n = FUN_000d8bfc(DAT_00338b08, kind);
  }
  if (flag != 0) {
    if (vec->cap < n + 1) FUN_001798f4(vec, n + 1);
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
    if (vec->cap < n) FUN_001798f4(vec, n);
  }
  for (i = 0; i < n; i++) {
    Src *s = FUN_000d8c24(DAT_00338b08, kind, i);
    if (s != 0) {
      bool ok = false;
      bool flag2 = false;
      if (kind == 0) {
        FUN_00193474(i);
        unsigned char *p = FUN_0016b21c(i);
        if (*p - 4U < 2) {
          ok = true;
        } else {
          ok = true;
          flag2 = true;
        }
      } else if (kind == 1) {
        unsigned char *p = FUN_0016b300(i);
        ok = *p - 4U < 2;
      } else if (kind == 2) {
        unsigned char *p = FUN_0016b348(i);
        ok = *p - 4U < 2;
      } else if (kind == 3 || kind == 4) {
        unsigned char *p = FUN_0016b390(i);
        ok = *p - 4U < 2;
      } else if (kind == 5) {
        unsigned char *p = FUN_0016b2b4(i);
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
  FUN_00179a70(&tmp, 0);
  return count;
}
