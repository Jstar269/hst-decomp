/* HSTMATCH module=EBOOT.BIN start=0x0025f1c4 end=0x0025f298 symbol=FUN_0025f1c4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: C++ virtual calls (this slot 2, child at +0x58 slot 10), the dropped this/float arguments of FUN_00103540 restored with float constants 1010.0f and 99990.0f, typed object view; exact match verified; names and types await human review. */
struct Child {
  virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
  virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
  virtual void s10();
};
struct Obj {
  virtual void s0(); virtual void s1(); virtual void s2();
  char pad4[0x54 - 4];
  unsigned char f54;
  unsigned char f55;
  char pad56[2];
  Child *f58;
  char pad5c[0x5d0 - 0x5c];
  int f5d0;
};
extern int *DAT_002cfc8c;
extern "C" void FUN_0001dfe8(int *, int);
extern "C" void FUN_0001e23c(int *, int, int);
extern "C" void FUN_00103540(Obj *, float);
extern "C" void FUN_00103628(Obj *, int);
extern "C" void FUN_001037c8(Obj *, int);
extern "C" void FUN_0025e698(Obj *, int);

extern "C" void FUN_0025f1c4(Obj *param_1)
{
  FUN_00103540(param_1, 1010.0f);
  FUN_001037c8(param_1, -1);
  FUN_0001dfe8(DAT_002cfc8c, 0x2000);
  FUN_0001e23c(DAT_002cfc8c, 0x2000, 1);
  if (param_1->f58 != 0) {
    param_1->f58->s10();
  }
  param_1->f54 = 1;
  param_1->f55 = 0;
  FUN_00103628(param_1, 0);
  param_1->s2();
  param_1->f5d0 = 0;
  FUN_0025e698(param_1, 0);
  FUN_00103540(param_1, 99990.0f);
  FUN_001037c8(param_1, -1);
}
