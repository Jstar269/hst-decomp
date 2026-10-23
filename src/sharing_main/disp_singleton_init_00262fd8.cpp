/* HSTMATCH module=hstp_trans_main.prx start=0x00262fd8 end=0x00263224 symbol=FUN_00262fd8 lang=c++ */
/* Clone of src/eboot/disp_singleton_init_00252c84.cpp (hstclone.py tag fm4c): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct DispVt {
  virtual void fn0();
  virtual void fn1();
};

struct Disp {
  int obj;
  int state;
  int f8;
  int fc;
};

extern char DAT_003b2bf8[];
extern Disp *DAT_003f3ac4;
extern void *DAT_003f3ac8;
extern char DAT_003b7ebc[];
extern char DAT_003a56ec[];
extern char DAT_003a5708[];
extern char DAT_003a5724[];
extern char DAT_003eaad8[];
extern void *DAT_003daec4;

extern "C" void *FUN_00000bcc(unsigned);
extern "C" void FUN_0001ec44(void *);
extern "C" void FUN_001a0bbc();
extern "C" void FUN_0001c684(void *, int, void *);
extern "C" void FUN_0001c73c(void *);
extern "C" void FUN_0001c5f4(void *, void *);
extern "C" void *FUN_0025ff04(void *);
extern "C" void FUN_002607c4(int);
extern "C" void FUN_001c1090(void *);
extern "C" void FUN_001c16b4(void *, int);
extern "C" void FUN_001c1f44(void *, int);
extern "C" void FUN_000648f4(int, int, float);

extern "C" Disp *FUN_00262fd8(Disp *self)
{
  FUN_0001ec44(self);
  self->obj = (int)DAT_003b2bf8;
  DAT_003f3ac8 = self;
  if (DAT_003f3ac4 == 0) {
    Disp *p = new Disp;
    if (p != 0) {
      p->obj = 0;
      DAT_003f3ac4 = p;
      p->f8 = 0;
      p->fc = -1;
      FUN_001a0bbc();
      FUN_0001c684(DAT_003b7ebc, 1, DAT_003a56ec);
      void *m = FUN_00000bcc(900);
      if (m != 0) {
        m = FUN_0025ff04(m);
      }
      p->obj = (int)m;
      FUN_0001c73c(DAT_003b7ebc);
      FUN_0001c5f4(DAT_003b7ebc, DAT_003a5708);
      FUN_002607c4(p->obj);
      FUN_0001c73c(DAT_003b7ebc);
      FUN_0001c5f4(DAT_003b7ebc, DAT_003a5724);
      FUN_001c1090(DAT_003eaad8);
      FUN_001c16b4(DAT_003eaad8, 2);
      FUN_0001c73c(DAT_003b7ebc);
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
        p->f8 = 9;
        break;
      case 3:
        break;
      }
    }
  }
  Disp *q = DAT_003f3ac4;
  FUN_001c1f44(DAT_003eaad8, 2);
  FUN_000648f4((int)DAT_003daec4, 0, 0.0f);
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
    q->f8 = 9;
    break;
  case 3:
    break;
  }
  return self;
}
