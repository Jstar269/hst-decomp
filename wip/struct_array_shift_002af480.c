/* HSTMATCH module=EBOOT.BIN start=0x002af480 end=0x002af5b0 symbol=FUN_002af480 lang=c99 */
// NEAR 58 (76/76 words): structure now identical to retail word for word - every differing word
// is a register-name permutation, not an opcode or offset. Two findings this round:
//   * `slt` -> `sltu` needs param_1 typed as a POINTER (`char *`) so the loop test is a pointer
//     compare; `(unsigned)param_1 < (unsigned)src` on an int param gives the same sltu but keeps the
//     old allocation, and `&dst[-param_2]` or a do-while both cost words.
//   * the whole 8-byte-chunk copy (26 `struct Pair` elements) unrolls from ONE `struct Arr26`
//     member assignment; typing the mover as a 308-byte struct assignment is what killed the
//     earlier 27-word candidate area. Ghost `char[0x134]` copies do NOT unroll.
// Remaining gap: retail holds dst in t2 and uses v1 for the 308 constant, mflo and the copy temp;
// ours puts the constant in a2 and dst in v1. Birth order matches (constant, dst, mflo, src), so
// this is an allocator tie, not a source shape - `int n = param_2` hoisting, `char *lim = param_1`,
// do-while, unsigned param, separate declarations and `&dst[-param_2]` all reproduce it unchanged.
struct Pair { int a, b; };
struct Arr26 { struct Pair v[26]; };
struct Vec4 { float x, y, z, w; };
struct Vec2 { float x, y; };

struct Elem {
  int f00;
  int f04;
  struct Arr26 arr;
  unsigned char b;
  char pad[3];
  int fdc;
  int fe0;
  struct Vec4 q;
  struct Vec4 r;
  struct Vec2 s;
  int f10c;
  struct Vec4 t;
  int u0;
  int u1;
  int u2;
  int u3;
  int u4;
};

void FUN_002af480(char *param_1,int param_2)
{
  struct Elem *dst = (struct Elem *)((char *)param_1 + 0x7850);
  struct Elem *src = dst - param_2;
  int i;

  while (param_1 < (char *)src) {
    src--;
    dst--;
    dst->f00 = src->f00;
    dst->f04 = src->f04;
    dst->arr = src->arr;
    dst->b = src->b;
    dst->fdc = src->fdc;
    dst->fe0 = src->fe0;
    dst->q = src->q;
    dst->r = src->r;
    dst->s = src->s;
    dst->f10c = src->f10c;
    dst->t = src->t;
    dst->u0 = src->u0;
    dst->u1 = src->u1;
    dst->u2 = src->u2;
    dst->u3 = src->u3;
    dst->u4 = src->u4;
  }
}
// improved by lane fm5 (unreviewed): 72 -> 58 differing words
