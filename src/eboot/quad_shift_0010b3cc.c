/* HSTMATCH module=EBOOT.BIN start=0x0010b3cc end=0x0010b564 symbol=FUN_0010b3cc lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char u8;

extern u8 DAT_002c10ac[];
extern u8 DAT_002c10c4[];
extern void FUN_0010b150(int);

struct Quad { int key; short a; short b; short c; short d; };
struct Obj {
  char pad0[0x10];
  struct Quad **quads;
  char pad1[0xd0 - 0x14];
  unsigned int f0d0;
  int f0d4;
  char pad2[0xec - 0xd8];
  short f0ec;
  short f0ee;
  char pad3[0x118 - 0xf0];
  int f118;
};

static inline void Shift(struct Quad *q, short x, short y)
{
  short d;
  d = q->a;
  q->a = x;
  d = x - d;
  q->c = q->c + d;
  d = q->b;
  q->b = y;
  d = y - d;
  q->d = q->d + d;
}

void FUN_0010b3cc(struct Obj *self)
{
  struct Quad **arr;
  struct Quad *cur;
  short off;
  short x;
  int idx;
  int mode;

  idx = self->f0d4;
  mode = self->f118;
  if (mode == 0)
    off = DAT_002c10ac[self->f0d0 % 21];
  else
    off = DAT_002c10c4[self->f0d0 % 21];
  arr = self->quads;
  cur = arr[idx];
  x = self->f0ec - 10 + off;
  switch (mode) {
  case 1:
    Shift(cur, x, self->f0ee + off - 19);
    break;
  case 2:
    Shift(*(struct Quad **)((char *)arr + (idx + 2) * 4), x, self->f0ee - off + 19);
    break;
  case 0:
  default:
    Shift(*(struct Quad **)((char *)arr + (idx + 1) * 4), x, self->f0ee);
    break;
  }
  FUN_0010b150((int)self);
}
