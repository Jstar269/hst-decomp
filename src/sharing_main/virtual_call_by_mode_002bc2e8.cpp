/* HSTMATCH module=hstp_trans_main.prx start=0x002bc2e8 end=0x002bc3b4 symbol=FUN_002bc2e8 lang=c++ */
/* Clone of src/eboot/virtual_call_by_mode_002acb2c.cpp (hstclone.py tag c034907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct VC { virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); };
extern int DAT_003ba2c4;
extern "C" void FUN_000430d8(float, int);

struct Obj {
  char pad[0x3c];
  VC *f3c;
  VC *f40;
  VC *f44;
  VC *f48;
  int mode;
};

extern "C" void FUN_002bc2e8(Obj *self)
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
  FUN_000430d8(100000.0f, DAT_003ba2c4);
}
