/* HSTMATCH module=EBOOT.BIN start=0x0026330c end=0x0026348c symbol=FUN_0026330c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Virtual slot 8 gates the update: advance the 32-entry ring index at +0x1864 (signed % 32), store base + index into the record at +0x1860, and when FUN_00262c14 returns 0 run the follow-up calls, show the string chosen from table entry 18 and bump the counter at +0x1858. */
struct Ring {
  char pad[0x24];
  int f24;
  int f28;
};
struct Obj {
  virtual void s0();
  virtual void s1();
  virtual void s2();
  virtual void s3();
  virtual void s4();
  virtual void s5();
  virtual void s6();
  virtual void s7();
  virtual int s8();
  char pad0[0x1858 - 4];
  int f1858;
  char pad1[4];
  Ring *f1860;
  int f1864;
};
struct Flags {
  char pad[0x178];
  unsigned char f178;
};
struct Inner8 {
  char pad[8];
  int f8;
};
struct InnerC {
  char pad[0x228];
  const char **f228;
  int f22c;
};
struct Ent {
  int f0;
  int f4;
  Inner8 *f8;
  InnerC *fc;
};
struct Sink {
  virtual void s0();
  virtual void s1();
  virtual void s2();
};

extern char DAT_002c0e18[];
extern char DAT_002c0e1c[];
extern char DAT_002c0e20[];
extern int DAT_003386c8;
extern Flags *DAT_00338ac4;
extern "C" {
Sink *FUN_0008d994(int);
void FUN_00103128(Obj *);
void FUN_00103628(Sink *, int);
void FUN_00110a78(Sink *, const char *, int);
Ent *FUN_0018c9f4(int);
void FUN_00258630(Obj *, int);
void FUN_00258a68(Obj *);
void FUN_0025967c(Obj *);
int FUN_00262c14(Obj *);
}

extern "C" void FUN_0026330c(Obj *o)
{
  if (!o->s8())
    return;
  FUN_00103128(o);
  int idx = (o->f1864 + 1) % 32;
  o->f1864 = idx;
  o->f1860->f24 = o->f1860->f28 + idx;
  if (FUN_00262c14(o) == 0) {
    FUN_00258630(o, 0);
    FUN_00258a68(o);
    int ok = 1;
    if (DAT_00338ac4 != 0 && DAT_00338ac4->f178 == 0)
      ok = 0;
    if (ok == 0)
      FUN_0025967c(o);
    Ent *e = FUN_0018c9f4(18);
    const char *s;
    if (e->f4 == 0)
      s = DAT_002c0e20;
    else if (e->f8->f8 < 47)
      s = DAT_002c0e1c;
    else if (e->fc->f22c < 1)
      s = DAT_002c0e18;
    else
      s = *e->fc->f228;
    FUN_00110a78(FUN_0008d994(DAT_003386c8), s, 0);
    FUN_00103628(FUN_0008d994(DAT_003386c8), 0);
    FUN_0008d994(DAT_003386c8)->s2();
    o->f1858++;
  }
}
