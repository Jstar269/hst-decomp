/* HSTMATCH module=EBOOT.BIN start=0x00107750 end=0x0010798c symbol=FUN_00107750 lang=c++ */
struct Obj {
  char pad[0x20];
  float key;
};

struct It {
  Obj **p;
  int tag;
};

struct Greater {
  bool operator()(Obj *a, Obj *b) const { return a->key > b->key; }
};

struct Out {
  Obj **p;
  Out() {}
};

extern "C" {
void FUN_001076c8(Obj **, Obj **, char);
void FUN_00107750(Obj **, Obj **, const It *, const It *, char);
void FUN_00108ca8(Out *, const It *, const It *, const It *, const It *, Obj **, char);
void FUN_00108dc0(Obj **, Obj **, Obj **, char, int, int, const It *, const It *);
void FUN_001091d4(Obj **, Obj **, const It *, char);
}

extern "C" void FUN_00107750(Obj **first, Obj **last, const It *inlo, const It *inhi, char comp)
{
  It lo = *inlo;
  It hi = *inhi;
  int n = last - first;

  if (n < 2) {
    return;
  }
  if (n == 2) {
    Obj *a = *(last - 1);
    Obj *b = *first;
    if (Greater()(a, b)) {
      *first = a;
      *(last - 1) = b;
    }
    return;
  }
  if (n < 21) {
    FUN_001076c8(first, last, comp);
    return;
  }
  int half = n / 2;
  int mid = n - half;
  Obj **m = first + mid;
  int span = hi.p - lo.p;
  if (span / 4 < n) {
    FUN_00107750(first, m, &lo, &hi, comp);
    FUN_00107750(m, last, &lo, &hi, comp);
    FUN_00108dc0(first, m, last, comp, m - first, last - m, &lo, &hi);
  } else {
    FUN_001091d4(first, m, &lo, comp);
    It t;
    t.p = lo.p + half;
    t.tag = lo.tag;
    FUN_001091d4(m, last, &t, comp);
    Out out;
    It a;
    It b;
    It c;
    a.p = lo.p + half;
    a.tag = lo.tag;
    b.p = lo.p + mid;
    b.tag = lo.tag;
    c.p = lo.p + n;
    c.tag = lo.tag;
    FUN_00108ca8(&out, &lo, &a, &b, &c, first, comp);
  }
}
// NEAR MISS: 151/143 words, 149 differ. This is MSL's __stable_sort_adaptive: n = last-first;
// n<2 return; n==2 swap-if-greater; n<21 insertion sort (FUN_001076c8); mid = n - n/2;
// if (buffer span < n) recurse both halves + FUN_00108dc0(first, mid, last, comp, n1, n2, &lo, &hi)
// else FUN_001091d4 twice into {buf+mid,tag} buffers + FUN_00108ca8(sret, &lo, &A, &B, &C, first, comp).
// Structure/call sequence matches; what differs: retail's frame is 112 vs our 96 (24 unused bytes at
// sp+32..55 = three more 8-byte slots declared after the last It), retail's slots lo=104 hi=96 t=84
// out=80 a=72 b=64 c=56 vs ours lo=88 hi=80 ..., and retail colours comp=s5/first=s3/last=s4/n=s2/
// mid*4=s1/m=s0 (we get an extra saved reg s6). Ruled out: It with user ctors (lw/sw copies instead of
// retail's lwc1/swc1), brace-init Its (adds temp copies, 183 words), construction order c,b,a (no change),
// It as {ptr,int} POD vs {float,float}.
// near miss from lane fm4 (unreviewed)
