/* HSTMATCH module=hstp_trans_main.prx start=0x001a6500 end=0x001a65f0 symbol=FUN_001a6500 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: restructured as a C++ deleting destructor; the member at +0x3c is a Slots object whose inline dtor makes the two calls and deletes six virtual-dtor pointers, so `delete self->slots` reproduces the doubled null test; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_003b247c;
extern char DAT_003eaad8;
extern void FUN_00000a00(...);
extern int *FUN_0001ed28(...);
extern void FUN_001c0d10(...);
extern void FUN_001c20b8(...);
}

struct VC {
  virtual ~VC();
};

struct Slots {
  VC *m[6];
  ~Slots()
  {
    unsigned i;
    VC **q;
    FUN_001c20b8(&DAT_003eaad8);
    FUN_001c0d10(&DAT_003eaad8);
    i = 0;
    q = m;
    do {
      if (*q != 0) {
        delete *q;
        *q = 0;
      }
      i++;
      q++;
    } while (i < 6);
  }
};

struct Obj {
  void *vptr;
  char pad[0x38];
  Slots *slots;
};

extern "C" Obj *FUN_001a6500(Obj *self, short flag)
{
  if (self != 0) {
    self->vptr = &DAT_003b247c;
    if (self->slots != 0) {
      delete self->slots;
      self->slots = 0;
    }
    FUN_0001ed28(self, 0);
    if (flag > 0) {
      FUN_00000a00(self);
    }
  }
  return self;
}
