/* HSTMATCH module=EBOOT.BIN start=0x001f2f08 end=0x001f3144 symbol=FUN_001f2f08 lang=c++ */
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
extern undefined DAT_0030ab9c;
extern undefined DAT_0030ebf4;
extern undefined * DAT_003386b0;
extern undefined * DAT_003415ac;
extern void FUN_00000a00(...);
extern void FUN_000104e0(...);
extern void FUN_0001bfb4(...);
extern void FUN_0001cb88(...);
extern int FUN_0001cbfc(...);
extern undefined4 FUN_0001cc54(...);
extern void FUN_00092ff8(...);
extern void FUN_001b5758(...);
extern void FUN_001ee0f8(...);
extern void FUN_001f4bbc(...);
extern void FUN_001fb44c(...);
extern void FUN_001fb7cc(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" void FUN_001f2f08(int param_1)
{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  FUN_001fb44c();
  FUN_001f4bbc(param_1);
  iVar4 = (int)(DAT_003415ac);
  if (DAT_003415ac != 0) {
    *(undefined4 *)(DAT_003415ac + 0x74) = 0x3f800000;
    *(undefined4 *)(iVar4 + 0x78) = 0x3f800000;
    iVar4 = (int)(DAT_003415ac);
    *(undefined4 *)(**(int **)(DAT_003415ac + 4) + 0x60) = 0x43700000;
    *(undefined4 *)(**(int **)(iVar4 + 4) + 100) = 0x43080000;
  }
  FUN_0001cb88((int)&DAT_0030ebf4);
  *(undefined4 *)(param_1 + 0x8188) = 0;
  if (*(int *)(param_1 + 0x1368) == 0) {
    iVar4 = *(int *)(param_1 + 0x584);
  }
  else {
    FUN_00000a00(*(int *)((int)param_1 + 4968));
    *(undefined4 *)(param_1 + 0x1368) = 0;
    iVar4 = *(int *)(param_1 + 0x584);
  }
  piVar3 = *(int **)(iVar4 + 0x90);
  if (piVar3 == (int *)0x0) {
    piVar3 = *(int **)(param_1 + 0x510);
  }
  else {
    delete ((VC_0 *)(piVar3));
    *(undefined4 *)(iVar4 + 0x90) = 0;
    piVar3 = *(int **)(param_1 + 0x510);
  }
  if (piVar3 != (int *)0x0) {
    delete ((VC_1 *)(piVar3));
    *(undefined4 *)(param_1 + 0x510) = 0;
  }
  if (DAT_003386b0 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(DAT_003386b0 + 0xa8);
  }
  iVar6 = 0;
  iVar5 = param_1;
  do {
    FUN_001fb7cc(iVar5 + 0x10fc);
    iVar6 = iVar6 + 1;
    iVar5 = iVar5 + 0xe4;
  } while (iVar6 < 2);
  iVar6 = 3;
  iVar5 = param_1 + 0xc;
  do {
    if (*(int *)(iVar5 + 0x3a0) == 0) {
      iVar7 = *(int *)(iVar5 + 0x3b0);
      if (iVar7 != 0) {
        if (iVar7 == 0) {
          *(undefined4 *)(iVar5 + 0x3b0) = 0;
        }
        else {
          FUN_001ee0f8(iVar7);
          FUN_00000a00(iVar7);
          *(undefined4 *)(iVar5 + 0x3b0) = 0;
        }
      }
    }
    else {
      if (iVar4 == 0) {
        uVar1 = *(undefined4 *)(iVar5 + 0x3a0);
      }
      else {
        FUN_001b5758(iVar4,iVar6);
        uVar1 = *(undefined4 *)(iVar5 + 0x3a0);
      }
      FUN_00092ff8(uVar1);
      iVar7 = *(int *)(iVar5 + 0x3b0);
      if (iVar7 == 0) {
        *(undefined4 *)(iVar5 + 0x3a0) = 0;
      }
      else {
        if (iVar7 == 0) {
          *(undefined4 *)(iVar5 + 0x3b0) = 0;
        }
        else {
          FUN_001ee0f8(iVar7);
          FUN_00000a00(iVar7);
          *(undefined4 *)(iVar5 + 0x3b0) = 0;
        }
        *(undefined4 *)(iVar5 + 0x3a0) = 0;
      }
    }
    iVar6 = iVar6 + -1;
    iVar5 = iVar5 + -4;
  } while (-1 < iVar6);
  *(undefined4 *)(param_1 + 0x3c0) = 0;
  if (*(int *)(param_1 + 0x39c) != 0) {
    uVar1 = FUN_0001cbfc();
    uVar2 = FUN_0001cc54();
    FUN_0001bfb4((int)&DAT_0030ab9c,uVar1,uVar2);
    if (*(int *)(param_1 + 0x39c) != 0) {
      FUN_000104e0(*(int *)((int)param_1 + 924));
      *(undefined4 *)(param_1 + 0x39c) = 0;
    }
  }
  return;
}
// near miss from lane fm9 (unreviewed)
