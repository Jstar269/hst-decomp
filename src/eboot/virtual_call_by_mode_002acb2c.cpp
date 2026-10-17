/* HSTMATCH module=EBOOT.BIN start=0x002acb2c end=0x002acbf8 symbol=FUN_002acb2c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct VC { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); };
extern int DAT_00310fc4;
extern "C" void FUN_00042ff4(float, int);

struct Obj {
  char pad[0x3c];
  VC *f3c;
  VC *f40;
  VC *f44;
  VC *f48;
  int mode;
};

extern "C" void FUN_002acb2c(Obj *self)
{
  self->f3c->s3();
  switch (self->mode) {
  case 1:
    self->f40->s3();
    break;
  case 2:
    self->f44->s3();
    break;
  case 3:
  case 4:
    self->f48->s3();
    break;
  }
  FUN_00042ff4(100000.0f, DAT_00310fc4);
}
