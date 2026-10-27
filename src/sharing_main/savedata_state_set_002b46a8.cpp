/* HSTMATCH module=hstp_trans_main.prx start=0x002b46a8 end=0x002b497c symbol=FUN_002b46a8 lang=c++ */
/* Hand-written reconstruction (port of src/eboot/savedata_state_set_002a4f18.cpp, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
struct Sub8 {
  int pad0[2];
  int f8;
};

struct Lists {
  char pad0[0x90];
  const char **a90;
  int c94;
  char pad1[0xf0 - 0x98];
  const char **af0;
  int cf4;
};

struct Info {
  int pad0;
  int f4;
  Sub8 *f8;
  Lists *fc;
};

struct Loc {
  const char *a;
  const char *b;
  int c;
  int d;
  int e;
  unsigned char f;
};

struct Self {
  char pad0[0x40];
  char sub[0x5d0 - 0x40];
  int state;
  int f5d4;
  char buf0[0x180];
  char buf1[0x180];
  char buf2[0x180];
  char buf3[0x180];
  char buf4[0x180];
  char buf5[0x180];
};

extern const char *DAT_003a98a8;
extern const char *DAT_003a98ac;
extern int DAT_003a98b0;
extern int DAT_003a98b4;
extern int DAT_003a98b8;
extern unsigned char DAT_003a98bc;
extern char DAT_002d10d4[];
extern char DAT_002d10d0[];
extern char DAT_002d10cc[];
extern void *DAT_003eaaac;
extern void *DAT_003ea8ec;

struct Dev {
  virtual void v0();
  virtual void m1(int);
};
extern Dev *DAT_003e1a00;

extern "C" {
void FUN_0001b584(void);
Info *FUN_001991d4(int);
int FUN_001a4bcc(void *, const char *, int, void *);
void FUN_0011fe78(void *, int, int, int, int);
int FUN_001108a4(void *, Loc *);
void FUN_002b46a8(Self *, int);
}

static inline const char *PickA(Info *o, int idx)
{
  if (o->f4 == 0) return DAT_002d10d4;
  if (o->f8->f8 < 0x15) return DAT_002d10d0;
  if (o->fc->cf4 <= idx) return DAT_002d10cc;
  return o->fc->af0[idx];
}

static inline const char *PickB(Info *o, int idx)
{
  if (o->f4 == 0) return DAT_002d10d4;
  if (o->f8->f8 < 13) return DAT_002d10d0;
  if (o->fc->c94 <= idx) return DAT_002d10cc;
  return o->fc->a90[idx];
}

extern "C" void FUN_002b46a8(Self *self, int state)
{
  self->state = state;
  switch (state) {
  case 0:
    break;
  case 1: {
    const char *p = PickA(FUN_001991d4(17), 6);
    int h = FUN_001a4bcc(DAT_003eaaac, p, 0x180, self->buf4);
    FUN_0011fe78(DAT_003ea8ec, 1, h, 0, 0);
    break;
  }
  case 2: {
    FUN_0001b584();
    if (DAT_003e1a00 != 0) DAT_003e1a00->m1(0);
    Loc loc;
    loc.a = DAT_003a98a8;
    loc.b = DAT_003a98ac;
    loc.c = DAT_003a98b0;
    loc.d = DAT_003a98b4;
    loc.e = DAT_003a98b8;
    loc.f = DAT_003a98bc;
    loc.c = FUN_001a4bcc(DAT_003eaaac, PickB(FUN_001991d4(17), 32), 0x180, self->buf0);
    loc.d = FUN_001a4bcc(DAT_003eaaac, PickA(FUN_001991d4(17), 1), 0x180, self->buf1);
    loc.e = FUN_001a4bcc(DAT_003eaaac, PickA(FUN_001991d4(17), 0), 0x180, self->buf2);
    if (FUN_001108a4(self->sub, &loc) == 0) {
      self->f5d4 = 0;
    } else {
      FUN_002b46a8(self, 3);
    }
    break;
  }
  case 3:
    break;
  }
}
