/* HSTMATCH module=hstp_trans_main.prx start=0x00063a28 end=0x00063b20 symbol=FUN_00063a28 lang=c++ */
/* Clone of src/eboot/FUN_00062b64.cpp (hstclone.py tag om1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Obj {
  int pad;
  int f4;
  unsigned char f8;
  int fc;
};

extern "C" int FUN_00077c14(int a, int b);
extern "C" int FUN_00077968(int a, int b, int c);
extern "C" void FUN_00078c30(int a, int b, int c);
extern "C" int FUN_00078f74(int a);
extern "C" void FUN_00078edc(int a, int b);

extern "C" int FUN_00063a28(Obj *self, int p2, int p3)
{
  if (self->f4 < 0) {
    return -1;
  }
  if (self->f8 != 0) {
    int old = self->fc;
    if (old >= 0) {
      FUN_00077c14(old, 0);
      if (self->f8 != 0 && self->fc == old) {
        self->fc = -1;
      }
    }
  }
  int r = FUN_00077968(self->f4, p2, p3);
  if (self->f8 != 0 && r >= 0) {
    FUN_00078c30(r, 0, 0x10000);
    self->fc = r;
  }
  if (r >= 0 && FUN_00078f74(r) == 0) {
    FUN_00078edc(r, 2);
  }
  return r;
}
