/* HSTMATCH module=EBOOT.BIN start=0x00067500 end=0x000675ac symbol=FUN_00067500 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Deleting destructor: installs the derived vtable, calls the seventh virtual (vtable slot at +32),
   feeds the member at +0x3c into FUN_0006792c with the address of the member at +0x40 and the value
   of the member at +0x44, then calls FUN_0001f0f0 and frees the object when the flag is positive.
   Matching idioms: the three redundant guards test the ADDRESS of the member at +0x3c (never null),
   and the three frame locals are declared in the order out / local_8 / local_c but assigned in the
   order local_c / local_8.
   Names provisional. */
/* Hand-written reconstruction from the disassembly; names and types await human review. */
struct VC {
  virtual void v0();
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6();
};

struct Obj {
  void *vptr;
  char pad[0x38];
  int *f3c;
  int f40;
  int f44;
};

extern char DAT_0030716c[];
extern "C" void FUN_0006792c(int *, int **, int *, int **);
extern "C" void FUN_0001f0f0(Obj *, int);
extern "C" void FUN_00000a00(void *);

extern "C" Obj *FUN_00067500(Obj *self, short flag)
{
  if (self != 0) {
    self->vptr = &DAT_0030716c;
    ((VC *)self)->v6();
    if (&self->f3c != 0 && &self->f3c != 0 && &self->f3c != 0) {
      int out;
      int local_8;
      int *local_c;
      local_c = &self->f40;
      local_8 = self->f44;
      FUN_0006792c(&out, &self->f3c, &local_8, &local_c);
    }
    FUN_0001f0f0(self, 0);
    if (flag > 0) {
      FUN_00000a00(self);
    }
  }
  return self;
}
