/* HSTMATCH module=EBOOT.BIN start=0x0011343c end=0x00113580 symbol=FUN_0011343c lang=c++ */
struct Obj { int f0; int f4; int f8; int f0c; int f10; int f14; int f18; };
struct Cell { short p0; short p2; short a; short b; short c; short d; };

extern "C" int DAT_002d9364;
extern "C" void FUN_00112674(int, int, int, int, int, int, int, int);
extern "C" void FUN_00112e10(int, int, int, int);

static inline int AtLeast(const int &v, const int &lo)
{
  return v < lo ? lo : v;
}

extern "C" void FUN_0011343c(Obj *self,int param_2,int param_3,int param_4,short param_5)
{
  self->f0c = param_2;
  param_5 = (short)AtLeast(param_5, DAT_002d9364);
  self->f10 = param_5;
  FUN_00112674(self->f0,param_3,param_4,param_5,0,0x80808080,param_2,3);
  short y = (short)param_4 + 0x13;
  int x = (short)param_3 + self->f10;
  Cell *e = *(Cell **)(*(int *)(*(int *)self->f0 + 0x10) + (param_2 + 6) * 4);
  short old4 = *(volatile short *)&e->a;
  short nx = x - (short)(e->c - e->a) * 6;
  e->a = nx;
  e->c = e->c + (short)(nx - old4);
  short old6 = e->b;
  e->b = y;
  e->d = e->d + (short)(y - old6);
  FUN_00112e10(self->f4,param_2 + 6,3,1);
  self->f14 = 0;
  self->f18 = 0;
}
// NEAR (sn7 lane, 81/81 words, 49 differ, nearly all register colouring): shape now right. Findings:
// (1) the clamp must return int and be cast: `param_5 = (short)AtLeast(param_5, DAT)` with `static inline int AtLeast(const int &v, const int &lo)`
//     gives retail's `slt; beqz; move; b; seh a3,a0 ; move a0,v1; seh a3,a0` shape (the short-returning helper lost a word).
// (2) retail reads e+4 TWICE (lh t2 for the width, lh v1 for old4); plain C CSEs them (80 words). `*(volatile short *)&e->a` for old4 gives
//     retail's three loads (c, a, a) and 81 words but is a matching hack; typed/raw aliasing, locals, reference-helper Slide(), int old4 all CSE.
// (3) x is an int (`(short)param_3 + self->f10`, no seh), y a short, order y, x, e after the call matches retail's load schedule.
// Remaining: retail colours self=s3, param_3=s2, param_4=s1, param_2=s0 and stores `sw a1,12(a0)` BEFORE both entry moves; we get param_2=s3, self=s0.
// Ruled out: local copies of params, store f0c moved to 10 other positions, param_2 as unsigned/short/char, slot=param_2+6 local.
// (o2: with the f0c store moved to the end param_2 does become s0 but self drops to s1.)
// improved by lane sn7 (unreviewed): 74 -> 49 differing words
