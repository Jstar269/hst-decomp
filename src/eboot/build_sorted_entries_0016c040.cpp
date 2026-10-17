/* HSTMATCH module=EBOOT.BIN start=0x0016c040 end=0x0016c574 symbol=FUN_0016c040 lang=c++ */
/* Clone of src/sharing_main/build_sorted_entries_001782b8.cpp (hstclone.py tag s10170158a2r1e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (structure and helper types taken from the sibling build_sorted_entries_0025fa78.cpp); exact match verified; names and types await human review. */
/* Collects entries of a group into a pointer vector (optional sentinel first), reorders it by sorted (score, index) pairs and returns the number of counted items through outCount. Matching idioms (as in the sibling): `#pragma opt_strength_reduction off`; the entry copied into a second pointer (`Entry *m = new Entry; e = m;`); first push_back through back() = at(size - 1), the later ones through data[size - 1]; an unused empty Tag on the inline push_back; loop bound through a const getter; `count = 0` set right before the loop; `shrink(n, Alloc())` before the out-of-line destructor call. New here: the byte flag is tested as plain `if (flagB)` (`!= 0` makes MWCC hoist an andi copy and spill that instead of the parameter's home slot), the 2-bit signed field at +0x65 is a bit-field (lb; sll; sra), and `flagB != 0` is the first arm. */
#pragma opt_strength_reduction off
struct Tag {};
struct Alloc {};
struct Src {
  char pad[0x5a];
  short f5a;
  char pad2[0x65 - 0x5c];
  signed char f65 : 2;
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
extern unsigned char *FUN_0016b300(int);
extern unsigned char *FUN_0016b348(int);
extern unsigned char *FUN_0016b390(int);
extern unsigned char *FUN_0016b2b4(int);
extern void FUN_0001cfa4(Pair *, int, int);
}

extern "C" void FUN_0016c040(int group, PtrVec *vec, int extra, unsigned char flagB, int p5, int, int, int *outCount)
{
  Pair buf[1024];
  Entry *e1;
  Entry *e2;
  PtrVec tmp;
  const Entry *elem;
  int count;
  int n;
  int i;
  unsigned j;
  unsigned k;

  n = FUN_000d8bfc(DAT_00338b08, group);
  if (extra != 0) {
    if (vec->cap < n + 1) FUN_001798f4(vec, n + 1);
    Entry *m1 = new Entry;
    e1 = m1;
    m1->id = 0x7fffffff;
    m1->score = -1;
    m1->src = 0;
    m1->fa = false;
    m1->fb = false;
    m1->fc = false;
    m1->fe = false;
    vec->push_back_b(e1, Tag());
  } else {
    if (vec->cap < n) FUN_001798f4(vec, n);
  }
  count = 0;
  for (i = 0; i < n; i++) {
    Src *s = FUN_000d8c24(DAT_00338b08, group, i);
    if (s != 0) {
      bool ok = false;
      bool flag2 = false;
      bool flag3 = false;
      if (flagB) {
        if (group == 5) {
          if (s->f65 != 0) {
            if (p5 != 0) {
              if (i == 0) {
                ok = true;
                count++;
              } else {
                ok = true;
                count++;
                flag3 = true;
              }
            }
          } else {
            ok = true;
            count++;
            flag2 = true;
          }
        } else {
          if (s->f65 != 0) {
            ok = true;
          } else if (group == 3) {
            if (i == 0) ok = true;
          }
          count++;
        }
      } else {
        if (group == 1) {
          unsigned char *p = FUN_0016b300(i);
          count++;
          ok = *p - 4U < 2;
        } else if (group == 2) {
          unsigned char *p = FUN_0016b348(i);
          count++;
          ok = *p - 4U < 2;
        } else if (group == 3 || group == 4) {
          unsigned char *p = FUN_0016b390(i);
          count++;
          ok = *p - 4U < 2;
        } else if (group == 5) {
          if (p5 != 0) {
            if (i == 0) {
              ok = true;
              count++;
            } else {
              unsigned char *p = FUN_0016b2b4(i);
              if (*p - 4U < 2) {
                ok = true;
                count++;
                flag3 = true;
              } else {
                ok = true;
                flag2 = true;
              }
            }
          } else {
            unsigned char *p = FUN_0016b2b4(i);
            if (*p - 4U < 2) {
              ok = true;
              count++;
            } else {
              ok = true;
              flag2 = true;
            }
          }
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
