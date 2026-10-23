/* HSTMATCH module=EBOOT.BIN start=0x0011343c end=0x00113580 symbol=FUN_0011343c lang=c++ */
struct Obj { int f0; int f4; int f8; int f0c; int f10; int f14; int f18; };

extern "C" int DAT_002d9364;
extern "C" void FUN_00112674(int, int, int, int, int, int, int, int);
extern "C" void FUN_00112e10(int, int, int, int);

static inline short AtLeast(short v, const int &lo)
{
  return v < lo ? (short)lo : v;
}

extern "C" void FUN_0011343c(Obj *self,int param_2,int param_3,int param_4,short param_5)
{
  short x;
  short y;
  short old4;
  short new4;
  short old6;
  int e;

  self->f0c = param_2;
  param_5 = AtLeast(param_5, DAT_002d9364);
  self->f10 = param_5;
  FUN_00112674(self->f0,param_3,param_4,param_5,0,0x80808080,param_2,3);
  x = (short)param_3 + (short)self->f10;
  y = (short)param_4 + 0x13;
  e = *(int *)(*(int *)(*(int *)self->f0 + 0x10) + (param_2 + 6) * 4);
  old4 = *(short *)(e + 4);
  new4 = x - (*(short *)(e + 8) - old4) * 6;
  *(short *)(e + 4) = new4;
  *(short *)(e + 8) = *(short *)(e + 8) + (new4 - old4);
  old6 = *(short *)(e + 6);
  *(short *)(e + 6) = y;
  *(short *)(e + 10) = *(short *)(e + 10) + (y - old6);
  FUN_00112e10(self->f4,param_2 + 6,3,1);
  self->f14 = 0;
  self->f18 = 0;
}
// NEAR 5 (76/81 words): the clamp double-load, the element fetch and the short arithmetic all
// match; retail stores `sw a1,12(a0)` before moving the parameters into their saved registers and
// keeps param_2 in s0 / param_4 in s1 (ours: s2=param_2, s1=param_3, s0=param_4), so every later
// s-register word differs. Ruled out: local `lim`, reassigned short param, reference-parameter
// clamp in C and C++, storing through a struct field vs raw offset.
// near miss from lane fm5 (unreviewed)
