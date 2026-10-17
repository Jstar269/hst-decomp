/* HSTMATCH module=EBOOT.BIN start=0x00225288 end=0x002254ec symbol=FUN_00225288 lang=c++ */
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
extern void *DAT_0034a820;
extern void FUN_00000a00(...);
extern int * FUN_000f64d8(...);
extern int FUN_0021aa6c(...);
extern void FUN_00291cdc(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };
struct VC_3 { virtual ~VC_3(); };
struct VC_4 { virtual ~VC_4(); };
struct VC_5 { virtual ~VC_5(); };
struct VC_6 { virtual ~VC_6(); };
struct VC_7 { virtual ~VC_7(); };
struct VC_8 { virtual ~VC_8(); };
struct VC_9 { virtual ~VC_9(); };
struct VC_10 { virtual ~VC_10(); };

extern "C" int * FUN_00225288(int *param_1,short param_2)
{
  int *piVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    piVar1 = (int *)*param_1;
    if (piVar1 != (int *)0x0) {
      delete ((VC_0 *)(piVar1));
      *param_1 = 0;
    }
    piVar1 = (int *)param_1[1];
    if (piVar1 != (int *)0x0) {
      delete ((VC_1 *)(piVar1));
      param_1[1] = 0;
    }
    piVar1 = (int *)param_1[2];
    if (piVar1 != (int *)0x0) {
      delete ((VC_2 *)(piVar1));
      param_1[2] = 0;
    }
    piVar1 = (int *)param_1[3];
    if (piVar1 != (int *)0x0) {
      delete ((VC_3 *)(piVar1));
      param_1[3] = 0;
    }
    piVar1 = (int *)param_1[4];
    if (piVar1 != (int *)0x0) {
      delete ((VC_4 *)(piVar1));
      param_1[4] = 0;
    }
    piVar1 = (int *)param_1[5];
    if (piVar1 != (int *)0x0) {
      delete ((VC_5 *)(piVar1));
      param_1[5] = 0;
    }
    piVar1 = (int *)param_1[6];
    if (piVar1 != (int *)0x0) {
      delete ((VC_6 *)(piVar1));
      param_1[6] = 0;
    }
    piVar1 = (int *)param_1[7];
    if (piVar1 != (int *)0x0) {
      delete ((VC_7 *)(piVar1));
      param_1[7] = 0;
    }
    piVar1 = (int *)param_1[8];
    if (piVar1 != (int *)0x0) {
      delete ((VC_8 *)(piVar1));
      param_1[8] = 0;
    }
    piVar1 = (int *)param_1[9];
    if (piVar1 != (int *)0x0) {
      delete ((VC_9 *)(piVar1));
      param_1[9] = 0;
    }
    iVar2 = param_1[10];
    if (iVar2 != 0) {
      FUN_0021aa6c(iVar2,1);
      param_1[10] = 0;
    }
    piVar1 = (int *)param_1[0xb];
    if (piVar1 != (int *)0x0) {
      delete ((VC_10 *)(piVar1));
      param_1[0xb] = 0;
    }
    iVar2 = param_1[0xc];
    if (iVar2 != 0) {
      if (iVar2 != 0) {
        FUN_000f64d8(iVar2,0);
        FUN_00000a00(iVar2);
      }
      param_1[0xc] = 0;
    }
    if (DAT_0034a820) {
      FUN_00291cdc();
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
// Near miss: two words differ at +0x220 because the global load/test uses v0; retail uses a0. A pointer declaration and direct truth test did not change the register choice.
// near miss from lane u4r4-0 (unreviewed)
