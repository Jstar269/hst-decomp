/* HSTMATCH module=hstp_trans_main.prx start=0x002414c8 end=0x002415f8 symbol=FUN_002414c8 lang=c++ */
/* Clone of src/eboot/singleton_ctor_002313c8.cpp (hstclone.py tag c21sn4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idiom: the setter that notifies when the stored value is 0 is a single-case switch on the member it just stored; an if folds the constant or flips the layout); names and types await human review. */
struct Target {
  virtual void m0();
  virtual void m1();
};

struct Holder {
  Target *target;
  int pending;
  unsigned char flag;
  void SetPending(int v)
  {
    pending = v;
    switch (pending) {
    case 0:
      target->m1();
      break;
    }
  }
};

extern "C" {
extern char DAT_003b2aec[];
extern void *DAT_003f3990;
extern Holder *DAT_003f398c;
extern char DAT_003b7ebc[];
extern char DAT_0039bf14[];
void FUN_0001ec44(void *);
void FUN_0001c684(void *, int, char *);
void FUN_0001c73c(void *);
Target *FUN_0023ced0(void *, unsigned char);
}

extern "C" void *FUN_002414c8(void *self, unsigned char flag)
{
  FUN_0001ec44(self);
  *(void **)self = DAT_003b2aec;
  DAT_003f3990 = self;
  if (DAT_003f398c == 0) {
    Holder *h = new Holder;
    if (h != 0) {
      h->target = 0;
      DAT_003f398c = h;
      h->flag = flag;
      FUN_0001c684(DAT_003b7ebc, 1, DAT_0039bf14);
      void *m = ::operator new(0x418);
      Target *t = (Target *)m;
      if (m != 0)
        t = FUN_0023ced0(m, h->flag);
      h->target = t;
      FUN_0001c73c(DAT_003b7ebc);
      h->SetPending(1);
    }
  }
  Holder *h2 = DAT_003f398c;
  if (h2->pending == 1)
    h2->SetPending(0);
  return self;
}
