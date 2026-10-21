/* HSTMATCH module=EBOOT.BIN start=0x000b4710 end=0x000b49ec symbol=FUN_000b4710 lang=c++ */
struct Elem {
  int w[14];
  float key;
  int pad[5];
} __attribute__((aligned(16)));

struct Iter {
  Elem *p;
  Iter operator+(int n) const { Iter r; r.p = p + n; return r; }
  Iter operator-(int n) const { Iter r; r.p = p - n; return r; }
};

struct Buf;

struct BufIter {
  Elem *p;
  Buf *buf;
  BufIter operator+(int n) const { BufIter r; r.p = p + n; r.buf = buf; return r; }
};

struct Comp {
  bool operator()(Elem a, Elem b) const { return a.key < b.key; }
};

struct RetIter {
  Elem *p;
};

extern "C" {
void FUN_000b4578(Iter, Iter, Comp);
void FUN_000b5ee8(Iter, Iter, BufIter, Comp);
RetIter FUN_000b55a0(BufIter, BufIter, BufIter, BufIter, Iter, Comp);
void FUN_000b5900(Iter, Iter, Iter, Comp, int, int, BufIter, BufIter);
Elem *FUN_000b42ac(Iter *);
void FUN_000b41b8(Elem *, Elem *);
void FUN_000b4710(Iter, Iter, BufIter, BufIter, Comp);
}

static inline bool Less(Comp c, const Elem &x, const Elem &y) { return c(x, y); }

static inline void IterSwap(Iter a, Iter b) { FUN_000b41b8(FUN_000b42ac(&a), FUN_000b42ac(&b)); }

extern "C" void FUN_000b4710(Iter first, Iter last, BufIter b1, BufIter b2, Comp comp)
{
  int n = last.p - first.p;
  if (n > 1) {
    if (n == 2) {
      Iter b = last;
      --b.p;
      last = b;
      if (Less(comp, *last.p, *first.p)) IterSwap(*(volatile Iter *)&first, last);
      return;
    }
    if (n < 21) {
      FUN_000b4578(first, last, comp);
      return;
    }
    int half = n - n / 2;
    Iter mid;
    mid.p = first.p + half;
    if (b2.p - b1.p >= n) {
      FUN_000b5ee8(first, mid, b1, comp);
      FUN_000b5ee8(mid, last, b1 + half, comp);
      FUN_000b55a0(b1, b1 + half, b1 + half, b1 + n, first, comp);
    } else {
      FUN_000b4710(first, mid, b1, b2, comp);
      FUN_000b4710(mid, last, b1, b2, comp);
      FUN_000b5900(first, mid, last, comp, mid.p - first.p, last.p - mid.p, b1, b2);
    }
  }
}
// Near miss (sn4, 2026-10-21): 184/183 words, 95 positional differ, ~11 differing blocks; first 0x70 bytes (prologue, n==2 compare-and-swap, n<21 insertion call) match exactly.
// What matches: Iter {Elem*} / BufIter {Elem*, Buf*} by-value classes (BufIter passed by hidden reference and copied by the callee via lwc1/swc1), Elem aligned(16) (Elem copies at sp+128/48),
//   the early-return chain INSIDE `if (n > 1)` (keeps the dead originals under the likely branches), `last` decremented in place with a named `Iter b = last; --b.p; last = b;`,
//   `IterSwap(*(volatile Iter *)&first, last)` (gives sw a0,36(sp) + lwc1 f0,36(sp) memory copy of first and reload after the copy loops clobber s2),
//   Less -> Comp::operator()(Elem,Elem) one inline level deeper than IterSwap (puts the Elem copies below the iterator temporaries), buffer arm first (`if (bufsize >= n)`), `b1 + half` / `b1 + n` temporaries via BufIter::operator+.
// What differs: (1) retail computes `mid` (addu s0,s2,s1) in the delay slot of `bnez at` AFTER `lw a0,272(sp)`, ours uses the incoming a0 for first.p (addu s0,a0,s1 before the loads) so the add is not movable and a likely branch (bnezl, slot = move a0,s2) is used instead;
//   (2) the first-pass temporaries (t1, hidden ret, three BufIter temps) sit 4 bytes lower than retail (retail 260/256/248/240/232, ours 256/252/244/236/228): retail has a 4-byte hole at 268..271 and another at 228..231, ours has both 4-byte named-local slots (Iter b, Iter mid) at 264..271;
//   (3) the buffer arm's t38/t30/t28 .buf stores are scheduled differently (follows from (1)/(2)).
// Ruled out: Iter &fr = first; (gives addiu t0,sp,36 + lwc1 0(t0)), Iter with ctors / copy ctor, operator+ everywhere without a mid local (no CSE, 5 saved regs), plain Elem* mid with MkIter, aligned(8) Iter, empty-Comp call forms, statement-order permutations of half/bufn/mid (the scheduler ignores them).
// Open idea: find the construct that adds a 4-byte object BELOW the first-pass temps (an inline-depth-1 local or Comp copy) instead of the second named local above them.
// near miss from lane sn4 (unreviewed)
