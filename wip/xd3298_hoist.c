/* HSTMATCH module=EBOOT.BIN start=0x000d3298 end=0x000d3414 symbol=FUN_000d3298 lang=c99 */
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

extern undefined DAT_00307484;
extern void FUN_00000788();
extern void FUN_00000a00();
extern undefined4 * FUN_0001f0f0();
extern int FUN_00053718();
extern int FUN_00055e48();
extern int * FUN_0006eb04();
extern void FUN_000d564c();
extern int * FUN_000d5730();
extern void FUN_00056cb0();

undefined4 * FUN_000d3298(undefined4 *param_1,short param_2)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_00307484);
    iVar2 = param_1[0x10];
    piVar5 = (int *)param_1[0xf];
    if (piVar5 == piVar5 + iVar2) {
      iVar1 = param_1[0x10];
    }
    else {
      piVar3 = (int *)*piVar5;
      while( true ) {
        if (piVar3 == (int *)0x0) {
          iVar2 = param_1[0x10];
        }
        else {
          if (piVar3 == (int *)0x0) {
            *piVar5 = 0;
          }
          else {
            (**(code **)(*piVar3 + 8))(piVar3,1);
            *piVar5 = 0;
          }
          iVar2 = param_1[0x10];
        }
        piVar5 = piVar5 + 1;
        if (piVar5 == (int *)(param_1[0xf] + iVar2 * 4)) break;
        piVar3 = (int *)*piVar5;
      }
      iVar1 = param_1[0x10];
    }
    param_1[0x10] = iVar1 - iVar2;
    FUN_000d564c(param_1 + 0x12,param_1[0x13],0);
    if (param_1[0x1e9] != 0) {
      FUN_00053718(param_1[0x1e9],1);
      param_1[0x1e9] = 0;
    }
    iVar2 = param_1[0x1ea];
    if (iVar2 != 0) {
      FUN_00055e48(iVar2,1);
      param_1[0x1ea] = 0;
    }
    FUN_00000788(param_1 + 0x38,FUN_00056cb0,0x1b0,4);
    puVar4 = param_1 + 0x12;
    if ((puVar4 != (undefined4 *)0x0) && (puVar4 != (undefined4 *)0x0)) {
      FUN_000d5730(puVar4,0);
    }
    puVar4 = param_1 + 0xf;
    if ((puVar4 != (undefined4 *)0x0) && (puVar4 != (undefined4 *)0x0)) {
      FUN_0006eb04(puVar4,0);
    }
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
// near miss from lane dsn3 (unreviewed)
