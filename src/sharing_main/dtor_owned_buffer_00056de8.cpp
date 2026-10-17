/* HSTMATCH module=hstp_trans_main.prx start=0x00056de8 end=0x00056ecc symbol=FUN_00056de8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag sh2/v15) corrected by hand: rebuilt as classes (owned buffer object with an inline destructor, delete of the buffer and delete[] of its element array with the implicit null checks), exact match verified; names and types await human review. */
/* matching idiom: the buffer destructor tests p0 twice (nested if) before the free call. */
extern "C" {
void FUN_000104e0(void *);
void FUN_00000a00(void *);
}

struct E { E(); int x; };

struct Buf {
  void *p0;
  int p4;
  int p8;
  E *p12;
  ~Buf() {
    if (p0) {
      if (p0) {
        FUN_000104e0(p0);
        p0 = 0;
      }
    }
    if (p12) {
      delete[] p12;
      p12 = 0;
    }
    p0 = 0;
    p4 = 0;
    p8 = 0;
    p12 = 0;
  }
};

struct Obj {
  Buf *buf;
  void *p4;
  unsigned char owned;
};

extern "C" Obj *FUN_00056de8(Obj *self, short flag)
{
  if (self) {
    if (self->owned) {
      if (self->buf) {
        delete self->buf;
        self->buf = 0;
      }
    }
    if (self->p4) {
      FUN_000104e0(self->p4);
      self->p4 = 0;
    }
    if (flag > 0) {
      FUN_00000a00(self);
    }
  }
  return self;
}
