/* HSTMATCH module=EBOOT.BIN start=0x001f47a4 end=0x001f483c symbol=FUN_001f47a4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed the object (vptr, flag byte at +0x98, two 36-byte records plus index), found the dropped first and third arguments of FUN_0006107c and the single-case switch; readability pass; exact match verified; names and types await human review. */
/* Matching idiom: the `if (mode == 0)` test is a one-case switch (retail has beqzl + b with both delay slots copied). */
struct Record {
  float value;
  char pad[32];
};

struct Obj {
  virtual void s0();
  virtual void s1(int);
  char pad4[0x90];
  int mode;
  unsigned char active;
  char pad99[3];
  Record recs[2];
  int cur_rec;
};

struct Owner {
  char pad[0x584];
  Obj *obj;
};

extern int DAT_003313c4;
extern char DAT_002bc420[];
extern "C" void FUN_0006107c(Obj *, float, char *);
extern "C" void FUN_000609f8(Obj *);
extern "C" void FUN_001f483c(Owner *);

/* If the object is active, apply its current record and notify it; otherwise delegate to the other handler. */
extern "C" void FUN_001f47a4(Owner *owner)
{
  Obj *o = owner->obj;
  if (o->active != 0) {
    switch (o->mode) {
    case 0:
      FUN_0006107c(o, o->recs[o->cur_rec].value, DAT_002bc420);
      break;
    }
    FUN_000609f8(o);
    o->s1(DAT_003313c4);
  } else {
    FUN_001f483c(owner);
  }
}
