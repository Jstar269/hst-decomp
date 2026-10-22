/* HSTMATCH module=hstp_trans_main.prx start=0x0022a89c end=0x0022a96c symbol=FUN_0022a89c lang=c++ */
/* Clone of src/eboot/wrapper_ctor_0021b328.cpp (hstclone.py tag fm1): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: the global read of DAT_00398418 uses an empty loop as the join that makes MWCC keep
   the address unfolded (retail: lui v0,hi ; addiu v0,v0,lo ; lw a1,0(v0)). */

typedef struct Self {
  void *vptr;
  char pad[0x54];
  void *items[2];
} Self;

struct Made {
  virtual void v1();
  virtual void v2();
  virtual void v3();
  virtual void v4();
  virtual void v5();
  virtual void v6(int mask);
};

extern int DAT_003b2a90;
extern float DAT_00398354;
extern int DAT_00398418;
extern int DAT_00398424[3];
extern char DAT_00398430;

extern "C" void FUN_0010873c(void *o);
extern "C" void FUN_00109a44(void *o, void *p, int n);
extern "C" void FUN_00108e6c(void *o, float f);
extern "C" void FUN_001090f4(void *o, int m);
extern "C" void *FUN_00109304(void *o, int a, int b);
extern "C" void *FUN_00108124(void *a, int b);
extern "C" void FUN_0022a974(void *o);

extern "C" Self *FUN_0022a89c(Self *self)
{
  void *p;

  FUN_0010873c(self);
  self->vptr = &DAT_003b2a90;
  FUN_00109a44(self, &DAT_00398430, 1);
  FUN_00108e6c(self, DAT_00398354);
  FUN_001090f4(self, -4097);
  int *gp = &DAT_00398418;
  for (int i = 0; i < 0; i++) { }
  self->items[0] = FUN_00109304(self, *gp, 0);
  ((Made *)self->items[0])->v6(-4097);
  int *st = (int *)&DAT_00398424[0];
  p = FUN_00108124(*(void **)((char *)self + 88 + st[0] * 4), st[1]);
  self->items[1] = p;
  st[2] = *(int *)((char *)p + 36);
  FUN_0022a974(self);
  return self;
}
