/* HSTMATCH module=hstp_trans_main.prx start=0x000ebd48 end=0x000ebe20 symbol=FUN_000ebd48 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

struct EmptyTag {};
struct VC_000ebd48 {
  virtual ~VC_000ebd48();
  virtual void m0();
  virtual void m1();
  virtual void m2();
  virtual void m3();
  virtual void m4();
};

extern undefined4 DAT_003b0900;
extern "C" {
extern void FUN_000006e8(int, void (*)());
extern void FUN_00000a00(void *);
extern int * FUN_0001ed28(int *, int);
extern void FUN_0005bbd8();
extern void FUN_000ed698(int *, int, EmptyTag);
extern void FUN_000ed818(int *, int);
extern void FUN_000ed630(int *, int);
}

extern "C" int * FUN_000ebd48(int *param_1, short param_2)
{
  int *piVar1;
  int iVar2;

  if (param_1 != 0) {
    *(void **)param_1 = &DAT_003b0900;
    ((VC_000ebd48 *)param_1)->m4();
    if (param_1[0x37] != 0) {
      FUN_000006e8(param_1[0x37], FUN_0005bbd8);
      param_1[0x37] = 0;
    }
    iVar2 = param_1[0x13];
    FUN_000ed698(param_1 + 0x12, iVar2, EmptyTag());
    piVar1 = param_1 + 0x12;
    if ((piVar1 != 0) && (piVar1 != 0)) {
      FUN_000ed818(piVar1, 0);
    }
    piVar1 = param_1 + 0xf;
    if ((piVar1 != 0) && (piVar1 != 0)) {
      FUN_000ed630(piVar1, 0);
    }
    FUN_0001ed28(param_1, 0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
