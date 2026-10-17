/* HSTMATCH module=hstp_trans_main.prx start=0x00202d34 end=0x00202dcc symbol=FUN_00202d34 lang=c++ */
/* Clone of src/eboot/state_dispatch_001f47a4.cpp (hstclone.py tag c17b07b): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed the object (vptr, flag byte at +0x98, two 36-byte records plus index), found the dropped first and third arguments of FUN_00061f00 and the single-case switch; exact match verified; names and types await human review. */
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

extern int DAT_003da704;
extern char DAT_002cc270[];
extern "C" void FUN_00061f00(Obj *, float, char *);
extern "C" void FUN_0006187c(Obj *);
extern "C" void FUN_00202dcc(Param *);

extern "C" void FUN_00202d34(Param *p)
{
  Obj *o = p->f584;
  if (o->f98 != 0) {
    switch (o->f94) {
    case 0:
      FUN_00061f00(o, o->ents[o->cur].f0, DAT_002cc270);
      break;
    }
    FUN_0006187c(o);
    o->s1(DAT_003da704);
  } else {
    FUN_00202dcc(p);
  }
}
