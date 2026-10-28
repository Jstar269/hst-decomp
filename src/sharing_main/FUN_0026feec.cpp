/* HSTMATCH module=hstp_trans_main.prx start=0x0026feec end=0x0026ffec symbol=FUN_0026feec lang=c++ */
/* Clone of src/eboot/FUN_0025f0c4.cpp (hstclone.py tag u5fr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: inverted if/else on DAT_003eaaf6, structured bool condition with xori, typed Obj fields; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern unsigned char DAT_003eaaf6;
extern void FUN_000114c0(void *, int, unsigned int);
extern void FUN_00111aa4(void *, int, int);
extern void FUN_002637c0(void *, int);
extern void FUN_0026fac8(void *);
extern void FUN_0026ffec(void *);
}

struct VC_1 { virtual void d0(); virtual void m(int); };

struct Obj {
  char pad0[88];
  void *f58;
  char pad1[100 - 92];
  unsigned char f100;
  unsigned char f101;
  char pad2[112 - 102];
  VC_1 *f70;
  char pad3[452 - 116];
  char f452[52];
  bool f504;
  char pad4[712 - 505];
  char f712[8];
  int f720;
};

struct Sub58 {
  char pad[216];
  int f216;
  char pad2[276 - 220];
  unsigned char f276;
};

extern "C" void FUN_0026feec(Obj *param_1)
{
  FUN_000114c0(param_1->f712, 0, 28);
  param_1->f720 = 1;
  FUN_0026fac8(param_1);
  param_1->f504 = DAT_003eaaf6 != 0;

  int b = (param_1->f100 != 0) ^ 1;
  if (b == 0) {
    b = param_1->f101 != 0;
  }
  FUN_002637c0(param_1->f452, b);

  if (DAT_003eaaf6 != 0) {
    Sub58 *sub = (Sub58 *)param_1->f58;
    sub->f216 = 0;
    sub->f276 = 1;
    FUN_00111aa4(param_1->f58, 1, 0);
    param_1->f70->m(1);
  }
  else {
    Sub58 *sub = (Sub58 *)param_1->f58;
    sub->f216 = 2;
    sub->f276 = 1;
    FUN_00111aa4(param_1->f58, 0, 0);
    param_1->f70->m(0);
  }
  FUN_0026ffec(param_1);
}
