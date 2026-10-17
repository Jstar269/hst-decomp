/* HSTMATCH module=EBOOT.BIN start=0x0025f0c4 end=0x0025f1c4 symbol=FUN_0025f0c4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: inverted if/else on DAT_003417be, structured bool condition with xori, typed Obj fields; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code(...);
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern unsigned char DAT_003417be;
extern void FUN_000114c0(void *, int, unsigned int);
extern void FUN_0010b8cc(void *, int, int);
extern void FUN_0025346c(void *, int);
extern void FUN_0025eca0(void *);
extern void FUN_0025f1c4(void *);
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

extern "C" void FUN_0025f0c4(Obj *param_1)
{
  FUN_000114c0(param_1->f712, 0, 28);
  param_1->f720 = 1;
  FUN_0025eca0(param_1);
  param_1->f504 = DAT_003417be != 0;

  int b = (param_1->f100 != 0) ^ 1;
  if (b == 0) {
    b = param_1->f101 != 0;
  }
  FUN_0025346c(param_1->f452, b);

  if (DAT_003417be != 0) {
    Sub58 *sub = (Sub58 *)param_1->f58;
    sub->f216 = 0;
    sub->f276 = 1;
    FUN_0010b8cc(param_1->f58, 1, 0);
    param_1->f70->m(1);
  }
  else {
    Sub58 *sub = (Sub58 *)param_1->f58;
    sub->f216 = 2;
    sub->f276 = 1;
    FUN_0010b8cc(param_1->f58, 0, 0);
    param_1->f70->m(0);
  }
  FUN_0025f1c4(param_1);
}
