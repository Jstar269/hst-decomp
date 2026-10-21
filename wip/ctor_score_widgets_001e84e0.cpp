/* HSTMATCH module=EBOOT.BIN start=0x001e84e0 end=0x001e88c0 symbol=FUN_001e84e0 lang=c++ */
#pragma opt_strength_reduction off

extern char DAT_003094c0[];
extern char DAT_002ed280[];
extern float DAT_002ec1c4;
extern char *DAT_002ec224[];
extern char DAT_002ec54c[];
extern int DAT_002ed244[];

struct Entry {
  int idx;
  char *name;
  int out;
};
extern Entry DAT_002ec980[];

extern "C" {
void FUN_00102e38(void *);
void FUN_00104118(void *, char *, int);
void FUN_00103540(void *, float);
void *FUN_001039d8(void *, char *, int);
int FUN_00014934(const char *, const char *);
int *FUN_001026b8(void *, char *);
void FUN_000ffc3c(void *, int);
void FUN_000ee44c(int, int, int, int, int);
}

class Widget {
public:
  virtual void m0();
  virtual void m1();
  virtual void m2();
  virtual void m3();
  virtual void m4();
  virtual void m5(int v);
};

struct Rect {
  short x0, x2, x4, x6, x8, xa;
};

struct Rec24 {
  int z[6];
};

struct Self {
  void *vt;
  char pad04[0x54 - 4];
  int f54;
  int f58;
  Widget *a5c[8];
  void *a7c[187];
  Widget *a368[12];
  int f398;
  int w39c[2];
  Rec24 za[2];
  int w3d4[2];
  int w3dc[2];
  int f3e4;
  Rec24 na[2];
  unsigned char b418;
  unsigned char b419;
  char pad41a[2];
  int f41c;
  int f420;
  unsigned char b424;
  char pad425[3];
  int f428;
  int f42c;
  int f430;
  int f434;
  int f438;
  unsigned char b43c;
  char pad43d[3];
  int f440;
};

extern "C" Self *FUN_001e84e0(Self *self)
{
  FUN_00102e38(self);
  self->vt = DAT_003094c0;
  FUN_00104118(self, DAT_002ed280, 0);
  FUN_00103540(self, DAT_002ec1c4);
  char *held = 0;
  int i = 0;
  char **src = DAT_002ec224;
  int off = 0;
  do {
    Widget *w = (Widget *)FUN_001039d8(self, *src, 0);
    *(Widget **)((unsigned int)self + off + 0x5c) = w;
    (*(Widget **)((unsigned int)self + off + 0x5c))->m5(-2);
    i++;
    src++;
    off += 4;
  } while (i < 8);
  int off2;
  int i2;
  int k;
  Entry *e;
  int j;
  Entry *ek;
  i2 = 0;
  e = DAT_002ec980;
  off2 = 0;
  do {
    if (FUN_00014934(e->name, DAT_002ec54c) == 0) {
      for (k = 1;; k++) {
        j = i2 - k;
        ek = &DAT_002ec980[j];
        if (FUN_00014934(ek->name, DAT_002ec54c) != 0)
          break;
      }
      void **tbl;
      if (k == 1) {
        held = *(char **)(((char **)self)[j + 0x1f] + 0x20);
        void *o = **(void ***)(held + 0x10);
        ((void **)self)[j + 0x1f] = o;
        FUN_000ffc3c(o, -256);
        ek->out = *(int *)(*(char **)((unsigned long)self + j * 4 + 0x7c) + 0x24);
        tbl = *(void ***)(held + 0x10);
      } else {
        tbl = *(void ***)(held + 0x10);
      }
      void *o2 = tbl[k];
      *(void **)((unsigned int)self + off2 + 0x7c) = o2;
      FUN_000ffc3c(o2, -256);
      char *r = *(char **)((unsigned long)self + off2 + 0x7c);
      int sv = (int)((float)k * 14.0f);
      *(short *)(r + 6) = *(short *)(r + 6) + sv;
      *(short *)(r + 10) = *(short *)(r + 10) + sv;
      e->out = *(int *)(*(char **)((unsigned long)self + off2 + 0x7c) + 0x24);
    } else {
      int *v = FUN_001026b8(self->a5c[e->idx], e->name);
      *(int **)((unsigned int)self + off2 + 0x7c) = v;
      if (v != 0) {
        FUN_000ffc3c(v, -256);
        e->out = *(int *)(*(char **)((unsigned long)self + off2 + 0x7c) + 0x24);
      }
    }
    i2++;
    e++;
    off2 += 4;
  } while (i2 < 187);
  int i3 = 0;
  int *src3 = DAT_002ed244;
  int off3 = 0;
  do {
    Widget *p = *(Widget **)((char *)self->a7c[*src3] + 0x20);
    *(Widget **)((unsigned int)self + off3 + 0x368) = p;
    (*(Widget **)((unsigned int)self + off3 + 0x368))->m5(-16);
    i3++;
    src3++;
    off3 += 4;
  } while (i3 < 12);
  int a;
  int b;
  int base;
  a = 0;
  base = 0;
  do {
    int *q = (int *)self + base;
    b = 0;
    do {
      if (b == 2) {
        unsigned color = a < 2 ? 0x807c79ff : 0x8040b4ff;
        **(unsigned **)(q + 0x4f) = color;
      }
      b++;
      q++;
    } while (b < 3);
    a++;
    base += 3;
  } while (a < 4);
  self->f398 = 1;
  int c = 0;
  int *pb;
  int *pa;
  pa = (int *)self;
  pb = (int *)self;
  do {
    pb[0xe7] = 0;
    pb[0xf5] = 0;
    pb[0xf7] = -1;
    pa[0xe9] = 0;
    pa[0xfa] = -1;
    pa[0xea] = 0;
    pa[0xfb] = -1;
    pa[0xeb] = 0;
    pa[0xfc] = -1;
    pa[0xec] = 0;
    pa[0xfd] = -1;
    pa[0xed] = 0;
    pa[0xfe] = -1;
    pa[0xee] = 0;
    c++;
    pa[0xff] = -1;
    pb++;
    pa += 6;
  } while (c < 2);
  self->f3e4 = 0;
  self->b418 = 0;
  self->b419 = 0;
  self->f41c = 5;
  self->f420 = 5;
  self->b424 = 1;
  self->f428 = 0;
  self->f54 = 0;
  self->f58 = 0;
  self->f42c = 0;
  self->f430 = 1;
  self->f434 = 0;
  self->f438 = 0x10;
  self->b43c = 0;
  self->f440 = 0;
  int d = 0;
  int off4 = 0;
  do {
    Rect *r = *(Rect **)((unsigned int)self + off4 + 0x13c);
    FUN_000ee44c(d, r->x4, r->x6, r->x8, r->xa);
    d++;
    off4 += 12;
  } while (d < 4);
  return self;
}
// NEAR MISS (249/248 words, 4 real differences left; verified with a sequence diff, the 179 'differ' words are mostly shift):
// File-level `#pragma opt_strength_reduction off` is part of the match (loop 4 keeps `t0 += 3` + `sll/addu`, the two pointer walks of the
// 2-entry init loop are explicit `pa += 6; pb++`). Solved on the way: virtual calls through the stored slot, plain assignment for
// `*(short *)(r + 6) = *(short *)(r + 6) + sv` (no seh), `(unsigned long)` re-reads of the element, declaration order off2,i2,k,e,j,ek,
// `unsigned color = a < 2 ? 0x807c79ff : 0x8040b4ff`, `a, b, base` declared up front and `pb`, `pa` in that order.
// Open:
// 1. latch of the search loop: retail `beqzl v0,top; addiu s3,s3,1` falling into the exit; ours `bnezl v0,exit+4; li v0,1; b top; addiu s3,s3,1` (+1 word).
//    Tried for(;;k++)+break, while(1), do/while with (k++,1) / ++k in the condition, continue, goto again, for(;comma-cond;k++), k pre-incremented,
//    condition-only loops with j/ek recomputed afterwards (they peel the first test).
// 2. the join after `if (k == 1) {..}` (tbl assigned in both arms, o2 = tbl[k]): retail temps lw v0 / sll v1 / addu a2,s5,s6 (store address
//    first), ours v1 / v0 and the address computed after the load.
// 3. two instruction-order swaps in the preheaders of loop 4 (`move t1,zero` after `sll v0,t0,2`) and loop 5 (`move a1,s5` before `move a0,s5`).
// near miss from lane sn4 (unreviewed)
