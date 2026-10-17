/* HSTMATCH module=hstp_trans_main.prx start=0x00274188 end=0x00274308 symbol=FUN_00274188 lang=c++ */
/* Clone of src/eboot/update_ring_index_0026330c.cpp (hstclone.py tag s10170158a1r4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Virtual slot 8 gates the update: advance the 32-entry ring index at +0x1864 (signed % 32), store base + index into the record at +0x1860, and when FUN_00273a5c returns 0 run the follow-up calls, show the string chosen from table entry 18 and bump the counter at +0x1858. */
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

extern char DAT_002d10cc[];
extern char DAT_002d10d0[];
extern char DAT_002d10d4[];
extern int DAT_003e1a08;
extern Flags *DAT_003e1e04;
extern "C" {
Sink *FUN_0008f170(int);
void FUN_00108a2c(Obj *);
void FUN_00108f54(Sink *, int);
void FUN_0011988c(Sink *, const char *, int);
Ent *FUN_001991d4(int);
void FUN_00268ae0(Obj *, int);
void FUN_00268f18(Obj *);
void FUN_00269b2c(Obj *);
int FUN_00273a5c(Obj *);
}

extern "C" void FUN_00274188(Obj *o)
{
  if (!o->s8())
    return;
  FUN_00108a2c(o);
  int idx = (o->f1864 + 1) % 32;
  o->f1864 = idx;
  o->f1860->f24 = o->f1860->f28 + idx;
  if (FUN_00273a5c(o) == 0) {
    FUN_00268ae0(o, 0);
    FUN_00268f18(o);
    int ok = 1;
    if (DAT_003e1e04 != 0 && DAT_003e1e04->f178 == 0)
      ok = 0;
    if (ok == 0)
      FUN_00269b2c(o);
    Ent *e = FUN_001991d4(18);
    const char *s;
    if (e->f4 == 0)
      s = DAT_002d10d4;
    else if (e->f8->f8 < 47)
      s = DAT_002d10d0;
    else if (e->fc->f22c < 1)
      s = DAT_002d10cc;
    else
      s = *e->fc->f228;
    FUN_0011988c(FUN_0008f170(DAT_003e1a08), s, 0);
    FUN_00108f54(FUN_0008f170(DAT_003e1a08), 0);
    FUN_0008f170(DAT_003e1a08)->s2();
    o->f1858++;
  }
}
