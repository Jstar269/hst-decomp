/* HSTMATCH module=hstp_trans_main.prx start=0x001b3298 end=0x001b3500 symbol=FUN_001b3298 lang=c++ */
/* Hand-written reconstruction from the disassembly (near miss, parked in wip/); names and types await human review. */
#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }
template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }
struct Tag {};
struct Elem {
  unsigned char b0;
  int w4;
  unsigned char b8, b9, b10;
  int w12;
  signed char arr[32];
  Elem() {}
};
struct Vec { Elem *data; unsigned size; unsigned cap; };
extern "C" unsigned FUN_001b45f4(Vec *, unsigned);
extern "C" void FUN_001b46d8(Vec *, unsigned, unsigned);
extern "C" void FUN_001b45e4(Vec *, unsigned, Tag);

static inline void Fill(Elem *p, unsigned m, const Elem &x, Tag, Tag)
{
  for (; m != 0; --m, ++p)
    *p = x;
}
static inline void AppendN(Vec *v, unsigned n, const Elem &x, Tag)
{
  Elem *p = v->data + v->size;
  for (; n != 0; --n, ++p) {
    new (p) Elem(x);
    ++v->size;
  }
}
extern "C" void FUN_001b3298(Vec *v, unsigned n, const Elem *x)
{
  unsigned c;
  if (v->cap < n) {
    c = FUN_001b45f4(v, n - v->cap);
  } else {
    Fill(v->data, Min(n, v->size), *x, Tag(), Tag());
    if (n < v->size) {
      FUN_001b45e4(v, v->size - n, Tag());
      return;
    }
    AppendN(v, n - v->size, *x, Tag());
    return;
  }
  FUN_001b46d8(v, n, c);
  AppendN(v, n, *x, Tag());
}

// NEAR MISS: 158 words vs 154 retail. Same instruction stream as retail except 4 DEAD words (the MWCC delay-slot
// copy artefact documented in wip/vec_assign_fill_0027f04c.cpp, same signature): Min's else arm leaves `b join` +
// a dead `addiu v1,sp,24`, the erase-call head leaves a dead `sll a0,a1,1`/`move a0,s2` copy, and the `lw a1,4(s2)`
// before `sltu` is ordered after `lw v1,24(sp)` (retail the reverse). Frame matches (n at 24(sp)) with
// `Fill(.., Tag, Tag)` (two tags) and `AppendN(.., Tag)`; Elem is {uchar; int; uchar x3; int; signed char[32]}
// with a user default ctor (non-POD: memberwise copy, 16-pass lb/lb array loop); `#pragma inline_depth(8)` inlines the
// implicit copy ctor/assignment. Tried (all the same dead words): pointer `x` instead of `const Elem &`, a
// non-template `const unsigned &Min` with if/return, grow-path-first if/else without the early returns (worse: 12 words moved).
