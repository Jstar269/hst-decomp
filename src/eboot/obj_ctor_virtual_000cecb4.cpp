/* HSTMATCH module=EBOOT.BIN start=0x000cecb4 end=0x000ced88 symbol=FUN_000cecb4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: base ctor receives this, virtual slot 2 call, FUN_00057b58 takes a float first argument; exact match verified; names and types await human review. */
extern char DAT_003074f8[];
extern char DAT_002d6374[];
extern char DAT_002d637c[];
extern "C" void FUN_000143b0(char *, char *, int);
extern "C" void FUN_00056b98(void *);
extern "C" void FUN_000573a0(void *, int, char *, int, int);
extern "C" void FUN_00057b58(float, void *, int, int);
extern "C" void FUN_00058ddc(void *, int, int);

struct Obj {
  virtual void v0();
  virtual void v1();
  virtual void v2(char *, int, int, int, int, int);
};

extern "C" Obj *FUN_000cecb4(Obj *self, int p2)
{
  char buf[256];
  FUN_00056b98(self);
  *(char **)self = DAT_003074f8;
  *(int *)((char *)self + 0x1b0) = 0;
  FUN_000143b0(buf, DAT_002d6374, p2);
  self->v2(buf, 0, 0, 0, 0, 0);
  FUN_000143b0(buf, DAT_002d637c, p2);
  FUN_000573a0(self, 0, buf, 0, 0);
  FUN_00057b58(0.0f, self, 0, 0);
  FUN_00058ddc(self, 0, -1);
  *((char *)self + 0xc0) = 0;
  return self;
}
