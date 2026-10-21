/* HSTMATCH module=hstp_trans_main.prx start=0x001bfb44 end=0x001bfbd8 symbol=FUN_001bfb44 lang=c++ */
/* Clone of src/eboot/holder_dtor_001b1b4c.cpp (hstclone.py tag c21sn4s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified (the member is released with a real delete of a class with an inline destructor, so MWCC keeps both null tests); names and types await human review. */
extern "C" {
extern void FUN_00000a00(void *);
extern void FUN_00063304(void *, int);
extern void FUN_001bd2a8(void *);
}

struct Res {
  char pad[0x160];
  void *p160;
  ~Res();
};

inline Res::~Res()
{
  FUN_001bd2a8(this);
  if (p160 != 0) {
    FUN_00063304(p160, 1);
    p160 = 0;
  }
}

struct Holder {
  Res *res;
};

extern "C" Holder *FUN_001bfb44(Holder *self, short flag)
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
