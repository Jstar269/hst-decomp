/* HSTMATCH module=EBOOT.BIN start=0x002a0e88 end=0x002a1000 symbol=FUN_002a0e88 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Deleting destructor: member pointers released in reverse order (inline user dtors give the doubled null checks), base dtor FUN_00056cb0(this, 0), then operator delete(this) when delete_flag > 0. Names provisional. */
extern "C" {
extern char DAT_00309e9c[];
extern void *DAT_00331b84;
extern void FUN_00000a00(void *);
extern void FUN_00063478(float, void *);
extern void *FUN_00056cb0(void *, int);
}

struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };

struct Pair {
  VC_1 *a;
  VC_0 *b;
  ~Pair() {
    if (b) {
      delete b;
      b = 0;
    }
    if (a) {
      delete a;
      a = 0;
    }
  }
};
struct Timer {
  int pad;
  ~Timer() { FUN_00063478(203000.0f, DAT_00331b84); }
};
struct Buf {
  int pad;
  char *data;
  ~Buf() {
    if (data) {
      delete[] data;
      data = 0;
    }
  }
};

struct Obj {
  void *vptr;
  char pad[0x1c4];
  VC_2 *f1c8;
  Buf *f1cc;
  Timer *f1d0;
  Pair *f1d4;
};

extern "C" Obj *FUN_002a0e88(Obj *self, short delete_flag)
{
  if (self != 0) {
    self->vptr = DAT_00309e9c;
    if (self->f1d4 != 0) {
      delete self->f1d4;
      self->f1d4 = 0;
    }
    if (self->f1d0 != 0) {
      delete self->f1d0;
      self->f1d0 = 0;
    }
    if (self->f1cc != 0) {
      delete self->f1cc;
      self->f1cc = 0;
    }
    if (self->f1c8 != 0) {
      delete self->f1c8;
      self->f1c8 = 0;
    }
    FUN_00056cb0(self, 0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
