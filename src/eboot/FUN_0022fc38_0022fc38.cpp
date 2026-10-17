/* HSTMATCH module=EBOOT.BIN start=0x0022fc38 end=0x0022fcdc symbol=FUN_0022fc38 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
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
extern undefined4 DAT_0034a81c;
extern undefined * DAT_0034b350;
extern void FUN_001031e8(void *);
extern void FUN_0015df28(void *);
extern void FUN_002917ac(undefined4);
}
struct VC { virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); };
struct Obj {
  char pad0[0x54];
  unsigned char flag;
  char pad1[0x214 - 0x55];
  VC *field214;
  char pad2[4];
  int *field21c;
  char pad3[0x414 - 0x220];
  int mode;
};

extern "C" void FUN_0022fc38(Obj *param_1)
{
  if (param_1->mode == 5) {
    FUN_002917ac(DAT_0034a81c);
  }
  else if ((DAT_0034b350 == 0) || (*(int *)(DAT_0034b350 + 0x5d0) == 0)) {
    FUN_001031e8(param_1);
    if (param_1->field21c != 0) {
      FUN_0015df28(param_1->field21c);
    }
    if ((param_1->flag != 0) && (param_1->field214 != 0)) {
      param_1->field214->f3();
    }
  }
  return;
}

