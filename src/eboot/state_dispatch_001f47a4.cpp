/* HSTMATCH module=EBOOT.BIN start=0x001f47a4 end=0x001f483c symbol=FUN_001f47a4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed the object (vptr, flag byte at +0x98, two 36-byte records plus index), found the dropped first and third arguments of FUN_0006107c and the single-case switch; exact match verified; names and types await human review. */
/* Matching idiom: the `if (f94 == 0)` test is a one-case switch (retail has beqzl + b with both delay slots copied). */
struct Ent {
  float f0;
  char pad[32];
};

struct Obj {
  virtual void s0();
  virtual void s1(int);
  char pad4[0x90];
  int f94;
  unsigned char f98;
  char pad99[3];
  Ent ents[2];
  int cur;
};

struct Param {
  char pad[0x584];
  Obj *f584;
};

extern int DAT_003313c4;
extern char DAT_002bc420[];
extern "C" void FUN_0006107c(Obj *, float, char *);
extern "C" void FUN_000609f8(Obj *);
extern "C" void FUN_001f483c(Param *);

extern "C" void FUN_001f47a4(Param *p)
{
  Obj *o = p->f584;
  if (o->f98 != 0) {
    switch (o->f94) {
    case 0:
      FUN_0006107c(o, o->ents[o->cur].f0, DAT_002bc420);
      break;
    }
    FUN_000609f8(o);
    o->s1(DAT_003313c4);
  } else {
    FUN_001f483c(p);
  }
}
