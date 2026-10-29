/* HSTMATCH module=EBOOT.BIN start=0x0014b998 end=0x0014ba1c symbol=FUN_0014b998 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: member at +8 is deleted through a virtual deleting destructor (`delete m;` on a class with `virtual ~VC_0()`), C++ rather than C; readability pass; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_00308444;
extern char DAT_00308460;
extern void FUN_00000a00(...);
}
/* The owned object: only its virtual deleting destructor is used. */
struct VC_0 { virtual ~VC_0(); };

struct Owner {
    const void *vtable; /* 0x00 */
    int unk04;          /* 0x04 */
    VC_0 *owned;        /* 0x08 deleted first */
};

/* Deleting destructor: delete the owned object, restore the base vtable, free when delete_flag > 0. */
extern "C" Owner *FUN_0014b998(Owner *self, short delete_flag)
{
  if (self != 0) {
    self->vtable = &DAT_00308444;
    VC_0 *m = self->owned;
    delete m;
    if (self != 0) {
      self->vtable = &DAT_00308460;
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
