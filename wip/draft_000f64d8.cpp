/* HSTMATCH module=EBOOT.BIN start=0x000f64d8 end=0x000f6690 symbol=FUN_000f64d8 lang=c++ */
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
extern void FUN_00000a00(...);
extern int * FUN_0006eb04(...);
extern int FUN_000fc19c(...);
extern int FUN_000fc210(...);
extern int * FUN_000fc398(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" int * FUN_000f64d8(int *param_1,short param_2)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if (param_1 != (int *)0x0) {
    piVar2 = (int *)*param_1;
    if (piVar2 != (int *)0x0) {
      delete ((VC_0 *)(piVar2));
      *param_1 = 0;
    }
    iVar1 = param_1[2];
    piVar2 = (int *)param_1[1];
    if (piVar2 == piVar2 + iVar1) {
      iVar1 = param_1[0x20d];
    }
    else {
      piVar3 = (int *)*piVar2;
      while( true ) {
        if (piVar3 != (int *)0x0) {
          delete ((VC_1 *)(piVar3));
          *piVar2 = 0;
        }
        piVar2 = (int *)FUN_000fc210(param_1 + 1,piVar2,0);
        if (piVar2 == (int *)(param_1[1] + param_1[2] * 4)) break;
        piVar3 = (int *)*piVar2;
      }
      iVar1 = param_1[0x20d];
    }
    piVar2 = (int *)param_1[0x20c];
    if (piVar2 != piVar2 + iVar1) {
      iVar1 = *piVar2;
      while( true ) {
        if (iVar1 != 0) {
          FUN_00000a00();
          *piVar2 = 0;
        }
        piVar2 = (int *)FUN_000fc19c(param_1 + 0x20c,piVar2,0);
        if (piVar2 == (int *)(param_1[0x20c] + param_1[0x20d] * 4)) break;
        iVar1 = *piVar2;
      }
    }
    piVar2 = param_1 + 0x20c;
    param_1[2] = 0;
    if ((piVar2 != (int *)0x0) && (piVar2 != (int *)0x0)) {
      FUN_000fc398(piVar2,0);
    }
    piVar2 = param_1 + 1;
    if ((piVar2 != (int *)0x0) && (piVar2 != (int *)0x0)) {
      FUN_0006eb04(piVar2,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
// near miss from lane fm9 (unreviewed)
