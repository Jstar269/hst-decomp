/* HSTMATCH module=EBOOT.BIN start=0x002313c8 end=0x002314f8 symbol=FUN_002313c8 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (matching idiom: the setter that notifies when the stored value is 0 is a single-case switch on the member it just stored; an if folds the constant or flips the layout); names and types await human review. */

#define TARGET_SIZE 0x418 /* size of the object the holder creates */
#define LOCK_MODE 1

/* Object the holder creates; slot 1 is the notification. */
struct Target {
  virtual void m0();
  virtual void m1();
};

struct Holder {
  Target *target;
  int pending;
  unsigned char flag;
  /* Store the pending state; clearing it notifies the target. */
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
extern Holder *DAT_0034a65c;  /* the singleton holder */
extern char DAT_0030ebf4[];
extern char DAT_002f3650[];
void FUN_0001f06c(void *);
void FUN_0001cad0(void *, int, char *);
void FUN_0001cb88(void *);
Target *FUN_0022cdd0(void *, unsigned char);
}

/* Constructor of the owner of the singleton: create the holder and its target on first use, then clear a pending state. */
extern "C" void *FUN_002313c8(void *self, unsigned char flag)
{
  FUN_0001f06c(self);
  *(void **)self = DAT_00309820;
  DAT_0034a660 = self;
  if (DAT_0034a65c == 0) {
    Holder *holder = new Holder;
    if (holder != 0) {
      holder->target = 0;
      DAT_0034a65c = holder;
      holder->flag = flag;
      FUN_0001cad0(DAT_0030ebf4, LOCK_MODE, DAT_002f3650);
      void *mem = ::operator new(TARGET_SIZE);
      Target *target = (Target *)mem;
      if (mem != 0)
        target = FUN_0022cdd0(mem, holder->flag);
      holder->target = target;
      FUN_0001cb88(DAT_0030ebf4);
      holder->SetPending(1);
    }
  }
  Holder *current = DAT_0034a65c;
  if (current->pending == 1)
    current->SetPending(0);
  return self;
}
