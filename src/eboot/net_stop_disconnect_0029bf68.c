/* HSTMATCH module=EBOOT.BIN start=0x0029bf68 end=0x0029c794 symbol=FUN_0029bf68 lang=c99 helpers=FUN_0029a584@0x0029a584-0x0029a5b0 */
/* Hand-written reconstruction from the disassembly (SetState copied from src/eboot/bundle_read_0029ade8.c); exact match verified; names and types await human review. The empty log stub FUN_0029a584 is a same-file static placed by helpers=. Matching idiom: the inlined SetState switches on the just-stored member (self->state). */
extern char DAT_002c0e18;
extern char DAT_002c0e1c;
extern char DAT_002c0e20;
extern char DAT_002cb848[];
extern char DAT_002cb824[];
extern char DAT_002ffef4[];
extern char DAT_002fff14[];
extern char DAT_002ffd3c[];
extern char DAT_002ffd74[];
extern char DAT_002ffda4[];
extern char DAT_002ffdd4[];
extern char DAT_002cb63c[];
extern char DAT_002cb5e8[];
extern char DAT_002cb8a4[];
extern char DAT_002cb880[];
extern char DAT_002cb7ec[];
extern char DAT_002fe878[];
extern char DAT_002fe888[];
extern char DAT_002cb68c[];
extern char DAT_002cb6a4[];
extern char DAT_002cb6dc[];
extern char DAT_002cb714[];
extern unsigned int DAT_0034b320;
extern unsigned int DAT_0034b324;
extern int DAT_002ffcc8;
extern int DAT_00311000;
extern void *DAT_003415ac;
extern void *DAT_00338ac4;

typedef struct Row { void **items; int count; int pad; } Row;
typedef struct Tbl { int a; int b; int count; } Tbl;
typedef struct Obj { int x; int ok; Tbl *tbl; Row *rows; } Obj;

typedef struct Xfer {
  unsigned char ready;     /* 0x00 */
  int f04;                 /* 0x04 */
  void *obj;               /* 0x08 */
  int fd;                  /* 0x0c */
  int f10;                 /* 0x10 */
  unsigned char b14, b15, b16, b17, b18;
  int f1c;                 /* 0x1c */
  char pad20[0x7420 - 0x20];
  int f7420;
  char pad7424[0xe424 - 0x7424];
  int fe424;
  char pade428[0x15828 - 0xe428];
  int f15828;
  int f1582c;
  int f15830;
  int f15834;
  int f15838;
} Xfer;

typedef struct Net {
  unsigned char active;    /* 0x00 */
  int f04;                 /* 0x04 */
  int state;               /* 0x08 */
  Xfer *xfer;              /* 0x0c */
  int f10, f14, f18;
  int buf;                 /* 0x1c */
  int size;                /* 0x20 */
} Net;

typedef struct Desc {
  int head[4];
  int size;
  int align;
  const char *name;
  const char *files;
} Desc;

extern int FUN_002b7dc0(void);
extern int FUN_002b7d68(void);
extern void FUN_002b7888(int);
extern int FUN_002b7d70(int);
extern int FUN_002b7d78(void);
extern int FUN_002b7e40(void);
extern int FUN_002b7d90(void);
extern int FUN_002b7cc0(int);
extern Obj *FUN_0018c9f4(int);
extern char *FUN_0018f1ac(Obj *, int, int);
extern void FUN_00115088(void *, int, const char *, int, int);
extern void FUN_00103628(void *, int);
extern void FUN_002956e0(int);
extern void *FUN_00000bcc(int);
extern void *FUN_000ba2a8(void *);
extern void *FUN_000c02d8(void *);
extern void FUN_000ba9e0(void *, Desc *);
extern unsigned char FUN_000ba57c(void *, Desc *);
extern int FUN_002b7790(const char *, int, int);
extern void FUN_0001b880(void);
extern void FUN_0029c794(Xfer *);
extern void FUN_00060224(int, int);
extern void FUN_002b7958(int);
extern long long FUN_002b77a0(int, long long, int);
extern int FUN_002b7720(int, int, int);
extern int FUN_002b7738(int);
extern unsigned int FUN_002b7cf8(void);

static void FUN_0029a584(...)
{
}

static inline void SetState(Net *self, int mode)
{
  int fd;
  int n;

  self->state = mode;
  switch (self->state) {
  case 0:
    return;
  case 3:
    self->f04 = 0;
    return;
  case 4:
    FUN_00060224(DAT_00311000, 1);
    FUN_0001b880();
    FUN_0029a584(DAT_002cb714, DAT_002cb6dc);
    while ((fd = FUN_002b7790(DAT_002cb6a4, 1, 0)) < 0) {
      FUN_0001b880();
    }
    self->size = (int)FUN_002b77a0(fd, 0LL, 2);
    while (self->size < 0) {
      FUN_0001b880();
      self->size = (int)FUN_002b77a0(fd, 0LL, 2);
    }
    while (FUN_002b77a0(fd, 0LL, 0) < 0) {
      FUN_0001b880();
    }
    for (;;) {
      while ((FUN_002b7cf8() & 0x20) == 0) {
        FUN_0029a584(DAT_002cb68c);
        FUN_002b7958(1000000);
      }
      n = self->size;
      if (FUN_002b7720(fd, self->buf, n) == n)
        break;
      FUN_002b7958(1000000);
    }
    n = FUN_002b7738(fd);
    while (n < 0) {
      FUN_002b7958(1000000);
      n = FUN_002b7738(fd);
    }
    FUN_00060224(DAT_00311000, 0);
    return;
  }
}

static inline char *GetStr(Obj *o, int i, int j)
{
  if (o->ok == 0)
    return &DAT_002c0e20;
  if (i < 0 || i >= o->tbl->count)
    return &DAT_002c0e1c;
  if (j < 0 || j >= o->rows[i].count)
    return &DAT_002c0e18;
  return o->rows[i].items[j];
}

int FUN_0029bf68(Net *self)
{
  int r;
  Xfer *x;
  void *p;
  Desc desc;

  r = FUN_002b7dc0();
  if (r < 0) {
    FUN_0029a584(DAT_002cb848, r);
  } else {
    FUN_0029a584(DAT_002cb824);
  }
  self->active = 0;
  FUN_0029a584(DAT_002ffef4);
  DAT_0034b320 = 0;
  DAT_0034b324 = 0;
  r = FUN_002b7d68();
  if (r < 0) {
    FUN_0029a584(DAT_002fff14, r);
  } else {
    for (;;) {
      if (DAT_0034b320 & 4)
        break;
      FUN_002b7888(1000000);
    }
    DAT_0034b320 &= ~4;
  }
  if (DAT_002ffcc8 > 0) {
    r = FUN_002b7d70(DAT_002ffcc8);
    if (r < 0) {
      FUN_0029a584(DAT_002ffd3c, r);
    }
    DAT_002ffcc8 = -1;
  }
  r = FUN_002b7d78();
  if (r < 0) {
    FUN_0029a584(DAT_002ffd74, r);
  }
  r = FUN_002b7e40();
  if (r < 0) {
    FUN_0029a584(DAT_002ffda4, r);
  }
  r = FUN_002b7d90();
  if (r < 0) {
    FUN_0029a584(DAT_002ffdd4, r);
  }
  switch (self->state) {
  case 8:
    x = self->xfer;
    FUN_0029a584(DAT_002cb8a4);
    FUN_002956e0(x->f1c);
    p = FUN_00000bcc(0x288);
    if (p != 0)
      p = FUN_000ba2a8(p);
    DAT_00338ac4 = p;
    p = FUN_00000bcc(0x1c);
    if (p != 0)
      p = FUN_000c02d8(p);
    x->obj = p;
    x->f04 = 0;
    x->f10 = 0;
    x->b14 = 1;
    x->b15 = 1;
    x->b16 = 0;
    x->b17 = 0;
    x->b18 = 0;
    x->f7420 = 0;
    x->fe424 = 0;
    x->f15828 = 0;
    x->f1582c = 0;
    x->f15830 = 0x7fffffff;
    x->f15834 = 0;
    x->f15838 = 0;
    FUN_000ba9e0(DAT_00338ac4, &desc);
    desc.size = 0xb800;
    desc.align = 0x1000;
    desc.name = DAT_002fe878;
    desc.files = DAT_002fe888;
    x->ready = FUN_000ba57c(DAT_00338ac4, &desc);
    FUN_0029a584(DAT_002cb880, DAT_002cb7ec);
    while ((x->fd = FUN_002b7790(DAT_002cb7ec, 1, 0)) < 0) {
      FUN_0001b880();
    }
    FUN_0029c794(x);
    FUN_00115088(DAT_003415ac, 4, FUN_0018f1ac(FUN_0018c9f4(0x11), 14, 2), 0, 0);
    SetState(self, 11);
    break;
  case 9:
    r = FUN_002b7cc0(0x101);
    if (r < 0) {
      FUN_0029a584(DAT_002cb63c, r);
    }
    r = FUN_002b7cc0(0x100);
    if (r < 0) {
      FUN_0029a584(DAT_002cb5e8, r);
    }
    FUN_00115088(DAT_003415ac, 2, GetStr(FUN_0018c9f4(0x11), 14, 8), 0, 0);
    SetState(self, 0);
    break;
  default:
    FUN_00103628(DAT_003415ac, 1);
    break;
  }
  return 0;
}
