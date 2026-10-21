/* HSTMATCH module=EBOOT.BIN start=0x001b1b4c end=0x001b1be0 symbol=FUN_001b1b4c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified (the member is released with a real delete of a class with an inline destructor, so MWCC keeps both null tests); names and types await human review. */
extern "C" {
extern void FUN_00000a00(void *);
extern void FUN_00062418(void *, int);
extern void FUN_001afbd0(void *);
}

struct Res {
  char pad[0x160];
  void *p160;
  ~Res();
};

inline Res::~Res()
{
  FUN_001afbd0(this);
  if (p160 != 0) {
    FUN_00062418(p160, 1);
    p160 = 0;
  }
}

struct Holder {
  Res *res;
};

extern "C" Holder *FUN_001b1b4c(Holder *self, short flag)
{
  if (self != 0) {
    if (self->res != 0) {
      delete self->res;
      self->res = 0;
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
