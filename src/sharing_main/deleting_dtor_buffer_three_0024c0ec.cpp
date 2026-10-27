/* HSTMATCH module=hstp_trans_main.prx start=0x0024c0ec end=0x0024c1d8 symbol=FUN_0024c0ec lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern "C" {
extern char DAT_003b2b98;
extern char *DAT_003f39f0;
extern void FUN_00000a00(void *);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };

struct Obj {
  void *vptr;
  VC_0 *m4;
  char pad8[0x14c0 - 8];
  VC_2 *m14c0;
  char pad14c4[0x1748 - 0x14c4];
  VC_1 *m1748;
};

extern "C" Obj *FUN_0024c0ec(Obj *self, short flag)
{
  if (self != 0) {
    self->vptr = &DAT_003b2b98;
    if (DAT_003f39f0 != 0) {
      delete[] DAT_003f39f0;
      DAT_003f39f0 = 0;
    }
    if (self->m4 != 0) {
      delete self->m4;
      self->m4 = 0;
    }
    if (self->m1748 != 0) {
      delete self->m1748;
      self->m1748 = 0;
    }
    if (self->m14c0 != 0) {
      delete self->m14c0;
      self->m14c0 = 0;
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
