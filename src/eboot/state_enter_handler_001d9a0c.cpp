/* HSTMATCH module=EBOOT.BIN start=0x001d9a0c end=0x001d9b98 symbol=FUN_001d9a0c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idiom: the three-way flag is a materialised bool chain 'flag = a; if (!flag) flag = b; if (!flag) flag = c;', and the repeated state==3 test is left unthreaded); names and types await human review. */
#include "hst/handler_obj.h"

/* Virtual interface of the embedded helper at unk1110. */
struct SubA {
  virtual void m0();
  virtual void m1();
  virtual void m2();
  virtual void m3();
};
/* Virtual interface of the object at unk119c. */
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
/* Virtual interface of the object returned by FUN_0008d994. */
struct SubC {
  virtual void m0();
  virtual void m1();
  virtual void m2();
  virtual void m3();
};
/* Pair of words: a target and a pending value. */
struct Holder {
  int target;
  int pending;
};

extern "C" {
extern int DAT_0034b328;
extern int DAT_0034a818;
extern Holder *DAT_0034a65c;
extern int DAT_003386c8;
int FUN_0029e0f0(int);
int FUN_002911c0(int);
void FUN_00231390(Holder *);
void FUN_0026cbac(void *);
void FUN_000ffb3c(int, int);
void FUN_001031e8(HandlerObj *);
void FUN_001033e8(HandlerObj *, float, int);
void FUN_00103474(HandlerObj *);
void FUN_002a43d4(void *);
SubC *FUN_0008d994(int);
}

/* Returns early when the checks on the two globals (FUN_0029e0f0, FUN_002911c0) report nonzero; otherwise refreshes the widgets and calls the helper objects in order. */
extern "C" void FUN_001d9a0c(HandlerObj *self)
{
  if (DAT_0034b328 != 0 && FUN_0029e0f0(DAT_0034b328) != 0)
    return;
  if (DAT_0034a818 != 0 && FUN_002911c0(DAT_0034a818) != 0) {
    if (self->state == 3)
      FUN_00231390(DAT_0034a65c);
    return;
  }
  FUN_0026cbac(self->unk530);
  ((SubA *)self->unk1110)->m3();
  if (self->state == 3)
    FUN_00231390(DAT_0034a65c);
  int flag = DAT_0034a65c->pending != 1;
  if (!flag)
    flag = self->state == 1;
  if (!flag)
    flag = self->state == 2;
  FUN_000ffb3c(self->unk514, flag);
  ((SubB *)self->unk119c)->m2(1);
  FUN_001031e8(self);
  ((SubB *)self->unk119c)->m2(0);
  FUN_001033e8(self, 1002.0f, 1);
  ((SubB *)self->unk119c)->m12(1);
  FUN_00103474(self);
  FUN_002a43d4(self->unk290);
  FUN_0008d994(DAT_003386c8)->m3();
}
