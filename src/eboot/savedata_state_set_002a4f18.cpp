/* HSTMATCH module=EBOOT.BIN start=0x002a4f18 end=0x002a51ec symbol=FUN_002a4f18 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified. State setter of a save/load style screen: state 1 resolves one message string and queues it, state 2 builds a 6-field parameter block (game id and directory name strings from the .data globals, three message handles) and passes it to FUN_0010aae4, falling through to state 3 on success. Matching idioms: switch with empty case 0/3 (tests emitted in reverse source order), two inline string pickers (PickA/PickB) whose limit compares and list bounds follow the retail slti/bgtz forms. Names and types await human review. */
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

extern const char *DAT_0030080c;
extern const char *DAT_00300810;
extern int DAT_00300814;
extern int DAT_00300818;
extern int DAT_0030081c;
extern unsigned char DAT_00300820;
extern char DAT_002c0e20[];
extern char DAT_002c0e1c[];
extern char DAT_002c0e18[];
extern void *DAT_0034176c;
extern void *DAT_003415ac;

struct Dev {
  virtual void v0();
  virtual void m1(int);
};
extern Dev *DAT_003386c0;

extern "C" {
void FUN_0001b880(void);
Info *FUN_0018c9f4(int);
int FUN_00198278(void *, const char *, int, void *);
void FUN_00115088(void *, int, int, int, int);
int FUN_0010aae4(void *, Loc *);
void FUN_002a4f18(Self *, int);
}

static inline const char *PickA(Info *o, int idx)
{
  if (o->f4 == 0) return DAT_002c0e20;
  if (o->f8->f8 < 0x15) return DAT_002c0e1c;
  if (o->fc->cf4 <= idx) return DAT_002c0e18;
  return o->fc->af0[idx];
}

static inline const char *PickB(Info *o, int idx)
{
  if (o->f4 == 0) return DAT_002c0e20;
  if (o->f8->f8 < 13) return DAT_002c0e1c;
  if (o->fc->c94 <= idx) return DAT_002c0e18;
  return o->fc->a90[idx];
}

extern "C" void FUN_002a4f18(Self *self, int state)
{
  self->state = state;
  switch (state) {
  case 0:
    break;
  case 1: {
    const char *p = PickA(FUN_0018c9f4(17), 6);
    int h = FUN_00198278(DAT_0034176c, p, 0x180, self->buf4);
    FUN_00115088(DAT_003415ac, 1, h, 0, 0);
    break;
  }
  case 2: {
    FUN_0001b880();
    if (DAT_003386c0 != 0) DAT_003386c0->m1(0);
    Loc loc;
    loc.a = DAT_0030080c;
    loc.b = DAT_00300810;
    loc.c = DAT_00300814;
    loc.d = DAT_00300818;
    loc.e = DAT_0030081c;
    loc.f = DAT_00300820;
    loc.c = FUN_00198278(DAT_0034176c, PickB(FUN_0018c9f4(17), 32), 0x180, self->buf0);
    loc.d = FUN_00198278(DAT_0034176c, PickA(FUN_0018c9f4(17), 1), 0x180, self->buf1);
    loc.e = FUN_00198278(DAT_0034176c, PickA(FUN_0018c9f4(17), 0), 0x180, self->buf2);
    if (FUN_0010aae4(self->sub, &loc) == 0) {
      self->f5d4 = 0;
    } else {
      FUN_002a4f18(self, 3);
    }
    break;
  }
  case 3:
    break;
  }
}
