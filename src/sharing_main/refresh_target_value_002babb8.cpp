/* HSTMATCH module=hstp_trans_main.prx start=0x002babb8 end=0x002baca8 symbol=FUN_002babb8 lang=c++ */
/* Clone of src/eboot/refresh_target_value_002ab3fc.cpp (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Target_002babb8 {
  virtual void s0();
  virtual void s1(int);
  char pad[0xe0 - 4];
  float fe0;
};
struct Ent_002babb8 { int a, b, c; };
struct Obj_002babb8 {
  char pad0[0x1034];
  int f1034;
  Target_002babb8 *f1038;
  char pad1[0x30c4 - 0x103c];
  unsigned char f30c4;
  unsigned char f30c5;
  char pad2[2];
  int f30c8;
  int f30cc;
  char pad3[0x30f0 - 0x30d0];
  Ent_002babb8 tab[2];
};

extern "C" {
extern char DAT_003eaad8;
void FUN_002b8778(Obj_002babb8 *);
void FUN_001bfc3c(char *, int);
void FUN_00111aa4(int, int, int);
void FUN_002ba93c(Obj_002babb8 *);
void FUN_00108a2c(Obj_002babb8 *);
}

extern "C" void FUN_002babb8(Obj_002babb8 *o)
{
  int a = o->f30cc;
  int b = o->f30c8;
  FUN_002b8778(o);
  if (a != o->f30cc || b != o->f30c8) {
    FUN_001bfc3c(&DAT_003eaad8, 1);
    if (b != o->f30c8) FUN_00111aa4(o->f1034, o->f30c8, 0);
  }
  o->f1038->fe0 = (float)o->f30cc;
  unsigned char idx = (o->f30c4 != 0) ^ 1;
  int on = 1;
  if (o->tab[idx].a > 5) {
    if (o->f30c5 == 0) on = 0;
  }
  o->f1038->s1(on);
  FUN_002ba93c(o);
  FUN_00108a2c(o);
}
