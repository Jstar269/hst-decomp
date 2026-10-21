/* HSTMATCH module=EBOOT.BIN start=0x002313c8 end=0x002314f8 symbol=FUN_002313c8 lang=c++ */
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
extern char DAT_00309820[];
extern void *DAT_0034a660;
extern Holder *DAT_0034a65c;
extern char DAT_0030ebf4[];
extern char DAT_002f3650[];
void FUN_0001f06c(void *);
void FUN_0001cad0(void *, int, char *);
void FUN_0001cb88(void *);
Target *FUN_0022cdd0(void *, unsigned char);
}

extern "C" void *FUN_002313c8(void *self, unsigned char flag)
{
  FUN_0001f06c(self);
  *(void **)self = DAT_00309820;
  DAT_0034a660 = self;
  if (DAT_0034a65c == 0) {
    Holder *h = new Holder;
    if (h != 0) {
      h->target = 0;
      DAT_0034a65c = h;
      h->flag = flag;
      FUN_0001cad0(DAT_0030ebf4, 1, DAT_002f3650);
      void *m = ::operator new(0x418);
      Target *t = (Target *)m;
      if (m != 0)
        t = FUN_0022cdd0(m, h->flag);
      h->target = t;
      FUN_0001cb88(DAT_0030ebf4);
      h->SetPending(1);
    }
  }
  Holder *h2 = DAT_0034a65c;
  if (h2->pending == 1)
    h2->SetPending(0);
  return self;
}
