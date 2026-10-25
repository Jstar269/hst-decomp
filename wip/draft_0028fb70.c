/* HSTMATCH module=EBOOT.BIN start=0x0028fb70 end=0x0028ff38 symbol=FUN_0028fb70 lang=c99 */
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

extern char DAT_002cabbc[];
extern char DAT_002cabe4[];
extern char DAT_002ff27c[];
extern char DAT_002ff2a8[];
extern char DAT_002ff2d0[];
extern char DAT_002ff300[];
extern char DAT_002ff320[];
extern char DAT_002ff34c[];
extern char DAT_002ff390[];
extern char DAT_002ff3bc[];
extern char DAT_002ff3e0[];
extern char DAT_002ff408[];
extern char DAT_002ff434[];
extern void FUN_000104e0();
extern undefined4 FUN_0006165c();
extern void FUN_0028fb44();
extern bool FUN_002903cc();
extern int FUN_002b78d0();
extern int FUN_002b7908();
extern void FUN_002b7958();
extern int FUN_002b7980();
extern int FUN_002b79a8();
extern int FUN_002b7a08();
extern int FUN_002b7cc0();
extern int FUN_002b7d50();
extern int FUN_002b7e78();
extern int FUN_002b7e90();
extern int FUN_002b7ec0();
extern int FUN_002b7ed8();
extern int FUN_002b7ee0();

undefined4 FUN_0028fb70(int param_1)
{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  if (*(char *)(param_1 + 0x28) == '\0') {
    uVar3 = 1;
  }
  else {
    FUN_0028fb44(DAT_002ff390);
    *(undefined1 *)(param_1 + 0x2a) = 1;
    iVar4 = FUN_002b7ee0(param_1);
    bVar2 = (iVar4 != -0x7f9e9fff && iVar4 != 0) && iVar4 != 1;
    if (bVar2) {
      iVar4 = FUN_002b7e78(param_1);
      if (iVar4 != 0) {
        FUN_0028fb44(DAT_002ff3bc,iVar4);
      }
      iVar4 = *(int *)(param_1 + 0x80);
    }
    else {
      iVar4 = *(int *)(param_1 + 0x80);
    }
    if (iVar4 < 0) {
      iVar4 = *(int *)(param_1 + 0x80);
    }
    else {
      iVar4 = FUN_002b7980(iVar4,0);
      if (iVar4 != 0) {
        FUN_0028fb44(DAT_002cabe4,iVar4);
      }
      iVar4 = *(int *)(param_1 + 0x80);
    }
    if (iVar4 < 0) {
      iVar4 = *(int *)(param_1 + 100);
    }
    else {
      iVar4 = FUN_002b79a8();
      if (iVar4 != 0) {
        FUN_0028fb44(DAT_002cabbc,iVar4);
      }
      *(undefined4 *)(param_1 + 0x80) = 0xffffffff;
      iVar4 = *(int *)(param_1 + 100);
    }
    if (iVar4 < 0) {
      iVar4 = *(int *)(param_1 + 100);
    }
    else {
      iVar4 = FUN_002b7980(iVar4,0);
      if (iVar4 != 0) {
        FUN_0028fb44(DAT_002cabe4,iVar4);
      }
      iVar4 = *(int *)(param_1 + 100);
    }
    if (-1 < iVar4) {
      iVar4 = FUN_002b79a8();
      if (iVar4 != 0) {
        FUN_0028fb44(DAT_002cabbc,iVar4);
      }
      *(undefined4 *)(param_1 + 100) = 0xffffffff;
      goto LAB_0028fccc;
    }
    uVar3 = *(undefined4 *)(param_1 + 0x48);
    while (iVar4 = FUN_002b7908(uVar3), iVar4 < 0) {
      iVar4 = FUN_002b7e90(param_1);
      if (iVar4 != 0) {
        FUN_0028fb44(DAT_002ff3e0,iVar4);
      }
      FUN_002b7958(100000);
LAB_0028fccc:
      uVar3 = *(undefined4 *)(param_1 + 0x48);
    }
    if (*(int *)(param_1 + 0x48) < 0) {
      iVar4 = *(int *)(param_1 + 0x48);
    }
    else {
      iVar4 = FUN_002b7980(*(int *)(param_1 + 0x48),0);
      if (iVar4 != 0) {
        FUN_0028fb44(DAT_002cabe4,iVar4);
      }
      iVar4 = *(int *)(param_1 + 0x48);
    }
    if (-1 < iVar4) {
      iVar4 = FUN_002b79a8();
      if (iVar4 != 0) {
        FUN_0028fb44(DAT_002cabbc,iVar4);
      }
      *(undefined4 *)(param_1 + 0x48) = 0xffffffff;
    }
    if (bVar2) {
      iVar4 = FUN_002b7ed8(param_1);
      if (iVar4 != 0) {
        FUN_0028fb44(DAT_002ff408,iVar4);
      }
      iVar4 = FUN_002b7e90(param_1);
      if (iVar4 != 0) {
        FUN_0028fb44(DAT_002ff3e0,iVar4);
      }
      FUN_0028fb44(DAT_002ff434);
    }
    iVar4 = FUN_002b7ec0(param_1);
    if (iVar4 != 0) {
      FUN_0028fb44(DAT_002ff2a8,iVar4);
    }
    iVar4 = FUN_002b7a08(0);
    if (iVar4 < 0) {
      FUN_0028fb44(DAT_002ff2d0,iVar4);
    }
    uVar3 = *(undefined4 *)(param_1 + 0x88);
    iVar4 = FUN_002b78d0(uVar3);
    if (iVar4 != 0) {
      FUN_0028fb44(DAT_002ff27c,iVar4);
    }
    iVar4 = FUN_002b7d50();
    if (iVar4 != 0) {
      FUN_0028fb44(DAT_002ff300,iVar4);
    }
    iVar4 = FUN_002b7cc0(0x303);
    if (iVar4 < 0) {
      FUN_0028fb44(DAT_002ff320,iVar4);
    }
    iVar4 = FUN_0006165c();
    if (iVar4 != 0) {
      FUN_0028fb44(DAT_002ff34c,iVar4);
    }
    cVar1 = *(char *)(param_1 + 0x1ec);
    if (cVar1 != '\0') {
      FUN_002903cc();
    }
    uVar5 = 0;
    iVar4 = param_1;
    do {
      if (*(int *)(iVar4 + 0xd4) != 0) {
        FUN_000104e0();
        *(undefined4 *)(iVar4 + 0xd4) = 0;
      }
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 4;
    } while (uVar5 < 2);
    if (*(int *)(param_1 + 0xe4) != 0) {
      FUN_000104e0();
      *(undefined4 *)(param_1 + 0xe4) = 0;
    }
    iVar4 = *(int *)(param_1 + 0x2c);
    if (iVar4 != 0) {
      FUN_000104e0();
      *(undefined4 *)(param_1 + 0x2c) = 0;
    }
    *(undefined4 *)(param_1 + 0xe0) = 0;
    *(undefined1 *)(param_1 + 0x29) = 0;
    *(undefined1 *)(param_1 + 0x28) = 0;
    *(undefined1 *)(param_1 + 0x2a) = 0;
    uVar3 = 0;
  }
  return uVar3;
}
// near miss from lane fm11 (unreviewed)
