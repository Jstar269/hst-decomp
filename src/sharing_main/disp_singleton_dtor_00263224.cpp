/* HSTMATCH module=hstp_trans_main.prx start=0x00263224 end=0x00263310 symbol=FUN_00263224 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Deleting destructor of the class whose constructor is FUN_00262fd8 (disp_singleton_init_00262fd8.cpp): it
   releases the DAT_003f3ac4 singleton through `delete` (inline destructor, hence the second null test) before
   the base destructor FUN_0001ed28. */
struct Obj {
  virtual ~Obj();
};

struct Disp {
  Obj *obj;
  int state;
  int f8;
  int fc;
  ~Disp();
};

struct Self {
  void *vptr;
};

extern char DAT_003b2bf8[];
extern Disp *DAT_003f3ac4;
extern void *DAT_003f3ac8;
extern char DAT_003eaad8[];
extern "C" void FUN_00000a00(void *);
extern "C" void FUN_0001ed28(void *, int);
extern "C" void FUN_001c170c(void *, int);
extern "C" void FUN_001c10a8(void *);
extern "C" void FUN_001a0bc4();

inline Disp::~Disp()
{
  DAT_003f3ac4 = 0;
  if (obj) {
    delete obj;
    obj = 0;
  }
  FUN_001c170c(DAT_003eaad8, 2);
  FUN_001c10a8(DAT_003eaad8);
  FUN_001a0bc4();
}

extern "C" Self *FUN_00263224(Self *self, short flag)
{
  if (self) {
    self->vptr = DAT_003b2bf8;
    DAT_003f3ac8 = 0;
    if (DAT_003f3ac4) {
      delete DAT_003f3ac4;
      DAT_003f3ac4 = 0;
    }
    FUN_0001ed28(self, 0);
    if (flag > 0)
      FUN_00000a00(self);
  }
  return self;
}
