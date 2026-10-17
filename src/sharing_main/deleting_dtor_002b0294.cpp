/* HSTMATCH module=hstp_trans_main.prx start=0x002b0294 end=0x002b040c symbol=FUN_002b0294 lang=c++ */
/* Clone of src/eboot/deleting_dtor_002a0e88.cpp (hstclone.py tag s10170158a2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Deleting destructor: member pointers released in reverse order (inline user dtors give the doubled null checks), base dtor FUN_00057904(this, 0), then operator delete(this) when flag > 0. Names provisional. */
extern "C" {
extern char DAT_003b3168[];
extern void *DAT_003daec4;
extern void FUN_00000a00(void *);
extern void FUN_0006433c(float, void *);
extern void *FUN_00057904(void *, int);
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
  ~Timer() { FUN_0006433c(203000.0f, DAT_003daec4); }
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

extern "C" Obj *FUN_002b0294(Obj *self, short flag)
{
  if (self != 0) {
    self->vptr = DAT_003b3168;
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
    FUN_00057904(self, 0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
