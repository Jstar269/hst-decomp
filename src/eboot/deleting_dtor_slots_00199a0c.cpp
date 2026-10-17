/* HSTMATCH module=EBOOT.BIN start=0x00199a0c end=0x00199afc symbol=FUN_00199a0c lang=c++ */
/* Clone of src/sharing_main/deleting_dtor_slots_001a6500.cpp (hstclone.py tag c025720): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: restructured as a C++ deleting destructor; the member at +0x3c is a Slots object whose inline dtor makes the two calls and deletes six virtual-dtor pointers, so `delete self->slots` reproduces the doubled null test; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_003091b0;
extern char DAT_0034179c;
extern void FUN_00000a00(...);
extern int *FUN_0001f0f0(...);
extern void FUN_001b2be0(...);
extern void FUN_001b3e2c(...);
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
    FUN_001b3e2c(&DAT_0034179c);
    FUN_001b2be0(&DAT_0034179c);
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

extern "C" Obj *FUN_00199a0c(Obj *self, short flag)
{
  if (self != 0) {
    self->vptr = &DAT_003091b0;
    if (self->slots != 0) {
      delete self->slots;
      self->slots = 0;
    }
    FUN_0001f0f0(self, 0);
    if (flag > 0) {
      FUN_00000a00(self);
    }
  }
  return self;
}
