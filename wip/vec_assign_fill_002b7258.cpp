/* HSTMATCH module=EBOOT.BIN start=0x002b7258 end=0x002b73e4 symbol=FUN_002b7258 lang=c++ */
/* Hand-written reconstruction (vector<C_002b6eb0>::assign(n, x)-style, libc++-like: recommend 0x2b74b8, reallocate 0x2b759c, erase tail 0x2b7450,
   inline fill_n over min(n, size) and inline construct-at-end loops with placement new; 4 words too long, see notes below). */
inline void *operator new(unsigned, void *p) { return p; }
template <class T> inline const T &Min_002b7258(const T &a, const T &b) { return b < a ? b : a; }
struct Tag {};
struct Tag2 {};

class C_002b6eb0 {
public:
  virtual void key();
  virtual ~C_002b6eb0() {}
  signed char a, b, c;
};

struct EntryVec {
  C_002b6eb0 *data;
  unsigned size;
  unsigned cap;
};

extern "C" unsigned FUN_002b74b8(EntryVec *v, unsigned n);
extern "C" void FUN_002b759c(EntryVec *v, unsigned n, unsigned cap);
extern "C" void FUN_002b7450(EntryVec *v, unsigned n, Tag);

inline void Fill_002b7258(C_002b6eb0 *p, unsigned m, const C_002b6eb0 &x, Tag2)
{
  for (; m != 0; --m, ++p)
    *p = x;
}

inline void Append_002b7258(EntryVec *v, unsigned m, const C_002b6eb0 &x, Tag2)
{
  C_002b6eb0 *p = v->data + v->size;
  for (; m != 0; --m) {
    new (p) C_002b6eb0(x);
    ++p;
    ++v->size;
  }
}

extern "C" void FUN_002b7258(EntryVec *v, unsigned n, C_002b6eb0 *x, Tag)
{
  unsigned c;
  if (v->cap < n) {
    c = FUN_002b74b8(v, n - v->cap);
  } else {
    Fill_002b7258(v->data, Min_002b7258(n, v->size), *x, Tag2());
    if (v->size > n) {
      FUN_002b7450(v, v->size - n, Tag());
      return;
    }
    Append_002b7258(v, n - v->size, *x, Tag2());
    return;
  }
  FUN_002b759c(v, n, c);
  Append_002b7258(v, n, *x, Tag2());
}

// Near miss: functionally identical block structure to retail, 4 dead words too long (103 vs 99), so every later word is shifted.
// Frame (48, n at sp+24) and every instruction match: the 16 frame bytes come from the unused Tag param plus the two Tag2 params of
// the inline Fill/Append helpers. What differs: MWCC leaves the dead originals of two delay-slot copies that retail removed:
//  (1) Min block: ours `beqzl at,L; addiu v1,sp,24; b L; addiu v1,s2,4; <dead addiu v1,sp,24>; L:`, retail
//      `beqzl at,L; addiu v1,sp,24; addiu v1,s2,4; L:`;  (2) the grow block keeps a dead `move a0,s2` after the `b X; move a0,s2`.
// The dead copies appear only when the else-part (after Fill) contains an inline append (loop or even `if (m) {store; ++size}`);
// with the else-append out of line, or the whole function if/else without the early returns, the Min block is clean.
// Ruled out: Min argument order/forms (ternary inline, named ref local), for/while/do loops, ++p/++size order, early-return vs
// nested if/else, wrapping the else-part in an inline helper (moves n's frame slot), flat code without helpers (hoists data load).
