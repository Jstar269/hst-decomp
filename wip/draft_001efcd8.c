/* HSTMATCH module=EBOOT.BIN start=0x001efcd8 end=0x001f00c8 symbol=FUN_001efcd8 lang=c99 */
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

extern undefined * DAT_002cfc8c;
extern int DAT_002ee828;
extern int DAT_002ee82c;
extern char DAT_002ee830[];
extern undefined4 FUN_00065740();
extern undefined4 FUN_001b1c44();
extern int FUN_001b2af0();
extern void FUN_001e09dc();
extern void FUN_001e28e0();
extern void FUN_001e2990();
extern void FUN_001e54dc();
extern void FUN_001e5524();
extern void FUN_001e5958();
extern void FUN_001e59d0();
extern void FUN_001e59d8();
extern void FUN_001f3770();
extern void FUN_001f461c();
extern void FUN_001f46b4();
extern void FUN_001f474c();
extern void FUN_001f47a4();
extern void FUN_001f4bfc();
extern void FUN_001f4ee0();
extern void FUN_001f9390();
extern void FUN_001f93dc();
extern void FUN_001f94a4();
extern void FUN_001f94ac();

void FUN_001efcd8(int param_1)
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x44) == 0) {
    *(undefined4 *)(param_1 + 0x5dc) = 0;
    *(undefined4 *)(param_1 + 0x5e0) = 0;
    FUN_001f9390();
    *(undefined4 *)(param_1 + 0x5f0) = *(undefined4 *)(param_1 + 0x5ec);
    FUN_001f474c(param_1,0);
    FUN_001e09dc(*(undefined4 *)(param_1 + 0x510),2);
    FUN_001e2990(*(undefined4 *)(param_1 + 0x510));
    FUN_001e54dc(*(undefined4 *)(param_1 + 0x510),0);
    FUN_001e59d8(*(undefined4 *)(param_1 + 0x510));
  }
  iVar2 = *(int *)(param_1 + 0x5dc);
  if (iVar2 == 4) {
    iVar4 = *(int *)(param_1 + 0x5e0) + 1;
    *(int *)(param_1 + 0x5e0) = iVar4;
    iVar2 = DAT_002ee828;
    if (iVar4 < DAT_002ee828) {
      *(int *)(param_1 + 0x5e0) = DAT_002ee828;
    }
    else {
      iVar2 = DAT_002ee82c;
      if (iVar4 <= DAT_002ee82c) {
        iVar2 = iVar4;
      }
      *(int *)(param_1 + 0x5e0) = iVar2;
    }
    iVar4 = FUN_00065740(*(undefined4 *)(*(int *)(param_1 + 0x584) + 0x90),DAT_002ee830,1);
    if (iVar2 == iVar4) {
      if ((*(char *)(param_1 + 0x5f4) != '\0') && (*(char *)(param_1 + 0x5f5) != '\0')) {
        FUN_001e59d0(*(undefined4 *)(param_1 + 0x510));
      }
      iVar2 = *(int *)(param_1 + 0x5e0);
    }
    else {
      iVar2 = *(int *)(param_1 + 0x5e0);
    }
    if (iVar2 == 10) {
      FUN_001e28e0(*(undefined4 *)(param_1 + 0x510));
      iVar2 = *(int *)(param_1 + 0x5e0);
    }
    else {
      iVar2 = *(int *)(param_1 + 0x5e0);
    }
    if (10 < iVar2) {
      if (*(char *)(param_1 + 0x58c) == '\0') {
        bVar1 = ((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e == 0;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        FUN_001b1c44(0x34179c,3);
        FUN_001f9390(param_1);
        FUN_001f94ac(param_1);
        FUN_001f3770(param_1);
      }
    }
  }
  else if (iVar2 == 3) {
    *(undefined4 *)(param_1 + 0x5dc) = 4;
    *(undefined4 *)(param_1 + 0x5e0) = 0;
    if (*(char *)(param_1 + 0x5f4) == '\0') {
      uVar3 = *(undefined4 *)(param_1 + 0x510);
    }
    else {
      if (*(char *)(param_1 + 0x5f5) == '\0') {
        uVar3 = FUN_001b2af0(0x34179c,0xf);
        *(undefined4 *)(param_1 + 0x5b8) = uVar3;
        FUN_001f461c(param_1,0);
        FUN_001f4ee0(param_1,*(undefined4 *)(param_1 + 0x3c4));
        FUN_001f94a4(param_1);
      }
      else {
        uVar3 = FUN_001b2af0(0x34179c,0xe);
        *(undefined4 *)(param_1 + 0x5b8) = uVar3;
        FUN_001f46b4(param_1,0);
        FUN_001e5958(*(undefined4 *)(param_1 + 0x510));
        FUN_001f93dc(param_1);
      }
      uVar3 = *(undefined4 *)(param_1 + 0x510);
    }
    FUN_001e5524(uVar3,*(undefined1 *)(param_1 + 0x5f4));
  }
  else if (iVar2 == 2) {
    iVar2 = *(int *)(param_1 + 0x5e0) + 1;
    *(int *)(param_1 + 0x5e0) = iVar2;
    if (iVar2 < 0x1a) {
      if (*(char *)(param_1 + 0x58c) == '\0') {
        bVar1 = ((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e == 0;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        FUN_001b1c44(0x34179c,3);
        *(undefined4 *)(param_1 + 0x5dc) = 3;
        *(undefined4 *)(param_1 + 0x5e0) = 0;
        FUN_001e5524(*(undefined4 *)(param_1 + 0x510),0);
      }
    }
    else {
      FUN_001b1c44(0x34179c,8);
      *(int *)(param_1 + 0x5dc) = *(int *)(param_1 + 0x5dc) + 1;
      *(undefined4 *)(param_1 + 0x5e0) = 0;
    }
  }
  else if (iVar2 == 1) {
    iVar2 = *(int *)(param_1 + 0x5e0) + 1;
    *(int *)(param_1 + 0x5e0) = iVar2;
    if (iVar2 < 0x1a) {
      if (*(char *)(param_1 + 0x58c) == '\0') {
        bVar1 = ((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e == 0;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        FUN_001b1c44(0x34179c,3);
        *(undefined4 *)(param_1 + 0x5dc) = 3;
        *(undefined4 *)(param_1 + 0x5e0) = 0;
      }
    }
    else {
      FUN_001b1c44(0x34179c,8);
      *(int *)(param_1 + 0x5dc) = *(int *)(param_1 + 0x5dc) + 1;
      *(undefined4 *)(param_1 + 0x5e0) = 0;
      FUN_001e5524(*(undefined4 *)(param_1 + 0x510),0);
    }
  }
  else if ((iVar2 == 0) &&
          (iVar2 = *(int *)(param_1 + 0x5e0) + 1, *(int *)(param_1 + 0x5e0) = iVar2, 0x28 < iVar2))
  {
    FUN_001b1c44(0x34179c,8);
    *(undefined4 *)(param_1 + 0x5dc) = 1;
    *(undefined4 *)(param_1 + 0x5e0) = 0;
    FUN_001e5524(*(undefined4 *)(param_1 + 0x510),0);
  }
  FUN_001f4bfc(param_1);
  FUN_001f47a4(param_1);
  return;
}
// near miss from lane fm11 (unreviewed)
