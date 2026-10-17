/* HSTMATCH module=EBOOT.BIN start=0x0027f04c end=0x0027f3cc symbol=FUN_0027f04c lang=c++ */
/* Hand-written reconstruction from the disassembly (near miss, parked in wip/); names and types await human review. */
#pragma inline_depth(8)
inline void *operator new(unsigned, void *p) { return p; }

template <class T> inline const T &Min(const T &a, const T &b) { return b < a ? b : a; }

struct Tag {};

class C_0027e6d4 {
public:
  virtual ~C_0027e6d4();
  short s4, s6, s8, sa, sc, se, s10;
  char a[10];
  char b[9];
  unsigned char c;
  short d;
};

struct Vec {
  C_0027e6d4 *data;
  unsigned size;
  unsigned cap;
};

extern "C" unsigned FUN_0027f814(Vec *, unsigned);
extern "C" void FUN_0027f8f8(Vec *, unsigned, unsigned);

static inline void Fill(C_0027e6d4 *p, unsigned m, const C_0027e6d4 &x, Tag, Tag)
{
  for (; m != 0; --m, ++p) {
    *p = x;
  }
}

static inline void AppendN(Vec *v, unsigned n, const C_0027e6d4 &x, Tag)
{
  C_0027e6d4 *p = v->data + v->size;
  for (; n != 0; --n, ++p) {
    new (p) C_0027e6d4(x);
    ++v->size;
  }
}

static inline void DestroyBack(C_0027e6d4 *e, int cnt, Tag)
{
  for (; cnt != 0; --cnt) {
    --e;
    e->~C_0027e6d4();
  }
}

extern "C" void FUN_0027f04c(Vec *v, unsigned n, const C_0027e6d4 *x)
{
  unsigned c;
  if (v->cap < n) {
    c = FUN_0027f814(v, n - v->cap);
  } else {
    Fill(v->data, Min(n, v->size), *x, Tag(), Tag());
    if (n < v->size) {
      int cnt = v->size - n;
      C_0027e6d4 *e = v->data + v->size;
      v->size -= cnt;
      DestroyBack(e, cnt, Tag());
      return;
    }
    AppendN(v, n - v->size, *x, Tag());
    return;
  }
  FUN_0027f8f8(v, n, c);
  AppendN(v, n, *x, Tag());
}

// NEAR MISS (228 words vs 224 retail; same instruction stream except 4 dead words + 1 load order):
//  - vector<C_0027e6d4>::assign(n, x)-style for the 40-byte element with the virtual dtor at 0x27e6d4 (vtable
//    __vt__10C_0027e6d4 = 0x309c88 is already in symbols/EBOOT.BIN.txt): grow path (0x27f814 recommend,
//    0x27f8f8 clear+reallocate), else copy-assign min(n, size) elements, then destroy the tail backwards
//    (virtual slot 0, flag -1) or append n - size copies (placement new, null check). Layout of retail is
//    reproduced with the grow path written as the fall-through after an if/else whose else-part returns
//    (same trick as src/eboot/vec_assign_fill_00179ad8.cpp), `#pragma inline_depth(8)` (needed to inline the
//    implicit copy ctor), memberwise implicit copies (7 shorts, char[10] 2-per-pass loop, char[9], uchar, short).
//  - matching idiom: empty `Tag` by-value parameters on the inline helpers (Fill has two, the others one) give
//    retail's 48-byte frame with `n` at 24(sp) (n is address-taken through the inline Min(const T&, const T&)).
//  - REMAINING DIFFERENCES (all of the same kind): MWCC leaves the original of an instruction it copied into a
//    likely/jump delay slot behind as dead code at 3 sites that retail does not have: Min's else arm
//    (`b join` + dead `addiu v1,sp,24`), the append block head (dead `subu a1,v1,a0`) and the realloc tail head
//    (dead `move a0,s1`), plus the n/size load order before `sltu` (ours `lw v1,24(sp); lw a0,4(s1)`, retail
//    the reverse). Retail is clean at all three.
//  - RULED OUT (about 200 compiles): any inline LOOP in the else-part after the Min diamond (destroy or append)
//    turns Min's diamond unclean, while out-of-line calls there (as in vec_assign_fill_00179ad8.cpp) or
//    non-loop inline code keep it clean; Min forms (ternary either arm order, if/return, pointer select
//    `r=&a;if(b<a)r=&b;` = non-likely beqz), `const unsigned &m`, Size() getters, n/size compare order, loop
//    shapes (for/while/do-while, index/pointer), static vs plain inline, inline_depth values, resize-style
//    wrapper, A-before-D order, initialising c, explicit copy ctor, putting everything in the body.
