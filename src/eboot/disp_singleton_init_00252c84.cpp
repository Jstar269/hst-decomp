/* HSTMATCH module=EBOOT.BIN start=0x00252c84 end=0x00252ed0 symbol=FUN_00252c84 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/disp_ctx.h"
#include "hst/vtable_obj.h"

struct DispVt {
  virtual void fn0();
  virtual void fn1();
};

extern char DAT_0030992c[];
extern DispCtx *DAT_0034a794;
extern void *DAT_0034a798;
extern char DAT_0030ebf4[];
extern char DAT_002fcbf8[];
extern char DAT_002fcc14[];
extern char DAT_002fcc30[];
extern char DAT_0034179c[];
extern void *DAT_00331b84;

extern "C" void *FUN_00000bcc(unsigned);
extern "C" void FUN_0001f06c(void *);
extern "C" void FUN_001943ac();
extern "C" void FUN_0001cad0(void *, int, void *);
extern "C" void FUN_0001cb88(void *);
extern "C" void FUN_0001ca58(void *, void *);
extern "C" void *FUN_0024fbb0(void *);
extern "C" void FUN_00250470(void *);
extern "C" void FUN_001b2f60(void *);
extern "C" void FUN_001b3378(void *, int);
extern "C" void FUN_001b3ce8(void *, int);
extern "C" void FUN_00063a30(void *, int, float);

/* Constructor: sets the vtable, registers itself in a global and creates the display singleton once. */
extern "C" VtableObj *FUN_00252c84(VtableObj *self)
{
  FUN_0001f06c(self);
  self->vtable = DAT_0030992c;
  DAT_0034a798 = self;
  if (DAT_0034a794 == 0) {
    DispCtx *p = new DispCtx;
    if (p != 0) {
      p->obj = 0;
      DAT_0034a794 = p;
      p->unk8 = 0;
      p->unkc = -1;
      FUN_001943ac();
      FUN_0001cad0(DAT_0030ebf4, 1, DAT_002fcbf8);
      void *m = FUN_00000bcc(900);
      if (m != 0) {
        m = FUN_0024fbb0(m);
      }
      p->obj = m;
      FUN_0001cb88(DAT_0030ebf4);
      FUN_0001ca58(DAT_0030ebf4, DAT_002fcc14);
      FUN_00250470(p->obj);
      FUN_0001cb88(DAT_0030ebf4);
      FUN_0001ca58(DAT_0030ebf4, DAT_002fcc30);
      FUN_001b2f60(DAT_0034179c);
      FUN_001b3378(DAT_0034179c, 2);
      FUN_0001cb88(DAT_0030ebf4);
      p->state = 5;
      switch (p->state) {
      case 0:
        ((DispVt *)p->obj)->fn1();
        break;
      case 1:
        ((DispVt *)p->obj)->fn1();
        break;
      case 2:
      case 4:
        p->unk8 = 9;
        break;
      case 3:
        break;
      }
    }
  }
  DispCtx *q = DAT_0034a794;
  FUN_001b3ce8(DAT_0034179c, 2);
  FUN_00063a30(DAT_00331b84, 0, 0.0f);
  q->state = 0;
  switch (q->state) {
  case 0:
    ((DispVt *)q->obj)->fn1();
    break;
  case 1:
    ((DispVt *)q->obj)->fn1();
    break;
  case 2:
  case 4:
    q->unk8 = 9;
    break;
  case 3:
    break;
  }
  return self;
}
