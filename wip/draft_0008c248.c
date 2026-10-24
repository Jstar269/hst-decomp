/* HSTMATCH module=EBOOT.BIN start=0x0008c248 end=0x0008c434 symbol=FUN_0008c248 lang=c99 */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined DAT_003070bc;
extern undefined4 DAT_00310fc4;
extern int * DAT_003386c0;
extern int * DAT_003415d4;
extern undefined4 DAT_0034a7f0;
extern undefined4 DAT_0034a820;
extern void FUN_00000788();
extern void FUN_00000a00();
extern void FUN_000429a0();
extern int FUN_0005ba00();
extern int * FUN_00064a08();
extern int FUN_00066338();
extern void FUN_00102958();
extern void FUN_00194110();
extern int FUN_001b8c54();
extern void FUN_001fe0f4();
extern int * FUN_00280114();
extern void FUN_00291cdc();
extern void FUN_00056cb0();

int * FUN_0008c248(int *param_1,short param_2)
{
  int *piVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    if (DAT_003386c0 != (int *)0x0) {
      if (DAT_003386c0 != (int *)0x0) {
        (**(code **)(*DAT_003386c0 + 8))(DAT_003386c0,1);
      }
      DAT_003386c0 = (int *)0x0;
    }
    if (DAT_003415d4 != (int *)0x0) {
      if (DAT_003415d4 != (int *)0x0) {
        (**(code **)(*DAT_003415d4 + 8))(DAT_003415d4,1);
      }
      DAT_003415d4 = (int *)0x0;
    }
    if (DAT_0034a7f0 != 0) {
      FUN_00280114(DAT_0034a7f0,1);
      DAT_0034a7f0 = 0;
    }
    FUN_00194110();
    FUN_00102958(**(undefined4 **)(*param_1 + 4));
    piVar1 = (int *)*param_1;
    if (piVar1 == (int *)0x0) {
      iVar2 = param_1[0x273];
    }
    else {
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1,1);
      }
      *param_1 = 0;
      iVar2 = param_1[0x273];
    }
    if (iVar2 != 0) {
      FUN_001b8c54(iVar2,1);
      param_1[0x273] = 0;
    }
    FUN_001fe0f4(0);
    FUN_000429a0(DAT_00310fc4);
    if (DAT_0034a820 != 0) {
      FUN_00291cdc();
    }
    if ((char *)param_1 + 0x990 != (char *)0) {
      piVar1 = param_1 + 0x26c;
      param_1[0x264] = (int)&DAT_003070bc;
      if ((((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) && (piVar1 != (int *)0x0)) &&
         (piVar1 != (int *)0x0)) {
        FUN_00066338(piVar1,0);
      }
      piVar1 = param_1 + 0x268;
      if (((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) &&
         ((piVar1 != (int *)0x0 && (piVar1 != (int *)0x0)))) {
        FUN_00066338(piVar1,0);
      }
      FUN_00064a08(param_1 + 0x264,0);
    }
    FUN_0005ba00(param_1 + 0x1b4,0xffffffff);
    FUN_00000788(param_1 + 4,FUN_00056cb0,0x1b0,4);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
// near miss from lane fm9 (unreviewed)
