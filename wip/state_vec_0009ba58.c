/* HSTMATCH module=EBOOT.BIN start=0x0009ba58 end=0x0009bbf0 symbol=FUN_0009ba58 lang=c99 */
typedef struct { float x, y, z, w; } Vec4;

typedef struct {
  char pad00[0xf0];
  int state;             /* 0xf0 */
  char padf4[0x10];
  float f104;            /* 0x104 */
} Node;

typedef struct {
  char pad00[0x58];
  Node *node;            /* 0x58 */
} Inner;

typedef struct {
  char pad00[0x588];
  float f588;
  char pad58c[0x1c];
  float f5a8;
  char pad5ac[0x10];
  Inner *inner;          /* 0x5bc */
} Obj;

typedef struct {
  char pad00[0x10];
  Vec4 vec;              /* 0x10 */
  char pad20[0x1d4 - 0x20];
  int f1d4;
} Ent;

typedef struct {
  char pad00[0x3c];
  int mode;              /* 0x3c */
  char pad40[0x48];
  Ent *ent;              /* 0x88 */
} Glob;

static inline int NodeState(Node *n)
{
  return n ? n->state : -1;
}

static inline float NodeF104(Node *n)
{
  return n ? n->f104 : 0.0f;
}

extern Glob *DAT_003386b0;
extern void FUN_00093c7c(Inner *, Vec4 *);

void FUN_0009ba58(Obj *self)
{
  float v;
  Inner *inner;
  Node *node;
  int state;

  v = 1.0f;
  inner = self->inner;
  node = inner->node;

  state = NodeState(node);
  if (state > 0x43 && state < 0x88 && NodeF104(node) <= 5.0f) {
    v = 0.0f;
  } else if (state > 0x87 && state < 0x9e) {
    v = 0.0f;
  } else if (state > 0x9d && state < 0xf8) {
    v = 0.0f;
  } else {
    int mode = DAT_003386b0->mode;
    Ent *e = DAT_003386b0->ent;
    if ((mode == 4 || mode == 7 || mode == 5) && e->f1d4 < 2 && !(self->f5a8 * *(float *)((char *)e + 0x18) < self->f588 - 5.0f)) {
    } else {
      v = -1.0f;
    }
  }
  if (v == 1.0f) {
    Ent *e = DAT_003386b0->ent;
    Vec4 a;
    a.x = e->vec.x;
    a.y = e->vec.y;
    a.z = e->vec.z;
    a.w = e->vec.w;
    FUN_00093c7c(self->inner, &a);
  } else {
    Vec4 b;
    b.x = 0.0f;
    b.y = 0.0f;
    b.z = 0.0f;
    b.w = v;
    FUN_00093c7c(self->inner, &b);
  }
}
// NEAR: 102/102 words, 38 differ (sy2). Control flow and block order are now retail's (inline NodeState/NodeF104 null-check
// helpers give beqzl; the -1.0 default is ONE block reached by `if (A && B && !(prod < diff)) {} else v = -1.0f;`;
// Vec4 b = {0,0,0,v} explains the dead `swc1 f3,28(sp)` in the bc1fl slot). What differs: retail keeps `node` in a1 (so
// the range tests use `slti v0`, not `slti at`) and `DAT_003386b0` in a1/mode in v1 (ours G in v1, mode in a1), plus
// `bc1f; nop` at the c.lt.s where ours fills a likely slot with the join's `lui 0x3f80` (bc1fl). Ruled out: node via
// Inner local, via Obj* helpers, GetNode inline, reordered declarations, early-return on inner, flag/ok int, goto-done
// (103 words), duplicated -1 arms (105-106 words), ternary condition (117).
// sy2 (later): an inline `InRange(v, lo, hi) { return v > lo && v < hi; }` for the three ranges (materialised compares) is worse (103 words,
// 92 differ); the `at` vs `v0` temps and a1 vs v0 for `node` stay the only open items of the 102-word form above.
// near miss from lane sy2 (unreviewed)
