/* HSTMATCH module=EBOOT.BIN start=0x0021b328 end=0x0021b3f8 symbol=FUN_0021b328 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* matching idiom: the global read of DAT_002f004c uses an empty loop as the join that makes MWCC keep
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

extern int DAT_003097c4;
extern float DAT_002eff88;
extern int DAT_002f004c;
extern int DAT_002f0058[3];
extern char DAT_002f0064;

extern "C" void FUN_00102e38(void *o);
extern "C" void FUN_00104118(void *o, void *p, int n);
extern "C" void FUN_00103540(void *o, float f);
extern "C" void FUN_001037c8(void *o, int m);
extern "C" void *FUN_001039d8(void *o, int a, int b);
extern "C" void *FUN_001026b8(void *a, int b);
extern "C" void FUN_0021b400(void *o);

extern "C" Self *FUN_0021b328(Self *self)
{
  void *p;

  FUN_00102e38(self);
  self->vptr = &DAT_003097c4;
  FUN_00104118(self, &DAT_002f0064, 1);
  FUN_00103540(self, DAT_002eff88);
  FUN_001037c8(self, -4097);
  int *gp = &DAT_002f004c;
  for (int i = 0; i < 0; i++) { }
  self->items[0] = FUN_001039d8(self, *gp, 0);
  ((Made *)self->items[0])->v6(-4097);
  int *st = (int *)&DAT_002f0058[0];
  p = FUN_001026b8(*(void **)((char *)self + 88 + st[0] * 4), st[1]);
  self->items[1] = p;
  st[2] = *(int *)((char *)p + 36);
  FUN_0021b400(self);
  return self;
}
