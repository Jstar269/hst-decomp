/* HSTMATCH module=EBOOT.BIN start=0x001cbedc end=0x001cc190 symbol=FUN_001cbedc lang=c++ */
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
extern undefined DAT_002c0e18;
extern undefined DAT_002c0e1c;
extern undefined DAT_002c0e20;
extern undefined DAT_002ea308;
extern char DAT_002eaa88[];
extern int FUN_0000d62c(...);
extern void FUN_000143b0(...);
extern int FUN_00014934(...);
extern uint * FUN_000149a8(...);
extern int FUN_00014a40(...);
extern void FUN_0018a950(...);
extern undefined1 * FUN_0018c9f4(...);
extern void FUN_001cd88c(...);
extern undefined * FUN_002294f4(...);
extern undefined4 FUN_002297d8(...);
extern undefined4 FUN_00287460(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual int m(); };

extern "C" void FUN_001cbedc(char *param_1,int *param_2,undefined4 param_3,undefined4 param_4)
{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined *puVar10;
  undefined1 auStack_100 [256];
  
  if (param_2 != (int *)0x0) {
    iVar2 = ((VC_0 *)(param_2))->m();
    if (iVar2 == 1) {
      iVar2 = FUN_00287460(param_2);
      uVar5 = 0xffffffff;
      if (iVar2 != 0) {
        iVar7 = FUN_00014a40(iVar2);
        pcVar1 = (char *)(iVar2 + iVar7);
        while ((*--pcVar1 >= '0') && (*pcVar1 < ':')) {
        }
        if (pcVar1 != (char *)0x0) {
          uVar5 = FUN_0000d62c(pcVar1 + 1);
        }
      }
      FUN_000143b0(auStack_100,DAT_002eaa88,uVar5,param_3,param_4);
      iVar2 = *(int *)(param_1 + 0x68);
    }
    else {
      FUN_000149a8(auStack_100,param_4);
      iVar2 = *(int *)(param_1 + 0x68);
    }
    uVar6 = 0;
    uVar8 = 0xffffffff;
    if (iVar2 != 0) {
      iVar2 = *(int *)(param_1 + 100);
      do {
        if (*(int *)(iVar2 + uVar6 * 4) != 0) {
          iVar2 = FUN_00014934(param_4);
          uVar8 = uVar6;
          if (iVar2 == 0) break;
        }
        uVar3 = *(uint *)(param_1 + 0x68);
        uVar6 = uVar6 + 1;
        uVar8 = 0xffffffff;
        if (uVar3 <= uVar6) break;
        iVar2 = *(int *)(param_1 + 100);
      } while( true );
    }
    if ((int)uVar8 < 0) {
      iVar7 = *(int *)(param_1 + 0x15c);
      iVar2 = (int)(FUN_002294f4(iVar7 + 0x34,*(undefined4 *)(iVar7 + 0x24),auStack_100,0));
      if (iVar2 != 0) {
        *(undefined1 *)(iVar7 + 99) = 0;
        *(undefined1 *)(iVar7 + 100) = 0;
        *(int *)(iVar7 + 0x68) = iVar2;
        *(undefined4 *)(iVar7 + 0x6c) = 0;
        *(undefined4 *)(iVar7 + 0x70) = 0;
        FUN_0018a950(*(undefined4 *)(iVar7 + 0x20),&DAT_002ea308);
        FUN_001cd88c(iVar7,2,1);
      }
      *(undefined4 *)(iVar7 + 0x74) = 0xffffffff;
      *(undefined4 *)(iVar7 + 0x78) = 0xffffffff;
      FUN_002297d8(iVar7 + 0x34,auStack_100,0);
    }
    else {
      iVar9 = *(int *)(*(int *)(param_1 + 0x4c) + uVar8 * 4);
      iVar7 = *(int *)(iVar9 + 0x34);
      iVar2 = (int)(FUN_0018c9f4(7));
      if (*(int *)(iVar2 + 4) == 0) {
        puVar10 = &DAT_002c0e20;
      }
      else if (*(int *)(*(int *)(iVar2 + 8) + 8) < 1) {
        puVar10 = &DAT_002c0e1c;
      }
      else if ((iVar7 < 0) || ((*(int **)(iVar2 + 0xc))[1] <= iVar7)) {
        puVar10 = &DAT_002c0e18;
      }
      else {
        puVar10 = *(undefined **)(**(int **)(iVar2 + 0xc) + iVar7 * 4);
      }
      iVar7 = *(int *)(param_1 + 0x15c);
      iVar2 = (int)(FUN_002294f4(iVar7 + 0x34,*(undefined4 *)(iVar7 + 0x24),auStack_100,0));
      if (iVar2 != 0) {
        *(undefined1 *)(iVar7 + 99) = 0;
        *(undefined1 *)(iVar7 + 100) = 0;
        *(int *)(iVar7 + 0x68) = iVar2;
        *(undefined4 *)(iVar7 + 0x6c) = 0;
        *(undefined4 *)(iVar7 + 0x70) = 0;
        FUN_0018a950(*(undefined4 *)(iVar7 + 0x20),puVar10);
        FUN_001cd88c(iVar7,2,1);
      }
      *(undefined4 *)(iVar7 + 0x74) = 0xffffffff;
      *(undefined4 *)(iVar7 + 0x78) = 0xffffffff;
      FUN_002297d8(iVar7 + 0x34,auStack_100,0);
      *(int *)(*(int *)(param_1 + 0x15c) + 0x5c) = iVar9;
    }
  }
  return;
}
// near miss from lane km4 (unreviewed)
