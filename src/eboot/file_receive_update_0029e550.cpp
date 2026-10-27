/* HSTMATCH module=EBOOT.BIN start=0x0029e550 end=0x0029ef50 symbol=FUN_0029e550 lang=c++ helpers=FUN_0029e3cc@0x0029e3cc-0x0029e3f8 rodata=0x002cb9c8 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. The empty log stub FUN_0029e3cc is a same-file static placed by helpers= (its preserved v0 carries the FUN_002990e0 result past the two log calls). Matching idioms: one-case switch with default for the state==0 test; the save-size compare written need-first (NeedKB(x) <= remain). */
struct RefObj {
  virtual void Release(int);
  virtual void Slot0();
};

struct Listener {
  virtual void V0();
  virtual void V1();
  virtual void V2();
  virtual void V3();
  virtual void V4();
  virtual void V5();
  virtual void V6();
  virtual void V7();
  virtual void V8();
  virtual void V9();
  virtual void V10();
  virtual void Notify();
};

struct MacAddr {
  char addr[6];
  MacAddr() {}
};

struct Recv {
  int state;               /* 0x00 */
  RefObj *obj;             /* 0x04 */
  int f08, f0c;
  int got;                 /* 0x10 */
  int total;               /* 0x14 */
  int extra;               /* 0x18 */
  int progress;            /* 0x1c */
  int error;               /* 0x20 */
  unsigned char failed;    /* 0x24 */
  unsigned char finished;  /* 0x25 */
  int thread;              /* 0x28 */
  char message[0x180];     /* 0x2c */
  int wait;                /* 0x1ac */
  Listener *listener;      /* 0x1b0 */
  char pad1b4[0x201c4 - 0x1b4];
  char text[0x400];        /* 0x201c4 */
};

struct Owner {
  char pad[0x3c];
  Recv *recv;
};

extern "C" {
extern char DAT_0034179c[];
extern char DAT_0034b32c[];
extern char DAT_002cbfbc[];
extern char DAT_002cbfa4[];
extern char DAT_002cbf90[];
extern void *DAT_003415ac;
extern void *DAT_0034176c;
extern RefObj *DAT_00338ac4;

static void FUN_0029e3cc(...)
{
}
int FUN_002a0370(void *);
int FUN_001156fc(void *);
int FUN_0011574c(void *);
int FUN_001156ac(void *);
int FUN_0011564c(void *);
int FUN_001155c0(void *);
int FUN_001156d4(void *);
void FUN_001b1c44(void *, int);
int FUN_0029bd04(RefObj *);
MacAddr *FUN_0029bcfc(RefObj *);
void FUN_000bab10(RefObj *);
void FUN_002b7da0(void *, MacAddr *);
int FUN_000c038c(RefObj *, unsigned char, int, const MacAddr *, const MacAddr *);
void FUN_0029f92c(Recv *, int);
void FUN_0029ef70(Recv *, int);
unsigned int FUN_000c06b0(RefObj *);
int FUN_000c06dc(RefObj *);
void FUN_000c06f0(RefObj *);
void FUN_0029f818(Recv *);
void FUN_0029f70c(Recv *, int);
void *FUN_0018c9f4(int);
char *FUN_0018f1ac(void *, int, int);
char *FUN_00198278(void *, const char *, int, char *);
void FUN_00115088(void *, int, const char *, int, int);
int FUN_00296cac(void);
int FUN_002990e0(int, long long *);
void FUN_002955b4(void *);
int FUN_0029ef50(void);
int FUN_002b7908(int);
void FUN_00295cdc(void *);
void FUN_0004784c(void);
void FUN_00295ccc(void *, float, float);
void FUN_00295cc4(void *, float);
void FUN_000bb190(RefObj *);
int FUN_0029ba14(void);
int FUN_0029ba08(void);
void FUN_000149a8(char *, const char *);
}

static inline char *Text(Recv *x, int j)
{
  return FUN_00198278(DAT_0034176c, FUN_0018f1ac(FUN_0018c9f4(0x11), 14, j), 0x400, x->text);
}

static inline void Fail(Recv *x, int code)
{
  x->failed = 1;
  FUN_0029ef70(x, code);
  FUN_0029f92c(x, 8);
}

static inline int NeedKB(Recv *x)
{
  return ((x->total + 0x7fff) / 0x8000 + (x->extra + 0x7fff) / 0x8000) * 0x8000 / 1024 + 0x60;
}

extern "C" void FUN_0029e550(Owner *self)
{
  Recv *x;
  RefObj *p;
  int r;
  int err;
  MacAddr mine;
  long long remain;

  x = self->recv;
  if (FUN_002a0370(DAT_003415ac) == 0) {
    if (FUN_001156fc(DAT_003415ac)) {
      FUN_001b1c44(DAT_0034179c, 3);
    } else if (FUN_0011574c(DAT_003415ac)) {
      FUN_001b1c44(DAT_0034179c, 4);
    } else if (FUN_001156ac(DAT_003415ac)) {
      FUN_001b1c44(DAT_0034179c, 1);
    }
  }
  switch (x->state) {
  case 0:
    switch (FUN_0029bd04(DAT_00338ac4)) {
    case 0:
      FUN_000bab10(DAT_00338ac4);
      break;
    case 2: {
      FUN_002b7da0(DAT_0034b32c, &mine);
      MacAddr peer = *FUN_0029bcfc(DAT_00338ac4);
      FUN_000c038c(x->obj, 0, 1, &mine, &peer);
      FUN_0029f92c(x, 1);
      break;
    }
    case 3:
      FUN_0029e3cc(DAT_002cbfbc);
      break;
    }
    break;
  default:
    p = x->obj;
    if (p != 0) {
      if (x->failed != 0) {
        if (p != 0) {
          if (p != 0) {
            p->Release(1);
          }
          x->obj = 0;
        }
      } else {
        if (x->finished == 0 && FUN_000c06b0(p) != 0 && FUN_000c06b0(x->obj) != 0x4000) {
          x->failed = 1;
          FUN_001b1c44(DAT_0034179c, 5);
          FUN_00115088(DAT_003415ac, 0, Text(x, 22), 0, 0);
          p = x->obj;
          if (p != 0) {
            if (p != 0) {
              p->Release(1);
            }
            x->obj = 0;
          }
        } else if (x->got >= x->total && FUN_000c06dc(x->obj) <= 0) {
          x->finished = 1;
        } else {
          FUN_0029f818(x);
        }
      }
    }
    break;
  }
  switch (x->state) {
  case 0:
  case 1:
  case 2:
    FUN_0029f70c(x, 0x20000);
    break;
  }
  switch (x->state) {
  case 0:
    if (FUN_0011564c(DAT_003415ac)) {
      Fail(x, 0x80000006);
    }
    break;
  case 1:
    if (FUN_001155c0(DAT_003415ac)) {
      if (FUN_001156d4(DAT_003415ac) == 0) {
        r = FUN_00296cac();
        if (r < 0) {
          Fail(x, r);
        } else {
          FUN_00115088(DAT_003415ac, 0, Text(x, 18), 0, 0);
          FUN_0029f92c(x, 2);
        }
      } else {
        Fail(x, 0x80000006);
      }
    }
    break;
  case 2:
    if (x->total == 0x7fffffff) {
      if (FUN_0011564c(DAT_003415ac)) {
        Fail(x, 0x80000006);
      }
    } else {
      r = FUN_002990e0(0, &remain);
      FUN_0029e3cc(DAT_002cbfa4, remain);
      FUN_0029e3cc(DAT_002cbf90, NeedKB(x));
      if (r == 0) {
        if (NeedKB(x) <= remain) {
          FUN_00115088(DAT_003415ac, 1, Text(x, 17), 0, 0);
          FUN_002955b4(DAT_003415ac);
          FUN_0029f92c(x, 3);
        } else {
          Fail(x, 0x8001001c);
        }
      } else if (r == (int)0x80020321 || r == (int)0x80010013) {
        Fail(x, 0x80010013);
      } else {
        Fail(x, r);
      }
    }
    break;
  case 3:
    if (FUN_001155c0(DAT_003415ac)) {
      if (FUN_001156d4(DAT_003415ac) == 0) {
        FUN_00115088(DAT_003415ac, 4, Text(x, 6), 0, 0);
        FUN_0029f92c(x, 4);
      } else {
        Fail(x, 0x80000006);
      }
    }
    break;
  case 4:
    if (FUN_0029ef50() != 0 || FUN_0011564c(DAT_003415ac) != 0) {
      if (FUN_0029ef50() != 0) {
        FUN_001b1c44(DAT_0034179c, 4);
      }
      x->failed = 1;
      FUN_0029f92c(x, 7);
    } else if (FUN_002b7908(x->thread) == 0) {
      if (x->error == 0) {
        FUN_0029f92c(x, 5);
      } else {
        x->failed = 1;
        FUN_0029ef70(x, x->error);
        FUN_0029f92c(x, 8);
      }
    }
    break;
  case 5:
    if (x->wait-- <= 0) {
      FUN_0029f92c(x, 6);
    }
    break;
  case 6:
    if (FUN_002b7908(x->thread) == 0) {
      FUN_0029ef70(x, x->error);
      FUN_0029f92c(x, 8);
    }
    break;
  case 7:
    if (FUN_002b7908(x->thread) == 0) {
      x->failed = 1;
      FUN_0029ef70(x, x->error);
      FUN_0029f92c(x, 8);
    }
    break;
  case 8:
    if (FUN_001155c0(DAT_003415ac)) {
      FUN_00295cdc(DAT_003415ac);
      FUN_0004784c();
    }
    break;
  }
  FUN_00295ccc(DAT_003415ac, 0.0f, (float)x->total);
  FUN_00295cc4(DAT_003415ac, (float)x->progress);
  FUN_000bb190(DAT_00338ac4);
  switch (x->state) {
  case 5:
  case 6:
  case 7:
  case 8:
    break;
  default:
    if (FUN_0029ba14() == 0) {
      x->failed = 1;
      err = FUN_0029ba08();
      switch (err) {
      case (int)0x80410b03:
      case (int)0x80410b0f:
        FUN_0029ef70(x, err);
        break;
      default:
        FUN_000149a8(x->message, Text(x, 22));
        break;
      }
      FUN_000c06f0(x->obj);
      FUN_0029f92c(x, 8);
    }
    break;
  }
  if (x->listener != 0) {
    x->listener->Notify();
  }
}
