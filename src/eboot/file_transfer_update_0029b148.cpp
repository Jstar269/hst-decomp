/* HSTMATCH module=EBOOT.BIN start=0x0029b148 end=0x0029ba08 symbol=FUN_0029b148 lang=c++ helpers=FUN_0029a584@0x0029a584-0x0029a5b0 */
/* Hand-written reconstruction from the disassembly (SetState copied from src/eboot/bundle_read_0029ade8.c, close sequence from src/eboot/net_match_teardown_0029ab94.cpp); exact match verified; names and types await human review. The empty log stub FUN_0029a584 is a same-file static placed by helpers=. Matching idioms: inlined SetState switches on the just-stored member; the "still sending" test is a const inline helper (IsSending) so x->done is reloaded later. */
extern "C" {
extern char DAT_002c0e18;
extern char DAT_002c0e1c;
extern char DAT_002c0e20;
extern char DAT_002cb92c[];
extern char DAT_002cb938[];
extern char DAT_002cb8bc[];
extern char DAT_002cb8d0[];
extern char DAT_002cb8f4[];
extern char DAT_002cb68c[];
extern char DAT_002cb6a4[];
extern char DAT_002cb6dc[];
extern char DAT_002cb714[];
extern char DAT_0034179c[];
extern int DAT_00311000;
extern void *DAT_003415ac;
}

struct RefObj {
  virtual void Release(int);
  virtual void Slot0();
};

extern "C" RefObj *DAT_00338ac4;

struct Row { void **items; int count; int pad; };
struct Tbl { int a; int b; int count; };
struct Obj { int x; int ok; Tbl *tbl; Row *rows; };

struct MacAddr {
  char addr[6];
  MacAddr() {}
};

struct Xfer {
  unsigned char ready;     /* 0x00 */
  int state;               /* 0x04 */
  RefObj *obj;             /* 0x08 */
  int fd;                  /* 0x0c */
  int sent;                /* 0x10 */
  unsigned char b14, b15, done, failed, aborted;
  int f1c;                 /* 0x1c */
  char pad20[0x15830 - 0x20];
  int total;               /* 0x15830 */
  int idle;                /* 0x15834 */
  int error;               /* 0x15838 */
};

struct Net {
  unsigned char active;    /* 0x00 */
  int f04;                 /* 0x04 */
  int state;               /* 0x08 */
  Xfer *xfer;              /* 0x0c */
  int f10, f14, f18;
  int buf;                 /* 0x1c */
  int size;                /* 0x20 */
  int f24;
  int result;              /* 0x28 */
};

extern "C" {
static void FUN_0029a584(...)
{
}
int FUN_0029bd04(RefObj *);
MacAddr *FUN_0029bcfc(RefObj *);
void FUN_000bab10(RefObj *);
int FUN_000c038c(RefObj *, unsigned char, int, const MacAddr *, const MacAddr *);
void FUN_0029bb48(Xfer *);
void FUN_0029ba20(Xfer *);
int FUN_000c06c8(RefObj *);
unsigned int FUN_000c06b0(RefObj *);
void FUN_000c06f0(RefObj *);
void FUN_000bb190(RefObj *);
int FUN_0029ba14(void);
int FUN_0029ba08(void);
int FUN_0001efc0(void);
void FUN_0001efac(void);
void FUN_0001ebd4(void);
int FUN_0011564c(void *);
void FUN_001b1c44(void *, int);
Obj *FUN_0018c9f4(int);
void FUN_00115088(void *, int, const char *, int, int);
void FUN_0029e108(void);
void FUN_002b7960(int, int);
int FUN_002b7dc0(void);
void FUN_000ba78c(RefObj *);
void FUN_00060224(int, int);
void FUN_0001b880(void);
void FUN_002b7958(int);
int FUN_002b7790(const char *, int, int);
long long FUN_002b77a0(int, long long, int);
int FUN_002b7720(int, int, int);
int FUN_002b7738(int);
unsigned int FUN_002b7cf8(void);
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
  return (char *)o->rows[i].items[j];
}

static inline int IsSending(const Xfer *x)
{
  int r = (x->done != 0) ^ 1;
  if (r)
    r = x->idle > 0;
  return r;
}

static inline void XferClose(Xfer *x)
{
  RefObj *p;
  int r;

  FUN_002b7960(0, 0x26);
  if (x->obj != 0) {
    FUN_000c06f0(x->obj);
  }
  p = x->obj;
  if (p != 0) {
    if (p != 0) {
      p->Release(1);
    }
    x->obj = 0;
  }
  r = x->fd;
  if (r >= 0) {
    FUN_002b7738(r);
    x->fd = -1;
  }
  if (x->ready != 0) {
    x->ready = 0;
    r = FUN_002b7dc0();
    if (r < 0) {
      FUN_0029a584(DAT_002cb8f4, r);
    } else {
      FUN_0029a584(DAT_002cb8d0);
    }
    FUN_000ba78c(DAT_00338ac4);
  }
  if (DAT_00338ac4 != 0) {
    if (DAT_00338ac4 != 0) {
      DAT_00338ac4->Release(1);
    }
    DAT_00338ac4 = 0;
  }
  FUN_0029a584(DAT_002cb8bc);
}

extern "C" void FUN_0029b148(Net *self)
{
  Xfer *x;
  bool show;
  char *msg;
  int locked;
  int pending;

  x = self->xfer;
  if (x == 0)
    return;
  switch (x->state) {
  case 0:
    switch (FUN_0029bd04(DAT_00338ac4)) {
    case 0:
      FUN_000bab10(DAT_00338ac4);
      break;
    case 2: {
      x->state = 1;
      MacAddr mac = *FUN_0029bcfc(DAT_00338ac4);
      FUN_000c038c(x->obj, 1, 1, &mac, 0);
      break;
    }
    case 3:
      FUN_0029a584(DAT_002cb938);
      break;
    }
    break;
  case 1:
    FUN_0029bb48(x);
    FUN_0029ba20(x);
    if (x->sent >= x->total && FUN_000c06c8(x->obj) <= 0 && ++x->idle > 120) {
      FUN_0029a584(DAT_002cb92c);
      x->state = 2;
      x->done = 1;
    }
    break;
  }
  if ((FUN_000c06b0(x->obj) & 0x8000) == 0x8000) {
    x->failed = 1;
    FUN_000c06f0(x->obj);
  }
  FUN_000bb190(DAT_00338ac4);
  if (FUN_0029ba14() == 0) {
    x->failed = 1;
    x->error = FUN_0029ba08();
    FUN_000c06f0(x->obj);
  }
  show = false;
  msg = 0;
  locked = (unsigned char)FUN_0001efc0();
  if (locked) {
    FUN_0001efac();
  }
  x = self->xfer;
  if (!IsSending(x)) {
    if (x->failed) {
      self->result = 2;
      show = true;
      switch (self->xfer->error) {
      case (int)0x80410b03:
        msg = GetStr(FUN_0018c9f4(0x11), 14, 20);
        break;
      case (int)0x80410b0f:
        msg = GetStr(FUN_0018c9f4(0x11), 14, 21);
        break;
      default:
        msg = GetStr(FUN_0018c9f4(0x11), 14, 19);
        break;
      }
    } else if (x->aborted) {
      self->result = 2;
      show = true;
      msg = GetStr(FUN_0018c9f4(0x11), 14, 26);
    } else if (x->done) {
      self->result = 1;
      show = true;
      msg = GetStr(FUN_0018c9f4(0x11), 14, 3);
    } else if (FUN_0011564c(DAT_003415ac)) {
      FUN_001b1c44(DAT_0034179c, 4);
      self->result = 2;
      show = true;
      msg = GetStr(FUN_0018c9f4(0x11), 14, 8);
    }
  }
  if (locked) {
    FUN_0001ebd4();
  }
  if (show) {
    SetState(self, 1);
    XferClose(self->xfer);
    FUN_00115088(DAT_003415ac, 2, msg, 0, 0);
    FUN_0029e108();
  }
}
