/* HSTMATCH module=EBOOT.BIN start=0x002ab3fc end=0x002ab4ec symbol=FUN_002ab3fc lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Target_002ab3fc {
  virtual void s0();
  virtual void s1(int);
  char pad[0xe0 - 4];
  float fe0;
};
struct Ent_002ab3fc { int a, b, c; };
struct Obj_002ab3fc {
  char pad0[0x1034];
  int f1034;
  Target_002ab3fc *f1038;
  char pad1[0x30c4 - 0x103c];
  unsigned char f30c4;
  unsigned char f30c5;
  char pad2[2];
  int f30c8;
  int f30cc;
  char pad3[0x30f0 - 0x30d0];
  Ent_002ab3fc tab[2];
};

extern "C" {
extern char DAT_0034179c;
void FUN_002a8fbc(Obj_002ab3fc *);
void FUN_001b1c44(char *, int);
void FUN_0010b8cc(int, int, int);
void FUN_002ab180(Obj_002ab3fc *);
void FUN_00103128(Obj_002ab3fc *);
}

extern "C" void FUN_002ab3fc(Obj_002ab3fc *o)
{
  int a = o->f30cc;
  int b = o->f30c8;
  FUN_002a8fbc(o);
  if (a != o->f30cc || b != o->f30c8) {
    FUN_001b1c44(&DAT_0034179c, 1);
    if (b != o->f30c8) FUN_0010b8cc(o->f1034, o->f30c8, 0);
  }
  o->f1038->fe0 = (float)o->f30cc;
  unsigned char idx = (o->f30c4 != 0) ^ 1;
  int on = 1;
  if (o->tab[idx].a > 5) {
    if (o->f30c5 == 0) on = 0;
  }
  o->f1038->s1(on);
  FUN_002ab180(o);
  FUN_00103128(o);
}
