/* HSTMATCH module=EBOOT.BIN start=0x000e1798 end=0x000e189c symbol=FUN_000e1798 lang=c++ */
/* Clone of src/sharing_main/FUN_000e5d60.cpp (hstclone.py tag s10170158a1r3e): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* The byte clear [this+0x5c, this+0xc0) is an inline loop whose count 0xc0 - (p - this) MWCC leaves unfolded (rolled/8x-unrolled with the 0x7fffffff guard); matching idiom: the pointer is bumped in the body, the counter declared after it; the abs is a ternary (an if gives bgezl). */
struct Ref {
  char pad0[0x18];
  short s18;
  char pad1[0x30 - 0x1a];
  int f30;
};
struct Obj {
  virtual void s0();
  virtual void s1();
  virtual void s2();
  virtual void s3();
  virtual void s4();
  virtual void s5(int);
  char pad0[0x3c - 4];
  Ref *ref;
  char pad1[0x5c - 0x40];
  char tail[0x60 - 0x5c];
  char f60;
  char f61;
  char pad2[0x74 - 0x62];
  float f74;
  char pad3[0x90 - 0x78];
  int f90;
  char pad4[0xc0 - 0x94];
};

extern "C" void FUN_000e1798(Obj *self)
{
  char *p = (char *)self + 0x5c;
  int n = 0xc0 - (p - (char *)self);
  int i = 0;
  for (; i < n; i++)
    *p++ = 0;
  self->f60 = 1;
  self->s5(self->ref->f30);
  self->f61 = 1;
  int v = self->ref->s18;
  v = v < 0 ? -v : v;
  self->f90 = v;
  self->f74 = 1.0f;
}
