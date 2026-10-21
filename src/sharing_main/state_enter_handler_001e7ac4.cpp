/* HSTMATCH module=hstp_trans_main.prx start=0x001e7ac4 end=0x001e7c50 symbol=FUN_001e7ac4 lang=c++ */
/* Clone of src/eboot/state_enter_handler_001d9a0c.cpp (hstclone.py tag c21sn4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idiom: the three-way flag is a materialised bool chain 'flag = a; if (!flag) flag = b; if (!flag) flag = c;', and the repeated state==3 test is left unthreaded); names and types await human review. */
struct SubA {
  virtual void m0();
  virtual void m1();
  virtual void m2();
  virtual void m3();
};
struct SubB {
  virtual void m0();
  virtual void m1();
  virtual void m2(int v);
  virtual void m3();
  virtual void m4();
  virtual void m5();
  virtual void m6();
  virtual void m7();
  virtual void m8();
  virtual void m9();
  virtual void m10();
  virtual void m11();
  virtual void m12(int v);
};
struct SubC {
  virtual void m0();
  virtual void m1();
  virtual void m2();
  virtual void m3();
};
struct Holder {
  int target;
  int pending;
};
struct Obj {
  char pad0[0x290];
  char m290[0x10];
  char pad1[0x514 - 0x290 - 0x10];
  int f514;
  char pad2[0x520 - 0x518];
  int state;
  char pad3[0x530 - 0x524];
  char m530[0x10];
  char pad4[0x1110 - 0x530 - 0x10];
  SubA sub;
  char pad5[0x119c - 0x1110 - sizeof(SubA)];
  SubB *f119c;
};

extern "C" {
extern int DAT_003f4668;
extern int DAT_003f3b48;
extern Holder *DAT_003f398c;
extern int DAT_003e1a08;
int FUN_002ad26c(int);
int FUN_002a28c8(int);
void FUN_00241490(Holder *);
void FUN_0027dbec(void *);
void FUN_00105470(int, int);
void FUN_00108aec(Obj *);
void FUN_00108cec(Obj *, float, int);
void FUN_00108da0(Obj *);
void FUN_002b3aec(void *);
SubC *FUN_0008f170(int);
}

extern "C" void FUN_001e7ac4(Obj *self)
{
  if (DAT_003f4668 != 0 && FUN_002ad26c(DAT_003f4668) != 0)
    return;
  if (DAT_003f3b48 != 0 && FUN_002a28c8(DAT_003f3b48) != 0) {
    if (self->state == 3)
      FUN_00241490(DAT_003f398c);
    return;
  }
  FUN_0027dbec(self->m530);
  self->sub.m3();
  if (self->state == 3)
    FUN_00241490(DAT_003f398c);
  int flag = DAT_003f398c->pending != 1;
  if (!flag)
    flag = self->state == 1;
  if (!flag)
    flag = self->state == 2;
  FUN_00105470(self->f514, flag);
  self->f119c->m2(1);
  FUN_00108aec(self);
  self->f119c->m2(0);
  FUN_00108cec(self, 1002.0f, 1);
  self->f119c->m12(1);
  FUN_00108da0(self);
  FUN_002b3aec(self->m290);
  FUN_0008f170(DAT_003e1a08)->m3();
}
