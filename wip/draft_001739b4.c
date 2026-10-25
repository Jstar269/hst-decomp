/* HSTMATCH module=EBOOT.BIN start=0x001739b4 end=0x00173e84 symbol=FUN_001739b4 lang=c99 */
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

extern undefined * DAT_003415ac;
extern void FUN_00103628();
extern void FUN_00114168();
extern void FUN_00115040();
extern void FUN_00170658();
extern void FUN_0017358c();
extern void FUN_0017d1f0();
extern void FUN_0017d1f8();
extern void FUN_0017de50();
extern void FUN_0017df34();
extern void FUN_00183954();
extern void FUN_00184040();
extern void FUN_00187294();
extern undefined * FUN_001fea10();

void FUN_001739b4(int param_1,int param_2,int param_3)
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *(int *)(*(int *)(*(int *)(param_2 + 0x18) + *(int *)(param_2 + 8) * 0xc) +
                  *(int *)(param_2 + 4) * 4);
  if (param_3 - 0x7ffeU < 2) {
    FUN_00183954(*(undefined4 *)(param_1 + 0x174),1,1,1,param_2,param_3);
    FUN_00184040(*(undefined4 *)(param_1 + 0x174),param_3,1,0,1,0);
    *(undefined1 *)(*(int *)(param_1 + 0x178) + 0x59) = 0;
    FUN_0017d1f0(*(undefined4 *)(param_1 + 0x178));
    iVar2 = (int)(DAT_003415ac);
    if (param_3 == 0x7fff) {
      if (*(int *)(param_1 + 0x56c) < 1) {
        uVar3 = (unsigned int)(FUN_001fea10(0x11,5,5));
        FUN_00114168(DAT_003415ac,0,uVar3,0,0);
      }
      else {
        *(undefined4 *)(**(int **)(DAT_003415ac + 4) + 0x60) = 0x43a10000;
        *(undefined4 *)(**(int **)(iVar2 + 4) + 100) = 0x43080000;
        iVar2 = (int)(DAT_003415ac);
        *(undefined4 *)(DAT_003415ac + 0x74) = 0x3f666666;
        *(undefined4 *)(iVar2 + 0x78) = 0x3f666666;
        uVar3 = (unsigned int)(FUN_001fea10(0x11,5,1));
        FUN_00115040(DAT_003415ac,0,uVar3,0,0);
        FUN_00187294(*(undefined4 *)(param_1 + 0x174),0);
      }
    }
    else {
      iVar2 = *(int *)(*(int *)(*(int *)(param_2 + 0x18) + *(int *)(param_2 + 8) * 0xc) +
                      *(int *)(param_2 + 4) * 4);
      if (param_3 == 0x7fff) {
        *(undefined1 *)(*(int *)(param_1 + 0x178) + 0x59) = 0;
        FUN_0017d1f0(*(undefined4 *)(param_1 + 0x178));
      }
      else if (param_3 != 0x7ffe) {
        if (*(char *)(iVar2 + 8) == '\0') {
          if ((*(char *)(iVar2 + 0xb) == '\0') && (*(char *)(iVar2 + 0xc) == '\0')) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          uVar3 = (**(code **)(param_1 + 0x550))(param_3);
          FUN_0017d1f8(*(undefined4 *)(param_1 + 0x178),uVar3,param_3,1);
        }
        else {
          *(undefined1 *)(*(int *)(param_1 + 0x178) + 0x59) = 0;
          FUN_0017d1f0(*(undefined4 *)(param_1 + 0x178));
        }
      }
      if ((DAT_003415ac != 0) &&
         ((*(ushort *)(**(int **)(*(int *)(DAT_003415ac + 0x54) + 0x10) + 0xe) & 3) == 0)) {
        FUN_00103628(DAT_003415ac,1);
        iVar2 = (int)(DAT_003415ac);
        if (DAT_003415ac != 0) {
          *(undefined4 *)(DAT_003415ac + 0x74) = 0x3f800000;
          *(undefined4 *)(iVar2 + 0x78) = 0x3f800000;
          iVar2 = (int)(DAT_003415ac);
          *(undefined4 *)(**(int **)(DAT_003415ac + 4) + 0x60) = 0x43700000;
          *(undefined4 *)(**(int **)(iVar2 + 4) + 100) = 0x43080000;
        }
        uVar3 = *(undefined4 *)(param_1 + 0x174);
        FUN_00187294(uVar3,1);
      }
    }
  }
  else {
    if (*(char *)(iVar2 + 8) == '\0') {
      if ((*(char *)(iVar2 + 0xb) == '\0') && (*(char *)(iVar2 + 0xc) == '\0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      FUN_0017358c(param_1,param_3);
      uVar3 = (**(code **)(param_1 + 0x550))(param_3);
      FUN_0017d1f8(*(undefined4 *)(param_1 + 0x178),uVar3,param_3,1);
      FUN_00183954(*(undefined4 *)(param_1 + 0x174),1,1,1,param_2,param_3);
      FUN_00170658(param_1,param_3);
      FUN_00184040(*(undefined4 *)(param_1 + 0x174),param_3,1,0,1,0);
      FUN_0017de50(0,*(undefined4 *)(param_1 + 0x178));
      *(undefined1 *)(*(int *)(param_1 + 0x178) + 0x40) = 0;
      FUN_0017df34(*(undefined4 *)(param_1 + 0x178));
      if ((DAT_003415ac != 0) &&
         ((*(ushort *)(**(int **)(*(int *)(DAT_003415ac + 0x54) + 0x10) + 0xe) & 3) == 0)) {
        FUN_00103628(DAT_003415ac,1);
        iVar2 = (int)(DAT_003415ac);
        if (DAT_003415ac != 0) {
          *(undefined4 *)(DAT_003415ac + 0x74) = 0x3f800000;
          *(undefined4 *)(iVar2 + 0x78) = 0x3f800000;
          iVar2 = (int)(DAT_003415ac);
          *(undefined4 *)(**(int **)(DAT_003415ac + 4) + 0x60) = 0x43700000;
          *(undefined4 *)(**(int **)(iVar2 + 4) + 100) = 0x43080000;
        }
        uVar3 = *(undefined4 *)(param_1 + 0x174);
        FUN_00187294(uVar3,1);
      }
    }
    else {
      FUN_00183954(*(undefined4 *)(param_1 + 0x174),1,1,1,param_2,param_3);
      FUN_00184040(*(undefined4 *)(param_1 + 0x174),param_3,1,0,1,0);
      *(undefined1 *)(*(int *)(param_1 + 0x178) + 0x59) = 0;
      FUN_0017d1f0(*(undefined4 *)(param_1 + 0x178));
      if ((DAT_003415ac != 0) &&
         ((*(ushort *)(**(int **)(*(int *)(DAT_003415ac + 0x54) + 0x10) + 0xe) & 3) == 0)) {
        FUN_00103628(DAT_003415ac,1);
        iVar2 = (int)(DAT_003415ac);
        if (DAT_003415ac != 0) {
          *(undefined4 *)(DAT_003415ac + 0x74) = 0x3f800000;
          *(undefined4 *)(iVar2 + 0x78) = 0x3f800000;
          iVar2 = (int)(DAT_003415ac);
          *(undefined4 *)(**(int **)(DAT_003415ac + 4) + 0x60) = 0x43700000;
          *(undefined4 *)(**(int **)(iVar2 + 4) + 100) = 0x43080000;
        }
        uVar3 = *(undefined4 *)(param_1 + 0x174);
        FUN_00187294(uVar3,1);
      }
    }
  }
  return;
}
// near miss from lane fm11 (unreviewed)
