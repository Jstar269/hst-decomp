/* HSTMATCH module=EBOOT.BIN start=0x00062b64 end=0x00062c5c symbol=FUN_00062b64 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
  int pad;
  int f4;
  unsigned char f8;
  int fc;
};

extern "C" int FUN_00076454(int a, int b);
extern "C" int FUN_000761a8(int a, int b, int c);
extern "C" void FUN_00077470(int a, int b, int c);
extern "C" int FUN_000777b4(int a);
extern "C" void FUN_0007771c(int a, int b);

extern "C" int FUN_00062b64(Obj *self, int p2, int p3)
{
  if (self->f4 < 0) {
    return -1;
  }
  if (self->f8 != 0) {
    int old = self->fc;
    if (old >= 0) {
      FUN_00076454(old, 0);
      if (self->f8 != 0 && self->fc == old) {
        self->fc = -1;
      }
    }
  }
  int r = FUN_000761a8(self->f4, p2, p3);
  if (self->f8 != 0 && r >= 0) {
    FUN_00077470(r, 0, 0x10000);
    self->fc = r;
  }
  if (r >= 0 && FUN_000777b4(r) == 0) {
    FUN_0007771c(r, 2);
  }
  return r;
}
